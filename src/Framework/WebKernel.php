<?php

namespace xpl\Framework;

use xpl\Dependency\ContainerAwareInterface;
use xpl\Dependency\Container;
use xpl\Routing\Exception\MethodNotAllowed;
use xpl\Routing\Exception\RouteException;

class WebKernel implements ContainerAwareInterface {
	
	protected $container;
	
	public function setContainer(Container $container) {
		$this->container = $container;
	}
	
	public function getContainer() {
		return isset($this->container) ? $this->container : null;
	}
	
	public function __invoke(Application\AppInterface $app) {
		
		try {
			
			$di = $this->getContainer();
			
			$router = $di['router'];
			$request = $di['request'];
			
			$router->add($app->getResource());
			
			if ($router($request->getMethod(), $request->getFullUri())) {
				
				$match = $router->getMatch();
				
				$di['events']->trigger('dispatch', $app, $request, $match);
				
				return $match($request, $app);
			}
		
		} catch (MethodNotAllowed $e) {
			$http_e = new \xpl\Http\Exception\MethodNotAllowed(null, 0, $e);
			$http_e->setAllowedValues($e->getAllowedValues());
			throw $http_e;
			
		} catch (RouteException $e) {
			throw new \xpl\Http\Exception\NotFound($e->getMessage(), 0, $e);
		}
			
		return null;
	}
	
}
