<?php

namespace xpl\WebServices\Yahoo\Pipes;

class Response extends \xpl\WebServices\Response {
	
	public function getResults() {
		
		if (isset($this->results)) {
			return $this->results;
		}
		
		if (isset($this->decoded_data->value->items)) {
			
			$items = (array) $this->decoded_data->value->items;
			
			foreach($items as &$item) {
				
				$item = (array)$item;
				
				unset($item['y:row']);
				unset($item['y:title']);
				unset($item['y:published']);
				unset($item['pubDate']);
				
				foreach($item as $k => $v) {
					if (0 === strpos($k, 'col_') || 0 === strpos($k, 'yahoo:')) {
						unset($item[$k]);
					}
				}
			}
			
			if (count($items) === 1) {
				$items = array_shift($items);
			}
			
			return $this->results = array_to_object($items, true);
		}
	}
	
}
