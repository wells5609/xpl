<?php

namespace xpl\Framework;

use xpl\Cache\Cache;
use xpl\Session\Session;
use xpl\Web\Request;
use xpl\Web\Response;
use xpl\Web\Api\Manager as ApiManager;
use xpl\Routing\Router;
use xpl\Database\ConnectionPool;
use xpl\Data\Service\Registry as ServiceRegistry;
use xpl\Event\Manager as EventManager;
use xpl\Utility\Url;

class DI extends \xpl\Dependency\DI {
	
	public function __construct() {
		
		$this['cache'] = Cache::instance();
		
		$this['session'] = Session::instance();
		
		$this['bundles'] = function () {
			return new BundleManager;
		};
		
		$this['request'] = function ($di) {
			$request = Request::createFromGlobals();
			$request->setSession($di['session']);
			return $request;
		};
		
		$this['response'] = function ($di) {
			return new Response($di['request']);
		};
		
		$this['dispatcher'] = function () {
			return new Dispatcher();
		};
		
		$this['api'] = function () {
			return new ApiManager();
		};
		
		$this['router'] = function () {
			return new Router();
		};
		
		$this['dbal'] = function ($di) {
			return new ConnectionPool($di['env']->getPath('env'));
		};
		
		$this['services'] = function () {
			return new ServiceRegistry;
		};
		
		$this['events'] = function () {
			return new EventManager;
		};
		
		$this['url'] = function ($di) {
			return new Url($di['request']->getUri(), $di['request']->getQuery());
		};
		
	}
	
}
