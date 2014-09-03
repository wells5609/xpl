<?php

namespace xpl\Data\Service;

use xpl\Data\Service\ServiceInterface as Service;

class Registry {
	
	protected $services = array();
	protected $registered = array();
	
	public function set($svc, Service $service) {
		$this->services[$svc] = $service;
		return $this;
	}
	
	public function register($svc, $class) {
		
		if (! is_string($class)) {
			throw new \InvalidArgumentException("Class for service '$svc' must be string, given: ".gettype($class));
		}
		
		$this->registered[$svc] = $class;
		
		return $this;
	}
	
	public function get($svc) {
		
		if (! isset($this->services[$svc])) {
			
			if (! isset($this->registered[$svc])) {
				throw new \RuntimeException("Unknown service '$svc'.");
			}
			
			$class = $this->registered[$svc];
			$this->services[$svc] = new $class();
		}
		
		return $this->services[$svc];
	}
	
	public function has($svc) {
		return isset($this->services[$svc]) || isset($this->registered[$svc]);
	}
	
	public function exists($svc) {
		return isset($this->services[$svc]) || isset($this->registered[$svc]);
	}
	
	public function unregister($svc, $class = null) {
			
		if (isset($this->services[$svc])) {
			if (empty($class) || $this->services[$svc] instanceof $class) {
				unset($this->services[$svc]);
			}
		}
		
		if (isset($this->registered[$svc])) {
			if (empty($class) || $this->registered[$svc] == $class) {
				unset($this->registered[$svc]);
			}
		}
		
		return $this;
	}
	
}
