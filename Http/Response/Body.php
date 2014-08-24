<?php

namespace xpl\Http\Response;

class Body implements BodyInterface {
	
	protected $data;
	
	public function get() {
		return $this->data;
	}
	
	public function set($data) {
		$this->data = $data;
		return $this;
	}
	
	public function toArray() {
		
		if (empty($this->data)) {
			return array();
		
		} else if (is_array($this->data)) {
			return $this->data;
		
		} else if (is_callable(array($this->data, 'toArray'))) {
			return $this->data->toArray();
		
		} else if ($this->data instanceof \Traversable) {
			return iterator_to_array($this->data, true);
		}
		
		return (array) $this->data;
	}
	
	public function __toString() {
		
		if (! isset($this->data)) {
			return '';
		}
		
		if (is_scalar($this->data) || is_callable(array($this->data, '__toString'))) {
			return (string) $this->data;
		}
		
		return '';
	}
	
}
