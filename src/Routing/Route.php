<?php

namespace xpl\Routing;

class Route implements \xpl\Foundation\RouteInterface {
	
	protected $group;
	protected $name;
	protected $uri;
	protected $compiled_uri;
	protected $action;
	protected $methods;
	protected $params;
	protected $options;
	protected $uri_template;
	
	public function __construct(Group $group, $name, $uri, array $methods, $action, array $options = array()) {
		$this->group = $group;
		$this->name = $name;
		$this->uri = trim($uri, '/');
		$this->methods = $methods;
		$this->action = $action;
		$this->options = $options;
		$this->params = array();
	}
	
	public function getGroup() {
		return $this->group;
	}
	
	public function getName() {
		return $this->name;
	}
	
	public function getUri() {
		return $this->uri;
	}
	
	public function getMethods() {
		return $this->methods;
	}
	
	public function hasMethod($method) {
		return in_array($method, $this->methods, true);
	}
	
	public function setAction($action) {
		$this->action = $action;
	}
	
	public function getAction() {
		return $this->action;
	}
	
	public function getParams() {
		return $this->params;
	}
	
	public function hasParam($name) {
		return array_key_exists($name, $this->params);
	}
	
	public function setParamValues(array $params) {
		if (count($params) === count($this->params)) {
			$this->params = array_combine(array_keys($this->params), $params);
		}
	}
	
	public function setParamValue($name, $value) {
		$this->params[$name] = $value;
	}
	
	public function hasParamValue($name) {
		return isset($this->params[$name]);
	}
	
	public function getParamValue($name) {
		return isset($this->params[$name]) ? $this->params[$name] : null;
	}
	
	public function setParamsFrom(array $values) {
		foreach($values as $key => $value) {
			if (array_key_exists($key, $this->params) && ! isset($this->params[$key])) {
				$this->params[$key] = $value;
			}
		}
	}
	
	public function isSatisfied(&$missing = null) {
		
		isset($this->compiled_uri) or $this->compile();
		
		if (empty($this->params)) {
			return true;
		}
		
		foreach($this->params as $key => $value) {
			if (null === $value) {
				$missing = $value;
				return false;
			}
		}
		
		return true;
	}
	
	public function isSatisfiedBy(array $values, &$missing = null) {
		
		isset($this->compiled_uri) or $this->compile();
		
		if (empty($this->params)) {
			return true;
		}
		
		foreach($this->params as $param => $null) {
			if (! isset($values[$param])) {
				$missing = $param;
				return false;
			}
		}
		
		return true;
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
	
	public function getCompiledUri() {
		isset($this->compiled_uri) or $this->compile();
		return $this->compiled_uri;
	}
	
	public function getStrippedUri() {
		
		if (false === strpos($this->uri, '{')) {
			return $this->uri;
		}
		
		$path = '';
		
		foreach(explode('/', $this->uri) as $segment) {
			if ('{' !== $segment[0]) {
				$path .= '/'.$segment;
			}
		}
		
		return ltrim($path, '/');
	}
	
	/**
	 * Returns a URI template for the route, generating if necessary.
	 * 
	 * @return \xpl\Utility\Uri\Template
	 */
	public function getUriTemplate() {
		
		if (! isset($this->uri_template)) {
			
			$uri = \xpl\System\Server::getHttpScheme().'://'
				.\xpl\System\Server::getDomainName().'/'
				.str_replace(array('{', '?}', '}'), array(':', ''), $this->uri);
			
			$this->uri_template = new \xpl\Utility\Uri\Template($uri);
		}
		
		return $this->uri_template;	
	}
	
	public function generateUrl(array $args = array()) {
		return $this->getUriTemplate()->build($args);
	}
	
	protected function compile() {
		
		$uri = $this->uri;
		$search = $replace = array();
		
		if (preg_match_all('#\{(\w+)\}(\?)?#', $uri, $vars)) {
			
			foreach($vars[1] as $i => $varname) {
				
				if (! $regex = $this->group->getRegex($varname)) {
					throw new \InvalidArgumentException("Unknown route parameter: '$varname'.");
				}
				
				if (! empty($vars[2][$i])) {
					$regex .= '?';
				}
				
				$search[] = $vars[0][$i];
				$replace[] = '('.$regex.')';
				
				$this->params[$varname] = null;
			}
			
			$uri = str_replace($search, $replace, $uri);
		}
		
		$this->compiled_uri = $uri;
	}
	
}
