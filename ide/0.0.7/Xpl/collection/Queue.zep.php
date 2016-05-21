<?php

namespace Xpl\Collection;

/**
 * Queue is an extended \SplQueue that implements QueueInterface.
 */
class Queue extends \SplQueue implements \Xpl\Collection\QueueInterface
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

}
