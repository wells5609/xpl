<?php

namespace xpl\Http\Response\Strategy;

use xpl\Http\Response\FormatStrategyInterface;

class Jsonp implements FormatStrategyInterface {
	
	protected $mimetype = 'application/json';
	
	public function format(\xpl\Http\Response $response) {
		
		if (empty($_REQUEST['callback'])) {
			$json = new Json();
			return $json->format($response);
		}
		
		$callback = esc_ascii($_REQUEST['callback']);
		
		$this->mimetype = 'text/javascript';
		
		$body = $response->getBody();
		
		if (is_object($body) && ! $body instanceof \JsonSerializable) {
			$body = method_exists($body, 'toArray') ? $body->toArray() : (array)$body;
		
		} else if (is_scalar($body)) {
			$body = array('content' => $body);
		}
	
		return $callback.'('.json_encode($body, JSON_NUMERIC_CHECK).')';
	}
	
	public function getMimetype() {
		return $this->mimetype;
	}
	
}
