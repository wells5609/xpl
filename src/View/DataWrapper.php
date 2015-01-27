<?php

namespace xpl\View;

abstract class DataWrapper implements \ArrayAccess 
{
	protected $data;
	
	public function setData(array $data) {
		$this->data = $data;
		return $this;
	}
	
	public function getData() {
		return isset($this->data) ? $this->data : null;
	}
	
	public function set($var, $val) {
		$this->data->set($var, $val);
		return $this;
	}
	
	public function get($var) {
		return $this->data->get($var);
	}
	
	public function has($var) {
		return $this->data->has($var);
	}
	
	public function remove($var) {
		$this->data->remove($var);
		return $this;
	}
	
	public function __set($var, $val) {
		$this->data->set($var, $val);
	}
	
	public function __get($var) {
		return $this->data->get($var);
	}
	
	public function __isset($var) {
		return $this->data->has($var);
	}
	
	public function __unset($var) {
		$this->data->remove($var);
	}
	
	public function offsetSet($var, $newval) {
		$this->data->set($var, $newval);
	}
	
	public function offsetGet($var) {
		return $this->data->get($var);
	}
	
	public function offsetExists($var) {
		return $this->data->has($var);
	}
	
	public function offsetUnset($var) {
		$this->data->remove($var);
	}
	
}
