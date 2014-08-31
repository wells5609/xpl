<?php

namespace xpl\Framework\Application;

use xpl\Foundation\BundleInterface;
use xpl\Foundation\RouteInterface;
use xpl\Foundation\RequestInterface;
use xpl\Web\Response;

interface AppInterface extends BundleInterface 
{
	
	public function setPath($key, $value);
	
	public function getPath($key);
	
	public function setConfig($key, $value);
	
	public function getConfig($key);
	
	public function getComponent($key);
	
	public function getResource();
	
	public function onRespond(Response $response);
	
}
