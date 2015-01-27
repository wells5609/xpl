<?php

namespace xpl\Data\Service;

abstract class AbstractReadWrite extends AbstractService implements ReadWriteInterface {
	
	abstract public function create(array $data);
	
	final public function isReadOnly() {
		return false;
	}
	
	protected function sanitizeField($field, $value) {
		return filter_var($value, FILTER_SANITIZE_STRING, FILTER_FLAG_STRIP_BACKTICK);
	}
	
}
