<?php

namespace xpl\Framework\Dependency;

class Container extends \xpl\Dependency\Container {
	
	public function __construct() {
		
		$this->register('request', function ($di) {
			$request = \xpl\Http\Request::createFromGlobals();
			$request->setSession($di['session']);
			return $request;
		});
		
		$this->register('response', function ($di) {
			return new \xpl\Http\Response($di['request'], $di['response_formatter']);
		});
		
		$this->register('dbal', function ($di) {
			return new \xpl\Database\ConnectionPool($di['env']->getPath('env'));
		});
		
		$this->register('response_formatter', function () {
			return new \xpl\Http\Response\Formatter;
		});
		
		$this->register('router', function () {
			return new \xpl\Routing\Router();
		});
		
		$this->register('web_kernel', 'xpl\\Framework\\WebKernel');
		$this->register('events', 'xpl\Event\Manager');
		$this->register('services', 'xpl\Data\Service\Registry');
	}
	
}
