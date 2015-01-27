<?php

namespace xpl\Api;

class Exception extends \xpl\Foundation\Exception {
	
	protected $httpStatusCode;
	
	public function setHttpStatus($code) {
		$this->httpStatusCode = (int)$code;
	}
	
	public function getHttpStatus() {
		return $this->httpStatusCode;
	}
	
	public function hasHttpStatus() {
		return isset($this->httpStatusCode);
	}
	
	public function report(Manager $api_manager) {
		$api_manager->reportError($this);
	}
	
}
