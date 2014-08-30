<?php

namespace xpl\Foundation;

interface ControllerInterface {
	
	public function setRequest(RequestInterface $request);
	
	public function setRoute(RouteInterface $route);
	
	public function setApp(BundleInterface $app);
	
}