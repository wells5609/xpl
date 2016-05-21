<?php

namespace Xpl\Collection;


class Config implements \Xpl\Collection\MapInterface
{

    /**
     * Constructor.
     *
     * @param array|\Traversable $data [Optional]
     * @return void 
     */
    public function __construct($data = null) {}

    /**
     * Checks whether the collection is empty (i.e. has 0 elements).
     *
     * @return boolean 
     */
    public function isEmpty() {}

    /**
     * Returns the number of properties.
     *
     * @return int 
     */
    public function count() {}

    /**
     * Returns the object data as an array.
     *
     * @return array 
     */
    public function toArray() {}

    /**
     * Adds multiple entries to the Config.
     *
     * @param array|\Traversable $data 
     * @return \Xpl\Collection\Config 
     */
    public function addAll($data) {}

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
     * Returns an item's key in the structure
     *
     * @param mixed $value 
     * @return mixed 
     */
    public function indexOf($value) {}

    /**
     * Whether the structure contains the given value.
     *
     * @param mixed $value 
     * @return boolean 
     */
    public function contains($value) {}

    /**
     * Returns an iterator for the object.
     *
     * @return \ArrayIterator 
     */
    public function getIterator() {}

    /**
     * Returns a property value using array access.
     *
     * @param string $index 
     * @return mixed 
     */
    public function offsetGet($index) {}

    /**
     * Sets a property value.
     *
     * @param string $index 
     * @param mixed $value 
     */
    public function offsetSet($index, $value) {}

    /**
     * Checks if a property exists.
     *
     * @param string $index 
     * @return boolean 
     */
    public function offsetExists($index) {}

    /**
     * Sets a property to null.
     *
     * @param string $index 
     */
    public function offsetUnset($index) {}

    /**
     * Get an item using "dot" notation.
     *
     * @param string $key 
     * @param mixed $defaultValue 
     * @return mixed 
     */
    public function get($key, $defaultValue = null) {}

    /**
     * Set an item using "dot" notation.
     *
     * @param string $key 
     * @param mixed $value 
     * @return \Xpl\Collection\Config 
     */
    public function set($key, $value) {}

    /**
     * Check if an item exists using "dot" notation.
     *
     * @param string $key 
     * @return bool 
     */
    public function has($key) {}

    /**
     * Returns a Config object for a given component.
     *
     * @param string $component 
     * @return \Xpl\Collection\Config 
     */
    public function getConfig($component) {}

    /**
     * @param mixed $key 
     */
    public function __get($key) {}

    /**
     * @param mixed $key 
     */
    public function __isset($key) {}

    /**
     * @param mixed $key 
     * @param mixed $value 
     */
    public function __set($key, $value) {}

    /**
     * @param mixed $key 
     */
    public function __unset($key) {}

    /**
     * Serializes the object.
     *
     * @return string 
     */
    public function serialize() {}

    /**
     * Restores the object from a serial string.
     *
     * @param string $serial 
     * @return void 
     */
    public function unserialize($serial) {}

    /**
     * Restores the state of a Config object.
     *
     * @param array $data 
     * @return Config 
     */
    public static function __set_state($data) {}

    /**
     * Provides Zephir compatibility for "new static()" construct.
     *
     * @param array $data 
     * @return \Xpl\Collection\Config 
     */
    protected function newStatic($data = null) {}

}
