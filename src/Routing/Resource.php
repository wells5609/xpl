<?php

namespace xpl\Routing;

use xpl\Foundation\RequestInterface;
use xpl\Foundation\ControllerInterface;

/**
 * A resource encapsulates a group of routes that share a common mount point (possibly just "/").
 */
class Resource implements \Serializable
{
	protected $name;
	protected $uri_prefix;
	protected $routes;
	protected $options;
	protected $tokens;
	protected $compiler;
	protected $generator;
	protected $controller;
	
	/**
	 * Constructor.
	 * 
	 * @param string $name Resource name.
	 * @param string $uri_prefix [Optional] Prepended to all route paths.
	 */
	public function __construct($name, $uri_prefix = '/') {
		$this->name = $name;
		$this->uri_prefix = trim($uri_prefix, '/');
		$this->routes = array();
		$this->options = array();
	}
	
	/**
	 * Returns the resource name.
	 * 
	 * @return string
	 */
	public function getName() {
		return $this->name;
	}
	
	/**
	 * Sets the tokens used by the resource's routes.
	 * 
	 * @param \xpl\Routing\Route\Tokens $tokens
	 */
	public function setTokens(Route\Tokens $tokens) {
		$this->tokens = $tokens;
	}
	
	/**
	 * Returns the tokens used by the routes.
	 * 
	 * @return \xpl\Routing\Route\Tokens
	 * 
	 * @throws \RuntimeException if tokens instance is not set.
	 */
	public function getTokens() {
			
		if (! isset($this->tokens)) {
			throw new \RuntimeException("No Tokens instance set.");
		}
		
		return $this->tokens;
	}
	
	/**
	 * Sets the object used to compile route URI's.
	 * 
	 * @param \xpl\Routing\Route\Compiler $compiler
	 */
	public function setCompiler(Route\Compiler $compiler) {
		$this->compiler = $compiler;
	}
	
	/**
	 * Returns the compiler instance, creating if not set.
	 * 
	 * @return \xpl\Routing\Route\Compiler
	 */
	public function getCompiler() {
		
		if (! isset($this->compiler)) {
			$this->compiler = new Route\Compiler($this);
		}
		
		return $this->compiler;
	}
	
	/**
	 * Sets the object used to generate routes.
	 * 
	 * @param \xpl\Routing\Route\Generator $generator
	 */
	public function setGenerator(Route\Generator $generator) {
		$this->generator = $generator;
	}
	
	/**
	 * Returns the generator, creating if not set.
	 * 
	 * @return \xpl\Routing\Route\Generator
	 */
	public function getGenerator() {
		
		if (! isset($this->generator)) {
			$this->generator = new Route\Generator($this);
		}
		
		return $this->generator;
	}
	
	/**
	 * Sets the controller instance.
	 * 
	 * @param \xpl\Foundation\ControllerInterface
	 */
	public function setController(ControllerInterface $controller) {
		$this->controller = $controller;
	}
	
	/**
	 * Returns the controller, creating from "controller_class" option if set.
	 * 
	 * @return \xpl\Foundation\ControllerInterface The controller to handle the request.
	 */
	public function getController() {
		
		if (! isset($this->controller)) {
			
			$class = $this->getOption('controller_class');
			
			if (! $class || ! class_exists($class)) {
				throw new \RuntimeException("Invalid controller class: '{$class}'.");
			}
			
			$this->controller = new $class();
		}
		
		return $this->controller;
	}
	
	/**
	 * Adds a route to the resource.
	 * 
	 * @param \xpl\Routing\Route $route
	 */
	public function addRoute(Route $route) {
		
		if (! $route->isCompiled()) {
			$this->getCompiler()->compile($route);
		}
		
		if (! empty($this->uri_prefix)) {
			$route->prefixUri($this->uri_prefix);
		}
		
		$this->routes[$route->getID()] = $route;
	}
	
	/**
	 * Gets a route by its ID.
	 * 
	 * @param string $id Route ID.
	 * @return \xpl\Routing\Route|null
	 */
	public function getRoute($id) {
		return isset($this->routes[$id]) ? $this->routes[$id] : null;
	}
	
	/**
	 * Returns an array of the resource's routes.
	 * 
	 * @return array
	 */
	public function getRoutes() {
		return $this->routes;
	}
	
	/**
	 * Sets an option value.
	 * 
	 * @param string $name Option name.
	 * @param mixed $value Option value.
	 */
	public function setOption($name, $value) {
		$this->options[$name] = $value;
	}
	
	/**
	 * Sets the resource's options to the given array.
	 * 
	 * @param array $options
	 */
	public function setOptions(array $options) {
		$this->options = $options;
	}
	
	/**
	 * Returns an option value by name.
	 * 
	 * @param string $name Option name.
	 * @return mixed Option value, if set, otherwise null.
	 */
	public function getOption($name) {
		return isset($this->options[$name]) ? $this->options[$name] : null;
	}
	
	/**
	 * Returns an array of the resource's options.
	 * 
	 * @return array
	 */
	public function getOptions() {
		return $this->options;
	}
	
	/**
	 * Checks whether the resource has a given option.
	 * 
	 * @param string $name Option name.
	 * 
	 * @return boolean True if option exists, otherwise false.
	 */
	public function hasOption($name) {
		return isset($this->options[$name]);
	}
	
	/**
	 * Adds options to the option array, overwriting existing values by default.
	 * 
	 * @param array $options Associative array of options to add.
	 * @param boolean $overwrite [Optional] Whether to overwrite existing options. Default true.
	 */
	public function addOptions(array $options, $overwrite = true) {
		if ($overwrite) {
			$this->options = array_merge($this->options, $options);
		} else {
			$this->options = array_merge($options, $this->options);
		}
	}
	
	/**
	 * Implements \Serializable
	 */
	public function serialize() {
		return serialize(get_object_vars($this));
	}
	
	/**
	 * Implements \Serializable
	 */
	public function unserialize($serial) {
		foreach(unserialize($serial) as $key => $value) {
			$this->$key = $value;
		}
	}
	
}
