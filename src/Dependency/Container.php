<?php

namespace xpl\Dependency;

use Closure;

class Container implements \ArrayAccess, \Countable, \xpl\Common\Arrayable {
	
	protected $keys = array();
	protected $values = array();
	protected $registered = array();
	protected $factories = array();
	protected $protected = array();
	
	/**
	 * Register a dependency.
	 * 
	 * Value can be:
	 * 	1) An object instance
	 *  2) A closure that returns the object
	 *  3) A classname 
	 * 
	 * @param string $key Dependency key.
	 * @param mixed $object
	 * @return $this
	 */
	public function register($key, $object) {
		
		if (isset($this->protected[$key])) {
			throw new Exception("Cannot overwrite protected item '$key'.");
		}
		
		if (is_object($object) && ! $object instanceof Closure) {
				
			if ($object instanceof ContainerAwareInterface) {
				$object->setContainer($this);
			}
			
			$this->values[$key] = $object;
		
		} else {
			$this->registered[$key] = new Dependency($object);
		}
		
		$this->keys[$key] = true;
		
		return $this;
	}
	
	/**
	 * Registers a factory closure.
	 * 
	 * @param string $key Dependency key.
	 * @param \Closure $call Factory closure.
	 * @return $this
	 */
	public function factory($key, Closure $call) {
		
		if (isset($this->protected[$key])) {
			throw new Exception("Cannot overwrite protected item '$key'.");
		}
		
		$this->keys[$key] = true;
		$this->factories[$key] = $call;
		
		return $this;
	}
	
	/**
	 * Sets an arbitrary value.
	 * 
	 * Object instances are stored as values.
	 * 
	 * Can also be used to store variables for use in DI (e.g. a classname).
	 * 
	 * @param string $key 
	 * @param mixed $value
	 * @return $this
	 */
	public function value($key, $value) {
		
		if (isset($this->protected[$key])) {
			throw new Exception("Cannot overwrite protected item '$key'.");
		}
		
		if ($value instanceof ContainerAwareInterface) {
			$value->setContainer($this);
		}
		
		$this->keys[$key] = true;
		$this->values[$key] = $value;
		
		return $this;
	}
	
	/**
	 * Resolves a dependency or value.
	 * 
	 * @param string $key
	 * @return mixed
	 */
	public function resolve($key) {
		
		if (isset($this->values[$key])) {
			// most calls go here
			return $this->values[$key];
		}
		
		if (isset($this->registered[$key])) {
			
			// Dependency::__invoke($this)
			$object = call_user_func($this->registered[$key], $this);
			
			if ($object instanceof Closure) {
				// Closures can return closures
				return $this->register($key, $object)->resolve($key);
			}
			
			if ($object instanceof ContainerAwareInterface) {
				$object->setContainer($this);
			}
			
			return $this->values[$key] = $object;
		}
		
		if (isset($this->factories[$key])) {
			return call_user_func($this->factories[$key], $this);
		}
		
		return null;
	}
	
	public function extend($key, Closure $call) {
		
		if (! isset($this->keys[$key])) {
			throw new Exception("No item '$key' found.");
		}
		
		$object = $this->resolve($key);
		
		if (! is_object($object)) {
			throw new Exception("Cannot extend non-object item: '$key'.");
		}
		
		$new_object = call_user_func($call, $object, $this);
		
		if (! is_object($new_object)) {
			throw new Exception("Must return object from extension for '$key', given: ".gettype($new_object));
		}
		
		$this->register($key, $new_object);
		
		return $this;
	}
	
	public function protect($key) {
			
		if (! isset($this->keys[$key])) {
			throw new Exception("No item '$key' found.");
		}
		
		$this->protected[$key] = true;
		
		return $this;
	}
	
	public function offsetGet($key) {
		return $this->resolve($key);
	}
	
	public function offsetSet($key, $newval) {
		if (is_object($newval)) {
			$this->register($key, $newval);
		} else {
			$this->value($key, $newval);
		}
	}
	
	public function offsetExists($key) {
		return isset($this->keys[$key]);
	}
	
	public function offsetUnset($key) {
		
		if (isset($this->protected[$key])) {
			throw new Exception("Cannot unset protected item '$key'.");
		}
		
		if (isset($this->keys[$key])) {
			unset($this->factories[$key], $this->registered[$key], $this->values[$key], $this->keys[$key]);
		}
	}
	
	public function count() {
		return count($this->keys);
	}
	
	public function toArray() {
		return $this->values;
	}
	
	public function get($key) {
		return $this->resolve($key);
	}
	
	public function __get($var) {
		return $this->resolve($var);
	}
	
}
