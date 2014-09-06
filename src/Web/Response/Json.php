<?php

namespace xpl\Web\Response;

class Json implements TypeInterface {
	
	protected $dev_param = 'dev';
	
	public function getName() {
		return 'json';
	}
	
	public function format($body) {
		
		if (is_object($body) && ! $body instanceof \JsonSerializable) {
			$body = method_exists($body, 'toArray') ? $body->toArray() : get_object_vars($body);
		
		} else if (is_scalar($body)) {
			$body = array('content' => $body);
		}
		
		$flags = JSON_NUMERIC_CHECK|JSON_FORCE_OBJECT;
		
		if (isset($_GET[$this->getDevParam()])) {
			$flags |= JSON_PRETTY_PRINT;
		}
		
		return json_encode($body, $flags);
	}
	
	public function getMimetype() {
		return 'application/json';
	}
	
	public function setDevParam($val) {
		$this->dev_param = $val;
	}
	
	public function getDevParam() {
		return $this->dev_param;
	}
	
}
