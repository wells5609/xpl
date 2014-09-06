<?php

namespace xpl\Data\Service;

interface ServiceInterface {
	
	/**
	 * Returns the datasource provider.
	 * 
	 * @return \xpl\Data\Provider\ProviderInterface
	 */
	public function getProvider();
	
	/**
	 * Returns a single record as a model.
	 * 
	 * @return \xpl\Data\Model\ModelInterface
	 */
	public function getOne(array $conditions = array());
	
	/**
	 * Returns multiple records as a model collection.
	 * 
	 * @return \xpl\Data\Model\Collection
	 */
	public function getAll(array $conditions = array());
	
	/**
	 * Returns true if the service is read-only.
	 * 
	 * @return boolean
	 */
	public function isReadOnly();
	
}
