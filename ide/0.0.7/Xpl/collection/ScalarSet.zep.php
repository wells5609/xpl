<?php

namespace Xpl\Collection;


class ScalarSet extends \SplObjectStorage implements \Xpl\Collection\SetInterface
{

    /**
     * @param mixed $value 
     */
    public function add($value) {}

    /**
     * @param mixed $value 
     * @param mixed $inf 
     */
    public function remove($value, $inf = null) {}

    /**
     * @param mixed $value 
     * @param mixed $inf 
     */
    public function attach($value, $inf = null) {}

    /**
     * @param mixed $value 
     * @param mixed $inf 
     */
    public function detach($value, $inf = null) {}

    /**
     * @param mixed $value 
     * @return bool 
     */
    public function contains($value) {}

    /**
     * @param mixed $obj 
     * @return string 
     */
    public function getHash($obj) {}

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

    /**
     * @param mixed $value 
     * @return object 
     */
    public static function cast($value) {}

}
