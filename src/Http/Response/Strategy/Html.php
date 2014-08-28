<?php

namespace xpl\Http\Response\Strategy;

use xpl\Http\Response\FormatStrategyInterface;

class Html implements FormatStrategyInterface {
	
	public function format(\xpl\Http\Response $response) {
		
		$body = $response->getBody();
		
		if (! is_scalar($body) && ! method_exists($body, '__toString')) {
			throw new \InvalidArgumentException("HTML response must be string or object with __toString method.");
		}
		
		return (string) $body;
	}
	
	public function getMimetype() {
		return 'text/html';
	}
	
}
