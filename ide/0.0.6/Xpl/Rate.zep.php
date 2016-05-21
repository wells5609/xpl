<?php

namespace Xpl;


class Rate extends \Xpl\Number
{

    /**
     * @param mixed $number 
     * @param mixed $precision 
     */
    public function __construct($number, $precision = null) {}

    /**
     * @param int $decimals 
     * @param bool $appendPctSign 
     * @return string 
     */
    public function format($decimals = 2, $appendPctSign = true) {}

    /**
     * @param mixed $number 
     * @return mixed 
     */
    public static function parsePercent($number) {}

}
