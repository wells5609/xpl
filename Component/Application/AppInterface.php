<?php

namespace xpl\Component\Application;

use xpl\Component\Bundle\BundleInterface;
use xpl\Component\Routing\RouteInterface;
use xpl\Component\Foundation\RequestInterface;

use Http\Response;
use View\Manager as ViewManager;

interface AppInterface extends BundleInterface 
{
	
	public function setPath($name, $path);
	
	public function getPath($name);
	
	public function setConfig($key, $value);
	
	public function getConfig($key);
	
	public function getComponent($name);
	
	public function useResources($arg = null);
	
	public function onDispatch(RouteInterface $route, RequestInterface $request);
	
	public function onRespond(Response $response);
	
	public function initViews(ViewManager $views);
	
		
}
