<?php

namespace xpl\Foundation;

use xpl\Routing\RouteInterface;
use xpl\Bundle\BundleInterface;

interface ControllerInterface 
{
	
	public function setRequest(RequestInterface $request);
	
	public function setRoute(RouteInterface $route);
	
	public function setApp(BundleInterface $app);
	
}