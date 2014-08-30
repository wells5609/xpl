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
			return new \xpl\Framework\Web\Response($di['request']);
		});
		
		$this->register('dbal', function ($di) {
			return new \xpl\Database\ConnectionPool($di['env']->getPath('env'));
		});
		
		$this->register('router', function () {
			return new \xpl\Routing\Router();
		});
		
		$this->register('api', function () {
			return new \xpl\Framework\Api\Manager();
		});
		
		$this->register('web_kernel', 'xpl\Framework\WebKernel');
		$this->register('events', 'xpl\Event\Manager');
		$this->register('services', 'xpl\Data\Service\Registry');
	}
	
}
