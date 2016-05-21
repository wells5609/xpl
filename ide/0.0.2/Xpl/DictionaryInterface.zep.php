<?php

namespace Xpl;

interface DictionaryInterface extends \Xpl\StructInterface, \ArrayAccess, \JsonSerializable
{

    /**
     * Returns an item's key in the structure
     *
     * @param mixed $value 
     * @return string|boolean 
     */
	public function indexOf($value);

    /**
     * Returns an array of keys
     *
     * @return array 
     */
	public function keys();

    /**
     * Returns an array of values
     *
     * @return array 
     */
	public function values();

    /**
     * Returns an item by key
     *
     * @param string $key 
     * @param string  
     * @return mixed 
     */
	public function get($key);

    /**
     * Sets an item by key
     *
     * @param string $key 
     * @param mixed $value 
     * @param string  
     */
	public function set($key, $value);

    /**
     * Whether the item given by key exists
     *
     * @param string $key 
     * @param string  
     * @return boolean 
     */
	public function has($key);

    /**
     * Removes an item by key
     *
     * @param string $key 
     * @param string  
     */
	public function remove($key);

    /**
     * Applies a callback function to each item in the object
     *
     * @param callable $callback 
     * @param mixed $userdata [Optional]
     */
	public function walk($callback, $userdata = null);

    /**
     * Applies a callback function to each item and returns a new object containing the items.
     *
     * @param callable $callback 
     * @return \Xpl\DictionaryInterface 
     */
	public function map($callback);

    /**
     * Filters the elements using a callback function and returns a new object.
     *
     * @param callable $callback 
     * @return \Xpl\DictionaryInterface 
     */
	public function filter($callback);

    /**
     * Merges the given items into the object.
     *
     * @param mixed $data 
     */
	public function merge($data);

    /**
     * Replaces items in the object with those given.
     *
     * @param mixed $data 
     */
	public function replace($data);

}
