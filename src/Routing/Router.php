<?php

namespace xpl\Routing;

class Router {	
	
	protected $groups;
	protected $tried;
	protected $match;
	
	public function __construct() {
		$this->groups = array();
		$this->tried = array();
	}
	
	public function add(Group $group) {
		$this->groups[$group->getName()] = $group;
	}
	
	public function has($group) {
		
		if (is_string($group)) {
			return isset($this->groups[$group]);
		}
		
		return in_array($group, $this->groups, true);
	}
	
	public function get($group) {
		return isset($this->groups[$group]) ? $this->groups[$group] : null;
	}
	
	public function remove($group) {
		
		if (is_string($group)) {
			
			if ($the_group = $this->get($group)) {
				unset($this->groups[$group]);
				return $the_group;
			}
		
		} else if ($key = array_search($group, $this->groups, true)) {
			$the_group = $this->groups[$key];
			unset($this->groups[$key]);
			return $the_group;
		}
		
		return null;
	}
	
	public function getMatch() {
		return isset($this->match) ? $this->match : null;
	}
	
	public function __invoke($method, $uri) {
		
		$query = array();
		
		if (false !== $pos = strpos($uri, '?')) {
			$qstr = substr($uri, $pos+1);
			$uri = substr($uri, 0, $pos);
			parse_str($qstr, $query);
		}
		
		$uri = ltrim($uri, '/');
	
		foreach($this->groups as $group) {
			
			// Skip obvious non-matches
			if (! $group->isPrefixMatch($uri)) {
				continue;
			}
			
			// Match the routes in the group
			foreach($group->getRoutes() as $route) {
				
				if ($this->matchRoute($route, $uri, $method, $query)) {
					
					// Throw exception if HTTP method is not allowed
					if (! $route->hasMethod($method)) {
						$exception = new Exception\MethodNotAllowed("The '$method' HTTP method is not allowed.");
						$exception->setAllowedValues($route->getMethods());
						throw $exception;
					}
					
					// Create a new match instance
					$this->match = new Match($route, $uri, $method);
					
					return true;
				}
				
				// track tried routes
				$this->tried[] = $group->getName().':'.$route->getName();
			}
		}
		
		throw new Exception\NotFound("Could not find matching route for '$uri'");
	}
	
	protected function matchRoute(Route $route, $uri, $http_method, array $query = array()) {
		
		if ($route instanceof REST\Route && ! $route->hasMethod($http_method)) {
			return false;
		}
		
		// Match route with path vars
		if ($this->matchUri($route, $route->getCompiledUri(), $uri, $http_method)) {
			return true;
		}
		
		if ($route->getOption('fallback_to_query_params')) {
			
			// Match route using query params
			if ($this->matchUri($route, $route->getStrippedUri(), $uri, $http_method)) {
				
				// Check if the query params satisfy the route
				if ($route->isSatisfiedBy($query, $missing)) {
					
					$route->setParamsFrom($query);
					
					if ($route->isSatisfied($missing)) {
						return true;
					}
				}
				
				throw new Exception\MissingParameter("Missing route parameter: '$missing'.");
			}
		}
		
		return false;
	}
	
	protected function matchUri(Route $route, $route_uri, $uri, $http_method) {
		
		if (preg_match('#^/?'.$route_uri.'/?$#i', $uri, $params)) {
			
			unset($params[0]);
			
			if (! empty($params)) {
				$route->setParamValues($params);
			}
			
			return true;
		}
		
		return false;
	}
	
}
