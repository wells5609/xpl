<?php

namespace xpl\Common\Storage;

use xpl\Common\Structure\Map;
use xpl\Utility\Arr;

/**
 * Container is a Map that uses dot-notation for keys.
 * 
 * e.g. "some.item.key" corresponds to:
 * 	'some' => array('item' => array('key' => {VALUE}));
 */
class Container extends Map {
	
	public function get($key) {
		return Arr::get($this->_data, $key);
	}
	
	public function set($key, $value) {
		Arr::set($this->_data, $key, $value);
		return $this;
	}
	
	public function has($key) {
		return Arr::exists($this->_data, $key);
	}
	
	public function remove($key) {
		Arr::remove($this->_data, $key);
		return $this;
	}
	
}
