<?php

namespace Xpl;

class TypeDictionary extends \Xpl\Dictionary
{
    /**
     * Allowed item datatype.
     *
     * @var string
     */
    protected $_type;

    /**
     * @param string $datatype 
     */
	public function setType($datatype) {}

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
     * Import data into the object
     *
     * @param mixed $data 
     * @param mixed  
     */
	public function import($data) {}

    /**
     * Sets an item by key
     *
     * @param string $key 
     * @param mixed $value 
     */
	public function set($key, $value) {}

    /**
     * Implements \ArrayAccess
     *
     * @param mixed $index 
     * @param mixed $newval 
     */
	public function offsetSet($index, $newval) {}

    /**
     * Merges the given items into the dictionary.
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
     * @param array $arr 
     * @return bool 
     */
	protected function validateArray($arr) {}

    /**
     * @param mixed $arg 
     * @return string 
     */
	public static function typename($arg) {}

}
