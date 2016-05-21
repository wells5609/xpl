<?php

namespace Xpl;

class Set extends \Xpl\Struct implements \Xpl\SetInterface
{

    /**
     * Adds a value to the set
     *
     * @throws \RuntimeException if the value already exists
     * @param mixed $value 
     */
	public function add($value) {}

    /**
     * Removes a value from the set
     *
     * @throws \OutOfBoundsException if the value does not exist in the set
     * @param mixed $value 
     */
	public function remove($value) {}

    /**
     * Adds a value to the end of the set
     *
     * @throws \RuntimeException if the value already exists
     * @param mixed $value 
     */
	public function append($value) {}

    /**
     * Adds a value to the beginning of the set
     *
     * @throws \RuntimeException if the value already exists
     * @param mixed $value 
     */
	public function prepend($value) {}

    /**
     * Imports items into the set
     *
     * @param mixed $data 
     */
	public function import($data) {}

    /**
     * Sort items and retain keys.
     *
     * @return boolean on success, or FALSE on failure.
     */
	public function asort() {}

    /**
     * Sort items by key.
     *
     * @return boolean on success, or FALSE on failure.
     */
	public function ksort() {}

    /**
     * Sort items using natural order algo.
     *
     * @return boolean on success, or FALSE on failure.
     */
	public function natsort() {}

    /**
     * Sort items using case-insensitive natural order algo.
     *
     * @return boolean on success, or FALSE on failure.
     */
	public function natcasesort() {}

    /**
     * Sort items using a given callback function.
     *
     * @param mixed $callback 
     * @return boolean on success, or FALSE on failure.
     */
	public function usort($callback) {}

    /**
     * Sort items using a given callback function.
     *
     * @param mixed $callback 
     * @return boolean on success, or FALSE on failure.
     */
	public function uasort($callback) {}

    /**
     * Sort items by key using a given callback function.
     *
     * @param mixed $callback 
     * @return boolean on success, or FALSE on failure.
     */
	public function uksort($callback) {}

}
