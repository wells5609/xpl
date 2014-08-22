<?php

namespace xpl\Component\Database;

use xpl\Component\Data\AdapterInterface;

class Table {
	
	/**
	 * @var string
	 */
	protected $table_name;
	
	/**
	 * @var \xpl\Component\Data\AdapterInterface
	 */
	protected $adapter;
	
	public function __construct($table_name, AdapterInterface $adapter) {
		$this->table_name = $table_name;
		$this->adapter = $adapter;
	}
	
	public function getAdapter() {
		return $this->adapter;
	}
	
	public function fetch(array $conditions = array()) {
		
		$this->getAdapter()->select($this->table_name, $conditions);

		if (! $row = $this->getAdapter()->fetch()) {
			return null;
		}

		return $row;
	}
	
	public function fetchAll(array $conditions = array()) {
			
		$this->getAdapter()->select($this->table_name, $conditions);
		
		return $this->getAdapter()->fetchAll();
	}
	
	public function insert(array $data) {
			return $this->getAdapter()->insert($this->table_name, $data);
	}
	
	public function update(array $data, array $conditions = array()) {
		return $this->getAdapter()->update($this->table_name, $data, $conditions);
	}
	
	public function delete(array $conditions = array()) {
		return $this->getAdapter()->delete($this->table_name, $conditions);
	}
	
}

