<?php

namespace xpl\Database\Config;

abstract class AbstractConfig extends \xpl\Common\PropertyAwareObject {
	
	public function __construct(array $args = null) {
		if (isset($args)) {
			$this->configure($args);
		}
	}
	
	public function configure(array $args) {
		foreach($args as $key => $val) {
			$this->set($key, $val);
		}
	}
	
}
