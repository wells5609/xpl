<?php

namespace xpl\Routing;

use xpl\Framework\RequestInterface;
use xpl\Framework\ControllerInterface;
use xpl\Bundle\Application\AppInterface;

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
		} else if (! $resource instanceof MatcherInterface) {
			throw new \InvalidArgumentException('Invalid dispatcher: expecting instance of MatcherInterface.');
		}
		
		try {
			// Match the route
			$this->route = $resource->match($this->request->getMethod(), $this->request->getUri());
			
		} catch (\HttpException $e) {
			
			// if not HTTP, return HTTP message as response
			if (! $this->request->isHttp()) {
				return 'HTTP Error '.$e->getStatusCode().': '.$e->getPublicMessage();
			}
			
			throw $e;
		}
		
		if (! $this->route) {
			
			$uri = $this->request->getMethod().': /'.$this->request->getUri();
			
			if ($q = $this->request->getQuery()) {
				$uri .= '?'.$q;
			}
			
			throw new \RuntimeException("Route not found: ".$uri);
		
		} else if (! $this->route instanceof RouteInterface) {
			throw new \InvalidArgumentException('Invalid route: expecting instance of RouteInterface.');
		}
		
		// Run event(s)
		$app->onDispatch($this->route, $this->request);
		
		isset($this->onDispatch) and call_user_func($this->onDispatch, $this->route);
		
		// Get controller
		$controller = $this->route->getControllerInstance();
		
		if (! $controller instanceof ControllerInterface) {
			throw new \InvalidArgumentException('Invalid controller: expecting instance of ControllerInterface.');
		}
		
		// Add request and route to controller
		$controller->setRequest($this->request);
		$controller->setRoute($this->route);
		
		// Invoke with matched route params
		return $this->route->invokeWithParams();
	}
	
	public function dispatch(AppInterface $app) {
		return $this($app);
	}
	
	public function getRoute() {
		return isset($this->route) ? $this->route : null;
	}
	
}
