<?php

namespace Xpl;

class Dictionary extends \Xpl\Struct implements \Xpl\DictionaryInterface
{

    /**
     * Returns an item's key in the structure
     *
     * @param mixed $value 
     * @return string|boolean 
     */
	public function indexOf($value) {}

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
     * Applies a callback function to each item in the object
     *
     * @param callable $callback 
     * @param mixed $userdata [Optional]
     */
	public function walk($callback, $userdata = null) {}

    /**
     * Applies a callback function to each item and returns a new Dictionary containing the items.
     *
     * @param callable $callback 
     * @return \Xpl\Dictionary 
     */
	public function map($callback) {}

    /**
     * Filters the elements using a callback function and returns a new Dictionary.
     *
     * @param callable $callback 
     * @return \Xpl\Dictionary 
     */
	public function filter($callback) {}

    /**
     * Merges the given items into the collection.
     *
     * @param mixed $data 
     */
	public function merge($data) {}

    /**
     * Replaces items in the collection with those given.
     *
     * @param mixed $data 
     */
	public function replace($data) {}

    /**
     * Implements \ArrayAccess
     *
     * @param mixed $index 
     */
	public function offsetGet($index) {}

    /**
     * Implements \ArrayAccess
     *
     * @param mixed $index 
     * @param mixed $newval 
     */
	public function offsetSet($index, $newval) {}

    /**
     * Implements \ArrayAccess
     *
     * @param mixed $index 
     * @return bool 
     */
	public function offsetExists($index) {}

    /**
     * Implements \ArrayAccess
     *
     * @param mixed $index 
     */
	public function offsetUnset($index) {}

    /**
     * Returns the structure as a native PHP array.
     * Implements \JsonSerializable
     *
     * @return array 
     */
	public function jsonSerialize() {}

}
