<?php

namespace xpl\Common\Structure;

class Map extends Base implements MapInterface {
	
	public function __construct($data = null) {
		isset($data) and $this->import($data);
	}
	
	public function get($key) {
		return isset($this->_data[$key]) ? $this->_data[$key] : null;
	}
	
	public function set($key, $value) {
		$this->_data[$key] = $value;
		return $this;
	}
	
	public function has($key) {
		return isset($this->_data[$key]);
	}
	
	public function remove($key) {
		unset($this->_data[$key]);
		return $this;
	}
	
	/**
	 * Implements \xpl\Commmon\Importable
	 */
	public function import($data) {
		if (! is_array($data)) {
			$data = is_callable(array($data, 'toArray')) ? $data->toArray() : (array)$data;
		}
		foreach($data as $key => $value) {
			$this->set($key, $value);
		}
		return $this;
	}
	
	/**
	 * Implements \ArrayAccess
	 */
	
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
		$this->remove($index);
	}
	
}
