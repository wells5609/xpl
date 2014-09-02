<?php

namespace xpl\Routing;

use xpl\Foundation\RequestInterface;
use xpl\Foundation\RoutableInterface;
use xpl\Event\Manager as Events;

class Dispatcher {
	
	public function __invoke(Router $router, RequestInterface $request, RoutableInterface $routable, Events $events = null) {
	
		$resource = $routable->getResource();
		
		if (! $router->has($resource)) {
			$router->add($resource);
		}
		
		if ($router($request->getMethod(), $request->getFullUri())) {
			
			$match = $router->getMatch();
			$route = $match->getRoute();
			
			$controller = $resource->getController();
			$controller->setRequest($request);
			$controller->setRoute($route);
			
			return $this->call(array($controller, $route->getAction()), $route->getParams());
		}
	}

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
