<?php

namespace xpl\Common\Storage;

use xpl\Common\Structure\Map;

class Bin extends Map {
	
	const MODE_NORMAL = 0;
	const MODE_DOT_NOTATION = 1;
	
	private $_mode = 1;
	
	public function setMode($mode) {
		
		if (! in_array($mode, $this->getModes(), true)) {
			throw new \InvalidArgumentException("Invalid mode: '$mode'.");
		}
		
		$this->_mode = $mode;
	}
	
	public function getMode() {
		return $this->_mode;
	}
	
	public function getModes() {
		return array(static::MODE_DOT_NOTATION, static::MODE_NORMAL);
	}
	
	public function get($key) {
		
		if ($this->_mode === static::MODE_DOT_NOTATION) {
			return Arr::get($this->_data, $key);
		}
		
		return isset($this->_data[$key]) ? $this->_data[$key] : null;
	}
	
	public function set($key, $value) {
		
		if ($this->_mode === static::MODE_DOT_NOTATION) {
			Arr::set($this->_data, $key, $value);
		} else {
			$this->_data[$key] = $value;
		}
		
		return $this;
	}
	
	public function has($key) {
		
		if ($this->_mode === static::MODE_DOT_NOTATION) {
			return Arr::exists($this->_data, $key);
		}
		
		return isset($this->_data[$key]);
	}
	
	public function remove($key) {
			
		if ($this->_mode === static::MODE_DOT_NOTATION) {
			Arr::remove($this->_data, $key);
		} else {
			unset($this->_data[$key]);
		}
		
		return $this;
	}
	
}
