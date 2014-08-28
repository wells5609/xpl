<?php

namespace xpl\Framework\Application;

use xpl\Bundle\BundleInterface;
use xpl\Routing\RouteInterface;
use xpl\Framework\RequestInterface;
use xpl\Http\Response;

interface AppInterface extends BundleInterface 
{
	
	public function setPath($key, $value);
	
	public function getPath($key);
	
	public function setConfig($key, $value);
	
	public function getConfig($key);
	
	public function getComponent($key);
	
	public function useResources($arg = null);
	
	public function onDispatch(RouteInterface $route, RequestInterface $request);
	
	public function onRespond(Response $response);
	
}
