<?php

namespace xpl\Routing;

use xpl\Framework\RequestInterface;
use xpl\Framework\ControllerInterface;
use xpl\Framework\Application\AppInterface;

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
		}
		
		$error_msg = $this->match($resource);
		
		if (! $this->route && $error_msg) {
			return $error_msg;
		}
		
		// Run event(s)
		$app->onDispatch($this->route, $this->request);
		
		isset($this->onDispatch) and call_user_func($this->onDispatch, $this->route);
		
		$this->prepareController();
		
		// Invoke with matched route params
		return $this->route->invokeWithParams();
	}
	
	public function dispatch(AppInterface $app) {
		return $this($app);
	}
	
	public function getRoute() {
		return isset($this->route) ? $this->route : null;
	}
	
	protected function match(MatcherInterface $resource) {
		
		if (! $resource instanceof MatcherInterface) {
			throw new \InvalidArgumentException('Invalid resource: expecting instance of MatcherInterface.');
		}
		
		try {
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
		
			throw new \RouteException("Route not found: ".$uri);
		}
		
		if (! $this->route instanceof RouteInterface) {
			throw new \InvalidArgumentException('Invalid route: expecting instance of RouteInterface.');
		}
	}
	
	protected function prepareController() {
			
		$controller = $this->route->getControllerInstance();
		
		if (! $controller instanceof ControllerInterface) {
			throw new \InvalidArgumentException('Invalid controller: expecting instance of ControllerInterface.');
		}
		
		// Add request and route to controller
		$controller->setRequest($this->request);
		$controller->setRoute($this->route);
	}
	
}
