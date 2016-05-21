<?php

namespace Xpl\Collection;

/**
 * Contract for a map data structure.
 * Each item in a map is identified by a unique key.
 *
 * @method get(key);
 * @method set(key, value);
 * @method has(key);
 * @method remove(key);
 */
interface MapInterface extends \Xpl\Collection, \ArrayAccess, \IteratorAggregate
{

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
     * Returns an item's key in the structure
     *
     * @param mixed $value 
     * @return mixed 
     */
    public function indexOf($value);

}
