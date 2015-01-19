<?php

namespace xpl\Framework;

use xpl\Routing\Router;
use xpl\Routing\RoutableInterface as Routable;
use xpl\Routing\Exception\MethodNotAllowed;
use xpl\Routing\Exception\NotFound;
use xpl\Web\Api\Exception as ApiError;
use xpl\Http\Exception as HttpError;
use xpl\Http\Exception\MethodNotAllowed as HTTP_405;
use xpl\Http\Exception\NotFound as HTTP_404;
use xpl\Foundation\RequestInterface as Request;

class Kernel 
{
	
	protected $di;
	protected $app;
	
	public function __construct(DI $di) {
		$this->di = $di;
	}
	
	public function __get($var) {
		return $this->di[$var];
	}
	
	public function getApp() {
		return isset($this->app) ? $this->app : null;
	}
	
	/**
	 * Runs the application from start to finish.
	 * 
	 * @param string $appID Application ID.
	 */
	public function run($appID) {
		$this->start($appID);
		$this->request();
		$this->send();
	}

	/**
	 * Boots and sets the app.
	 * 
	 * @param string $appID Application ID string.
	 */
	public function start($appID) {
		
		// @event start
		$this->di['events']->trigger('start', $this->di, $appID);
		
		// Boot the app
		$this->di['bundles']->boot("app.{$appID}");
		
		// Set the app
		$this->app = $this->di['bundles']->getBundle("app.{$appID}");
	}
	
	public function request() {
		
		$events = $this->di['events'];
		
		// @event run
		$events->trigger('run', $this->app, $this->di);
		
		// Catch HTTP exceptions in or prior to the "respond" event.
		try {
			// Catch API exceptions in or prior to the controller
			try {
				
				// Route the request and invoke the controller.
				$body = $this->dispatch($this->di['router'], $this->di['request']);
				
				// Set response body
				$this->di['response']->setBody($body);
			
			} catch (ApiError $exception) {
				// @event api_error
				$events->trigger('api_error', $exception, $this->app, $this->di);
			}
			
			// @event respond
			$events->trigger('respond', $this->app, $this->di);
		
		} catch (HttpError $exception) {
			// @event http_error
			$events->trigger('http_error', $exception, $this->app, $this->di);
		}
	}
	
	/**
	 * Sends the response.
	 * 
	 * @return void
	 */
	public function send() {
		
		// @event send
		$this->di['events']->trigger('send', $this->app, $this->di);
		
		// Send response headers & body
		$this->di['response']->send();
	}
	
	protected function dispatch(Router $router, Request $request) {
		
		$events = $this->di['events'];
		
		try {
			
			$resource = $this->app->getResource();
			
			if (! $router->has($resource)) {
				$router->add($resource);
			}
			
			if (! $router($request->getMethod(), $request->getUri())) {
				throw new HTTP_404('Page not found.', 404);
			}
			
			$route = $router->getMatchedRoute();
			
			if ($params	= $route->getParams()) {
				$request->setPathParams($params);
			}
			
			// @event route
			$events->trigger('route', $this->app, $route, $request);
			
			// Get the controller instance
			$controller = $resource->getController();
			
			$controller->setRequest($request);
			$controller->setRoute($route);
			
			// @event dispatch
			$events->trigger('dispatch', $this->app, $route, $request, $controller);
			
			return call_user_func_array(array($controller, $route->getAction()), $params);
		
		} catch (MethodNotAllowed $e) {
			$http405 = new HTTP_405(null, 405, $e);
			$http405->setAllowedValues($e->getAllowedValues());
			throw $http405;
		
		} catch (NotFound $e) {
			throw new HTTP_404($e->getMessage(), 404, $e);
		}
	}

}
