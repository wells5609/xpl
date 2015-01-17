<?php

namespace xpl\Web;

use xpl\Routing\Router;
use xpl\Routing\RoutableInterface;
use xpl\Foundation\RequestInterface;
use xpl\Event\Manager as Events;
use xpl\Http\Exception\NotFound as HTTP_404;
use xpl\Http\Exception\MethodNotAllowed as HTTP_405;

class Dispatcher extends \xpl\Routing\Dispatcher {
	
	public function __invoke(Router $router, RequestInterface $request, RoutableInterface $routable) {
		
		try {
				
			$resource = $routable->getResource();
			
			if (! $router->has($resource)) {
				$router->add($resource);
			}
			
			if (! $router($request->getMethod(), $request->getUri())) {
				throw new HTTP_404("Page not found.", 404);
			}
			
			$route = $router->getMatchedRoute();
			$controller = $resource->getController($request, $route);
			
			return $this->call(array($controller, $route->getAction()), $route->getParams());
		
		} catch (Exception\MethodNotAllowed $e) {
			$http405 = new HTTP_405(null, 405, $e);
			$http405->setAllowedValues($e->getAllowedValues());
			throw $http405;
		
		} catch (Exception $e) {
			throw new HTTP_404($e->getMessage(), 404, $e);
		}
	}

}
