<?php

namespace xpl\Framework;

use xpl\Routing\Route;
use xpl\Routing\Router;
use xpl\Routing\RoutableInterface as Routable;
use xpl\Routing\Exception as RouteException;
use xpl\Routing\Exception\MethodNotAllowed;
use xpl\Http\Exception\MethodNotAllowed as HTTP_405;
use xpl\Http\Exception\NotFound as HTTP_404;

class Dispatcher extends \xpl\Routing\Dispatcher
{
	
	protected $onMatch;
	
	public function __invoke(Routable $routable) {
		try {
			return parent::__invoke($routable);
		} catch (RouteException $e) {
			return $this->handleRouteException($e);
		}
	}
	
	public function onMatch(\Closure $callable) {
		$this->onMatch = $callable;
	}
	
	protected function handleRouteException(RouteException $e) {
	
		if ($e instanceof MethodNotAllowed) {
			$exception = new HTTP_405(null, 405, $e);
			$exception->setAllowedValues($e->getAllowedValues());
		} else {
			$exception = new HTTP_404($e->getMessage(), 404, $e);
		}
		
		throw $exception;
	}
	
	protected function prepareRouter(Routable $routable) {
			
		$this->router->add($routable->getResource());
	}
	
	protected function noMatch(Routable $routable) {
		throw new HTTP_404('Page not found.', 404);
	}
	
	protected function match(Routable $routable, Route $route) {
		
		if (isset($this->onMatch)) {
			$function = $this->onMatch->bindTo($this, get_class($this));
			return call_user_func($function, $routable, $route);
		}
	
		if ($params = $route->getParams()) {
			$this->request->setPathParams($params);
		}
		
		$callback = $this->getCallback($routable, $route);
		
		return call_user_func_array($callback, $route->getParams());
	}
	
	protected function getCallback(Routable $routable, Route $route) {
		
		$action = $route->getAction();
		
		// Return a callable route action
		if (is_callable($action)) {
			return $action;
		}
		
		// Try to get the controller instance
		$controller = $routable->getResource()->getController();
		
		if ($controller) {
			
			$controller->setRequest($this->request);
			$controller->setRoute($route);
			$controller->setApp($routable);
			
			return array($controller, $action);
		}
		
		throw new RouteException;
	}
	
	
}
