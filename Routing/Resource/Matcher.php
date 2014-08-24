<?php

namespace xpl\Routing\Resource;

class Matcher {
	
	protected $resources;
	protected $match;
	
	public function __construct() {
		$this->resources = array();
	}
	
	public function addResource(Resource $resource, $prepend = false) {
		
		if ($prepend) {
			array_unshift($this->resources, $resource);
		} else {
			array_push($this->resources, $resource);
		}
		
		return $this;
	}
	
	public function match($http_method, $uri) {
		
		foreach($this->resources as $resource) {
			
			if ($this->matchRoutes($resource->getRoutes())) {
				return $this->match;
			}
		}
		
		return null;
	}
	
	public function getMatch() {
		return isset($this->match) ? $this->match : null;
	}
	
	protected function matchRoutes(array $routes) {
			
		foreach($routes as $route) {
			
			if ($route->match($http_method, $uri)) {
				$this->match = $route;
				return true;
			}
		}
		
		return false;
	}
	
}
