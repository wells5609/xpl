<?php

namespace xpl\Routing;

class Group {
	
	protected $paramContainer;
	protected $pathPrefix;
	protected $name;
	protected $routes;
	protected $options = array(
		'fallback_to_query_params' => true
	);
	
	public function __construct(Parameter\Container $params, $name, $path_prefix = '/', array $options = null) {
		
		$this->paramContainer = $params;
		$this->name = $name;
		$this->pathPrefix = trim($path_prefix, '/').'/';
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
	
	public function set(Route $route) {
		$this->routes[$route->getName()] = $route;
	}
	
	public function add($name, $uri, array $methods, $action, array $options = array()) {
		
		$uri = $this->pathPrefix.ltrim($uri, '/');
		
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
	
	public function getParamRegex($name) {
		return $this->paramContainer->get($name);
	}
	
	public function getParamContainer() {
		return $this->paramContainer;
	}
	
	public function isPrefixMatch($uri) {
		return '/' === $this->pathPrefix || 0 === stripos($uri, $this->pathPrefix);
	}
	
}
