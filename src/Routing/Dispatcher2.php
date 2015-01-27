<?php

namespace xpl\Routing;

use xpl\Foundation\RequestInterface;
use xpl\Foundation\ControllerInterface;

/**
 * Encapsulates the operations required for routing, including adding resources to the router, 
 * matching the request to a route, and invoking the route's callback function.
 */
class Dispatcher2 
{
	
	/**
	 * @var \xpl\Routing\Router2
	 */
	protected $router;
	
	/**
	 * @var \xpl\Foundation\RequestInterface
	 */
	protected $request;
	
	/**
	 * Constructs the dispatcher using a router and request.
	 * 
	 * @param \xpl\Routing\Router $router
	 * @param \xpl\Foundation\RequestInterface $request
	 */
	public function __construct(Router2 $router, RequestInterface $request) {
		$this->router = $router;
		$this->request = $request;
	}
	
	public function getRouter() {
		return $this->router;
	}
	
	public function getRequest() {
		return $this->request;
	}
	
	/**
	 * Dispatches the request, matching the route and calling its callback.
	 * 
	 * @param \xpl\Routing\RoutableInterface $routable
	 * @return mixed Results of callback function, or null if no matching route.
	 */
	public function __invoke(RoutableInterface $routable) {
		
		if ($this->router->__invoke($this->request->getMethod(), $this->request->getUri())) {
			
			$route = $this->router->getMatchedRoute();
			
			return $this->match($routable, $route);
			
		} else {
			return $this->noMatch($routable);
		}
	}
	
	protected function match(RoutableInterface $routable, Route $route) {
	
		$callback = $this->getCallback($routable, $route);
		
		return call_user_func_array($callback, $route->getParams());
	}
	
	protected function noMatch(RoutableInterface $routable) {
		
		throw new Exception\NotFound;
	}
	
	protected function getCallback(RoutableInterface $routable, Route $route) {
		
		if (is_callable($route->getAction())) {
			return $route->getAction();
		}
		
		$controller = $routable->getResource()->getController();
		
		if ($controller) {
			return array($controller, $route->getAction());
		}
		
		throw new Exception;
	}
	
}
