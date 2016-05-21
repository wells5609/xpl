<?php

namespace Xpl\Collection;

/**
 * Implementation of an object set using SplObjectStorage.
 */
class ObjectSet extends \SplObjectStorage implements \Xpl\Collection\SetInterface
{

    /**
     * Add a value to the set if it does not exist.
     *
     * @param mixed $value 
     */
    public function add($value) {}

    /**
     * Removes a value from the set.
     *
     * @param mixed $value 
     */
    public function remove($value) {}

    /**
     * @return bool 
     */
    public function isEmpty() {}

    /**
     * @return array 
     */
    public function toArray() {}

    /**
     * @param mixed $data 
     */
    public function addAll($data) {}

}
