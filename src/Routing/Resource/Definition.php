<?php

namespace xpl\Routing\Resource;

use xpl\Cache\Cache;
use xpl\Routing\Resource;
use xpl\Routing\Route;
use xpl\Routing\Route\Tokens;

abstract class Definition {
	
	abstract public function getName();
	
	abstract public function getControllerClass();
	
	abstract public function getRoutes();
	
	public function getDomain() {
		return null;
	}
	
	public function getParams() {
		return array();
	}
	
	public function getOptions() {
		return array();
	}
	
	public function getPathPrefix() {
		return '/';
	}
	
	public function create() {
		
		$resource = new Resource($this->getName(), $this->getPathPrefix());
		
		$resource->setTokens($tokens = new Tokens());
		
		foreach($this->getParams() as $token => $regex) {
			$tokens->add($token, $regex);
		}
		
		foreach($this->getRoutes() as $name => $arr) {
			
			$uri = $arr[0];
			$method = isset($arr[1]) ? $arr[1] : 'GET';
			$action = isset($arr[2]) ? $arr[2] : null;
			
			$resource->addRoute(new Route($name, $method, $uri, $action));
		}
		
		$resource->setOption('controller', $this->getControllerClass());
		
		if ($domain = $this->getDomain()) {
			$resource->setOption('domain', $domain);
		}
		
		return $resource;
	}
	
	public function getCached(Cache $cache) {
		if ($resource = $cache->get('route_resource_'.$this->getName())) {
			return unserialize($resource);
		}
	}
	
	public function cache(Cache $cache, Resource $resource) {
		$cache->set('route_resource_'.$this->getName(), serialize($resource));
	}
	
}
