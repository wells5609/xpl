<?php

namespace xpl\Data\Provider;

use xpl\Database\PdoAdapter;

class Database extends AbstractDatabase 
{
	
	protected $table_name;
	protected $entity_class = 'xpl\Common\Object';
	protected $collection_class = 'xpl\Common\Storage\Collection';
	
	public function __construct(PdoAdapter $adapter, $table_name, $entity_class = null, $collection_class = null) {
		
		$this->table_name = $table_name;
		
		parent::__construct($adapter);
		
		if (isset($entity_class)) {
			$this->entity_class = $entity_class;
		}
		
		if (isset($collection_class)) {
			$this->collection_class = $collection_class;
		}
	}
		
	public function getTableName() {
		return $this->table_name;
	}
	
	public function getEntityClass() {
		return $this->entity_class;
	}
	
	public function getCollectionClass() {
		return $this->collection_class;
	}
	
}
