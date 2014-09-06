<?php

namespace xpl\Web;

use xpl\Routing\Router;
use xpl\Foundation\RequestInterface;
use xpl\Foundation\RoutableInterface;
use xpl\Event\Manager as Events;
use xpl\Http\Exception\MethodNotAllowed as HTTP_405;
use xpl\Http\Exception\NotFound as HTTP_404;

class Dispatcher extends \xpl\Routing\Dispatcher {
	
	public function __invoke(Router $router, RequestInterface $request, RoutableInterface $routable, Events $events = null) {
		
		try {
			
			$resource = $this->prepareRouter($router, $routable);
			
			if ($match = $this->routeRequest($router, $request)) {
				
				$route = $match->getRoute();
				
				$controller = $resource->getController();
				$controller->setRequest($request);
				$controller->setRoute($route);
				
				if ($routable instanceof Application) {
					
					$controller->setApp($routable);
					
					if (isset($events)) {
						$events->trigger('dispatch', $routable, $route, $request, $controller);
					}
					
					$routable->onRoute($route, $request, $controller);
				}
				
				return $this->call(array($controller, $route->getAction()), $route->getParams());
			}
		
		} catch (Exception\MethodNotAllowed $e) {
			$http_e = new HTTP_405(null, 405, $e);
			$http_e->setAllowedValues($e->getAllowedValues());
			throw $http_e;
		
		} catch (Exception $e) {
			throw new HTTP_404($e->getMessage(), 404, $e);
		}
	}

}
