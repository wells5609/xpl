<?php

namespace xpl\Data\Provider;

use xpl\Data\AdapterInterface;

abstract class AbstractProvider implements ProviderInterface {
	
	protected $adapter;
	
	abstract public function fetchOne(array $conditions);
	
	abstract public function fetchAll(array $conditions = array());
	
	public function getEntityClass() {
		return 'xpl\Common\Object';
	}
	
	public function getCollectionClass() {
		return 'xpl\Common\Storage\Collection';
	}
	
	public function setAdapter(AdapterInterface $adapter) {
		$this->adapter = $adapter;
	}
	
	public function setDataSourceAdapter(AdapterInterface $adapter) {
		$this->setAdapter($adapter);
	}
	
	public function getAdapter() {
		
		if (! isset($this->adapter)) {
			throw new \RuntimeException("Adapter is not set.");
		}
		
		return $this->adapter;
	}
	
	/**
	 * Maps a stored entity to an object.
	 * 
	 * @param array $data Entity data.
	 * @return \xpl\Common\Object Instance of data model.
	 */
	public function createEntity(array $data) {
		
		$class = $this->getEntityClass();
		
		return new $class($data);
	}
	
	/**
	 * Maps multiple stored entities to an object containing Entities.
	 * 
	 * @param array $data Entity data.
	 * @return \xpl\Common\Storage\Collection Instance of data model.
	 */
	public function createCollection(array $objects) {
			
		$class = $this->getCollectionClass();
		
		$data = array_map(array($this, 'createEntity'), $objects);
		
		return new $class($data);
	}
	
}
