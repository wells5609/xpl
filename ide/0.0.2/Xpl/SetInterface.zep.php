<?php

namespace Xpl;

interface SetInterface extends \Xpl\StructInterface, \Xpl\Sortable
{

    /**
     * Add a value to the set
     * If the item already exists, a \RuntimeException must be thrown.
     *
     * @throws \RuntimeException if the value already exists in the set
     * @param mixed $value 
     */
	public function add($value);

    /**
     * Removes a value from the set
     * If the item does not exist, a \OutOfBoundsException must be thrown.
     *
     * @throws \OutOfBoundsException if the value does not exist in the set
     * @param mixed $value 
     */
	public function remove($value);

}
