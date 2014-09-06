<?php

namespace xpl\Framework;

use xpl\Dependency\DiAwareInterface;
use xpl\Dependency\DI;
use xpl\Foundation\RequestInterface as Request;
use xpl\Foundation\RoutableInterface as Routable;
use xpl\Event\Manager as Events;
use xpl\Routing\Router;
use xpl\Routing\Exception\MethodNotAllowed;
use xpl\Routing\Exception\NotFound;
use xpl\Http\Exception\MethodNotAllowed as HTTP405;
use xpl\Http\Exception\NotFound as HTTP404;

class Dispatcher extends \xpl\Web\Dispatcher implements DiAwareInterface 
{
	
	/**
	 * @var \xpl\Dependency\DI
	 */
	protected $di;
	
	/**
	 * @param \xpl\Dependency\DI
	 */
	public function setDI(DI $di) {
		$this->di = $di;
	}
	
	/**
	 * @return \xpl\Dependency\DI
	 */
	public function getDI() {
		return isset($this->di) ? $this->di : null;
	}
	
	public function __invoke(Router $router, Request $request, Routable $routable, Events $events = null) {
		
		try {
			
			$resource = $this->prepareRouter($router, $routable);
			
			if ($match = $this->routeRequest($router, $request)) {
				
				$route = $match->getRoute();
				
				$controller = $resource->getController();
				$controller->setRequest($request);
				$controller->setRoute($route);
				
				if ($controller instanceof DiAwareInterface) {
					$controller->setDI($this->di);
				}
				
				if ($routable instanceof Application\App) {
					
					$controller->setApp($routable);
					
					if (isset($events)) {
						$events->trigger('dispatch', $routable, $route, $request, $controller);
					}
					
					$routable->onRoute($route, $request, $controller);
				}
				
				return $this->call(array($controller, $route->getAction()), $route->getParams());
			}
		
		} catch (MethodNotAllowed $e) {
			$http_e = new HTTP405(null, 405, $e);
			$http_e->setAllowedValues($e->getAllowedValues());
			throw $http_e;
		
		} catch (NotFound $e) {
			throw new HTTP404($e->getMessage(), 404, $e);
		}
	}

}
