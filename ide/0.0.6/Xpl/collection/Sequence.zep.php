<?php

namespace Xpl\Collection;

/**
 * Sequence is a list of a fixed size.
 */
class Sequence extends \SplFixedArray implements \Xpl\Collection\ListInterface
{

    /**
     * Constructor.
     *
     * @param mixed $data [Optional]
     */
    public function __construct($data = null) {}

    /**
     * Add a value to the list by index.
     *
     * @param int $index 
     * @param mixed $value 
     */
    public function add($index, $value) {}

    /**
     * Removes a value from the list by index.
     *
     * @param int $index 
     */
    public function remove($index) {}

    /**
     * Checks whether the collection is empty (i.e. has 0 elements).
     *
     * @return boolean 
     */
    public function isEmpty() {}

    /**
     * Checks whether the collection contains the given value.
     *
     * @param mixed $value 
     * @return boolean 
     */
    public function contains($value) {}

    /**
     * Adds all the elements of data into the collection.
     *
     * @param mixed $values 
     * @param mixed $data 
     */
    public function addAll($values) {}

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
