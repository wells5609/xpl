<?php

namespace Xpl;

/**
 * Contract for a collection.
 */
interface Collection extends \Xpl\Arrayable, \Countable, \Serializable
{

    /**
     * Checks whether the collection is empty (i.e. has 0 elements).
     *
     * @return boolean 
     */
    public function isEmpty();

    /**
     * Checks whether the collection contains the given value.
     *
     * @param mixed $value 
     * @return boolean 
     */
    public function contains($value);

    /**
     * Adds all the elements of data into the collection.
     *
     * @param mixed $data 
     */
    public function addAll($data);

}
