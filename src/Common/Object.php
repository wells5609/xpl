<?php

namespace xpl\Common;

use xpl\Common\Structure\MapInterface;

class Object extends \ArrayObject implements \JsonSerializable, MapInterface {
	
	public function __construct($data = array()) {
		parent::__construct($data);
	}
	
	public function offsetGet($key) {
		return parent::offsetExists($key) ? parent::offsetGet($key) : null;
	}
	
	public function set($key, $value) {
		$this->offsetSet($key, $value);
		return $this;
	}
	
	public function get($key) {
		return $this->offsetGet($key);
	}
	
	public function has($key) {
		return $this->offsetExists($key);
	}
	
	public function remove($key) {
		$this->offsetUnset($key);
		return $this;
	}
	
	public function isEmpty() {
		return 0 == count($this);
	}
	
	public function contains($value) {
		return in_array($value, $this->toArray(), true);
	}
	
	public function keys() {
		return array_keys($this->toArray());
	}
	
	public function values() {
		return array_values($this->toArray());
	}
	
	/**
	 * Implements xpl\Common\Structure\MapInterface
	 */
	public function indexOf($value) {
		return array_search($value, $this->toArray(), true);
	}
	
	/**
	 * Implements \xpl\Common\Arrayable
	 */
	public function toArray() {
		return iterator_to_array($this);
	}
	
	/**
	 * Implements \xpl\Common\Importable
	 */
	public function import($data) {
		
		if (! is_array($data)) {
			$data = is_callable(array($data, 'toArray')) ? $data->toArray() : (array)$data;
		}
		
		foreach($data as $key => $value) {
			$this->offsetSet($key, $value);
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
