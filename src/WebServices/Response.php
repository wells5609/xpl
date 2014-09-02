<?php

namespace xpl\WebServices;

class Response {
	
	protected $raw_data;
	protected $decoded_data;
	
	public function __construct($data) {
		if (is_string($data)) {
			$this->raw_data = $data;
		} else {
			$this->decoded_data = $data;
		}
	}
	
	public function jsonDecode() {
		if (! isset($this->raw_data)) {
			throw new \RuntimeException("Data already decoded.");
		}
		$this->decoded_data = json_decode($this->raw_data);
		return $this;
	}
	
	public function xmlDecode() {
		if (! isset($this->raw_data)) {
			throw new \RuntimeException("Data already decoded.");
		}
		$this->decoded_data = json_decode(json_encode(simplexml_load_string($this->raw_data)));
		return $this;
	}
	
	public function serialPhpDecode() {
		if (! isset($this->raw_data)) {
			throw new \RuntimeException("Data already decoded.");
		}
		$this->decoded_data = unserialize($this->raw_data);
		return $this;
	}
	
	public function getDecoded() {
		return $this->decoded_data;
	}
	
	public function getRaw() {
		return $this->raw_data;
	}
	
	public function getData() {
		return isset($this->decoded_data) ? $this->decoded_data : $this->raw_data;
	}
	
	/**
	 * Returns the raw response content as a string.
	 * 
	 * @return string
	 */
	public function __toString() {
		
		if (isset($this->raw_data)) {
			return (string) $this->raw_data;
		
		} else if (isset($this->decoded_data) && method_exists($this->decoded_data, '__toString')) {
			return (string) $this->decoded_data;
		}
		
		return '';
	}
	
}
