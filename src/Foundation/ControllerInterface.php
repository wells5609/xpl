<?php

namespace xpl\Foundation;

use xpl\Routing\RouteInterface;

interface ControllerInterface {
	
	public function setRequest(RequestInterface $request);
	
	public function setRoute(RouteInterface $route);
	
	public function setApp(BundleInterface $app);
	
}