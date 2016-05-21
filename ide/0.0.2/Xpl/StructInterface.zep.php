<?php

namespace Xpl;

interface StructInterface extends \Xpl\Arrayable, \Countable, \IteratorAggregate, \Serializable
{

    /**
     * Imports data into the structure
     *
     * @throws \Xpl\ImmutableException if object data is immutable
     * @param mixed $data 
     */
	public function import($data);

    /**
     * Whether the structure is empty
     *
     * @return boolean 
     */
	public function isEmpty();

    /**
     * Whether the structure contains the given value
     *
     * @param mixed $value 
     * @return boolean 
     */
	public function contains($value);

}
