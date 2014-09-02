<?php

namespace xpl\WebServices;

class Client {
	
	protected $handler;
	
	public function __construct($handler) {
		
		if (! is_callable($handler)) {
			throw new \InvalidArgumentException("Non-callable client handler given: ".gettype($handler));
		}
		
		$this->handler = $handler;
	}
	
	public function __invoke(RequestInterface $request) {
		
		return call_user_func($this->handler, $request->getUrl());
	}
	
}
