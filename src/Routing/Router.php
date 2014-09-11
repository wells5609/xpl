<?php

namespace xpl\Routing;

/**
 * Router maps a request method and URI to a route.
 */
class Router
{
	protected $resources;
	protected $match;
	
	/**
	 * Adds a resource to the router.
	 * 
	 * @param \xpl\Routing\Resource $resource
	 */
	public function add(Resource $resource) {
		$this->resources[$resource->getName()] = $resource;
	}
	
	/**
	 * Gets an added resource by name.
	 * 
	 * @param string $resource
	 * @return \xpl\Routing\Resource|null
	 */
	public function get($resource) {
		return isset($this->resources[$resource]) ? $this->resources[$resource] : null;
	}
	
	/**
	 * Returns an array of all added resources.
	 * 
	 * @return array
	 */
	public function getAll() {
		return $this->resources;
	}
	
	/**
	 * Checks whether the router has the given resource.
	 * 
	 * Resource can be given by name or as an object.
	 * 
	 * @param string|\xpl\Routing\Resource $resource
	 * 
	 * @return boolean
	 */
	public function has($resource) {
		
		if (isset($this->resources[$resource])) {
			return true;
		}
		
		if (isset($this->resources)) {
			return in_array($resource, $this->resources, true);
		}
		
		return false;
	}
	
	/**
	 * Removes a resource from the router.
	 * 
	 * Resource can be given by name or as an object.
	 * 
	 * @param string|\xpl\Routing\Resource $resource
	 */
	public function remove($resource) {
		
		if (isset($this->resources[$resource])) {
			unset($this->resources[$resource]);
		
		} else if ($key = array_search($resource, $this->resources, true)) {
			unset($this->resources[$key]);
		}
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
		
		foreach($this->resources as $name => $resource) {
		
			if ($this->matchResource($resource, $method, $uri)) {
				return true;
			}
		}
		
		return false;
	}
	
	/** Alias of __invoke() */
	public function match($method, $uri) {
		return $this($method, $uri);
	}
	
	/**
	 * Returns the matched route, if any.
	 * 
	 * @return \xpl\Routing\Route|null
	 */
	public function getMatchedRoute() {
		
		if (empty($this->match)) {
			return null;
		}
		
		return $this->resources[$this->match['resource']]->getRoute($this->match['route']);
	}
	
	/**
	 * Returns the resource containing the matched route, if any.
	 * 
	 * @return \xpl\Routing\Resource|null
	 */
	public function getMatchedResource() {
		
		if (empty($this->match)) {
			return null;
		}
		
		return $this->resources[$this->match['resource']];
	}
	
	/**
	 * Attempts to match a resource's routes to a request method and URI.
	 * 
	 * @param \xpl\Routing\Resource $resource
	 * @param string $method
	 * @param string $uri
	 * 
	 * @return boolean True if a match was found, otherwise false.
	 */
	protected function matchResource(Resource $resource, $method, $uri) {
		
		foreach($resource->getRoutes() as $route) {
		
			if ($this->matchRoute($route, $method, $uri)) {
		
				$this->match = array(
					'resource' => $resource->getName(), 
					'route' => $route->getID()
				);
		
				return true;
			}
		}
		
		return false;
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
		
		if ($route->getMethod() !== $method) {
			return false;
		}
		
		if (preg_match('#^/?'.$route->getCompiledUri().'/?$#i', $uri, $params)) {
			
			unset($params[0]);
			
			if (! empty($params)) {
				$route->setParams($params);
			}
			
			return true;
		}
		
		return false;
	}
	
}
