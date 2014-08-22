<?php

namespace xpl\Component\Http\Header;

class AcceptLanguage extends NegotiatedHeader {
	
	/**
	 * Additional check for prefix matches.
	 */
	protected function nomatch(array &$results, array $accepted) {
		
		$accept = array();
		
		foreach($accepted as $key => $val) {
			$accept[substr($key, 0, 2)] = $key;
		}
		
		$found = array();
		
		foreach($this->values as $value) {
			$prefix = substr($value->value, 0, 2);
			if (isset($accept[$prefix])) {
				$i = (int)($value->quality*90);
				$found[$i] = $prefix;
				$results[$i] = $accept[$prefix];
			}
		}
		
		if (! empty($found)) {
			ksort($found);
			$first = array_shift($found);
			return $accept[$first];
		}
	}
	
}
