<?php

namespace xpl\WebServices\Yahoo\Yql;

class Response extends \xpl\WebServices\Response {
	
	/**
	 * Constructor.
	 * 
	 * @param mixed $raw Raw response content returned from request execution.
	 * @param \xpl\WebServices\Yahoo\Yql\Request $request
	 */
	public function __construct($raw, Request $request) {
		
		parent::__construct($raw);
		
		if (is_string($raw)) {
			if ('json' === $request->getFormat()) {
				$this->jsonDecode();
			} else {
				$this->xmlDecode();
			}
		}
	}
	
	/**
	 * Returns the response results, if able.
	 * 
	 * @return object
	 */
	public function getResults() {
		
		if (isset($this->results)) {
			return $this->results;
		}
			
		if (isset($this->decoded_data->results)) {
			
			// YQL returns a nested object within "results" with a key
			// set by the table (so we cannot access it generically).
			// There is only ever 1 item, so we just take the first item.
			
			$results = (array) $this->decoded_data->results;
			
			return $this->results = array_shift($results);
		}
	}
	
}
