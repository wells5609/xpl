<?php

namespace xpl\Component\Routing;

interface DispatchableInterface {
	
	public function dispatch($http_method, $request_uri);
	
}
