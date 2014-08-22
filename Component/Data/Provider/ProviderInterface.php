<?php

namespace xpl\Component\Data\Provider;

use xpl\Component\Data\AdapterInterface;

interface ProviderInterface {
	
	public function setAdapter(AdapterInterface $adapter);
	
	public function getAdapter();
	
	public function getEntityClass();
	
	public function getCollectionClass();
	
	public function fetchOne(array $conditions);
	
	public function fetchAll(array $conditions = array());
	
	/**
	 * Creates an object from data.
	 * 
	 * Uses the model's class, if set, otherwise the standard model.
	 * 
	 * @param mixed $data Object data.
	 * @return \Orm\Model Instance of data model.
	 */
	public function createEntity(array $data);
	
	public function createCollection(array $data);
	
	public function isReadOnly();
	
}
