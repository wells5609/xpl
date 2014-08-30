<?php

namespace xpl\Common;

abstract class PropertyAwareObject extends Object {
	
	public function set($key, $value) {
			
		if (! property_exists($this, $key)) {
			throw new \InvalidArgumentException("Attempting to set invalid property: '$key'.");
		}
		
		$this->$key = $value;
		
		return $this;
	}
	
}
