<?php

namespace xpl\Routing;

class Route implements RouteInterface {
	
	protected $name;
	protected $uri;
	protected $methods;
	protected $action;
	protected $options;
	protected $params;
	protected $group;
	protected $compiledUri;
	
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
		
		isset($this->compiledUri) or $this->compile();
		
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
		if (! isset($this->compiledUri)) {
			$this->compile();
		}
		return $this->compiledUri;
	}
	
	public function getStrippedUri() {
		
		if (false === strpos($this->uri, '{')) {
			return $this->uri;
		}
		
		$path = array();
		
		foreach(explode('/', $this->uri) as $segment) {
			if ('{' !== $segment[0]) {
				$path[] = $segment;
			}
		}
		
		return implode('/', $path);
	}
	
	protected function compile() {
		
		$uri = $this->uri;
		$search = $replace = array();
		
		if (preg_match_all('#\{(\w+)\}(\?)?#', $uri, $vars)) {
			
			foreach($vars[1] as $i => $varname) {
				
				if (! $regex = $this->group->getParamRegex($varname)) {
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
		
		$this->compiledUri = $uri;
	}
	
}
