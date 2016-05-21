<?php

namespace Xpl;


class ClassUtil
{

    const TYPE_CLASS = "class";


    const TYPE_INTERFACE = "interface";


    const TYPE_TRAIT = "trait";


    /**
     * @param mixed $classname 
     * @return object 
     */
    public static function newInstance($classname) {}

    /**
     * @param mixed $classname 
     * @param array $args 
     * @return object 
     */
    public static function newInstanceArgs($classname, $args) {}

    /**
     * @param mixed $classname 
     * @return string 
     */
    public static function classBasename($classname) {}

    /**
     * @param mixed $classname 
     * @return string 
     */
    public static function classNamespace($classname) {}

    /**
     * @param mixed $classname 
     * @return string 
     */
    public static function realclass($classname) {}

    /**
     * @param mixed $obj 
     * @return string|null 
     */
    public static function classType($obj) {}

}
