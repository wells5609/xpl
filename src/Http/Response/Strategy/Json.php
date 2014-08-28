<?php

namespace xpl\Http\Response\Strategy;

use xpl\Http\Response\FormatStrategyInterface;

class Json implements FormatStrategyInterface {
	
	public function format(\xpl\Http\Response $response) {
		
		$body = $response->getBody();
		
		if (is_object($body) && ! $body instanceof \JsonSerializable) {
			$body = method_exists($body, 'toArray') ? $body->toArray() : (array)$body;
		
		} else if (is_scalar($body)) {
			$body = array('content' => $body);
		}
		
		$flags = JSON_NUMERIC_CHECK|JSON_FORCE_OBJECT;
		
		if (isset($_REQUEST['dev'])) {
			$flags |= JSON_PRETTY_PRINT;
		}
		
		return json_encode($body, $flags);
	}
	
	public function getMimetype() {
		return 'application/json';
	}
	
}
