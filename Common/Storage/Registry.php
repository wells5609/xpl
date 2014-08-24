<?php

namespace xpl\Common\Storage;

use xpl\Common\Structure\Map;

/**
 * Registry is a Map that restricts values to objects.
 * 
 * It also allows objects to be registered and loaded lazily via closures.
 */
class Registry extends Map {
	
	/**
	 * @var array
	 */
	protected $registered = array();
	
	/**
	 * Sets an object.
	 * 
	 * @param string $key Item key.
	 * @param object $object Object instance.
	 * 
	 * @return $this
	 */
	public function set($key, $object) {
		
		if (! is_object($object)) {
			throw new \InvalidArgumentException("Registry only accepts objects, given: ".gettype($object));
		}
		
		$this->_data[$key] = $object;
		
		return $this;
	}
	
	/**
	 * Adds an array of items.
	 * 
	 * @param array $items
	 * 
	 * @return $this
	 */
	public function add(array $items) {
		
		foreach($items as $name => $object) {
			$this->set($name, $object);
		}
		
		return $this;
	}
	
	/**
	 * Returns a registered value.
	 * 
	 * @param string $key Item key.
	 * 
	 * @return mixed
	 */
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
	
	/**
	 * Registers a closure which loads an item when invoked.
	 * 
	 * @param string $key Item key.
	 * @param \Closure $callback Closure that returns the item.
	 * 
	 * @return $this
	 */
	public function register($key, \Closure $callback) {
		
		$this->registered[$key] = $callback;
		
		return $this;
	}
	
}
