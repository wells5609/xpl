<?php

namespace xpl\Common;

use xpl\Common\Structure\MapInterface;

class Object extends \ArrayObject implements \JsonSerializable, MapInterface {
	
	public function __construct($data = null) {
		parent::__construct($data);
	#	if (isset($data)) {
	#		$this->import($data);
	#	}
	}
	
	public function set($key, $value) {
		
		#$mutator = 'set'.ucfirst(strtolower($key));
		
		#if (is_callable(array($this, $mutator))) {
		#	$this->$mutator($value);
		#} else {
		#	$this->$key = $value;
		#}
		$this->offsetSet($key, $value);
		return $this;
	}
	
	public function get($key) {
		return $this->offsetGet($key);
		#$accessor = 'get'.ucfirst(strtolower($key));
		
		#if (is_callable(array($this, $accessor))) {
		#	return $this->$accessor();
		#}
		
		return isset($this->$key) ? $this->$key : null;
	}
	
	public function has($key) {
		return $this->offsetExists($key);
		#$accessor = 'has'.ucfirst(strtolower($key));
		
		#if (is_callable(array($this, $accessor))) {
		#	return $this->$accessor();
		#}
		
		return isset($this->$key);
	}
	
	public function remove($key) {
		$this->offsetUnset($key);
		#$remover = 'remove'.ucfirst(strtolower($key));
		
		#if (is_callable(array($this, $remover))) {
		#	$this->$remover();
		#} else {
		#	unset($this->$key);
		#}
		
		return $this;
	}
	
	public function isEmpty() {
		return count($this) != 0;
	}
	
	public function contains($value) {
		return in_array($value, $this->toArray(), true);
	}
	
	/**
	 * Implements xpl\Common\Structure\MapInterface
	 */
	public function indexOf($value) {
		return array_search($value, $this->toArray(), true);
	}
	
	/**
	 * Implements \Arrayable
	 */
	public function toArray() {
		return get_object_vars($this);
	}
	
	/**
	 * Implements \Importable
	 */
	public function import($data) {
		
		if (! is_array($data)) {
			$data = ($data instanceof Arrayable) ? $data->toArray() : (array)$data;
		}
		
		foreach($data as $key => $value) {
			$this->set($key, $value);
		}
		
		return $this;
	}
	
	/**
	 * @param string|int $var
	 * @return mixed
	 */
	public function __get($var) {
		return $this->offsetGet($var);
	}

	/**
	 * @param string|int $var
	 * @param mixed $val
	 * @return void
	 */
	public function __set($var, $val) {
		$this->offsetSet($var, $val);
	}

	/**
	 * @param string|int $var
	 * @return boolean
	 */
	public function __isset($var) {
		return $this->offsetExists($var);
	}

	/**
	 * @param string|int $var
	 * @return void
	 */
	public function __unset($var) {
		$this->offsetUnset($var);
	}
	
	/**
	 * Serializes properties as an associative array.
	 *
	 * @return string
	 */
	public function serialize() {
		return serialize($this->toArray());
	}

	/**
	 * Unserializes and adds properties.
	 *
	 * @param string $serialized
	 * @return void
	 */
	public function unserialize($serialized) {
		$this->import(unserialize($serialized));
	}
	
	/**
	 * Implements \JsonSerializable
	 */
	public function jsonSerialize() {
		return $this->toArray();
	}
	
}
