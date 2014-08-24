<?php

namespace xpl\Bundle\Application;

use xpl\Bundle\ProviderInterface;

class Factory implements ProviderInterface {
	
	const DEFAULT_CLASS = 'xpl\\Bundle\\Application\\App';
	
	protected $path;
	protected $class;
	protected $lastClass;
	protected $allowOwnClass = true;
	protected $onConfig;
	protected $apps;
	
	public function __construct($apps_path, $class = self::DEFAULT_CLASS) {
		$this->setPath($apps_path);
		$this->setClass($class);
		$this->apps = array();
	}
	
	/**
	 * Implements \xpl\Component\Bundle\Contract\Provider
	 * 
	 * @param string $type Bundle type (must be "app").
	 * @param string $name Bundle name (app name).
	 * @return \xpl\Component\Application\App
	 */
	public function provideBundle($type, $name) {
		
		if ('app' !== $type) {
			throw new \LogicException("App factory only creates apps, requested: '$type'.");
		}
		
		return $this->create($name);
	}
	
	public function setAllowOwnClass($value) {
		$this->allowOwnClass = (bool) $value;
	}
	
	public function setPath($path) {
		
		if (! $realpath = realpath($path)) {
			throw new \RuntimeException("Directory does not exist: '$path'.");
		}
		
		$this->path = $realpath.DIRECTORY_SEPARATOR;
	}
	
	public function setClass($class) {
		
		if ($class !== static::DEFAULT_CLASS && ! is_subclass_of($class, static::DEFAULT_CLASS)) {
			throw new \UnexpectedValueException("App class '$class' must implement ".static::DEFAULT_CLASS);
		}
		
		isset($this->class) and $this->lastClass = $this->class;
		
		$this->class = $class;
	}
	
	public function resetClass() {
		isset($this->lastClass) and $this->setClass($this->lastClass);
	}
	
	public function create($name) {
		
		if (isset($this->apps[$name])) {
			throw new \LogicException("Application '$name' already exists.");
		}
		
		$path = $this->path.$name.'/';
		$class = $this->class;
		
		if (! is_dir($path)) {
			throw new \RuntimeException("Invalid application directory for '$name': '$path'.");
		
		}
		
		$config = new Config($name, $path);
		
		if ($this->allowOwnClass && is_readable($path.'Application.php')) {
			
			// Use a custom class from Application.php
			import($path.'Application.php');
			
			$appClass = ucfirst($name).'Application';
			
			if (class_exists($appClass, false) && is_subclass_of($appClass, static::DEFAULT_CLASS)) {
				$class = $appClass;
			}
		}
		
		if (isset($this->onConfig)) {
			call_user_func($this->onConfig, $config);
		}
		
		return $this->apps[$name] = new $class($config);
	}
	
	public function onConfig(\Closure $call) {
		$this->onConfig = $call;
		return $this;
	}
	
	public function get($name) {
		
		if (isset($this->apps[$name])) {
			return $this->apps[$name];
		}
		
		return $this->create($name);
	}
	
	public function exists($name) {
		return isset($this->apps[$name]);
	}
	
}

