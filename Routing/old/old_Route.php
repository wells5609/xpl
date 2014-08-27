<?php

namespace xpl\Routing;

use xpl\Routing\Router;

/**
 * Routes represent a single URI.
 */
class Route implements \Serializable, RouteInterface
{
	/**
	 * URI path.
	 * @var string
	 */
	protected $uri;

	/**
	 * HTTP methods accepted.
	 * @var array
	 */
	protected $methods;

	/**
	 * Controller class name.
	 * @var string
	 */
	protected $controller;
	
	/**
	 * Controller method name.
	 * @var string
	 */
	protected $action;
	
	/**
	 * The URI with var placeholders replaced with regex.
	 * @var string
	 */
	protected $parsed_uri;
	
	/**
	 * Indexed array of variable names from the parsed URI.
	 * @var array
	 */
	protected $vars;
	
	/**
	 * Associative array of route options.
	 * @var array
	 */
	protected $options;
	
	/**
	 * Matched route variables from request URI.
	 * @var array
	 */
	protected $params;
	
	/**
	 * Array callable with object when built.
	 * @var callable
	 */
	protected $callback;
	
	/**
	 * The router that controls this route.
	 * @var \xpl\Routing\MatcherInterface
	 */
	protected $router;
	
	/**
	 * Construct route with URI, callback/action, and accepted HTTP methods.
	 *
	 * @param string $uri Route URI
	 * @param mixed $controller_action Array of controller (object or classname) and action, 
	 * the action name (string), or the controller object.
	 * @param array $methods Accepted HTTP methods for this route.
	 */
	public function __construct(MatcherInterface $router, $uri, $controller_action, array $methods, array $options = array()) {
		
		$this->router = $router;
		$this->uri = $uri;
		$this->methods = array_combine($methods, $methods);
		$this->options = $options;
		
		if (is_array($controller_action)) {
			$this->controller = $controller_action[0];
			isset($controller_action[1]) and $this->action = $controller_action[1];
			
		} else if (is_string($controller_action)) {
			$this->action = $controller_action;
		
		} else if (is_object($controller_action)) {
			$this->controller = $controller_action;
		}
	}
	
	/**
	 * Sets the route's router.
	 * 
	 * @param \xpl\Routing\MatcherInterface $router
	 * @return $this
	 */
	public function setMatcher(MatcherInterface $router) {
		$this->router = $router;
		return $this;
	}
	
	/**
	 * Returns the route URI.
	 *
	 * @return string URI path.
	 */
	public function getUri() {
		return $this->uri;
	}
	
	/**
	 * Returns the parsed route URI.
	 * 
	 * @return string Parsed route URI.
	 */
	public function getParsedUri() {
		if (! isset($this->parsed_uri)) {
			$this->parseRoute();
		}
		return $this->parsed_uri;
	}
	
	/**
	 * Sets the route vars, likely from parsing.
	 * 
	 * @param array Indexed array of route vars.
	 * @return $this
	 */
	public function setVars(array $vars) {
		$this->vars = $vars;
		return $this;
	}
	
	/**
	 * Returns an array of the route vars.
	 * 
	 * @return array Indexed array of route vars.
	 */
	public function getVars() {
		return $this->vars;
	}
	
	/**
	 * Returns allowed HTTP methods.
	 *
	 * @return array Array of allowed HTTP methods.
	 */
	public function getMethods() {
		return $this->methods;
	}

	/**
	 * Returns whether a given HTTP method is allowed.
	 *
	 * @param string $method Uppercase name of HTTP method.
	 * @return boolean True if method allowed, otherwise false.
	 */
	public function isMethodAllowed($method) {
		return isset($this->methods[$method]);
	}
	
	/**
	 * Sets an associative array of route parameters from the matched request URI.
	 * 
	 * @param array $params Indexed array of path parameters.
	 * @return $this
	 */
	public function setParams(array $params) {
		if (! empty($this->vars) && ! empty($params)) {
			$this->params = array_combine($this->vars, $params);
		}
		return $this;
	}
	
	/**
	 * Returns route parameters set from request match.
	 * 
	 * @return array Associative array of parameters if set, otherwise empty array.
	 */
	public function getParams() {
		return isset($this->params) ? $this->params : array();
	}

