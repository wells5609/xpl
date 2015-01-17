<?php

namespace xpl\Api;

class Exception extends \xpl\Foundation\Exception {
	
	protected $httpStatusCode;
	
	public function setHttpStatus($statusCode) {
		$this->httpStatusCode = (int)$statusCode;
	}
	
	public function getHttpStatus() {
		return isset($this->httpStatusCode) ? $this->httpStatusCode : null;
	}
	
	public function report(Manager $api_manager) {
		$api_manager->reportError($this);
	}
	
}
