<?php

namespace xpl\Routing;

use xpl\Foundation\RequestInterface;

interface RoutableInterface 
{
	
	/**
	 * Returns a route collection.
	 * 
	 * @return \xpl\Routing\Route\Collection
	 */
	public function getRoutes();
	
	/**
	 * Called when one of the routable's routes is matched.
	 * 
	 * @param \xpl\Routing\RouteInterface $route
	 * @param \xpl\Foundation\RequestInterface $request
	 */
	public function onRoute(RouteInterface $route, RequestInterface $request);
	
	/**
	 * Called prior to the invoking the controller action for the route.
	 * 
	 * @param \xpl\Routing\RouteInterface $route
	 * @param \xpl\Foundation\RequestInterface $request
	 */
	public function onDispatch(RouteInterface $route, RequestInterface $request);
	
}
