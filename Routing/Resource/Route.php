<?php

namespace xpl\Routing\Resource;

use xpl\Routing\RouteInterface;
use xpl\Routing\Resource;

class Route implements RouteInterface 
{
	
	protected $resource;
	protected $name;
	protected $uri;
	protected $http_methods;
	protected $controller;
	protected $controller_method;
	protected $parsed_uri;
	protected $vars;
	protected $params;
	protected $options;
	
	public function __construct(Resource $resource, $name, $uri, array $http_methods) {
		$this->resource = $resource;
		$this->name = $name;
		$this->uri = trim($uri, '/');
		$this->http_methods = array_map('strtoupper', $http_methods);
		$this->vars = array();
		$this->params = array();
		$this->options = array();
	}
	
	public function setResource($resource) {
		$this->resource = $resource;
		return $this;
	}
	
	public function getResource() {
		return $this->resource;
	}
	
	public function getName() {
		return $this->name;
	}
	
	public function getUri() {
		return $this->uri;
	}
	
	public function getHttpMethods() {
		return $this->http_methods;
	}
	
	public function getControllerInstance() {
		return $this->resource->getControllerInstance();
	}
	
	public function isHttpMethodAllowed($http_method) {
		return in_array($http_method, $this->getHttpMethods(), true);
	}
	
	public function setControllerMethod($method) {
		$this->controller_method = $method;
		return $this;
	}
	
	public function getControllerMethod() {
		return isset($this->controller_method) ? $this->controller_method : $this->name;
	}
	
	public function setParams(array $params) {
		if (count($params) === count($this->getVars())) {
			$this->params = array_combine($this->getVars(), $params);
		}
		return $this;
	}
	
	public function getParams() {
		return $this->params;
	}
	
	public function getCompiledUri() {
		if (! isset($this->compiled_uri)) {
			$this->compile();
		}
		return $this->compiled_uri;
	}
	
	public function getVars() {
		if (! isset($this->compiled_uri)) {
			$this->compile();
		}
		return $this->vars;
	}
	
	public function setCompiledUri($uri) {
		$this->compiled_uri = $uri;
		return $this;
	}
	
	public function setVars(array $vars) {
		$this->vars = $vars;
		return $this;
	}
	
	public function invoke(array $args = null) {
		
		$controller = $this->getControllerInstance();
		$method = $this->getControllerMethod();
		
		if (empty($args)) {
			// call directly
			return $controller->$method();
		}
		
		// call slowly
		return call_user_func_array(array($controller, $method), $args);
	}
	
	public function invokeWithParams() {
		return $this->invoke($this->getParams());
	}
	
	/**
	 * Sets an array of route options.
	 * 
	 * @param array $options
	 * @return $this
	 */
	public function setOptions(array $options) {
		$this->options = $options;
		return $this;
	}
	
	public function setOption($name, $value) {
		$this->options[$name] = $value;
		return $this;
	}
	
	public function getOptions() {
		return $this->options;
	}
	
	public function getOption($name) {
		return isset($this->options[$name]) ? $this->options[$name] : null;
	}
	
	/**
	 * @return boolean
	 */
	public function match($http_method, $uri) {
		
		if (preg_match('#^/?'.$this->getCompiledUri().'/?$#i', $uri, $params)) {
			
			// Throw exception if HTTP method is not allowed
			if (! $this->isHttpMethodAllowed($http_method)) {
				$exception = new \HttpMethodNotAllowedException();
				$exception->setAllowedValues($this->getHttpMethods());
				throw $exception;
			}
			
			// unset the full match & set params
			unset($params[0]);
			empty($params) OR $this->setParams($params);

			return true;
		}

		return false;
	}
	
	protected function compile() {
		
		$uri = $this->uri;
		$replace = array();
		
		if (preg_match_all('#\{(\w+)(\?)?\}#', $uri, $vars)) {
			
			foreach($vars[1] as $i => $varname) {
				
				$regex = '('.$this->resource->getRegex($varname).')';
				
				if (! empty($vars[2][$i])) {
					$regex .= '?';
				}
				
				// Replace full string (at index 0)
				$uri = str_replace($vars[0][$i], $regex, $uri);
				
				// add var name to list
				$this->vars[] = $varname;
			}
		}
		
		$this->compiled_uri = $uri;
	}
	
}
