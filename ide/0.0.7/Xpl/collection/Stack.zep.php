<?php

namespace Xpl\Collection;

/**
 * Stack is an extended \SplStack that implements StackInterface.
 */
class Stack extends \SplStack implements \Xpl\Collection\StackInterface
{

    /**
     * Constructor.
     *
     * @param mixed $data [Optional]
     */
    public function __construct($data = null) {}

    /**
     * Removes an item by index.
     *
     * @param int $index 
     */
    public function remove($index) {}

    /**
     * Checks whether the object contains a given value.
     *
     * @param mixed $value 
     * @return boolean 
     */
    public function contains($value) {}

    /**
     * Returns the object data as an array.
     *
     * @return array 
     */
    public function toArray() {}

    /**
     * Adds data to the collection.
     *
     * @param mixed $data 
     */
    public function addAll($data) {}

    /**
     * Implements \IteratorAggregate
     *
     * @return \Iterator 
     */
    public function getIterator() {}

}
