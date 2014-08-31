<?php

namespace xpl\Database\Config;

abstract class AbstractConfig extends \xpl\Common\Object {
	
	public function __construct(array $args) {
		$this->import($args);
	}
	
}
