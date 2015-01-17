<?php

namespace xpl\Routing;

/**
 * Route represents a request destination/action.
 */
class Route implements RouteInterface
{
	
	/**
	 * @var string
	 */
	protected $name;
	
	/**
	 * @var string
	 */
	protected $uri;
	
	/**
	 * @var string
	 */
	protected $method;
	
	/**
	 * @var string
	 */
	protected $action;
	
	/**
	 * @var string
	 */
	protected $compiled_uri;
	
	/**
	 * @var array
	 */
	protected $tokens;
	
	/**
	 * @var array
	 */
	protected $params;
	
	/**
	 * Constructor.
	 * 
	 * @param string $name Route name (does not need to be unique).
	 * @param string $method HTTP method allowed.
	 * @param string $uri Route URI path (unparsed).
	 * @param string $action [Optional] Route action. Default is to prepend the lowercased method
	 * to the route's name with the first letter uppercased: e.g. "GET" + "myroute" => "getMyroute"
	 */
	public function __construct($name, $method, $uri, $action = null) {
		
		$this->name = $name;
		$this->method = strtoupper($method);
		$this->uri = trim($uri, '/');
		$this->params = array();
		
		if (empty($action)) {
			$action = strtolower($this->method).ucfirst($this->name);
		}
		
		$this->action = $action;
	}
	
	/**
	 * Method used for identifying a route by string.
	 * 
	 * Default implementation uses "$this->action", since some routes can 
	 * potentially have the same name (e.g. if their HTTP methods differ).
	 * 
	 * @return string
	 */
	public function getID() {
		return $this->action;
	}
	
	/**
	 * Returns the route's name.
	 * 
	 * @return string
	 */
	public function getName() {
		return $this->name;
	}
	
	/**
	 * Returns the route's HTTP method.
	 * 
	 * @return string
	 */
	public function getMethod() {
		return $this->method;
	}
	
	/**
	 * Returns the URI (raw, including params like "{param}").
	 * 
	 * @return string
	 */
	public function getUri() {
		return $this->uri;
	}
	
	/**
	 * Returns the route action.
	 * 
	 * @return string
	 */
	public function getAction() {
		return $this->action;
	}
	
	/**
	 * Sets the compiled route URI.
	 * 
	 * Called from Compiler.
	 * 
	 * @param string $uri Compiled URI.
	 */
	public function setCompiledUri($uri) {
		$this->compiled_uri = $uri;
	}
	
	/**
	 * Returns the compiled URI, if set.
	 * 
	 * @return string|null
	 */
	public function getCompiledUri() {
		return isset($this->compiled_uri) ? $this->compiled_uri : null;
	}
	
	/**
	 * Checks whether the route URI has been compiled.
	 * 
	 * @return boolean
	 */
	public function isCompiled() {
		return isset($this->compiled_uri);
	}
	
	/**
	 * Sets the route's URI tokens.
	 * 
	 * @param array $tokens
	 */
	public function setTokens(array $tokens = array()) {
		$this->tokens = $tokens;
	}
	
	/**
	 * Returns the route's tokens.
	 * 
	 * @return array
	 */
	public function getTokens() {
		return $this->tokens;
	}
	
	/**
	 * Checks whether the route uses a given token.
	 * 
	 * @param string $name
	 */
	public function hasToken($name) {
		return isset($this->tokens[$name]);
	}
	
	/**
	 * Sets the parameters matched from the route tokens.
	 * 
	 * Parameters are the route's tokens filled with values.
	 * 
	 * @param array $params
	 */
	public function setParams(array $params = array()) {
		if (count($params) === count($this->tokens)) {
			$this->params = array_combine($this->tokens, $params);
		}
	}
	
	/**
	 * Checks whether the route has a given parameter set.
	 * 
	 * @param string $token
	 */
	public function hasParam($token) {
		return isset($this->params[$token]);
	}
	
	/**
	 * Returns the route's parameters.
	 * 
	 * @return array
	 */
	public function getParams() {
		return $this->params;
	}
	
	/**
	 * Returns a parameter value by token name.
	 * 
	 * @param string $token Token name.
	 * @return string Parameter value, if set, otherwise null.
	 */
	public function getParam($token) {
		return isset($this->params[$token]) ? $this->params[$token] : null;
	}
	
	/**
	 * Prepends a string to the route's URI.
	 * 
	 * Called by Resource.
	 * 
	 * @param string $uri_prefix
	 */
	public function prefixUri($uri_prefix) {
		
		$this->uri = rtrim($uri_prefix, '/').'/'.$this->uri;
		
		if (isset($this->compiled_uri)) {
			$this->compiled_uri = $uri_prefix.'/'.$this->compiled_uri;
		}
	}
	
	/**
	 * Checks whether the route's tokens have been satisfied.
	 * 
	 * @return boolean
	 */
	public function isSatisfied() {
		
		if (empty($this->tokens)) {
			return true;
		}
		
		foreach($this->tokens as $token) {
			if (! isset($this->params[$token])) {
				return false;
			}
		}
		
		return true;
	}
	
	/**
	 * Implements \Serializable
	 */
	public function serialize() {
		// don't store the parameters if this is the matched route
		$this->params = array();
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
