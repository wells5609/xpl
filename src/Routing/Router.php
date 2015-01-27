<?php

namespace xpl\Routing;

/**
 * Router maps a request to a route.
 */
class Router
{
	
	/**
	 * The collection of routes.
	 * 
	 * @var \xpl\Routing\Route\Collection
	 */
	protected $collection;
	
	/**
	 * The matched route.
	 * 
	 * @var \xpl\Routing\Route
	 */
	protected $match;
	
	/**
	 * Construct the router with a route collection.
	 * 
	 * @param \xpl\Routing\Route\Collection $collection
	 */
	public function __construct(Route\Collection $collection) {
		$this->collection = $collection;
	}
	
	/**
	 * Matches the given method and URI to a resource route.
	 * 
	 * @param string $method Request HTTP method.
	 * @param string $uri Request URI.
	 * 
	 * @return boolean True if a match was found, otherwise false.
	 */
	public function __invoke($method, $uri) {
		
		$method = strtoupper($method);
		$uri = trim($uri, '/');
		
		foreach($this->collection as $route) {
			
			if ($this->matchRoute($route, $method, $uri)) {
				
				$this->match = $route;
				
				return true;
			}
		}
		
		return false;
	}
	
	/**
	 * Returns the route collection.
	 * 
	 * @return \xpl\Routing\Route\Collection
	 */
	public function getCollection() {
		return $this->collection;
	}
	
	/**
	 * Returns the matched route, if any.
	 * 
	 * @return \xpl\Routing\Route|null
	 */
	public function getMatch() {
		return isset($this->match) ? $this->match : null;
	}
	
	/**
	 * Attempts to match a route to a request method and URI.
	 * 
	 * If matched, sets the route's parameters from the regex matches.
	 * 
	 * @param \xpl\Routing\Route $route
	 * @param string $method
	 * @param string $uri
	 * 
	 * @return boolean True if the route matched, otherwise false.
	 */
	protected function matchRoute(Route $route, $method, $uri) {
		
		if (! $route->isCompiled()) {
			$this->collection->getCompiler()->compile($route);
		}
		
		if ($route->getMethod() === $method) {
		
			if (preg_match('#^/?'.$route->getCompiledUri().'/?$#i', $uri, $params)) {
				
				unset($params[0]);
				
				if (! empty($params)) {
					$route->setParams($params);
				}
				
				return true;
			}
		}
		
		return false;
	}
	
}
