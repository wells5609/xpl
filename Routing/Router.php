<?php

namespace xpl\Routing;

use Closure;

/**
 * Routes a request to a callback.
 */
class Router implements MatcherInterface
{
	/**
	 * Matched route object.
	 * @var \xpl\Component\Routing\Route
	 */
	protected $route;
	
	/**
	 * Fluent interface for adding routes.
	 * @var \xpl\Component\Routing\Fluent
	 */
	protected $fluentInterface;
	
	/**
	 * Route objects.
	 * @var array
	 */
	protected $routes = array();
	
	/**
	 * Endpoint closures.
	 * @var array
	 */
	protected $endpoints = array();

	/**
	 * Path of endpoint being currently executed.
	 * @var string
	 */
	protected $endpointPath;
	
	/**
	 * Default controller class for endpoint currently being executed.
	 * @var string
	 */
	protected $endpointControllerClass;
	
	/**
	 * Default allowed HTTP methods for endpoint currently being executed.
	 * @var string
	 */
	protected $endpointDefaultMethods;
	
	/**
	 * Route query variables.
	 * @var array
	 */
	protected $vars = array(
		'segment'	=> '([^_/][^/]+)', 
		'words'		=> '(\w\-+)', 
		'integer'	=> '(\d+)',
		'float'		=> '(\d?\.\d+)',
		'number'	=> '(\d?\.?\d+)', 
		'any'		=> '(.+?)', 
		'all'		=> '(.?.+?)', 
	);
	
	/**
	 * Matches a request URI and calls its method.
	 * 
	 * @param string $http_method HTTP method (e.g. GET, POST, etc.)
	 * @param string $uri Request URI path (without host or query string).
	 * @return \Route\Route Matched route
	 */
	public function match($http_method, $uri) {
		
		if ($this->matchEndpoints($uri, $http_method) || $this->matchRoutes($uri, $http_method)) {
			return $this->route;
		}
		
		throw new \HttpNotFoundException;
	}

	/**
	 * Adds query var and regex
	 *
	 * @param string $name The query var name.
	 * @param string $regex The var's regex.
	 * @return $this
	 */
	public function setVar($name, $regex) {
		$this->vars[$name] = $regex;
		return $this;
	}
	
	/**
	 * Adds array of query vars and regexes
	 * 
	 * @param array $vars Associative array of var name/regex pairs.
	 * @return $this
	 */
	public function setVars(array $vars) {
		foreach ($vars as $name => $regex) {
			$this->setVar($name, $regex);
		}
		return $this;
	}

	/**
	 * Returns array of query vars and regexes
	 * 
	 * @return array Associative array of query var names and regexes.
	 */
	public function getVars() {
		return $this->vars;
	}

	/**
	 * Returns regex for a query var name.
	 * 
	 * @param string $key Query var name.
	 * @return string Regex for var if set, otherwise empty string.
	 */
	public function getRegex($key) {
		return isset($this->vars[$key]) ? $this->vars[$key] : '';
	}

	/**
	 * Creates and adds a single route object.
	 * 
	 * @see \Phpf\Route\Route
	 * 
	 * @param string $uri URI path.
	 * @param array $args Route arguments passed to constructor.
	 * @param int $priority Route priority. Default 10.
	 * @return $this
	 */
	public function addRoute($uri, $action_callback, array $methods = null, $priority = 10) {
		
		$route_options = array();
		
		if (is_array($priority)) {
			$route_options = $priority;
			$priority = 10;
		}
		
		if (isset($this->defaultOptions)) {
			$route_options = array_merge($this->defaultOptions, $route_options);
		}
		
		$uri = ltrim($uri, '/');
		
		if (empty($methods)) {
			$methods = array('GET','HEAD','POST');
		}
		
		if ($this->endpointPath) {
			// We are currently running an endpoint closure!
			
			if (isset($this->endpointDefaultMethods) && $methods == array('GET','HEAD','POST')) {
				$methods = $this->endpointDefaultMethods;
			}
			
			$this->addEndpointRoute($this->endpointPath, $uri, array(
				'action' => $action_callback,
				'methods' => $methods,
				'options' => $route_options,
			));
			
		} else {
			
			$route = new Route($uri, $action_callback, $methods, $route_options);
			$route->setResource($this);
			
			$this->routes[$priority][$uri] = $route;
		}
		
		return $this;
	}
	
