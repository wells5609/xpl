<?php

namespace xpl\Framework\Dependency;

class Container extends \xpl\Dependency\Container {
	
	public function __construct() {
		
		$this->register('request', function ($di) {
			$request = \xpl\Http\Request::createFromGlobals();
			$request->setSession($di['session']);
			return $request;
		});
		
		$this->register('response_formatter', function () {
			return new \xpl\Http\Response\Formatter;
		});
		
		$this->register('response', function ($di) {
			return new \xpl\Http\Response($di['request'], $di['response_formatter']);
		});
		
		$this->register('http_dispatcher', function ($di) {
			return new \xpl\Routing\Dispatcher($di['request']);
		});
		
		$this->register('dbal', function ($di) {
			return new \xpl\Database\ConnectionPool($di['kernel']->getPath('env'));
		});
		
		$this->register('app_factory', function ($di) { 
			return new \xpl\Bundle\Application\Factory($di['kernel']->getPath('apps'));
		});
		
		$this->register('events', 'xpl\Event\Manager');
		$this->register('services', 'xpl\Data\Service\Registry');
			
	}
	
}
