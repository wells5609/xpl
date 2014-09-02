<?php

namespace xpl\Routing\REST\Resource;

use xpl\Routing\REST\Resource as RestResource;

abstract class Definition extends \xpl\Routing\Resource\Definition {
	
	public function getDefaultMethods() {
		return array('GET', 'POST', 'HEAD', 'PUT', 'DELETE');
	}
	
	public function createResource() {
		
		$resource = new RestResource(
			$this->getParams(), 
			$this->getName(), 
			$this->getPathPrefix(), 
			$this->getOptions()
		);
		
		foreach($this->getRoutes() as $name => $arr) {
			
			$uri = $arr[0];
			
			$ucfirst_name = ucfirst($name);
			
			if (! isset($arr[1])) {
				
				// add a route for each default method	
				foreach($this->getDefaultMethods() as $method) {
					$name = strtolower($method).$ucfirst_name;
					$resource->add($name, $uri, array($method));
				}
			
			} else if (is_array($arr[1])) {
				
				// add a route for each given method
				foreach($arr[1] as $method) {
					$name = strtolower($method).$ucfirst_name;
					$resource->add($name, $uri, array($method));
				}
			
			} else {
				// add a route for the given method
				$name = strtolower($arr[1]).$ucfirst_name;
				$resource->add($name, $uri, array($arr[1]));
			}
		}
		
		$controllerClass = $this->getControllerClass();
		$resource->setController(new $controllerClass);
		
		return $resource;
	}
	
}
