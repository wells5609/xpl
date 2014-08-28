<?php

namespace xpl\Routing;

use xpl\Framework\RequestInterface;
use xpl\Framework\ControllerInterface;

abstract class Controller implements ControllerInterface {
	
	protected $request;
	protected $route;
	
	public function setRequest(RequestInterface $request) {
		$this->request = $request;
	}
	
	public function setRoute(RouteInterface $route) {
		$this->route = $route;
	}
	
}
