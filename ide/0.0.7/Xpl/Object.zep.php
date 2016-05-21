<?php

namespace Xpl;


class Object implements \Serializable
{

    /**
     * Indicates whether some other object is "equal to" this one.
     *
     * @param object $obj 
     * @param object  
     * @return boolean 
     */
    public function equals($obj) {}

    /**
     * Returns a unique hash for the object.
     *
     * @return string 
     */
    public function getObjectHash() {}

    /**
     * Returns a new instance of the given object.
     *
     * @param object $obj 
     * @param array $ctorArgs 
     * @param mixed $arg [Optional]
     * @return object 
     */
    public static function valueOf($obj, $ctorArgs = array()) {}

    /**
     * Serializes the object.
     *
     * @return string 
     */
    public function serialize() {}

    /**
     * Unserializes the object.
     *
     * @param string $serial 
     * @return void 
     */
    public function unserialize($serial) {}

}
