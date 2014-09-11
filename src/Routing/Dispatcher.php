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
	 * @param \xpl\Foundation\RoutableInterface $routable
	 * @param \xpl\Event\Manager $events [Optional]
	 * 
	 * @return mixed Results of callback function, or null if no matching route.
	 */
	public function __invoke(Router $router, RequestInterface $request, RoutableInterface $routable, Events $events = null) {
	
		$resource = $this->prepareRouter($router, $routable);
		
		if ($route = $this->routeRequest($router, $request)) {
			
			$controller = $resource->getController();
			$controller->setRequest($request);
			$controller->setRoute($route);
			
			return $this->call(array($controller, $route->getAction()), $route->getParams());
		}
	}
	
	/**
	 * Prepares the router by adding the routable's resource (if necessary) and returns the resource.
	 * 
	 * @param \xpl\Routing\Router $router
	 * @param \xpl\Foundation\RoutableInterface $routable
	 * 
	 * @return \xpl\Routing\Resource
	 */
	protected function prepareRouter(Router $router, RoutableInterface $routable) {
		
		$resource = $routable->getResource();
		
		if (! $router->has($resource)) {
			$router->add($resource);
		}
		
		return $resource;
	}
	
	/**
	 * Invokes the router and returns the matched route, if any.
	 * 
	 * @param \xpl\Routing\Router $router
	 * @param \xpl\Foundation\RequestInterface $request
	 * 
	 * @return \xpl\Routing\Route|null
	 */
	protected function routeRequest(Router $router, RequestInterface $request) {
		
		if ($router($request->getMethod(), $request->getUri())) {
				
			return $router->getMatchedRoute();
		}
	}
	
	/**
	 * Calls a callback function faster than call_user_func_array() if less than 3 params.
	 */
	protected function call($callback, array $params) {
		switch(count($params)) {
			case 0:
				return $callback();
			case 1:
				return $callback(array_shift($params));
			case 2:
				return $callback(array_shift($params), array_shift($params));
			default:
				return call_user_func_array($callback, $params);
		}
	}
	
}
