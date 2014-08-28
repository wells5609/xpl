<?php

namespace xpl\Common\Storage;

/**
 * Config is a Container that allows setting a parent 
 * (i.e. the object for which it holds config values)
 */
class Config extends Container {
	
	protected $parent;
	
	public function setParent($object) {
		$this->parent = $object;
		return $this;
	}
	
	public function getParent() {
		return isset($this->parent) ? $this->parent : null;
	}

}
