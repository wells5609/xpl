<?php

namespace xpl\Component\Routing;

use xpl\Component\Foundation\RequestInterface;
use xpl\Component\Application\AppInterface;

class Dispatcher {
	
	protected $request;
	protected $route;
	protected $onDispatch;
	
	public function __construct(RequestInterface $request) {
		$this->request = $request;
	}
	
	public function onDispatch(\Closure $call) {
		$this->onDispatch = $call;
		return $this;
	}
	
	public function __invoke(AppInterface $app) {
		
		$resource = $app->useResources() ? $app->getResource() : $app->getComponent('router');
		
		if (! $resource) {
			throw new \RuntimeException("Cannot dispatch: no router/resource returned from App.");
		} else if (! $resource instanceof DispatchableInterface) {
			throw new \InvalidArgumentException('Invalid dispatcher: expecting instance of DispatchableInterface.');
		}
		
		try {
			// Dispatch to get the route
			$this->route = $resource->dispatch($this->request->getMethod(), $this->request->getUri());
			
		} catch (\HttpException $e) {
			
			// if not HTTP, return HTTP message as response
			if (! $this->request->isHttp()) {
				return 'HTTP Error '.$e->getStatusCode().': '.$e->getPublicMessage();
			}
			
			throw $e;
		}
		
		if (! $this->route) {
			throw new \RuntimeException("Route not found.");
		} else if (! $this->route instanceof RouteInterface) {
			throw new \InvalidArgumentException('Invalid route: expecting instance of RouteInterface.');
		}
		
		// Run event(s)
		$app->onDispatch($this->route, $this->request);
		
		isset($this->onDispatch) and call_user_func($this->onDispatch, $this->route);
		
		// Get controller
		$controller = $this->route->getControllerInstance();
		
		if (! $controller instanceof Controller) {
			throw new \InvalidArgumentException('Invalid controller: expecting instance of Controller.');
		}
		
		// Add request and route to controller
		$controller->prepare($this->request, $this->route);
		
		// Invoke with matched route params
		return $this->route->invokeWithParams();
	}
	
	public function dispatch(App $app) {
		return $this($app);
	}
	
	public function getRoute() {
		return isset($this->route) ? $this->route : null;
	}
	
}
