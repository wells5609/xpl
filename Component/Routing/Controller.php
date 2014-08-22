<?php

namespace xpl\Component\Routing;

use xpl\Component\Foundation\RequestInterface;

abstract class Controller extends \Object {
	
	protected $request;
	protected $route;
	
	public function prepare(RequestInterface $request, RouteInterface $route) {
		$this->request = $request;
		$this->route = $route;
	}
	
}
