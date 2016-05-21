<?php

namespace Xpl\Collection;

/**
 * Contract for a Set data structure
 * In a set, the order of items is insignificant, and duplicate items are not permitted.
 *
 * @link http://en.wikipedia.org/wiki/Set_(abstract_data_type)
 */
interface SetInterface extends \Xpl\Collection, \Iterator
{

    /**
     * Add a value to the set.
     * If the item already exists, a \RuntimeException must be thrown.
     *
     * @throws \RuntimeException if the value already exists in the set
     * @param mixed $value 
     */
    public function add($value);

    /**
     * Removes a value from the set.
     * If the item does not exist, a \OutOfBoundsException must be thrown.
     *
     * @throws \OutOfBoundsException if the value does not exist in the set
     * @param mixed $value 
     */
    public function remove($value);

}
