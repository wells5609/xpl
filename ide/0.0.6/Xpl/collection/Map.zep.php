<?php

namespace Xpl\Collection;

/**
 * Basic implementation of a Map.
 */
class Map extends \Xpl\Collection\AbstractBaseCollection implements \Xpl\Collection\MapInterface, \JsonSerializable
{

    /**
     * Constructor.
     *
     * @param mixed $data [Optional]
     */
    public function __construct($data = null) {}

    /**
     * Import data into the object.
     *
     * @param mixed $data 
     * @param mixed  
     */
    public function addAll($data) {}

    /**
     * Returns an item by key.
     *
     * @param mixed $key 
     * @param mixed  
     * @return mixed 
     */
    public function get($key) {}

    /**
     * Sets an item by key.
     *
     * @param mixed $key 
     * @param mixed $value 
     * @param mixed  
     */
    public function set($key, $value) {}

    /**
     * Whether the item given by key exists.
     *
     * @param mixed $key 
     * @param mixed  
     * @return boolean 
     */
    public function has($key) {}

    /**
     * Removes an item by key.
     *
     * @param mixed $key 
     * @param mixed  
     */
    public function remove($key) {}

    /**
     * Returns an item's key in the structure.
     *
     * @param mixed $value 
     * @return string|boolean 
     */
    public function indexOf($value) {}

    /**
     * Returns an array of keys.
     *
     * @return array 
     */
    public function keys() {}

    /**
     * Returns an array of values.
     *
     * @return array 
     */
    public function values() {}

    /**
     * Applies a callback function to each item in the object.
     *
     * @param callable $callback 
     * @param mixed $userdata [Optional]
     * @return \Xpl\Collection\MapInterface 
     */
    public function walk($callback, $userdata = null) {}

    /**
     * Applies a callback function to each item and returns a new MapInterface containing the items.
     *
     * @param callable $callback 
     * @return \Xpl\Collection\MapInterface 
     */
    public function map($callback) {}

    /**
     * Filters the elements using a callback function and returns a new MapInterface.
     *
     * @param callable $callback 
     * @return \Xpl\Collection\MapInterface 
     */
    public function filter($callback) {}

    /**
     * Merges the given items into the object.
     *
     * @param mixed $data 
     * @return \Xpl\Collection\MapInterface 
     */
    public function merge($data) {}

    /**
     * Replaces items in the collection with those given.
     *
     * @param mixed $data 
     * @return \Xpl\Collection\MapInterface 
     */
    public function replace($data) {}

    /**
     * Returns an iterator for the object.
     *
     * @return \ArrayIterator 
     */
    public function getIterator() {}

    /**
     * Implements \ArrayAccess
     *
     * @param mixed $index 
     * @return mixed|null 
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
