<?php

namespace xpl\Framework;

class DI extends \xpl\Dependency\DI {
	
	public function __construct() {
		
		$this['cache'] = \xpl\Cache\Cache::instance();
		
		$this['session'] = \xpl\Session\Session::instance();
		
		$this['bundles'] = new BundleManager();
		
		$this['events'] = new \xpl\Event\Manager();
		
		$this['router'] = new \xpl\Routing\Router();
		
		$this['dispatcher'] = new Dispatcher();
		
		$this['kernel'] = new Kernel($this);
		
		$this['request'] = function ($di) {
			$request = \xpl\Web\Request::createFromGlobals();
			$request->setSession($di['session']);
			return $request;
		};
		
		$this['response'] = function ($di) {
			return new \xpl\Web\Response($di['request']);
		};
		
		$this['dbal'] = function ($di) {
			return new \xpl\Database\ConnectionPool($di['env']->getPath('env'));
		};
		
		$this['services'] = function () {
			return new \xpl\Data\Service\Registry;
		};
		
		$this['api'] = function () {
			return new \xpl\Web\Api\Manager;
		};
		
		$this['resource.factory'] = function () {
			return new \xpl\Routing\Resource\Factory;
		};
		
		$this['url'] = function ($di) {
			return new \xpl\Utility\Url($di['request']->getUri(), $di['request']->getQuery());
		};
		
	}
	
}
