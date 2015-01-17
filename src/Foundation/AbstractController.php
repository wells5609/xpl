<?php

namespace xpl\Foundation;

use xpl\Bundle\BundleInterface;
use xpl\Routing\RouteInterface;

abstract class AbstractController implements ControllerInterface 
{
	
	/**
	 * @var \xpl\Foundation\RequestInterface
	 */	
	protected $request;
	
	/**
	 * @var \xpl\Routing\RouteInterface
	 */
	protected $route;
	
	/**
	 * @var \xpl\Bundle\BundleInterface
	 */
	protected $app;
	
	/**
	 * @param \xpl\Foundation\RequestInterface $request
	 */	
	public function setRequest(RequestInterface $request) {
		$this->request = $request;
	}
	
	/**
	 * @param \xpl\Routing\RouteInterface $route
	 */
	public function setRoute(RouteInterface $route) {
		$this->route = $route;
	}
	
	/**
	 * @param \xpl\Bundle\BundleInterface $app
	 */
	public function setApp(BundleInterface $app) {
		$this->app = $app;
	}
	
	/**
	 * @return \xpl\Foundation\RequestInterface
	 */	
	public function getRequest() {
		return isset($this->request) ? $this->request : null;
	}
	
	/**
	 * @return \xpl\Routing\RouteInterface
	 */
	public function getRoute() {
		return isset($this->route) ? $this->route : null;
	}
	
	/**
	 * @return \xpl\Bundle\BundleInterface
	 */
	public function getApp() {
		return isset($this->app) ? $this->app : null;
	}
	
}
