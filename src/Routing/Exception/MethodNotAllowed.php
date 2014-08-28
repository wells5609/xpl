<?php

namespace xpl\Routing\Exception;

class MethodNotAllowed extends RouteException {
	
	protected $allowed = array();
	
	public function setAllowedValues(array $values) {
		$this->allowed = $values;
	}
	
	public function getAllowedValues() {
		return $this->allowed;
	}
}
