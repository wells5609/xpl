<?php

namespace xpl\Data\Service;

abstract class AbstractService implements ServiceInterface {
	
	abstract public function getProvider();
	
	abstract public function isReadOnly();
	
	public function getOne(array $conditions = array()) {
		return $this->getProvider()->fetchOne($conditions);
	}
	
	public function getAll(array $conditions = array()) {
		return $this->getProvider()->fetchAll($conditions);
	}
	
}
