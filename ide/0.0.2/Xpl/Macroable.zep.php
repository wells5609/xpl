<?php

namespace Xpl;

class Macroable
{
    /**
     * @var array
     */
    private $macros = array();

    /**
     * @return array 
     */
	public function getMacros() {}

    /**
     * Adds a named macro to the object
     *
     * @param string $name Macro name
     * @param callable $callback Macro callback function
     * @return void 
     */
	public function addMacro($name, $callback) {}

    /**
     * Whether a macro given by name exists
     *
     * @param string $name Macro name
     * @return boolean 
     */
	public function hasMacro($name) {}

    /**
     * Returns a raw macro callback
     *
     * @param string $name Macro name
     * @return mixed|null 
     */
	public function getMacro($name) {}

    /**
     * Executes a macro using the given arguments
     *
     * @param string $name Macro name
     * @param array $args [Optional] Arguments to pass to the macro callback
     */
	public function doMacro($name, $args = array()) {}

    /**
     * Whether the object has a method or macro given by name
     *
     * @param string $name Method/macro name
     * @return bool 
     */
	public function isCallable($name) {}

    /**
     * Allows macros to be called like object methods
     *
     * @throws \BadMethodCallException if a macro with method name does not exist
     * @param string $func 
     * @param array $args 
     */
	public function __call($func, $args) {}

    /**
     * Allows the object to be invokable using an "__invoke" macro
     *
     * @throws BadMethodCallException if a "__invoke" macro does not exist
     */
	public function __invoke() {}

    /**
     * Allows the object to be cast to a string using a "__toString" macro
     * Returns an empty string if a "__toString" macro does not exist
     *
     * @return string 
     */
	public function __toString() {}


	public function __construct() {}

}
