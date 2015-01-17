<?php

namespace xpl\Dependency;

use Closure;

class DI implements \ArrayAccess, \Countable {
	
	protected $keys = array();
	protected $values = array();
	protected $registered = array();
	protected $factories = array();
	
	/**
	 * Register a dependency.
	 * 
	 * Value can be:
	 * 	1) An object instance
	 *  2) A closure that returns the object
	 * 
	 * @param string $key Dependency key.
	 * @param mixed $object
	 */
	public function offsetSet($key, $object) {
		
		$this->keys[$key] = true;
	
		if ($object instanceof Closure) {
			$this->registered[$key] = $object;
		} else {
			$this->values[$key] = $object;
		}
	}
	
	/**
	 * Resolves a dependency or value.
	 * 
	 * @param string $key
	 * @return mixed
	 */
	public function offsetGet($key) {
		
		if (isset($this->values[$key])) {
			return $this->values[$key];
		}
		
		if (isset($this->registered[$key])) {
			return $this->values[$key] = call_user_func($this->registered[$key], $this);
		}
		
		if (isset($this->factories[$key])) {
			return call_user_func($this->factories[$key], $this);
		}
		
		return null;
	}
	
	public function offsetExists($key) {
		return isset($this->keys[$key]);
	}
	
	public function offsetUnset($key) {
		if (isset($this->keys[$key])) {
			unset($this->registered[$key], $this->values[$key], $this->factories[$key], $this->keys[$key]);
		}
	}
	
	public function factory($key, Closure $factory) {
		$this->keys[$key] = true;
		$this->factories[$key] = $factory;
	}
	
	public function extend($key, Closure $call) {
		
		if (! isset($this->keys[$key])) {
			throw new Exception("No item '$key' found.");
		}
		
		$object = $this[$key];
		
		if (! is_object($object)) {
			throw new Exception("Cannot extend non-object item: '$key'.");
		}
		
		$new_object = call_user_func($call, $object, $this);
		
		if (! is_object($new_object)) {
			throw new Exception("Must return object from extension for '$key', given: ".gettype($new_object));
		}
		
		$this[$key] = $new_object;
	}
	
	public function get($key) {
		return $this->offsetGet($key);
	}
	
	public function __get($var) {
		return $this->offsetGet($var);
	}
	
	public function __invoke($key) {
		return $this->offsetGet($key);
	}
	
	public function resolve($key) {
		return $this->offsetGet($key);
	}
	
	public function register($key, $newval) {
		$this->offsetSet($key, $newval);
	}
	
	public function count() {
		return count($this->keys);
	}
	
	public function toArray() {
		return get_object_vars($this);
	}
	
}
