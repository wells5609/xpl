<?php

namespace xpl\Routing\Resource;

use xpl\Routing\Parameter\Container;
use xpl\Routing\Resource;

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
	
	public function createResource() {
		
		$resource = new Resource(
			new Container($this->getParams()), 
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
		
		$resource->setController($this->getControllerClass());
		
		return $resource;
	}
	
}
