<?php

namespace xpl\Routing;

class Resource extends Group implements \Serializable {
	
	/**
	 * Controller classname.
	 * @var string
	 */
	protected $controller;
	
	/**
	 * Base URL.
	 * @var string
	 */
	protected $baseUrl;
	
	public function setController($class) {
		$this->controller = $class;
	}
	
	public function setBaseUrl($url) {
		$this->baseUrl = rtrim($url, '/').'/';
	}
	
	public function getController() {
		return isset($this->controller) ? $this->controller : null;
	}
	
	public function getBaseUrl() {
		return isset($this->baseUrl) ? $this->baseUrl : null;
	}
	
	public function buildUrl($path) {
		return $this->baseUrl.ltrim($path, '/');
	}
	
	public function serialize() {
		$vars = get_object_vars($this);
		return serialize($vars);
	}
	
	public function unserialize($serial) {
		foreach(unserialize($serial) as $key => $value) {
			$this->$key = $value;
		}
	}
	
}