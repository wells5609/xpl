<?php

namespace xpl\Framework;

use xpl\Routing\RouteInterface;

interface ControllerInterface {
	
	public function setRequest(RequestInterface $request);
	
	public function setRoute(RouteInterface $route);
	
}
