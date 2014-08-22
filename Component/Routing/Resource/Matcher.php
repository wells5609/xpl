<?php

namespace xpl\Component\Routing\Resource;

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
			
			foreach($resource->getRoutes() as $route) {
				
				if ($route->match($http_method, $uri)) {
					
					return $this->match = $route;
				}
			}
		}
		
		return null;
	}
	
	public function getMatchedRoute() {
		return isset($this->match) ? $this->match : null;
	}
	
}