	/**
	 * Sets the route controller.
	 *
	 * Controller can be a classname or an object.
	 *
	 * @param string|object $controller Route controller class or object.
	 * @return $this
	 */
	public function setController($controller) {
		
		if (! is_string($controller) && ! is_object($controller)) {
			throw new \InvalidArgumentException("Controller must be classname or object, given: ".gettype($controller));
		}
		
		$this->controller = $controller;
		return $this;
	}
	
	/**
	 * Returns the controller class.
	 * 
	 * @return string
	 */
	public function getController() {
		return isset($this->controller) ? $this->controller : null;
	}
	
	/**
	 * Sets the route "action" - i.e. the controller class method.
	 * 
	 * @param string $action Callable method of controller.
	 * @return $this
	 */
	public function setAction($action) {
		
		if (! is_string($action)) {
			throw new \InvalidArgumentException("Action must be string, given: ".gettype($action));
		}
		
		$this->action = $action;
		return $this;
	}
	
	/**
	 * Returns the controller action.
	 * 
	 * @return string Action (method) name, if set, otherwise "__invoke".
	 */
	public function getAction() {
		return isset($this->action) ? $this->action : '__invoke';
	}
	
	/**
	 * Returns the controller object, instantiating if necessary.
	 * 
	 * @return object
	 */
	public function getControllerInstance() {
		
		if ($controller = $this->getController()) {
		
			if (! is_object($controller)) {
				$this->controller = new $controller();
			}
		
			return $this->controller;
		}
		
		return null;
	}
	
	/**
	 * Returns the callback in a callable array format.
	 * 
	 * Callback is built 1st time called, depending on information provided 
	 * (e.g. whether an action and/or class/object have been set).
	 * 
	 * @return callable Route callback
	 * 
	 * @throws RuntimeException if callback cannot be built.
	 */
	public function getCallback() {
		
		// build callback if necessary
		if (! isset($this->callback)) {
			
			if (! $controller = $this->getControllerInstance()) {
				throw new \RuntimeException("Cannot create callback: must set controller as class or object.");
			}
			
			$action = $this->getAction();
			
			if (! is_callable(array($controller, $action))) {
				throw new \RuntimeException("Cannot create callback: controller method not callable: '$action'.");
			}
			
			$this->callback = array($controller, $action);
		}
		
		return $this->callback;
	}
	
	public function invokeWithParams() {
		
		return invoke($this->getCallback(), $this->getParams());
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
	 * Serialization - export properties.
	 */
	public function serialize() {
		
		$vars = get_object_vars($this);
		
		// reset controller object to class if this is the matched route
		if (! empty($vars['callback']) && is_object($vars['controller'])) {
			
			if (empty($vars['action']) || '__invoke' != $vars['action']) {
				$vars['controller'] = get_class($vars['controller']);
			}
		}
		
		unset($vars['callback']);
		unset($vars['params']);
		
		return serialize($vars);
	}
	
	/**
	 * Unserialization - Re-import the properties.
	 */
	public function unserialize($serial) {
		foreach(unserialize($serial) as $key => $val) {
			$this->$key = $val;
		}
	}
	
	/**
	 * Parses the route's URI, changing query vars to regex and adding keys to $vars.
	 * 
	 * @param string $uri URI to parse.
	 * @param array &$vars Associative array of vars parsed from URI.
	 * @return string URI with var placeholders replaced with their corresponding regex.
	 */
	protected function parseRoute() {
		
		$vars = array();
		$uri = $this->uri;
	
		if (preg_match_all('/<(\w+)(\:.+?)?>/', $uri, $route_vars)) {
			
			foreach($route_vars[1] as $i => $varname) {
				
				if (! empty($route_vars[2][$i])) {
					// has inline regex like "<varname:\w+>"
					$regex = ltrim($route_vars[2][$i], ':');
					
				} else if ($rgx = $this->router->getRegex($varname)) {
					// named var with regex
					$regex = $rgx;
				
				} else {
					// unnamed vars get a subpattern that matches everything except slashes
					$regex = '[^/]+';
				}
				
				// Replace full string (at index 0)
				$uri = str_replace($route_vars[0][$i], '('.$regex.')', $uri);
				
				// add var name to list
				$vars[] = $varname;
			}
		}
		
		$this->parsed_uri = $uri;
		$this->vars = $vars;
	}

}
