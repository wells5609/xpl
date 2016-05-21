<?php

namespace Xpl;

/**
 * Money represents a generic monetary unit.
 */
class Money extends \Xpl\Number
{

    /**
     * Formats the number.
     *
     * @param int $decimals 
     * @return string 
     */
    public function format($decimals = 2) {}

    /**
     * @param mixed $locale 
     * @return \NumberFormatter 
     */
    public function getNumberFormatter($locale = null) {}

    /**
     * @return string|bool 
     */
    public function getLocale() {}

}
