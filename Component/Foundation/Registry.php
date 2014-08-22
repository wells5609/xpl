<?php

namespace xpl\Component\Foundation;

use xpl\Common\Structure\Map;

/**
 * Registry is a Map that restricts values to objects.
 * 
 * It also allows objects to be registered and loaded lazily via closures.
 */
class Registry extends Map {
	
	protected $registered = array();
	
	public function set($key, $object) {
		
		if (! is_object($object)) {
			throw new \InvalidArgumentException("Registry only accepts objects, given: ".gettype($object));
		}
		
		$this->_data[$key] = $object;
		
		return $this;
	}
	
	public function add(array $components) {
		foreach($components as $name => $object) {
			$this->set($name, $object);
		}
		return $this;
	}
	
	public function get($key) {
		
		if (isset($this->_data[$key])) {
			return $this->_data[$key];
		
		} else if (isset($this->registered[$key])) {
		
			$this->_data[$key] = call_user_func($this->registered[$key], $this);
		
			unset($this->registered[$key]);
		
			return $this->_data[$key];
		}
		
		return null;	
	}
	
	public function register($key, \Closure $callback) {
		
		$this->registered[$key] = $callback;
		
		return $this;
	}
	
}
