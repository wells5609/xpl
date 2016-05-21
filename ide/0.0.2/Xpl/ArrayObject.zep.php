<?php

namespace Xpl;

class ArrayObject extends \ArrayObject implements \Xpl\DictionaryInterface
{

    /**
     * Constructor
     *
     * @param array|object $input 
     * @param string $iterator_class Iterator classname. Default "ArrayIterator"
     */
	public function __construct($input = array(), $iterator_class = "ArrayIterator") {}

    /**
     * Flags cannot be changed from \ArrayObject::ARRAY_AS_PROPS
     *
     * @throws \Xpl\ImmutableException
     * @param mixed $flags 
     */
	public function setFlags($flags) {}

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
     * Returns an item's key in the structure
     *
     * @param mixed $value 
     * @return string|boolean 
     */
	public function indexOf($value) {}

    /**
     * Returns an item by key
     *
     * @param string $key 
     * @param string  
     * @return mixed 
     */
	public function get($key) {}

    /**
     * Sets an item by key
     *
     * @param string $key 
     * @param mixed $value 
     * @param string  
     */
	public function set($key, $value) {}

    /**
     * Whether the item given by key exists
     *
     * @param string $key 
     * @param string  
     * @return boolean 
     */
	public function has($key) {}

    /**
     * Removes an item by key
     *
     * @param string $key 
     * @param string  
     */
	public function remove($key) {}

    /**
     * Returns an array of keys
     *
     * @return array 
     */
	public function keys() {}

    /**
     * Returns an array of values
     *
     * @return array 
     */
	public function values() {}

    /**
     * Implements \JsonSerializable
     *
     * @return array 
     */
	public function jsonSerialize() {}

    /**
     * Applies a callback function to each item in the object
     *
     * @param callable $callback 
     * @param mixed $userdata [Optional]
     */
	public function walk($callback, $userdata = null) {}

    /**
     * Applies a callback function to each item and returns a new ArrayObject.
     *
     * @param callable $callback 
     * @return \Xpl\ArrayObject 
     */
	public function map($callback) {}

    /**
     * Filters the elements using a callback function and returns a new ArrayObject.
     *
     * @param callable $callback 
     * @return \Xpl\ArrayObject 
     */
	public function filter($callback) {}

    /**
     * Merges items into the object
     *
     * @param mixed $data 
     */
	public function merge($data) {}

    /**
     * Replaces items in the object
     *
     * @param mixed $data 
     */
	public function replace($data) {}

}
