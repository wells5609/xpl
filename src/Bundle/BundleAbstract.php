<?php

namespace xpl\Bundle;

abstract class BundleAbstract implements BundleInterface {
	
	protected $name;
	protected $namespace;
	protected $dirpath;
	
	abstract public function boot();
	
	abstract public function shutdown();
	
	abstract public function isBooted();
	
	abstract public function getType();
	
	public function getOverrides() {
		return array();
	}
	
	public function getDependencies() {
		return array();
	}
	
	public function getName() {
		
		if (null === $this->name) {
			
			$class = strtolower(get_class($this));
			
			if (false !== $pos = strrpos($class, '\\')) {
				$name = substr($class, $pos+1);
			} else {
				$name = $class;
			}
			
			$this->name = str_replace(array('bundle', $this->getType()), '', $name);
		}
		
		return $this->name;
	}
	
	public function getNamespace() {
			
		if (null === $this->namespace) {
			$class = get_class($this);
			$this->namespace = substr($class, 0, strrpos($class, '\\'));
		}
		
		return $this->namespace;
	}
	
	public function getDirpath() {
			
		if (null === $this->dirpath) {
			$refl = new \ReflectionObject($this);
			$this->dirpath = str_replace('\\', '/', dirname($refl->getFileName())).'/';
		}
		
		return $this->dirpath;
	}
	
	public function getIdentifier() {
		return $this->getType().'.'.$this->getName();
	}
	
}