	public function setDefaultOptions(array $options) {
		$this->defaultOptions = $options;
		return $this;
	}
	
	public function resetDefaultOptions() {
		unset($this->defaultOptions);
		return $this;
	}
	
	/**
	 * Returns the fluent interface for adding routes.
	 * 
	 * @return \Route\Fluent Fluent interface instance.
	 */
	public function fluent() {
		if (! isset($this->fluentInterface)) {
			$this->fluentInterface = new Fluent($this);
		}
		return $this->fluentInterface;
	}

	/**
	 * Add a group of routes under an endpoint/namespace
	 * 
	 * @param string $path Endpoint path
	 * @param Closure $callback Closure that returns the routes
	 * @return $this
	 */
	public function endpoint($path, Closure $callback) {
		$this->endpoints[$path] = $callback;
		return $this;
	}
	
	/**
	 * Set the default HTTP methods to use for routes in the endpoint currently being executed.
	 * 
	 * @see matchEndpoints()
	 * 
	 * @param array $methods Indexed array of default HTTP methods.
	 * @return $this
	 */
	public function setDefaultMethods(array $methods) {
		$this->endpointDefaultMethods = $methods;
		return $this;
	}
	
	/**
	 * Set a controller class to use for routes in the endpoint currently being executed
	 * 
	 * @see matchEndpoints()
	 * 
	 * @param string $class Controller classname.
	 * @return $this
	 */
	public function setController($class) {
		$this->endpointControllerClass = $class;
		return $this;
	}
	
	/**
	 * Returns array of all route objects, their URI as the key.
	 * 
	 * Useful for caching routes along with the setRoutes() method,.
	 * 
	 * @return array Route objects.
	 */
	public function getRoutes() {
		static $didEndpoints;
		static $didParse;
		
		if (true === $didParse && (empty($this->endpoints) || true === $didEndpoints)) {
			return $this->routes;
		}
		
		// execute all unexecuted endpoints
		foreach($this->endpoints as $path => $closure) {
			if (! isset($this->routes[$path])) {
				$this->doEndpoint($path, $closure);
			}
		}
		$didEndpoints = true;
		
		// parse every route and add its (parsed) URI and vars as properties
		foreach($this->routes as &$group) {
			foreach($group as &$route) {
				// just make sure it gets parsed
				$route->getParsedUri();
			}
		}
		$didParse = true;
		
		return $this->routes;
	}
	
	/**
	 * Sets the router's routes, possibly from a cache.
	 * 
	 * @param array Routes
	 * @return $this
	 */
	public function setRoutes(array $routes) {
		$this->routes = $routes;
		return $this;
	}
	
	/**
	 * Returns the matched route, if any.
	 * 
	 * @return \Route\Route
	 */
	public function getMatchedRoute() {
		return isset($this->route) ? $this->route : null;
	}
	
	/**
	 * Creates and adds a single route object under a namespace.
	 * 
	 * @see \Route\Route
	 * 
	 * @param string $basepath Base endpoint path.
	 * @param string $path Route path.
	 * @param array $array Keys: "controller", "action", "methods".
	 * @return Route New endpoint Route object.
	 * @throws InvalidArgumentException if no 'action' or 'controller' items are 
	 * given and these items cannot be determined.
	 */
	protected function addEndpointRoute($basepath, $path, array $array) {
		
		// Try to set action from path if author is lazy
		if (! isset($array['action'])) {
			
			if (! ctype_alpha($slug = trim($path, '/'))) {
				throw new \InvalidArgumentException("Missing 'action' item for route with path '$path'.");
			}
			
			$array['action'] = $slug;
		}
		
		// Set defeault endpoint controller if not set
		if (empty($array['controller'])) {
				
			// Check if there is a default controller class
			if (! isset($this->endpointControllerClass)) {
				throw new \InvalidArgumentException("Missing 'controller' item for route with path '$path'.");
			}
			
			$array['controller'] = $this->endpointControllerClass;
		}
		
		// Callback in array format
		$callback = array($array['controller'], $array['action']);
		
		// Set default methods if not given or if set to router defaults
		if (isset($this->endpointDefaultMethods)) {
		
			if (empty($array['methods']) || $array['methods'] == array('GET','HEAD','POST')) {
				$array['methods'] = $this->endpointDefaultMethods;
			}
			
		} else if (empty($array['methods'])) {
			$array['methods'] = array('GET','HEAD','POST');
		}
		
		if (! isset($array['options'])) {
			$array['options'] = array();
		}

		$route = new Route($basepath.$path, $callback, $methods, $array['options']);
		$route->setResource($this);
		
		isset($this->routes[$basepath]) or $this->routes[$basepath] = array();
				
		// create the route object
		return $this->routes[$basepath][$basepath.$path] = $route;
	}

