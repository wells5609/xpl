<?php

namespace xpl\Data\Provider;

use xpl\Data\ProviderInterface;
use xpl\Data\AdapterInterface;
use xpl\Data\FactoryInterface;
use xpl\Data\Factory;

abstract class AbstractProvider implements ProviderInterface 
{
	
	protected $adapter;
	protected $factory;
	
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
	
	public function getAdapter() {
		
		if (! isset($this->adapter)) {
			throw new \RuntimeException("Adapter is not set.");
		}
		
		return $this->adapter;
	}
	
	/**
	 * Set the object factory.
	 * 
	 * @param \xpl\Data\FactoryInterface
	 */
	public function setFactory(FactoryInterface $factory) {
		$this->factory = $factory;
	}
	
	/**
	 * Returns the object factory.
	 * 
	 * If not set at the time called, a xpl\Data\Factory will be created.
	 * 
	 * @return \xpl\Data\FactoryInterface
	 */
	public function getFactory() {
		
		if (! isset($this->factory)) {
			$this->factory = new Factory($this->getEntityClass(), $this->getCollectionClass());
		}
		
		return $this->factory;
	}
	
	/**
	 * Maps a stored entity to an object.
	 * 
	 * @param array $data Entity data.
	 * @return \xpl\Common\Object Instance of data model.
	 */
	public function createEntity(array $data) {
		return $this->getFactory()->createEntity($data);
	}
	
	/**
	 * Maps multiple stored entities to an object containing Entities.
	 * 
	 * @param array $data Entity data.
	 * @return \xpl\Common\Storage\Collection Instance of data model.
	 */
	public function createCollection(array $objects) {
		return $this->getFactory()->createCollection($objects);
	}
	
}
