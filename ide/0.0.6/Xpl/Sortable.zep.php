<?php

namespace Xpl;

/**
 * Contract for an object whose data can be sorted.
 */
interface Sortable
{

    /**
     * Sort items and retain keys.
     *
     * @return boolean on success, or FALSE on failure.
     */
    public function asort();

    /**
     * Sort items by key.
     *
     * @return boolean on success, or FALSE on failure.
     */
    public function ksort();

    /**
     * Sort items using natural order algo.
     *
     * @return boolean on success, or FALSE on failure.
     */
    public function natsort();

    /**
     * Sort items using case-insensitive natural order algo.
     *
     * @return boolean on success, or FALSE on failure.
     */
    public function natcasesort();

    /**
     * Sort items using a given callback function.
     *
     * @param callable $callback 
     * @return boolean on success, or FALSE on failure.
     */
    public function usort($callback);

    /**
     * Sort items using a given callback function.
     *
     * @param callable $callback 
     * @return boolean on success, or FALSE on failure.
     */
    public function uasort($callback);

    /**
     * Sort items by key using a given callback function.
     *
     * @param callable $callback 
     * @return boolean on success, or FALSE on failure.
     */
    public function uksort($callback);

}
