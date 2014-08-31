<?php

namespace xpl\Web\Response;

class Html implements TypeInterface {
	
	public function getName() {
		return 'html';
	}
	
	public function format($body) {
		
		if (empty($body)) {
			return '';
		}
		
		is_callable($body) and $body = call_user_func($body);
		
		if (is_scalar($body) || method_exists($body, '__toString')) {
			return (string) $body;
		}
		
		throw new \InvalidArgumentException("HTML response body must be string(able), given: ".gettype($body));
	}
	
	public function getMimetype() {
		return 'text/html';
	}
	
}
