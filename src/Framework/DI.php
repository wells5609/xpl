<?php

namespace xpl\Framework;

class DI extends \xpl\Dependency\DI {
	
	public function __construct() {
		
		$this['cache'] = \xpl\Cache\Cache::instance();
		
		$this['session'] = \xpl\Session\Session::instance();
		
		$this['bundles'] = function () {
			return new BundleManager;
		};
		
		$this['request'] = function ($di) {
			$request = \xpl\Web\Request::createFromGlobals();
			$request->setSession($di['session']);
			return $request;
		};
		
		$this['response'] = function ($di) {
			return new \xpl\Web\Response($di['request']);
		};
		
		$this['dispatcher'] = function () {
			return new \xpl\Web\Dispatcher();
		};
		
		$this['api'] = function () {
			return new \xpl\Web\Api\Manager();
		};
		
		$this['router'] = function () {
			return new \xpl\Routing\Router();
		};
		
		$this['dbal'] = function ($di) {
			return new \xpl\Database\ConnectionPool($di['env']->getPath('env'));
		};
		
		$this['url'] = function ($di) {
			return new \xpl\Utility\Url($di['request']->getUri(), $di['request']->getQuery());
		};
		
		$this['services'] = function () {
			return new \xpl\Data\Service\Registry;
		};
		
		$this['events'] = function () {
			return new \xpl\Event\Manager;
		};
	}
	
}
