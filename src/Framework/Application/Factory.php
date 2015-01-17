<?php

namespace xpl\Framework\Application;

class Factory implements \xpl\Bundle\ProviderInterface
{
	
	const BASE_CLASS = 'xpl\\Framework\\Application\\App';
	
	protected $path;
	protected $class;
	protected $allow_custom_class = true;
	protected $apps;
	
	/**
	 * Constructor.
	 * 
	 * @param string $apps_path Filesystem path to applications directory.
	 * @param string $class [Optional] Default application class.
	 */
	public function __construct($apps_path, $class = self::BASE_CLASS) {
		
		if (! $realpath = realpath($apps_path)) {
			throw new \RuntimeException("Apps directory does not exist: '$apps_path'.");
		}
		
		if (! $this->isValidClass($class)) {
			throw new \RuntimeException("App class '$class' must implement ".static::BASE_CLASS);
		}
		
		$this->path = $realpath.DIRECTORY_SEPARATOR;
		$this->class = $class;
		$this->apps = array();
	}
		
	public function isValidClass($class) {
		return trim($class, '\\') === static::BASE_CLASS || is_subclass_of($class, static::BASE_CLASS);
	}
	
	public function setAllowCustomClass($value) {
		$this->allow_custom_class = (bool)$value;
	}
	
	public function exists($name) {
		return isset($this->apps[$name]);
	}
	
	public function get($name) {
		return $this->exists($name) ? get_app($name) : null;
	}
	
	/**
	 * Implements \xpl\Bundle\ProviderInterface
	 * 
	 * @param string $type Bundle type (must be "app").
	 * @param string $name Bundle name (app name).
	 * @return \xpl\Bundle\Application
	 */
	public function provideBundle($type, $name) {
		
		if ('app' !== $type) {
			throw new \LogicException("App factory only creates apps, requested: '$type'.");
		}
		
		if (isset($this->apps[$name])) {
			throw new \LogicException("Application already exists: '$name'.");
		}
		
		if (! is_dir($path = $this->path.$name.'/')) {
			throw new \RuntimeException("Invalid directory for application '$name': '$path'.");
		}
		
		// Set up config
		$config = new Config($name, $path);
		
		$this->configure($config);
		
		$class = $this->getAppClass($config);
		
		$this->setupAutoloader($config);
		
		if (empty($this->apps)) {
			// 1st app is primary
			$config->set('is_primary', true);
		}
		
		$this->apps[$name] = $class;
		
		return new $class($config);
	}

	protected function configure(Config $config) {
		
		$config_path = $config->getPath().'config/';
		$config_file = $config_path.'config.php';
		
		$config->setPath('config', $config_path);
		
		if (is_readable($config_file)) {
			
			$vars = include $config_file;
			
			foreach($vars as $key => $value) {
					
				if ('paths' === $key || 'dirs' === $key) {
					
					foreach($value as $dirname => $dirpath) {
						$config->setPath($dirname, $dirpath);
					}
				
				} else {
					$config->set($key, $value);
				}
			}
		}
	}
	
	protected function getAppClass(Config $config) {
		
		// Use a custom App class?
		if ($this->allow_custom_class) {
		
			$file = $config->get('class_file') ?: $config->getPath().'Application.php';
			
			if (is_readable($file)) {
				
				include $file;
				
				if ($namespace = $config->get('namespace')) {
					$class = $namespace.'\\Application';
				} else {
					$class = ucfirst($name).'Application';
				}
				
				if (class_exists($class, false) && $this->isValidClass($class)) {
					return $class;
				}
			}
		}
		
		return $this->class;
	}
	
	protected function setupAutoloader(Config $config) {
		
		if ($autoload = $config->get('autoload') && $namespace = $config->get('namespace')) {
			
			$dirname = $config->get('autoload_dir') ?: 'classes';
			
			if ($path = $config->getPath($dirname)) {
				
				if ('psr-0' === strtolower($autoload)) {
					di('autoloader')->addPsr0($namespace, $path);
				} else {
					di('autoloader')->addPsr4($namespace, $path);
				}
			}
		}
	}

}

