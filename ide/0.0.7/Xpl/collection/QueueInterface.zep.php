<?php

namespace Xpl\Collection;


interface QueueInterface extends \Xpl\Collection\ListInterface
{

    /**
     * Enqueues an item onto the list.
     *
     * @param mixed $value 
     */
    public function enqueue($value);

    /**
     * Dequeues an item off the list.
     * If the list is empty, a \UnderflowException must be thrown.
     *
     * @throws \UnderflowException if the list is empty (contains no items)
     * @return mixed 
     */
    public function dequeue();

}
