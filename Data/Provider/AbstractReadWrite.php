<?php

namespace xpl\Data\Provider;

abstract class AbstractReadWrite extends AbstractProvider implements ReadWriteInterface {
	
	abstract public function insert(array $data);
	
	abstract public function update(array $data, array $conditions);
	
	abstract public function delete(array $conditions);
	
	final public function isReadOnly() {
		return false;
	}
	
}
