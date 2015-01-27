<?php

namespace xpl\Data\Service;

use xpl\Data\ServiceInterface as Service;

class Registry 
{
	
	protected $services = array();
	protected $registered = array();
	
	public function set($name, Service $service) {
		$this->services[$name] = $service;
		return $this;
	}
	
	public function register($name, $class) {
		
		if ($class instanceof Service) {
			return $this->set($name, $class);
		}
		
		if (! is_string($class)) {
			throw new \InvalidArgumentException("Class for service '$name' must be string, given: ".gettype($class));
		}
		
		$this->registered[$name] = $class;
		
		return $this;
	}
	
	public function get($name) {
		
		if (! isset($this->services[$name])) {
			
			if (! isset($this->registered[$name])) {
				throw new \RuntimeException("Unknown service: '$name'.");
			}
			
			$class = $this->registered[$name];
			
			$this->services[$name] = new $class();
		}
		
		return $this->services[$name];
	}
	
	public function has($name) {
		return isset($this->services[$name]) || isset($this->registered[$name]);
	}
	
	public function exists($name) {
		return isset($this->services[$name]) || isset($this->registered[$name]);
	}
	
	public function unregister($name, $class = null) {
			
		if (isset($this->services[$name])) {
			if (empty($class) || $this->services[$name] instanceof $class) {
				unset($this->services[$name]);
			}
		}
		
		if (isset($this->registered[$name])) {
			if (empty($class) || $this->registered[$name] == $class) {
				unset($this->registered[$name]);
			}
		}
		
		return $this;
	}
	
}
