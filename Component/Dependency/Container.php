<?php

namespace xpl\Component\Dependency;

class Container implements \ArrayAccess, \Countable {
	
	protected $keys = array();
	protected $values = array();
	protected $registered = array();
	protected $factories = array();
	protected $protected = array();
	
	public function register($key, $object) {
		
		if (isset($this->protected[$key])) {
			throw new \InvalidArgumentException("Cannot overwrite protected item '$key'.");
		}
		
		if (is_object($object) && ! $object instanceof \Closure) {
			$this->values[$key] = $object;
		} else {
			$this->registered[$key] = new Dependency($object);
		}
		
		$this->keys[$key] = true;
		
		return $this;
	}
	
	public function factory($key, \Closure $call) {
		
		if (isset($this->protected[$key])) {
			throw new \InvalidArgumentException("Cannot overwrite protected item '$key'.");
		}
		
		$this->keys[$key] = true;
		$this->factories[$key] = $call;
		
		return $this;
	}
	
	public function value($key, $value) {
		
		if (isset($this->protected[$key])) {
			throw new \InvalidArgumentException("Cannot overwrite protected item '$key'.");
		}
		
		$this->values[$key] = $value;
		
		return $this;
	}
	
	public function resolve($key) {
		
		if (isset($this->values[$key])) {
			return $this->values[$key];
		}
		
		if (isset($this->registered[$key])) {
			
			$object = $this->registered[$key]($this);
			
			if ($object instanceof \Closure) {
				return $this->register($key, $object)->resolve($key);
			}
			
			return $this->values[$key] = $object;
		}
		
		if (isset($this->factories[$key])) {
			return call_user_func($this->factories[$key], $this);
		}
		
		throw new \InvalidArgumentException("No item '$key' found.");
	}
	
	public function protect($key) {
			
		if (! isset($this->keys[$key])) {
			throw new \InvalidArgumentException("No item '$key' found.");
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
			throw new \InvalidArgumentException("Cannot unset protected item '$key'.");
		}
		
		if (isset($this->keys[$key])) {
			unset($this->factories[$key], $this->registered[$key], $this->values[$key], $this->keys[$key]);
		}
	}
	
	public function count() {
		return count($this->keys);
	}
	
	public function get($key) {
		return $this->resolve($key);
	}
	
	public function __get($var) {
		return $this->resolve($var);
	}
	
}
