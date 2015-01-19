<?php

namespace xpl\Routing;

use xpl\Foundation\RequestInterface;
use xpl\Foundation\ControllerInterface;

interface RoutableInterface {
	
	public function getResource($name = null);
	
	public function onRoute(RouteInterface $route, RequestInterface $request);
	
	/**
	 * Called prior to the invoking the controller action for the route.
	 * 
	 * @param \xpl\Routing\RouteInterface $route
	 * @param \xpl\Foundation\RequestInterface $request
	 * @param \xpl\Foundation\ControllerInterface $controller
	 */
	public function onDispatch(RouteInterface $route, RequestInterface $request, ControllerInterface $controller);
	
}
