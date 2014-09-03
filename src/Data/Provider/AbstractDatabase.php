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
	
	public function fetchOne(array $conditions, $bool_operator = 'AND') {
			
		if ($data = $this->table->fetch($conditions, $bool_operator)) {
			return $this->createEntity((array)$data);
		}
		
		return null;
	}
	
	public function fetchAll(array $conditions = array(), $bool_operator = 'AND') {
		
		if ($data = $this->table->fetchAll($conditions, $bool_operator)) {
			return $this->createCollection((array)$data);
		}
		
		return null;
	}
	
	public function fetchAllLike(array $conditions = array(), $bool_operator = 'AND') {
		
		if ($data = $this->table->fetchAllLike($conditions, $bool_operator)) {
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
