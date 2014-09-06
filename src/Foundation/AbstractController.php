<?php

namespace xpl\Foundation;

abstract class AbstractController implements ControllerInterface {
	
	protected $request;
	protected $route;
	protected $app;
	
	public function setRequest(RequestInterface $request) {
		$this->request = $request;
	}
	
	public function setRoute(RouteInterface $route) {
		$this->route = $route;
	}
	
	public function setApp(BundleInterface $app) {
		$this->app = $app;
	}
	
	public function getRequest() {
		return isset($this->request) ? $this->request : null;
	}
	
	public function getRoute() {
		return isset($this->route) ? $this->route : null;
	}
	
	public function getApp() {
		return isset($this->app) ? $this->app : null;
	}
	
}
