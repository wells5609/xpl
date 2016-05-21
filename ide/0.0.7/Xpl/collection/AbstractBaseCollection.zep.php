<?php

namespace Xpl\Collection;

/**
 * Abstract implementation of Collection.
 */
abstract class AbstractBaseCollection implements \Xpl\Collection
{
    /**
     * @var array
     */
    protected $items = array();


    /**
     * Returns the structure as a native PHP array.
     *
     * @return array 
     */
    public function toArray() {}

    /**
     * Whether the structure is empty.
     *
     * @return boolean 
     */
    public function isEmpty() {}

    /**
     * Whether the structure contains the given value.
     *
     * @param mixed $value 
     * @return boolean 
     */
    public function contains($value) {}

    /**
     * Returns the number of items in the structure
     *
     * @return int 
     */
    public function count() {}

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
