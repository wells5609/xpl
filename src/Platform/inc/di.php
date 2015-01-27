<?php

$di['cache'] = xpl\Cache\Cache::instance();

$di['session'] = xpl\Session\Session::instance();

$di['events'] = new xpl\Event\Manager();

$di['bundles'] = new xpl\Bundle\Manager();

$di['kernel'] = new xpl\Framework\Kernel($di);

$di['request'] = function ($di) {
	$request = xpl\Web\Request::createFromGlobals();
	$request->setSession($di['session']);
	return $request;
};

$di['response'] = function ($di) {
	return new xpl\Web\Response($di['request']);
};

$di['router'] = function (xpl\Routing\Route\Collection $collection) {
	return new xpl\Routing\Router($collection);
};

$di['web.kernel'] = function (xpl\Web\Request $request, xpl\Routing\Router $router) {
	return new xpl\Web\Kernel($request, $router);
};

$di->factory('response.type.html', function ($di) {
	return new xpl\Web\Response\Html($di);
});
$di->factory('response.type.json', function ($di) {
	return new xpl\Web\Response\Json($di);
});
$di->factory('response.type.jsonp', function ($di) {
	return new xpl\Web\Response\Jsonp($di);
});
$di->factory('response.type.xml', function ($di) {
	return new xpl\Web\Response\Xml($di);
});
$di->factory('response.type.api', function ($di) {
	return new xpl\Api\Response\Type($di['api']);
});

$di['dbal'] = function ($di) {
	return new xpl\Database\ConnectionPool($di['env']->getPath('env'));
};

$di['services'] = function () {
	return new xpl\Data\Service\Registry();
};

$di['api'] = function () {
	return new xpl\Api\Manager();
};

$di['url'] = function ($di) {
	return new xpl\Utility\Url($di['request']->getUri(), $di['request']->getQuery());
};
