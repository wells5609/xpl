<?php

namespace xpl\Component\Data\Service;

abstract class AbstractReadWrite extends AbstractService implements ReadWriteInterface {
	
	abstract public function create(array $data);
	
	final public function isReadOnly() {
		return false;
	}
	
}
