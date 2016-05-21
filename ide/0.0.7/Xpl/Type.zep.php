<?php

namespace Xpl;

/**
 * Provides utilities to cast PHP variables to other types.
 */
class Type
{

    const CAST_NUMERIC = 0;


    const FORCE_STRING = 1;


    const IGNORE_ERROR = 5;

    /**
     * The locale-dependent decimal point character.
     *
     * @var string
     */
    static protected $decimalPoint;


    /**
     * Returns an iterator for the given argument.
     *
     * @param mixed $argument 
     * @param mixed $arg 
     * @return array|\Traversable 
     */
    public static function iterate($argument) {}

    /**
     * Converts a value to an array
     *
     * @param mixed $arg 
     * @param mixed  
     * @return array 
     */
    public static function toArray($arg) {}

    /**
     * Converts a value to an object
     *
     * @param mixed $arg 
     * @param mixed  
     * @return object 
     */
    public static function toObject($arg) {}

    /**
     * Converts a value to arrays recursively.
     *
     * @param mixed $arg 
     * @param mixed  
     * @return array 
     */
    public static function toArrays($arg) {}

    /**
     * Converts a value to objects recursively.
     * Objects are converted to instances of stdClass
     *
     * @param mixed $arg 
     * @param mixed  
     * @return object 
     */
    public static function toObjects($arg) {}

    /**
     * Converts a variable to a boolean value
     *
     * @param mixed $arg 
     * @return boolean 
     */
    public static function toBool($arg) {}

    /**
     * Convert value to a scalar value.
     *
     * @throws InvalidArgumentException if value can not be scalarized.
     * @param mixed $arg 
     * @param int $flags 
     * @param string $Value we"d like to be scalar.
     * @param int $$flags SCALAR_* flag bitwise mask.
     * @return string 
     */
    public static function toScalar($arg, $flags = 0) {}

    /**
     * If $value is a numeric string, it is converted to a float or integer depending
     * on whether a decimal point is present. Otherwise the original value is returned.
     *
     * @param mixed $value If numeric string, converted to integer or float.
     * @return mixed as string, integer, or float.
     */
    public static function toNumber($value) {}

    /**
     * Checks whether a variable is a mixed number
     *
     * @param mixed $value 
     * @return bool 
     */
    public static function isMixedNumber($value) {}

    /**
     * Casts a numeric string to a float or integer
     *
     * @param mixed $value 
     * @param bool $allowNonNumeric 
     * @return double|int|mixed|null 
     */
    public static function castNumericString($value, $allowNonNumeric = true) {}

    /**
     * Checks whether an object was created by casting a scalar value.
     * Objects created from scalars will be an instance of \stdClass with
     * a property named "scalar" set to the value.
     *
     * @param object $value 
     * @return boolean 
     */
    public static function isScalarObject($value) {}

    /**
     * Converts an object to a scalar value.
     *
     * @param object $value 
     * @return scalar|null 
     */
    public static function objectToScalar($value) {}

    /**
     * @param mixed $variable 
     * @return bool 
     */
    public static function canStringCast($variable) {}

    /**
     * Casts a variable to its "natural" type.
     *
     * @param mixed $variable 
     * @return mixed 
     */
    public static function natcast($variable) {}

    /**
     * Returns the decimal point for the current locale
     *
     * @return string 
     */
    public static function getDecimalPoint() {}

}
