<?php

namespace xpl\Routing;

abstract class Group {
	
	protected $params;
	protected $prefix;
	protected $name;
	protected $controller;
	protected $routes;
	protected $options = array(
		'fallback_to_query_params' => true
	);
	
	public function __construct(array $params, $name, $path_prefix = '/', array $options = null) {
		
		$this->params = $params;
		$this->name = $name;
		$this->prefix = trim($path_prefix, '/').'/';
		$this->routes = array();
		
		if (isset($options)) {
			$this->options = array_merge($this->options, $options);
		}
	}
	
	public function getName() {
		return $this->name;
	}
	
	public function get($route_name) {
		return isset($this->routes[$route_name]) ? $this->routes[$route_name] : null;
	}
	
	public function setController($object) {
		$this->controller = $object;
	}
	
	public function getController() {
		return isset($this->controller) ? $this->controller : null;
	}
	
	public function set(Route $route) {
		$this->routes[$route->getName()] = $route;
	}
	
	public function add($name, $uri, array $methods, $action, array $options = array()) {
		
		$uri = $this->prefix.ltrim($uri, '/');
		
		if (! empty($this->options)) {
			$options = array_merge($this->options, $options);
		}
		
		$this->set(new Route($this, $name, $uri, $methods, $action, $options));
	}

	public function getRoutes() {
		return $this->routes;
	}
	
	public function setOptions(array $options) {
		$this->options = $options;
	}
	
	public function getOptions() {
		return $this->options;
	}
	
	public function setOption($name, $value) {
		$this->options[$name] = $value;
	}
	
	public function getOption($name) {
		return isset($this->options[$name]) ? $this->options[$name] : null;
	}
	
	public function addOptions(array $options, $overwrite = false) {
		if ($overwrite) {
			$this->options = array_merge($this->options, $options);
		} else {
			$this->options = array_merge($options, $this->options);
		}
	}
	
	public function getRegex($name) {
		return isset($this->params[$name]) ? $this->params[$name] : null;
	}
	
	public function getParams() {
		return $this->params;
	}
	
	public function isPrefixMatch($uri) {
		return '/' === $this->prefix || 0 === stripos($uri, $this->prefix);
	}
	
}
