<?php

namespace Xpl;


class Number
{
    /**
     * @var int
     */
    const PRECISION = 128;

    /**
     * @var number
     */
    protected $value;

    /**
     * @var integer
     */
    private $precision;


    /**
     * Constructor.
     *
     * @throws InvalidArgumentException if argument is not numeric or instance of Number.
     * @param number $number 
     * @param mixed $precision 
     */
    public function __construct($number, $precision = null) {}

    /**
     * Returns the number of digits to use after the decimal.
     *
     * @return int 
     */
    public function getPrecision() {}

    /**
     * Sets the number of digits to the right of the decimal.
     *
     * @param int $digits 
     */
    public function setPrecision($digits) {}

    /**
     * Returns the number as a floating point number.
     *
     * @return float 
     */
    public function asFloat() {}

    /**
     * Returns the number as a double.
     *
     * @return double 
     */
    public function asDouble() {}

    /**
     * Returns the number as an integer
     *
     * @return int 
     */
    public function asInt() {}

    /**
     * Returns the number as an integer
     *
     * @return int 
     */
    public function asInteger() {}

    /**
     * Returns the number as a string.
     *
     * @return string 
     */
    public function asString() {}

    /**
     * Returns the number as a string.
     *
     * @return string 
     */
    public function __toString() {}

    /**
     * Returns the number as a string or integer.
     *
     * @return string|int 
     */
    public function safe() {}

    /**
     * Returns the number with the least amount of formatting suitable for display.
     *
     * @return string 
     */
    public function display() {}

    /**
     * Applies the number_format() function to the number.
     *
     * @param int $decimals 
     * @return string 
     */
    public function format($decimals) {}

    /**
     * Compares a given number to this number.
     *
     * @param mixed $number 
     * @return int 
     */
    public function cmp($number) {}

    /**
     * Checks whether the given number is equal to this one.
     * Unlike a "===" comparison in PHP, the argument type does not need to match.
     * Only the value of the numbers must be equal for this method to return true.
     *
     * @param mixed $number 
     * @return boolean 
     */
    public function equals($number) {}

    /**
     * Adds a number to this one and returns a new instance.
     *
     * @param mixed $number 
     * @return \Xpl\Number 
     */
    public function add($number) {}

    /**
     * Subtracts a number from this one and returns a new instance.
     *
     * @param mixed $number 
     * @return \Xpl\Number 
     */
    public function sub($number) {}

    /**
     * Multiplies a number by this one and returns a new instance.
     *
     * @param mixed $number 
     * @return \Xpl\Number 
     */
    public function mul($number) {}

    /**
     * Divides by the given number and returns a new instance.
     *
     * @param mixed $number 
     * @return \Xpl\Number 
     */
    public function div($number) {}

    /**
     * Raises the number to a given exponent and returns a new instance.
     *
     * @param mixed $exponent 
     * @return \Xpl\Number 
     */
    public function pow($exponent) {}

    /**
     * Computes the square root of the number and returns a new instance.
     *
     * @return \Xpl\Number 
     */
    public function sqrt() {}

    /**
     * Creates a new instance of the late-bound class from the given value.
     *
     * @param mixed $number 
     * @param int $precision [Optional]
     * @return \Xpl\Number 
     */
    public static function create($number, $precision = null) {}

    /**
     * Returns a new instance of the current class.
     *
     * @param string $number 
     * @return Number 
     */
    protected function newInstance($number) {}

}
