<?php

namespace xpl\Routing;

class Resource extends Group {
	
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
	
}