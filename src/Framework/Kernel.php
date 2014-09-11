<?php

namespace xpl\Framework;

class Kernel 
{
	
	protected $di;
	protected $app;
	
	public function __construct(DI $di) {
		$this->di = $di;
	}
	
	public function di($var = null) {
		return isset($var) ? $this->di[$var] : $this->di;
	}
	
	public function getApp() {
		return isset($this->app) ? $this->app : null;
	}
	
	/**
	 * Boots and sets the app.
	 */
	public function start() {
		
		$bundles = $this->di['bundles'];
		
		$bundles->boot('app.'.APPID);
		
		$this->app = $bundles->getBundle('app.'.APPID);
		
		/** @event start */
		$this->di['events']->trigger('start', $this->app, $this->di);
	}
	
	/**
	 * Routes the request.
	 */
	public function run() {
	
		$events = $this->di['events'];
		
		try {
			/* 
			 * Route the request and invoke the controller.
			 * 
			 * Catch API exceptions in or prior to the controller, and catch HTTP 
			 * exceptions in or prior to the "respond" event.
			 */
			try {
				
				$body = $this->di['dispatcher']->__invoke(
					$this->di['router'], 
					$this->di['request'], 
					$this->app, 
					$events
				);
				
				$this->di['response']->setBody($body);
			
			} catch (\xpl\Web\Api\Exception $e) {
				
				/** @event api_error */
				$events->trigger('api_error', $e, $this->app, $this->di);
			}
			
			/** @event respond */
			$events->trigger('respond', $this->app, $this->di);
			
		} catch (\xpl\Http\Exception $e) {
				
			/** @event http_error */
			$events->trigger('http_error', $e, $this->app, $this->di);
		}
	}
	
	/**
	 * Sends the response.
	 */
	public function complete() {
		
		/** @event complete */
		$this->di['events']->trigger('complete', $this->app, $this->di);
		
		$this->di['response']->send();
	}
	
}
