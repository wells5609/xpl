<?php

namespace Xpl;

class Collection implements \Countable, \IteratorAggregate, \Serializable
{

    protected $_data = array();

    protected $_keys = array();

    protected $datatype;

    /**
     * Constructor
     *
     * @param array|object $data [Optional]
     */
	public function __construct($data = null) {}

    /**
     * Import data into the object
     *
     * @param mixed $data 
     * @param mixed  
     */
	public function import($data) {}

    /**
     * @param mixed $item 
     * @param mixed $key 
     */
	public function add($item, $key = null) {}

    /**
     * @param mixed $item 
     * @param mixed $key 
     */
	public function set($item, $key = null) {}

    /**
     * @param mixed $key 
     */
	public function get($key) {}

    /**
     * @param mixed $key 
     * @return bool 
     */
	public function has($key) {}

    /**
     * @param mixed $key 
     */
	public function remove($key) {}

    /**
     * Returns the structure as a native PHP array
     *
     * @return array 
     */
	public function toArray() {}

    /**
     * Whether the structure is empty
     *
     * @return boolean 
     */
	public function isEmpty() {}

    /**
     * Whether the structure contains the given value
     *
     * @param mixed $value 
     * @return boolean 
     */
	public function contains($value) {}

    /**
     * Returns the index of an item in the collection.
     *
     * @param mixed $item 
     * @return int|boolean 
     */
	public function indexOf($item) {}

    /**
     * Returns the number of items in the structure
     *
     * @return int 
     */
	public function count() {}

    /**
     * Returns an iterator for the structure
     *
     * @return \Iterator 
     */
	public function getIterator() {}

    /**
     * Serializes the object data
     *
     * @return string 
     */
	public function serialize() {}

    /**
     * Constructs the object from a serialized string
     *
     * @param string $serialized 
     */
	public function unserialize($serialized) {}

    /**
     * @return string|null 
     */
	public function getType() {}

    /**
     * @param mixed $item 
     * @return bool 
     */
	public function isValid($item) {}

    /**
     * @param mixed $arg 
     * @return string 
     */
	public static function getTypeName($arg) {}


	private function reindex() {}

}
