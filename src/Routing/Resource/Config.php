<?php

namespace xpl\Routing\Resource;

abstract class Config {
	
	protected $routes;
	protected $regex;
	protected $controller;
	
	public function __construct() {
		$this->regex = array();
		$this->initRouteVars();
	}
	
	abstract public function getName();
	
	abstract public function getControllerInstance();
	
	abstract protected function getRouteConfig();
	
	protected function getRouteVars() {
		return array();
	}
	
	protected function getDefaultHttpMethods() {
		return array('GET','HEAD');
	}
	
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
	 * @return \Resource\Route
	 */
	public function getNamedRoute($name) {
		isset($this->routes) OR $this->buildRoutes();
		return isset($this->routes[$name]) ? $this->routes[$name] : null;
	}
	
	public function setRegex($varname, $regex) {
		$this->regex[$varname] = trim($regex, '()');
		return $this;
	}
	
	public function getRegex($varname) {
		return isset($this->regex[$varname]) ? $this->regex[$varname] : '[^/]+';
	}
	
	protected function buildRoutes() {
		$this->routes = array();
		
		foreach($this->getRouteConfig() as $name => $conf) {
			
			$uri = $conf[0];
			$http_methods = isset($conf[1]) ? (array) $conf[1] : $this->getDefaultHttpMethods();
			$method = isset($conf[2]) ? $conf[2] : $this->guessRouteMethod($name, $http_methods);
			
			$this->routes[$name] = new Route($this, $name, $uri, $http_methods);
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
