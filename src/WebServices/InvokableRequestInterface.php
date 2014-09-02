<?php

namespace xpl\WebServices;

interface InvokableRequestInterface extends RequestInterface {
	
	public function __invoke($callback);
	
}
