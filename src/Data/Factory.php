<?php

namespace xpl\Data;

class Factory implements FactoryInterface
{
	
	/**
	 * Class to use for entities.
	 * 
	 * @var string
	 */
	protected $entity_class;
	
	/**
	 * Class to use for collections.
	 * 
	 * @var string
	 */
	protected $collection_class;
	
	/**
	 * Constructor. Set the entity and/or collection class.
	 * 
	 * @param string $entity_class [Optional] Entity class.
	 * @param string $collection_class [Optional] Collection class.
	 */
	public function __construct($entity_class = null, $collection_class = null) {
		$this->entity_class = $entity_class ?: 'xpl\\Common\\Object';
		$this->collection_class = $collection_class ?: 'xpl\\Common\\Storage\\Collection';
	}
	
	public function getEntityClass() {
		return $this->entity_class;
	}
	
	public function getCollectionClass() {
		return $this->collection_class;
	}
	
	/**
	 * Creates an object from an array of data.
	 * 
	 * @param array $data Array of entity data.
	 * @return \xpl\Common\Object
	 */
	public function createEntity(array $data) {
		return $this->forge($this->getEntityClass(), $data);
	}
	
	/**
	 * Creates a collection of objects from a 2d array of data.
	 * 
	 * @param array $data 2d array of entity data.
	 * @return \xpl\Common\Storage\Collection
	 */
	public function createCollection(array $data) {
		return $this->forge($this->getCollectionClass(), $this->mapEntities($data));
	}
	
	/**
	 * Maps an array of entity data to an array of objects.
	 * 
	 * @param array $entities 2d array of data.
	 * @return array Array of objects.
	 */
	public function mapEntities(array $entities) {
		return array_map(array($this, 'createEntity'), $entities);
	}
	
	/**
	 * Creates an object of the given class, passing the constructor an array of data.
	 * 
	 * @param string $class Class to create.
	 * @param array $data Array of object data.
	 * @return object
	 */
	public function forge($class, array $data) {
		return new $class($data);
	}
	
}
