<?php

namespace xpl\Framework\Dependency;

class Container extends \xpl\Dependency\Container {
	
	public function __construct() {
		
		$this->register('request', function ($di) {
			$request = \xpl\Web\Request::createFromGlobals();
			$request->setSession($di['session']);
			return $request;
		});
		
		$this->register('response', function ($di) {
			return new \xpl\Web\Response($di['request']);
		});
		
		$this->register('dispatcher', function () {
			return new \xpl\Web\Dispatcher();
		});
		
		$this->register('api', function () {
			return new \xpl\Web\Api\Manager();
		});
		
		$this->register('router', function () {
			return new \xpl\Routing\Router();
		});
		
		$this->register('dbal', function ($di) {
			return new \xpl\Database\ConnectionPool($di['env']->getPath('env'));
		});
		
		$this->register('web_kernel', 'xpl\Framework\WebKernel');
		$this->register('events', 'xpl\Event\Manager');
		$this->register('services', 'xpl\Data\Service\Registry');
	}
	
}
