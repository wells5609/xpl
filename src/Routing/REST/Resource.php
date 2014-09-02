<?php

namespace xpl\Routing\REST;

use xpl\Routing\Route;
use xpl\Routing\REST\Route as RestRoute;

class Resource extends \xpl\Routing\Resource {
	
	public function set(Route $route) {
		$this->routes[$route->getName()] = $route;
	}
	
	public function add($name, $uri, array $methods, $action = null, array $options = array()) {
		
		$uri = $this->prefix.ltrim($uri, '/');
		
		if (! empty($this->options)) {
			$options = array_merge($this->options, $options);
		}
		
		$this->set(new RestRoute($this, $name, $uri, $methods[0], $options));
	}
	
}
