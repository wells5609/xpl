<?php

namespace xpl\Common;

abstract class PropertyAwareObject extends Object {
	
	public function set($key, $value) {
			
		if (! property_exists($this, $key)) {
			throw new \InvalidArgumentException("Attempting to set invalid property: '$key'.");
		}
		
		$mutator = 'set'.ucfirst(strtolower($key));
		
		if (is_callable(array($this, $mutator))) {
			return $this->$mutator($value);
		} else {
			$this->$key = $value;
		}
		
		return $this;
	}
	
}
