<?php

namespace xpl\Data\Provider;

use xpl\Database\PdoAdapter;

abstract class AbstractDatabase extends AbstractReadWrite {
	
	/**
	 * @var \xpl\Database\Table
	 */
	protected $table;
	
	/**
	 * @return string Database table name.
	 */
	abstract public function getTableName();
	
	/**
	 * Constructor
	 * 
	 * @param \xpl\Database\PdoAdapter $adapter
	 */
	public function __construct(PdoAdapter $adapter) {
		$this->setAdapter($adapter);
		$this->table = $adapter->table($this->getTableName());
	}
	
	public function fetchOne(array $args) {
			
		if ($data = $this->table->fetch($args)) {
			return $this->createEntity((array)$data);
		}
		
		return null;
	}
	
	public function fetchAll(array $args = array()) {
		
		if ($data = $this->table->fetchAll($args)) {
			return $this->createCollection((array)$data);
		}
		
		return null;
	}
	
	public function insert(array $data) {
		return $this->table->insert($data);
	}
	
	public function update(array $data, array $conditions) {
		return $this->table->update($data, $conditions);
	}
	
	public function delete(array $conditions) {
		return $this->table->delete($conditions);
	}
	
}
