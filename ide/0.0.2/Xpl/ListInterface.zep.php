<?php

namespace Xpl;

interface ListInterface extends \Xpl\StructInterface
{

    /**
     * Pushes an item onto the list
     *
     * @param mixed $value 
     * @param mixed  
     */
	public function push($value);

    /**
     * Pops an item off the list
     * If the list is empty, a \UnderflowException must be thrown.
     *
     * @throws \UnderflowException if the list is empty (contains no items)
     * @return mixed 
     */
	public function pop();

}
