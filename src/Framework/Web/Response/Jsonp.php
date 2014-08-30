<?php

namespace xpl\Framework\Web\Response;

class Jsonp implements TypeInterface {
	
	protected $mimetype = 'application/json';
	
	public function getName() {
		return 'jsonp';
	}
	
	public function format($body) {
		
		if (empty($_GET['callback'])) {
			$json = new Json();
			return $json->format($body);
		}
		
		$callback = filter_var($_GET['callback'], FILTER_SANITIZE_STRING, FILTER_FLAG_STRIP_HIGH|FILTER_FLAG_STRIP_BACKTICK);
		
		$this->mimetype = 'text/javascript';
		
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
