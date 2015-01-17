<?php

namespace xpl\Web\Response;

class Jsonp implements TypeInterface {
	
	protected $mimetype = 'application/json';
	
	protected $callback_param = 'callback';
	
	public function getName() {
		return 'jsonp';
	}
	
	public function format($body) {
			
		$cbParam = $this->getCallbackParam();
		
		if (empty($_GET[$cbParam])) {
			$json = new Json();
			return $json->format($body);
		}
		
		$callback = filter_var($_GET[$cbParam], FILTER_SANITIZE_STRING, FILTER_FLAG_STRIP_HIGH|FILTER_FLAG_STRIP_BACKTICK);
		
		$this->mimetype = 'text/javascript';
		
		if (is_object($body) && ! $body instanceof \JsonSerializable) {
			$body = method_exists($body, 'toArray') ? $body->toArray() : get_object_vars($body);
		
		} else if (is_scalar($body)) {
			$body = array('content' => $body);
		}
	
		return $callback.'('.json_encode($body, JSON_NUMERIC_CHECK).')';
	}
	
	public function getMimetype() {
		return $this->mimetype;
	}
	
	public function setCallbackParam($val) {
		$this->callback_param = $val;
	}
	
	public function getCallbackParam() {
		return $this->callback_param;
	}
	
}
