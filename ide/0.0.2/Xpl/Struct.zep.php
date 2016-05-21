<?php

namespace Xpl;

class Struct implements \Xpl\StructInterface
{
    /**
     * @var array
     */
    protected $_data = array();

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

}
