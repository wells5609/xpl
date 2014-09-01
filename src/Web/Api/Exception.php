<?php

namespace xpl\Web\Api;

class Exception extends \xpl\Foundation\Exception {
	
	public function report(Manager $api_manager) {
		$api_manager->reportError($this);
	}
	
}
