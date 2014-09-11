<?php

namespace xpl\Routing\Route;

use xpl\Routing\Route;
use xpl\Routing\Resource;

class Generator 
{
	protected $resource;
	
	public function __construct(Resource $resource) {
		$this->resource = $resource;
	}
	
	public function get($name, $uri, $action = null) {
		$this->resource->addRoute(new Route($name, 'GET', $uri, $action));
	}
	
	public function post($name, $uri, $action = null) {
		$this->resource->addRoute(new Route($name, 'POST', $uri, $action));
	}
	
	public function head($name, $uri, $action = null) {
		$this->resource->addRoute(new Route($name, 'HEAD', $uri, $action));
	}
	
	public function put($name, $uri, $action = null) {
		$this->resource->addRoute(new Route($name, 'PUT', $uri, $action));
	}
	
	public function delete($name, $uri, $action = null) {
		$this->resource->addRoute(new Route($name, 'DELETE', $uri, $action));
	}
	
	public function options($name, $uri, $action = null) {
		$this->resource->addRoute(new Route($name, 'OPTIONS', $uri, $action));
	}
	
	public function patch($name, $uri, $action = null) {
		$this->resource->addRoute(new Route($name, 'PATCH', $uri, $action));
	}
}
