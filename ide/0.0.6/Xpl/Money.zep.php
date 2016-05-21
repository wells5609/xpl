<?php

namespace Xpl;

/**
 * Money represents a generic monetary unit.
 * Note: Several methods are copied from Number - this is duplicative but is the
 * only way to return instances of Money (Zephir does not recognize the 'static'
 * keyword) without reverting to slow, inefficient method calls (e.g. get_called_class()).
 */
class Money extends \Xpl\Number
{
    /**
     * @var array
     */
    static protected $localeSettings;


    /**
     * Formats the number.
     *
     * @param int $decimals 
     * @return string 
     */
    public function format($decimals = 2) {}

    /**
     * Returns the local (default) or international currency symbol.
     *
     * @param boolean $local [Optional] Default = true
     * @return string 
     */
    public static function getCurrencySymbol($local = true) {}

    /**
     * Returns an associative array containing localized numeric and monetary formatting information.
     *
     * @see localeconv()
     * @return array 
     */
    public static function getLocaleSettings() {}

}
