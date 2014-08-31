<?php

namespace xpl\Web;

use xpl\Routing\Router;
use xpl\Foundation\RequestInterface;
use xpl\Event\Manager as Events;
use xpl\Routing\Exception\MethodNotAllowed;
use xpl\Routing\Exception\RouteException;
use xpl\Http\Exception\MethodNotAllowed as HTTP_405;
use xpl\Http\Exception\NotFound as HTTP_404;

class Dispatcher {
	
	public function __invoke(Router $router, RequestInterface $request, Application $app, Events $events = null) {
		
		try {
			
			$router->add($app->getResource());
			
			if ($router($request->getMethod(), $request->getFullUri())) {
				
				$match = $router->getMatch();
				$route = $match->getRoute();
				
				$cntrlClass = $route->getGroup()->getController();
				$controller = new $cntrlClass();
				
				$controller->setRequest($request);
				$controller->setRoute($route);
				$controller->setApp($app);
				
				if (isset($events)) {
					$events->trigger('dispatch', $app, $route, $request, $controller);
				}
				
				if ($request instanceof Request) {
					// Request is a WEB request (not HMVC or other)
					$app->onRoute($route, $request, $controller);
				}
				
				return call_user_func_array(array($controller, $route->getAction()), $route->getParams());
			}
		
		} catch (MethodNotAllowed $e) {
			$http_e = new HTTP_405(null, 0, $e);
			$http_e->setAllowedValues($e->getAllowedValues());
			throw $http_e;
		
		} catch (RouteException $e) {
			throw new HTTP_404($e->getMessage(), 0, $e);
		}
	}
	
}
