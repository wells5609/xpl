<?php

namespace xpl\Http\Response;

class BodyStream implements BodyInterface {
	
	protected $stream;
	
	public function __construct($value = null) {
		if (isset($value)) {
			$this->set($value);
		}
	}
	
	public function get() {
		return $this->stream;
	}
	
	public function set($value) {
		
		if (! is_callable($value)) {
			throw new \InvalidArgumentException("Streaming body must be callable.");
		}
		
		$this->stream = $value;
		
		return $this;
	}
	
	public function toArray() {
		
		if (empty($this->stream)) {
			return array();
		}
		
		if (is_object($this->stream)) {
				
			if (is_callable(array($this->stream, 'toArray'))) {
				return $this->stream->toArray();
			}
		}
	
		$data = call_user_func($this->stream);
		
		return $this->data2array($data);
	}
	
	public function __toString() {
		
		if (empty($this->stream)) {
			return '';
		}
		
		if (is_object($this->stream) && is_callable(array($this->stream, '__toString'))) {
			return (string) $this->stream;
		}
		
		$data = call_user_func($this->stream);
		
		if (is_scalar($data) || method_exists($data, '__toString')) {
			return (string) $data;
		}
	
		return '';
	}
	
	protected function data2array($data) {
			
		if (is_array($data)) {
			return $data;
		}
		
		if (is_object($data)) {
				
			if (is_callable(array($data, 'toArray'))) {
				return $data->toArray();
		
			} else if ($data instanceof \Traversable) {
				return iterator_to_array($data, true);
			}
		}
		
		return (array) $data;
	}
	
	public function __invoke($arg = null) {
		return call_user_func($this->stream, $arg);
	}
	
}
