<?php

namespace xpl\Routing\Rest;

class Resource {
	
	const CLASSNAME = 'RestController';
	
	protected $namespace;
	
	public function __construct($namespace) {
		$this->namespace = trim($namespace, '\\');
	}
	
	public function match($http_method, $uri) {
		
		$uri = trim($uri, '/');
		
		$parts = explode('/', $uri);
		
		$path = array_shift($parts);
		
		$method = strtolower($http_method).ucfirst($path);
		
		
	}
	
}
