<?php

namespace xpl\Routing;

use xpl\Foundation\RouteInterface;
use xpl\Foundation\RequestInterface;
use xpl\Foundation\BundleInterface;

class Match {
	
	protected $route;
	protected $requestUri;
	protected $requestMethod;
	
	public function __construct(RouteInterface $route, $request_uri, $request_method) {
		$this->route = $route;
		$this->requestUri = $request_uri;
		$this->requestMethod = $request_method;
	}
	
	public function __invoke(RequestInterface $request, BundleInterface $app = null) {
		
		$controllerClass = $this->route->getGroup()->getController();
		
		$controller = new $controllerClass();
		
		$controller->setRequest($request);
		$controller->setRoute($this->route);
		
		if (isset($app)) {
			$controller->setApp($app);
		}
		
		$callback = array($controller, $this->route->getAction());
		
		return call_user_func_array($callback, $this->route->getParams());
	}
	
	public function getRoute() {
		return $this->route;
	}
	
}
