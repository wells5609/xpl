<?php

namespace xpl\Foundation;

interface RoutableInterface {
	
	public function getResource($name = null);
	
	public function onRoute(RouteInterface $route, RequestInterface $request, ControllerInterface $controller);
	
}
