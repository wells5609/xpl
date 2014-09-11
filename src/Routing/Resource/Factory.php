<?php

namespace xpl\Routing\Resource;

use xpl\Cache\Cache;
use xpl\Routing\Resource;
use xpl\Routing\Route;
use xpl\Routing\Route\Tokens;

class Factory 
{
	
	/**
	 * Creates a new resource from a resource definition instance.
	 * 
	 * @param \xpl\Routing\Resource\Definition
	 */	
	public function fromDefinition(Definition $definition) {
		
		$resource = new Resource($definition->getName(), $definition->getPathPrefix());
		
		$resource->setTokens($tokens = new Tokens());
		
		foreach($definition->getParams() as $token => $regex) {
			$tokens->add($token, $regex);
		}
		
		foreach($definition->getRoutes() as $name => $arr) {
			
			$uri = $arr[0];
			$method = isset($arr[1]) ? $arr[1] : 'GET';
			$action = isset($arr[2]) ? $arr[2] : null;
			
			$resource->addRoute(new Route($name, $method, $uri, $action));
		}
		
		if ($controller = $definition->getControllerClass()) {
			$resource->setOption('controller', $controller);
		}
		
		if ($domain = $definition->getDomain()) {
			$resource->setOption('domain', $domain);
		}
		
		return $resource;
	}
	
	/**
	 * Attempts to fetch a resource from the cache.
	 * 
	 * @param \xpl\Cache\Cache $cache
	 * @param string $resource_name
	 * 
	 * @return \xpl\Routing\Resource|null
	 */
	public function fromCache(Cache $cache, $resource_name) {
		
		if ($resource = $cache->get('route_resource_'.$resource_name)) {
			return unserialize($resource);
		}
		
		return null;
	}
	
	/**
	 * Caches a resource.
	 * 
	 * @param \xpl\Cache\Cache $cache
	 * @param \xpl\Routing\Resource $resource
	 */
	public function cache(Cache $cache, Resource $resource) {
		
		$cache->set('route_resource_'.$resource->getName(), serialize($resource));
	}
	
}