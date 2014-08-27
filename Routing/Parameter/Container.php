<?php

namespace xpl\Routing\Parameter;

class Container implements \xpl\Common\Arrayable, \xpl\Common\Importable {
	
	protected $params = array();
	
	public function __construct(array $params = null) {
		if (isset($params)) {
			$this->import($params);
		}
	}
	
	public function set($name, $regex) {
		$this->params[$name] = $regex;
	}
	
	public function get($name) {
		if (isset($this->params[$name])) {
			return $this->params[$name];
		}
	}
	
	public function has($name) {
		return array_key_exists($name, $this->params);
	}
	
	public function remove($name) {
		unset($this->params[$name]);
	}
	
	public function toArray() {
		return $this->params;
	}
	
	public function import($data) {
		
		if (! is_array($data)) {
			$data = (array)$data;
		}
		
		foreach($data as $key => $value) {
			$this->set($key, $value);
		}
	}
	
}
