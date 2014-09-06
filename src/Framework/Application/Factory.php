<?php

namespace xpl\Framework\Application;

use xpl\Foundation\BundleProviderInterface;
use xpl\Dependency\DiAwareInterface;
use xpl\Framework\DiAwareTrait;

class Factory implements BundleProviderInterface, DiAwareInterface
{
	use DiAwareTrait;
	
	const DEFAULT_CLASS = 'xpl\\Framework\\Application\\App';
	
	protected $path;
	protected $class;
	protected $allow_own_class = true;
	protected $apps;
	
	/**
	 * Constructor.
	 * 
	 * @param string $apps_path Filesystem path to applications directory.
	 * @param string $class [Optional] Default application class.
	 */
	public function __construct($apps_path, $class = self::DEFAULT_CLASS) {
		
		if (! $realpath = realpath($apps_path)) {
			throw new \RuntimeException("Apps directory does not exist: '$apps_path'.");
		}
		
		if (! $this->isValidClass($class)) {
			throw new \RuntimeException("App class '$class' must implement ".static::DEFAULT_CLASS);
		}
		
		$this->path = $realpath.DIRECTORY_SEPARATOR;
		$this->class = $class;
		$this->apps = array();
	}
	
	/**
	 * Implements \xpl\Foundation\BundleProviderInterface
	 * 
	 * @param string $type Bundle type (must be "app").
	 * @param string $name Bundle name (app name).
	 * @return \xpl\Foundation\Application
	 */
	public function provideBundle($type, $name) {
		
		if ('app' !== $type) {
			throw new \LogicException("App factory only creates apps, requested: '$type'.");
		}
		
		if (isset($this->apps[$name])) {
			throw new \LogicException("Application '$name' already exists.");
		}
		
		$path = $this->path.$name.'/';
		$class = $this->class;
		
		if (! is_dir($path)) {
			throw new \RuntimeException("Invalid application directory for '$name': '$path'.");
		}
		
		$config = new Config($name, $path);
		
		if ($this->allow_own_class && is_readable($path.'Application.php')) {
			
			// Use a custom class from Application.php
			include $path.'Application.php';
			
			$app_class = ucfirst($name).'Application';
			
			if (class_exists($app_class, false) && $this->isValidClass($app_class)) {
				$class = $app_class;
			}
		}
		
		$this->apps[$name] = $class;
		
		return new $class($config);
	}
	
	public function setAllowOwnClass($value) {
		$this->allow_own_class = (bool) $value;
	}
	
	public function isValidClass($class) {
		return $class === static::DEFAULT_CLASS || is_subclass_of($class, static::DEFAULT_CLASS);
	}
	
	public function get($name) {
		
		if (isset($this->apps[$name])) {
			return $this->di('bundles')->getBundle('app.'.$name);
		}
		
		return null;
	}
	
	public function exists($name) {
		return isset($this->apps[$name]);
	}
	
}

