<?php

namespace xpl\Foundation;

use xpl\Bundle\BundleInterface as Bundle;
use xpl\Routing\RouteInterface as Route;

abstract class AbstractController implements ControllerInterface 
{
		
	/**
	 * @var \xpl\Foundation\RequestInterface
	 */	
	protected $request;
	
	/**
	 * @var \xpl\Foundation\ResponseInterface
	 */	
	protected $response;
	
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
	 * @param \xpl\Foundation\ResponseInterface $response
	 * @param \xpl\Routing\RouteInterface $route
	 * @param \xpl\Bundle\BundleInterface $app
	 */	
	public function __construct(RequestInterface $request, ResponseInterface $response, Route $route, Bundle $app) {
		$this->request = $request;
		$this->response = $response;
		$this->route = $route;
		$this->app = $app;
	}
	
	/**
	 * @param \xpl\Foundation\RequestInterface $request
	 */	
	public function setRequest(RequestInterface $request) {
		$this->request = $request;
	}
	
	/**
	 * @param \xpl\Foundation\ResponseInterface $response
	 */	
	public function setResponse(RequestInterface $response) {
		$this->response = $response;
	}
	
	/**
	 * @param \xpl\Routing\RouteInterface $route
	 */
	public function setRoute(Route $route) {
		$this->route = $route;
	}
	
	/**
	 * @param \xpl\Bundle\BundleInterface $app
	 */
	public function setApp(Bundle $app) {
		$this->app = $app;
	}
	
	/**
	 * @return \xpl\Foundation\RequestInterface
	 */	
	public function getRequest() {
		return $this->request;
	}
	
	/**
	 * @return \xpl\Foundation\RequestInterface
	 */	
	public function getResponse() {
		return $this->response;
	}
	
	/**
	 * @return \xpl\Routing\RouteInterface
	 */
	public function getRoute() {
		return $this->route;
	}
	
	/**
	 * @return \xpl\Bundle\BundleInterface
	 */
	public function getApp() {
		return $this->app;
	}
	
}
