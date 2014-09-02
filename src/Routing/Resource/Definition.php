<?php

namespace xpl\Routing\Resource;

use xpl\Routing\Resource;
use xpl\Cache\Cache;

abstract class Definition {
	
	abstract public function getName();
	
	abstract public function getControllerClass();
	
	abstract protected function getRoutes();
	
	protected function getParams() {
		return array();
	}
	
	protected function getOptions() {
		return array();
	}
	
	protected function getPathPrefix() {
		return '/';
	}
	
	public function createResource(Cache $cache = null) {
		
		if (isset($cache) && $resource = $cache->get($this->getName(), 'resources')) {
			return unserialize($resource);
		}
		
		$resource = new Resource(
			$this->getParams(), 
			$this->getName(), 
			$this->getPathPrefix(), 
			$this->getOptions()
		);
		
		foreach($this->getRoutes() as $name => $arr) {
			
			$uri = $arr[0];
			$methods = isset($arr[1]) ? (array) $arr[1] : array('GET','HEAD','POST');
			$action = isset($arr[2]) ? $arr[2] : $name;
			
			$resource->add($name, $uri, $methods, $action);
		}
		
		$controllerClass = $this->getControllerClass();
		
		$resource->setController(new $controllerClass);
		
		if (isset($cache)) {
			$cache->set($this->getName(), serialize($resource), 'resources');
		}
		
		return $resource;
	}
	
}
