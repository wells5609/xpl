<?php

namespace xpl\Input;

/**
 * Base class for a global input variable.
 */
class Input implements \ArrayAccess, \Countable, \IteratorAggregate
{
	
	protected $data;
	protected $options;
	
	public function __construct(array $source, array $options = array()) {
		$this->data = $source;
		$this->options = $options;
	}
	
	public function get($key, $default = null) {
		
		if (isset($this->data[$key])) {
			return $this->data[$key];
		}
		
		return $default;
	}
	
	public function set($key, $value) {
		$this->data[$key] = $value;
	}
	
	public function has($key) {
		return isset($this->data[$key]);
	}
	
	public function offsetGet($index) {
		return $this->get($index);
	}
	
	public function offsetSet($index, $newval) {
		$this->set($index, $newval);
	}
	
	public function offsetExists($index) {
		return $this->has($index);
	}
	
	public function offsetUnset($index) {
		// do nothing
	}
	
	public function count() {
		return count($this->data);
	}
	
	public function getIterator() {
		return new \ArrayIterator($this->data);
	}
	
	public function getOptions() {
		return $this->options;
	}
	
	public function getOption($name, $default = null) {
		return isset($this->options[$name]) ? $this->options[$name] : $default;
	}
	
	public function setOption($name, $value) {
		$this->options[$name] = $value;
	}
	
}
