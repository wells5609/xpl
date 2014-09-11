<?php

namespace xpl\Web;

use xpl\Routing\RoutableInterface;
use xpl\Routing\RouteInterface;
use xpl\Foundation\Application as BaseApp;
use xpl\Foundation\RequestInterface;
use xpl\Foundation\ControllerInterface;

abstract class Application extends BaseApp implements RoutableInterface {
	
	/**
	 * Returns the route resource for routing.
	 * 
	 * @return \xpl\Routing\Resource
	 */
	abstract public function getResource($name = null);
	
	
	/**
	 * Called when one of the application's route is matched by the router.
	 */
	public function onRoute(RouteInterface $route, RequestInterface $request, ControllerInterface $controller) {
	}
	
	
	/**
	 * Called before response is sent when the application is the primary app (i.e. the target of the web request).
	 */
	public function onRespond(Response $response) {
	}
	
}
