<?php

namespace xpl\Routing;

abstract class Resource implements MatcherInterface
{

	protected $routes;
	protected $regex;
	protected $controller;
	protected $matcher;
	protected $match;
	
	public static function createFromClass($class) {
		
		if (! is_subclass_of($class, 'xpl\\Routing\\Resource')) {
			$msg = "Resource class '$class' must implement 'xpl\\Routing\\Resource'.";
			throw new \InvalidArgumentException($msg);
		}
		
		return new $class;
	}
	
	/**
	 * Constructor
	 */
	public function __construct() {
		$this->regex = array();
		$this->initRouteVars();
		$this->init();
	}
	
	/**
	 * @return void
	 */
	protected function init() {}
	
	/**
	 * @return string
	 */
	abstract public function getName();
	
	/**
	 * @return \xpl\Component\Routing\Controller
	 */
	abstract public function getControllerInstance();
	
	public function setMatcher(Matcher $matcher) {
		$this->matcher = $matcher;
		return $this;
	}
	
	public function getMatcher() {
		if (! isset($this->matcher)) {
			$this->matcher = new Matcher();
		}
		return $this->matcher;
	}
	
	/**
	 * Returns route vars and regex for the resource's routes.
	 * 
	 * @return array
	 */
	protected function getRouteVars() {
		return array();
	}
	
	/**
	 * Returns the default HTTP methods for the resource's routes.
	 * 
	 * @return array
	 */
	protected function getDefaultHttpMethods() {
		return array('GET','HEAD');
	}
	
	/**
	 * Guess the route controller method from its name and http methods.
	 * 
	 * @param string $name Route name
	 * @param array $http_methods Allowed HTTP methods for the route.
	 * @return string
	 */
	protected function guessRouteMethod($name, array $http_methods) {
		return $name;
	}
	
	/**
	 * @return array
	 */
	public function getRoutes() {
		isset($this->routes) OR $this->buildRoutes();
		return $this->routes;
	}
	
	/**
	 * @return xpl\Component\Routing\Resource\Route
	 */
	public function getNamedRoute($name) {
		isset($this->routes) OR $this->buildRoutes();
		return isset($this->routes[$name]) ? $this->routes[$name] : null;
	}
	
	/**
	 * @return xpl\Component\Routing\Resource\Route
	 */
	public function getMatchedRoute() {
		return isset($this->match) ? $this->match : null;
	}
	
	/**
	 * @return $this
	 */
	public function setRegex($varname, $regex) {
		$this->regex[$varname] = trim($regex, '()');
		return $this;
	}
	
	/**
	 * @return string
	 */
	public function getRegex($varname) {
		return isset($this->regex[$varname]) ? $this->regex[$varname] : '[^/]+';
	}
	
	/**
	 * @return mixed
	 */
	public function dispatchNamedRoute($route_name) {
		
		if ($route = $this->getNamedRoute($route_name)) {
			return $route;
		}
		
		return false;
	}
	
	/**
	 * @return mixed
	 */
	public function match($http_method, $match_uri) {
		
		foreach($this->getRoutes() as $route) {
			if ($route->match($http_method, $match_uri)) {
				return $this->match = $route;
			}
		}
		
		return false;
	}
	
	protected function buildRoutes() {
		$this->routes = array();
		
		foreach($this->getRouteConfig() as $name => $conf) {
			
			$uri = $conf[0];
			$http_methods = isset($conf[1]) ? (array)$conf[1] : $this->getDefaultHttpMethods();
			$method = isset($conf[2]) ? $conf[2] : $this->guessRouteMethod($name, $http_methods);
			
			$this->routes[$name] = new Resource\Route($this, $name, $uri, $http_methods);
			$this->routes[$name]->setControllerMethod($method);
		}
	}
	
	protected function initRouteVars() {
		
		if ($vars = $this->getRouteVars()) {
			foreach($vars as $varname => $regex) {
				$this->setRegex($varname, $regex);
			}
		}
	}
	
}
