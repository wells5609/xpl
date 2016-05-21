<?php

namespace Xpl;


class Math
{
    /**
     * BCMath scale.
     *
     * @var int
     */
    const SCALE = 20;


    /**
     * Adds two numbers using bcadd()
     *
     * @param string $left 
     * @param string $right 
     * @return string 
     */
    public static function add($left, $right) {}

    /**
     * Subtracts two numbers using bcsub()
     *
     * @param string $left 
     * @param string $right 
     * @return string 
     */
    public static function subtract($left, $right) {}

    /**
     * @param mixed $left 
     * @param mixed $right 
     * @return string 
     */
    public static function sub($left, $right) {}

    /**
     * Multiplies two numbers using bcmul()
     *
     * @param string $left 
     * @param string $right 
     * @return string 
     */
    public static function multiply($left, $right) {}

    /**
     * @param mixed $left 
     * @param mixed $right 
     * @return string 
     */
    public static function mul($left, $right) {}

    /**
     * Divides two numbers using bcdiv()
     *
     * @param string $left 
     * @param string $right 
     * @return string 
     */
    public static function divide($left, $right) {}

    /**
     * @param mixed $left 
     * @param mixed $right 
     * @return string 
     */
    public static function div($left, $right) {}

    /**
     * Raises a number to a power using bcpow()
     *
     * @param string $left 
     * @param string $right 
     * @return string 
     */
    public static function pow($left, $right) {}

    /**
     * Returns the square root of a number using bcsqrt()
     *
     * @param string $operand 
     * @return string 
     */
    public static function sqrt($operand) {}

    /**
     * Filters out non-numbers from an array.
     *
     * @param array $numbers 
     * @return array 
     */
    public static function filterNumeric($numbers) {}

    /**
     * Sums the arguments.
     *
     * @param number $left 
     * @param ...  
     * @return string 
     */
    public static function sum($left) {}

    /**
     * Sums an array of values.
     *
     * @param array $values 
     * @return string 
     */
    public static function arraySum($values) {}

    /**
     * Returns the number of numeric values in the array
     *
     * @param array $values 
     * @param array $arg 
     * @return int 
     */
    public static function count($values) {}

    /**
     * Calculate mean (simple arithmetic average).
     *
     * @param array $values 
     * @param array $$values 
     * @return string 
     */
    public static function mean($values) {}

    /**
     * Calculate median.
     *
     * @param array $vals 
     * @param array $$values 
     * @return string value
     */
    public static function median($vals) {}

    /**
     * Calculate the sum of products.
     *
     * @param array $x_values 
     * @param array $y_values 
     * @return string of products.
     */
    public static function sumxy($x_values, $y_values) {}

    /**
     * Compute the sum of squares.
     *
     * @param null|scalar|array values2 If NULL, squares each array value.
     * If scalar, squares the difference between each array value and
     * the scalar value (good for explained/regression SS).
     * If given an array, squares the difference between betweeen each array value
     * and the value in values2 with matching key (good for residual SS).
     * @param array $values An array of values.
     * @param mixed $values2 
     * @return string of all da squares.
     */
    public static function sos($values, $values2 = null) {}

    /**
     * Calculate variance.
     *
     * @param array $values 
     * @param boolean $is_sample Default false.
     * @return string of the values.
     */
    public static function variance($values, $is_sample = false) {}

    /**
     * Compute standard deviation.
     *
     * @param bool sample [Optional] Set true if given a sample of the population (otherwise assumes data
     * is population); Defaults to false
     * @param array $values 
     * @param bool $sample 
     * @param array $a The array of data to find the standard deviation for.
     * @return string|bool standard deviation or false on error.
     */
    public static function stddev($values, $sample = false) {}

    /**
     * Calculate covariance.
     *
     * @param array $x_values Dependent variable values.
     * @param array $y_values Independent variable values.
     * @return string of x and y.
     */
    public static function covariance($x_values, $y_values) {}

    /**
     * Compute correlation.
     *
     * @param array $x_values 
     * @param array $y_values 
     * @return string 
     */
    public static function correlation($x_values, $y_values) {}

    /**
     * Returns the present value of a cashflow.
     *
     * @param int|float|string period A number representing time period in which the
     * cash flow occurs. e.g. for an annual cashflow, start a 0 and increase by 1
     * each year (e.g. [Year] 0, [Year] 1, ...)
     * @param int|float|string $cashflow Numeric quantity of currency.
     * @param float|string $rate Discount rate
     * @param int $period 
     * @return string value of the cash flow.
     */
    public static function pv($cashflow, $rate, $period = 0) {}

    /**
     * Returns the Net Present Value of a series of cashflows.
     *
     * @param array $cashflows Indexed array of cash flows.
     * @param number $rate Discount rate applied.
     * @return string of cashflows discounted at rate.
     */
    public static function npv($cashflows, $rate) {}

    /**
     * Returns the weighted average of a series of values.
     *
     * @param array $values Indexed array of values.
     * @param array $weights Indexed array of weights corresponding to each value.
     * @return string average of values.
     */
    public static function weightedAvg($values, $weights) {}

    /**
     * Returns the % of an amount of the total.
     * e.g. for operating margin, use operating income as 1st arg, revenue as 2nd.
     * e.g. for capex as a % of sales, use capex as 1st arg, revenue as 2nd.
     *
     * @param number $portion An amount, a portion of the total.
     * @param number $total The total amount.
     * @return string 
     */
    public static function pct($portion, $total) {}

    /**
     * Returns the % change between two values.
     *
     * @param number $current The current value.
     * @param number $previous The previous value.
     * @return string change from previous to current.
     */
    public static function pctChange($current, $previous) {}

    /**
     * Convert an array of values to % change.
     *
     * @param array $vals 
     * @param array $values Raw values ordered from oldest to newest.
     * @return array of the % change between values.
     */
    public static function pctChangeArray($vals) {}

}
