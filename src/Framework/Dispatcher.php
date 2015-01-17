<?php

namespace xpl\Framework;

use xpl\Routing\Router;
use xpl\Routing\RoutableInterface as Routable;
use xpl\Routing\Exception\MethodNotAllowed;
use xpl\Routing\Exception\NotFound;
use xpl\Http\Exception\MethodNotAllowed as HTTP_405;
use xpl\Http\Exception\NotFound as HTTP_404;
use xpl\Foundation\RequestInterface as Request;
use xpl\Event\Manager as Events;

class Dispatcher extends \xpl\Routing\Dispatcher
{
	
	public function __invoke(Router $router, Request $request, Routable $routable, Events $events = null) {
		
		try {
			
			$resource = $routable->getResource();
			
			if (! $router->has($resource)) {
				$router->add($resource);
			}
			
			if (! $router($request->getMethod(), $request->getUri())) {
				throw new HTTP_404('Page not found.', 404);
			}
			
			$route		= $router->getMatchedRoute();
			$controller = $resource->getController($request, $route);
			
			if (isset($events)) {
				/** 
				 * @event dispatch
				 */
				$events->trigger('dispatch', $routable, $route, $request, $controller);
			}
			
			return $this->call(array($controller, $route->getAction()), $route->getParams());
		
		} catch (MethodNotAllowed $e) {
			$http405 = new HTTP_405(null, 405, $e);
			$http405->setAllowedValues($e->getAllowedValues());
			throw $http405;
		
		} catch (NotFound $e) {
			throw new HTTP_404($e->getMessage(), 404, $e);
		}
	}
	
}
