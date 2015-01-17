<?php

namespace xpl\Routing;

use xpl\Foundation\RequestInterface;
use xpl\Foundation\ControllerInterface;
use xpl\Event\Manager as Events;

/**
 * Encapsulates the operations required for routing, including adding resources to the router, 
 * matching the request to a route, and invoking the route's callback function.
 */
class Dispatcher {
	
	/**
	 * Dispatches the request, matching the route and calling its callback.
	 * 
	 * @param \xpl\Routing\Router $router
	 * @param \xpl\Foundation\RequestInterface $request
	 * @param \xpl\Routing\RoutableInterface $routable
	 * 
	 * @return mixed Results of callback function, or null if no matching route.
	 */
	public function __invoke(Router $router, RequestInterface $request, RoutableInterface $routable) {
		
		$resource = $routable->getResource();
		
		if (! $router->has($resource)) {
			$router->add($resource);
		}
		
		if ($router($request->getMethod(), $request->getUri())) {
			
			$route = $router->getMatchedRoute();
			
			$controller = $resource->getController($request, $route);
			
			return $this->call(array($controller, $route->getAction()), $route->getParams());
		}
	}
	
	/**
	 * Calls a callback function.
	 */
	protected function call($callback, array $params) {
		switch(count($params)) {
			case 0:
				return $callback();
			case 1:
				return $callback(reset($params));
			case 2:
				return $callback(array_shift($params), array_shift($params));
			default:
				return call_user_func_array($callback, $params);
		}
	}
	
}
