<?php

namespace xpl\Routing;

use xpl\Foundation\RequestInterface;
use xpl\Foundation\ControllerInterface;

interface RoutableInterface {
	
	public function getResource($name = null);
	
	public function onRoute(RouteInterface $route, RequestInterface $request, ControllerInterface $controller);
	
}
