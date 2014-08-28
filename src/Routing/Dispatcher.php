<?php

namespace xpl\Routing;

use xpl\Framework\RequestInterface;
use xpl\Framework\Application\AppInterface;

class Dispatcher {
	
	public function __invoke(AppInterface $app, RequestInterface $request, Match $match) {
		
		$app->onDispatch($match->getRoute(), $request);
		
		return $match->__invoke($request);
	}
	
}
