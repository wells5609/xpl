<?php

namespace Xpl\Collection;


interface StackInterface extends \Xpl\Collection\ListInterface
{

    /**
     * Pushes an item onto the stack.
     *
     * @param mixed $value 
     * @param mixed  
     */
    public function push($value);

    /**
     * Pops an item off the stack.
     * If the stack is empty, a \UnderflowException must be thrown.
     *
     * @throws \UnderflowException if the list is empty (contains no items)
     * @return mixed 
     */
    public function pop();

}
