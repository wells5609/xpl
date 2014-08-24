<?php

namespace xpl\Bundle\Application;

use xpl\Bundle\Application;
use xpl\Framework\RequestInterface;
use xpl\Routing\RouteInterface;
use xpl\Routing\Resource;
use xpl\Routing\Router;
use xpl\Http\Response;
use RuntimeException;

class App extends Application implements AppInterface {
	
	/**
	 * @var string
	 */
	protected static $primary;
	
	/**
	 * Sets up a new application instance.
	 * 
	 * @param \xpl\Bundle\Application\Config $config
	 * 
	 * @return \xpl\Bundle\Application\App
	 */
	public static function create(Config $config) {
		
		$path = $config->getPath();
		$name = $config->get('name');
		
		if (! is_readable($path.'config/config.php')) {
			throw new RuntimeException("Missing config.php file for application '$name'.");
		}
		
		$config->setPath('config', 'config/');
		
		$vars = import($path.'config/config.php');
		
		if (! is_array($vars)) {
			throw new RuntimeException("App config.php must return array, got: ".gettype($vars));
		}
		
		// the 1st app is primary
		if (! isset(static::$primary)) {
			static::$primary = $name;
			$config->set('is_primary', true);
		}
		
		// Set vars
		if (! empty($vars['app'])) {
			$config->import($vars['app']);
		}
		
		// Set paths
		if (! empty($vars['paths'])) {
			foreach($vars['paths'] as $name => $path) {
				$config->setPath($name, $path);
			}
		}
		
		// Set env vars
		if (! empty($vars['general'])) {
			
			$config->import($vars['general']);
			
			// import into env if primary
			if ($config->get('is_primary')) {
							
				$env_vars = array_combine(array_map('strtoupper', array_keys($vars['general'])), $vars['general']);
				
				di()->resolve('kernel')->getEnvironment()->import($env_vars);
			}
		}
		
		return new static($config);
	}
	
	public function onDispatch(RouteInterface $route, RequestInterface $request) {
	}
	
	public function onRespond(Response $response) {
	}
	
	public function initViews(\View\Manager $views) {
		
		$__FILE__ = $this->getPath('config').'views.php';
		
		file_exists($__FILE__) and include $__FILE__;
	}
	
	/**
	 * @return $this|boolean
	 */
	public function useResources($newval = null) {
		
		if (! isset($newval)) {
			return $this->config->get('use_resources');
		}
		
		$this->config->set('use_resources', (bool)$newval);
		
		return $this;
	}
	
	/**
	 * @return \Resource\Resource
	 */
	public function getResource($name = null) {
		
		$key = 'resource'.(isset($name) ? ".{$name}" : '');
		
		if ($this->registry->has($key)) {
			return $this->registry->get($key);
		}
		
		$class = $this->getNamespace().'\\Resource';
		
		isset($name) and $class .= '\\'.ucfirst($name);
		
		if (! class_exists($class, true)) {
			throw new \InvalidArgumentException("Resource class does not exist: '$class'.");
		}
		
		$resource = Resource::createFromClass($class);
		
		$this->registry->set($key, $resource);
		
		return $resource;
	}
	
	/**
	 * Sets a config item value.
	 * 
	 * @param string $item Config item key.
	 * @param mixed $value Conifg item value. Pass null to unset the item.
	 */
	public function setConfig($item, $value) {
		if (null === $value) {
			$this->config->remove($item);
		} else {
			$this->config->set($item, $value);
		}
		return $this;
	}
	
	/**
	 * Returns a config item or the entire \App\Config object.
	 * 
	 * @param string $item [Optional] Item key to retrive, or null to get the object.
	 * @return mixed
	 */
	public function getConfig($item = null) {
		return isset($item) ? $this->config->get($item) : $this->config;
	}
	
	/**
	 * Sets a named app directory path.
	 * 
	 * @param string $name Name used to identify the directory.
	 * @param string $path Relative path to directory from application root.
	 * @return $this
	 */
	public function setPath($name, $path) {
		$this->config->setPath($name, $path);
		return $this;
	}
	
	/**
	 * Returns a directory path by name, or the root path if given null.
	 * 
	 * @param string $name Name of directory, or NULL for the root path.
	 * @return string Directory path if found, otherwise null.
	 */
	public function getPath($name = null) {
		return $this->config->getPath($name);
	}
	
	/**
	 * Returns an array of all the app's directory paths.
	 * 
	 * @return array Associative array of directories.
	 */
	public function getPaths() {
		return $this->config->get('paths');
	}
	
	/**
	 * Sets a component in the object registry.
	 * 
	 * @param string $name Component name.
	 * @param object $object Component object.
	 * @return $this
	 */
	public function setComponent($name, $object) {
		$this->registry->set($name, $object);
		return $this;
	}
	
	/**
	 * Retrieves a component from the application's object registry.
	 * 
	 * @param string $name Component name.
	 * @return mixed
	 */
	public function getComponent($name) {
		return $this->registry->get($name);
	}
	
	/**
	 * Alias of getName()
	 * @return string
	 */
	public function getId() {
		return $this->getName();
	}
	
	/**
	 * Checks whether the app is the primary app.
	 * 
	 * @return boolean
	 */
	public function isPrimary() {
		return (bool) $this->config->get('is_primary');
	}
	
	/**
	 * Called at end of `__construct()`
	 */
	protected function onInit() {
		
		$this->loadComponents();
	}
	
	/**
	 * Sets up initial application components in object registry.
	 */
	protected function loadComponents() {
		
		if (true !== $this->useResources()) {
			
			$this->registry->set('router', $router = new Router);
			
			$__FILE__ = $this->getPath('config').'routes.php';
		
			file_exists($__FILE__) and include $__FILE__;
		}
	}
	
	/**
	 * Adds autoloading of the app's namespace from the directory/(ies) given.
	 * 
	 * The application's namespace MUST be set prior to calling, otherwise
	 * a RuntimeException is thrown.
	 * 
	 * @param string $dir Directory path.
	 * @param boolean $psr4 [Optional] Whether to load using PSR-4. Default false.
	 * 
	 * @throws \RuntimeException if app namespace is not set.
	 */
	protected function autoloadRegister($dir, $psr4 = false) {
		
		if (! $namespace = $this->getNamespace()) {
			throw new RuntimeException("Must set app namespace to register autoloader.");
		}
		
		$func = 'add'.($psr4 ? 'Psr4' : '');
		
		composer()->$func($namespace.'\\', $dir);
	}
	
}
