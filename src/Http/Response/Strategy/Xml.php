<?php

namespace xpl\Http\Response\Strategy;

use xpl\Http\Response\FormatStrategyInterface;

class Xml implements FormatStrategyInterface {
	
	public function format(\xpl\Http\Response $response) {
		
		$body = $response->getBody();
		
		if (is_object($body)) {
				
			if (method_exists($body, 'xmlSerialize')) {
				$body = $body->xmlSerialize();
			
			} else if (method_exists($body, 'toArray')) {
				$body = $body->toArray();
			
			} else {
				$body = (array)$body;
			}
		
		} else if (is_scalar($body)) {
			$body = array('content' => $body);
		}
		
		return xml_write_document($body);
	}
	
	public function getMimetype() {
		return 'text/xml';
	}
	
}
