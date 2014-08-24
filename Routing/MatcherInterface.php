<?php

namespace xpl\Routing;

interface MatcherInterface {
	
	public function match($http_method, $request_uri);
	
}
