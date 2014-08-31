<?php

namespace xpl\Web;

use xpl\Foundation\Application as BaseApp;
use xpl\Foundation\RoutableInterface;
use xpl\Foundation\RouteInterface;

class Application extends BaseApp implements RoutableInterface {
	
	/**
	 * Returns the route resource for routing.
	 * 
	 * @return \xpl\Routing\Resource
	 */
	public function getResource($name = null) {
		
		$key = 'resource'.(isset($name) ? ".{$name}" : '');
		
		if (isset($this->registry[$key])) {
			return $this->registry[$key];
		}
		
		$class = $this->getNamespace().'\\Resource'.(isset($name) ? '\\'.ucfirst($name) : '');
		
		if (class_exists($class, true)) {
			
			$definition = new $class();
			
			return $this->registry[$key] = $definition->createResource();
		}
		
		throw new \RuntimeException("Resource definition class does not exist: '$class'.");
	}
	
	public function onRoute(RouteInterface $route, Request $request) {
	}
	
}
