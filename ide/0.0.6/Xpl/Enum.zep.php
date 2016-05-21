<?php

namespace Xpl;

/**
 * Base class for an enum
 */
abstract class Enum
{
    /**
     * This enum value.
     *
     * @var mixed
     */
    protected $value;


    /**
     * Set the value or pass a constant name.
     * If a '_default' constant is set, null is also accepted.
     *
     * @throws \RuntimeException if given null and no default exists, or if the value is invalid.
     * @param mixed $value [Optional]
     */
    public function __construct($value = null) {}

    /**
     * Returns the enum value.
     *
     * @return mixed 
     */
    public function getValue() {}

    /**
     * Evaluates the enum to a value.
     *
     * @param ... $[Optional] 
     * @return mixed 
     */
    public function evaluate() {}

    /**
     * Returns the name of the current enum value.
     *
     * @return string 
     */
    public function getConstantName() {}

    /**
     * Returns the default enum value, if it exists.
     *
     * @return mixed 
     */
    public function getDefaultValue() {}

    /**
     * Checks whether the enum value is the default value.
     *
     * @return boolean 
     */
    public function isDefault() {}

    /**
     * Allows read-only access to the "value" property, "constant" name, and "default" value.
     *
     * @throws \OverflowException if var is not "value", "constant" or "default".
     * @param string $property 
     * @param string $var One of "value", "constant" or "default".
     * @return mixed 
     */
    public function __get($property) {}

    /**
     * Returns the value as a string.
     *
     * @return string 
     */
    public function __toString() {}

    /**
     * Returns the constants for a given class or the current class.
     *
     * @param string $classname [Optional]
     * @return array 
     */
    public static function getConstants($classname = null) {}

    /**
     * Validates a value against the class constants.
     * If value is a valid constant name, returns the corresponding value.
     * If value is null and a default is set, returns the default value.
     *
     * @throws \RuntimeException if value is null and no default exists, or if given an invalid value.
     * @param mixed $value 
     * @return mixed 
     */
    protected function filterValidateValue($value = null) {}

}