	/**
	 * Execute an endpoint closure.
	 * 
	 * @param string $path Endpoint URI path.
	 * @param Closure $closure Endpoint closure.
	 * @param null &$returned Set to closure's return value, if any.
	 * @return boolean Whether there are routes for the given endpoint path.
	 */
	protected function doEndpoint($path, Closure $closure, &$returned = null) {
		
		// store the path for use by addRoute()
		$this->endpointPath = $path;
		
		// execute the closure - any of the router's methods may be called
		$returned = $closure($this);
		
		// reset
		unset($this->endpointPath);
		unset($this->endpointControllerClass);
		unset($this->endpointDefaultMethods);
				
		// return bool whether routes were added
		return ! empty($this->routes[$path]);
	}

	/**
	 * Searches endpoints for route match.
	 * 
	 * @param string $uri Request URI.
	 * @param string $http_method Request HTTP method.
	 * @return boolean True if endpoint route matched, otherwise false.
	 */
	protected function matchEndpoints($uri, $http_method) {
		
		// we have no endpoints
		if (empty($this->endpoints)) {
			return false;
		}
		
		foreach($this->endpoints as $path => $closure) {
				
			// check for endpoint path match
			if (0 === stripos($uri, $path)) {
				
				// Run the endpoint closure
				$routes_added = $this->doEndpoint($path, $closure, $returned);
				
				if (! empty($returned) && is_object($returned)) {
					// If an object was returned, stop routing and return it.
					// This allows you to "short-circuit" routing.
					$this->route = $returned;
					return true;
				
				} else if (! $routes_added) {
					// If no routes were added, move to next endpoint
					continue;
				}
				
				// iterate through the endpoint's routes and match
				foreach ($this->routes[$path] as $route) {
					if ($this->matchRoute($route, $uri, $http_method)) {
						return true;
					}
				}
			}
		}

		return false;
	}
	
	/**
	 * Searches static routes for match.
	 * 
	 * @param string $uri Request URI.
	 * @param string $http_method Request method.
	 * @return boolean True if match, otherwise false.
	 */
	protected function matchRoutes($uri, $http_method) {
		
		// we have no routes
		if (empty($this->routes)) {
			return false;
		}
		
		// sort groups by priority
		ksort($this->routes);
		
		foreach($this->routes as $i => $group) {
			// skip endpoint paths
			if (! is_numeric($i)) {
				continue;
			}
			// Iterate and match routes in each priority group
			foreach($group as $route) {
				if ($this->matchRoute($route, $uri, $http_method)) {
					return true;
				}
			}
		}
		
		return false;
	}
	
	/**
	 * Determines if a given Route URI matches the request URI.
	 * 
	 * If matched, sets the matching parameter values on the Route object
	 * and sets the object as the router's $route property.
	 * 
	 * If the HTTP method is not allowed for the matched route, a 
	 * RouteException with 405 status error is thrown
	 * 
	 * @param Route $route \Route\Route object.
	 * @param string $uri Request URI.
	 * @param string $http_method Request HTTP method.
	 * @return boolean True if match and set up, otherwise false.
	 * @throws RouteException if match but request method is not allowed (HTTP status 405)
	 */
	protected function matchRoute(Route $route, $uri, $http_method) {
		
		$route_uri = $route->getParsedUri();
		
		if (preg_match('#^/?'.$route_uri.'/?$#i', $uri, $params)) {
			
			// Throw exception if HTTP method is not allowed
			if (! $route->isMethodAllowed($http_method)) {
				$exception = new \HttpMethodNotAllowedException();
				$exception->setAllowedValues($route->getMethods());
				throw $exception;
			}
			
			// unset the full match
			unset($params[0]);

			if (! empty($params)) {
				// set path parameters
				$route->setParams($params);
			}

			$this->route = $route;

			return true;
		}

		return false;
	}

}
