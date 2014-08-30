<?php

namespace xpl\Framework\Application;

use xpl\Foundation\RequestInterface;
use xpl\Http\Request as HttpRequest;

class HmvcRequest implements RequestInterface 
{
	
	protected $httpRequest;
	protected $method;
	protected $uri;
	protected $query;
	protected $mimetype;
	protected $headers;
	protected $params;
	protected $options;
	
	public static function createEmpty() {
		return new static();
	}
	
	public static function createFromHttp(HttpRequest $httpRequest) {
		return new static($httpRequest);
	}
	
	public function __construct(HttpRequest $httpRequest = null) {
		
		if (isset($httpRequest)) {
			$this->httpRequest = $httpRequest;
		}
		
		$this->headers = array();
		$this->params = array();
		$this->options = array();
	}
	
	public function setMethod($method) {
		$this->method = strtoupper($method);
		return $this;
	}
	
	public function setUri($uri) {
		$this->uri = trim(filter_var(parse_url($uri, PHP_URL_PATH), FILTER_SANITIZE_URL), '/');
		return $this;
	}
	
	public function setHeader($name, $value) {
		$this->headers[$name] = $value;
		return $this;
	}
	
	public function setMimetype($mimetype) {
		$this->mimetype = $mimetype;
		return $this;
	}
	
	public function setQuery($query) {
		
		if (empty($query)) {
			$this->query = '';
			return $this;
		} 
		
		if (is_array($query)) {
			$queryParams = $query;
			foreach($query as $arg => $val) {
				$this->query .= "{$arg}={$val}&";
			}
			$this->query = rtrim($this->query, '&');
		} else {
			$this->query = $query;
			parse_str($this->query, $queryParams);
		}
		
		if (! empty($queryParams)) {
			$this->addParams($queryParams);
		}
		
		return $this;
	}
	
	public function getMethod() {
		return isset($this->method) ? $this->method : $this->fallback('getMethod');
	}
	
	public function getUri() {
		return isset($this->uri) ? $this->uri : $this->fallback('getUri');
	}
	
	public function getMimetype() {
		return isset($this->mimetype) ? $this->mimetype : $this->fallback('getMimetype');
	}
	
	public function getQuery() {
		return isset($this->query) ? $this->query : $this->fallback('getQuery');
	}
	
	public function getFullUri() {
		
		if ($q = $this->getQuery()) {
			return $this->getUri().'?'.$q;
		}
		
		return $this->getUri();
	}
	
	public function getHeaders() {
		if (isset($this->httpRequest)) {
			return empty($this->headers) 
				? $this->httpRequest->getHeaders()
				: array_merge($this->httpRequest->getHeaders(), $this->headers);
		}
		return empty($this->headers) ? array() : $this->headers;
	}
	
	public function getHeader($name) {
		return isset($this->headers[$name]) 
			? $this->headers[$name] 
			: $this->fallback('getHeader', $name);
	}
	
	public function getParam($name) {
		return isset($this->params[$name]) 
			? $this->params[$name] 
			: $this->fallback('getParam', $name);
	}
	
	public function getParams() {
		if (isset($this->httpRequest)) {
			return array_merge($this->httpRequest->getParams(), $this->params);
		}
		return $this->params;
	}
	
	public function addParams(array $params) {
		$this->params = array_merge($this->params, $params);
		return $this;
	}
	
	final public function isHmvc() {
		return true;
	}
	
	final public function isHttp() {
		return false;
	}
	
	public function setOption($name, $value) {
		$this->options[$name] = $value;
		return $this;
	}
	
	public function getOption($name) {
		return isset($this->options[$name]) ? $this->options[$name] : null;
	}
	
	public function setOptions(array $options) {
		foreach($options as $name => $value) {
			$this->setOption($name, $value);
		}
		return $this;
	}
	
	public function getOptions() {
		return $this->options;
	}
	
	public function toArray() {
		return get_object_vars($this);
	}
	
	protected function fallback($method, $arg = null) {
	
		if (! isset($this->httpRequest)) {
			return null;
		}
	
		return isset($arg) ? $this->httpRequest->$method($arg) : $this->httpRequest->$method();
	}
	
}
