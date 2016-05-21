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
     * @param string left
     * @param string right
     * @return string
     */
    public static function add(var left, var right) -> string
    {
        return bcadd((string)left, (string)right, self::SCALE);
    }

    /**
     * Subtracts two numbers using bcsub()
     *
     * @param string left
     * @param string right
     * @return string
     */
    public static function subtract(var left, var right) -> string
    {
        return bcsub((string)left, (string)right, self::SCALE);
    }

    public static function sub(var left, var right) -> string
    {
        return bcsub(left, right, self::SCALE);
    }

    /**
     * Multiplies two numbers using bcmul()
     *
     * @param string left
     * @param string right
     * @return string
     */
    public static function multiply(var left, var right) -> string
    {
        return bcmul((string)left, (string)right, self::SCALE);
    }

    public static function mul(var left, var right) -> string
    {
        return bcmul((string)left, (string)right, self::SCALE);
    }

    /**
     * Divides two numbers using bcdiv()
     *
     * @param string left
     * @param string right
     * @return string
     */
    public static function divide(var left, var right) -> string
    {
        return bcdiv((string)left, (string)right, self::SCALE);
    }

    public static function div(var left, var right) -> string
    {
        return bcdiv((string)left, (string)right, self::SCALE);
    }

    /**
     * Raises a number to a power using bcpow()
     *
     * @param string left
     * @param string right
     * @return string
     */
    public static function pow(var left, var right) -> string
    {
        return bcpow((string)left, (string)right, self::SCALE);
    }

    /**
     * Returns the square root of a number using bcsqrt()
     *
     * @param string operand
     * @return string
     */
    public static function sqrt(var operand) -> string
    {
        return bcsqrt((string)operand, self::SCALE);
    }

    /**
     * Filters out non-numbers from an array.
     *
     * @param array numbers
     * @return array
     */
    public static function filterNumeric(const array! numbers) -> array
    {
        var num;
        array filtered = [];

        for num in numbers {
            if typeof num == "object" {
                if num instanceof Number {
                    let filtered[] = num->asString();
                }
            } else {
                if is_numeric(num) {
                    let filtered[] = num;
                }
            }
        }

        return filtered;
    }

    /**
     * Sums the arguments.
     *
     * @param number left
     * @param ...
     * @return string
     */
    public static function sum(var left) -> string
    {
        var args, sum, val;

        let args = func_get_args();
        let sum = "0";

    	for val in self::filterNumeric(args) {
    		let sum = self::add(sum, val);
    	}

    	return sum;
    }

    /**
     * Sums an array of values.
     *
     * @param array values
     * @return string
     */
    public static function arraySum(const array! values) -> string
    {
        var sum, val;
    	let sum = "0";

    	for val in self::filterNumeric(values) {
    		let sum = self::add(sum, val);
    	}

    	return sum;
    }

    /**
     * Returns the number of numeric values in the array
     *
     * @param array arg
     * @return int
     */
    public static function count(const array! values) -> int
    {
        return count(self::filterNumeric(values));
    }

    /**
     * Calculate mean (simple arithmetic average).
     *
     * @param array $values
     * @return string Mean
     */
    public static function mean(const array! values) -> string
    {
        var sum, numericValues, val;

        let sum = "0";
        let numericValues = self::filterNumeric(values);

    	for val in numericValues {
    		let sum = self::add(sum, val);
    	}

        return self::div(sum, count(numericValues));
    }

    /**
     * Calculate median.
     *
     * @param array $values
     * @return string Median value
     */
    public static function median(const array! vals) -> string|null
    {
        var count, values, halfCount;
    	let values = array_values(array_map("strval", vals));

        sort(values, SORT_NUMERIC);

        let count = count(values);
        let halfCount = intval(count / 2);

    	// exact median
    	if isset values[halfCount] {
    		return values[halfCount];
    	}

    	// average of two middle values
    	var mid1, mid2;
        let mid1 = intval((count - 1) / 2);
    	let mid2 = intval((count + 1) / 2);

    	if isset values[mid1] {
            if isset values[mid2] {
        		return self::div(self::add(values[mid1], values[mid2]), 2);
            }
    	}

        // best guess
        var midRnd;
    	let midRnd = intval(round(halfCount, 0));

        if isset values[midRnd] {
    		return values[midRnd];
    	}

        return null;
    }

    /**
     * Calculate the sum of products.
     *
     * @param array x_values
     * @param array y_values
     * @return string Sum of products.
     */
    public static function sumxy(const array! x_values, const array! y_values) -> string
    {
        var sum, index, xVal, yVal;

    	let sum = "0";

        for index, xVal in x_values {

    		if fetch yVal, y_values[index] {
    			let sum = self::add(sum, self::mul(xVal, yVal));
    		}
    	}

    	return sum;
    }

    /**
     * Compute the sum of squares.
     *
     * @param array values An array of values.
     * @param null|scalar|array values2 If NULL, squares each array value.
     * If scalar, squares the difference between each array value and
     *   the scalar value (good for explained/regression SS).
     * If given an array, squares the difference between betweeen each array value
     *   and the value in values2 with matching key (good for residual SS).
     * @return string Sum of all da squares.
     */
    public static function sos(const array! values, var values2 = null) -> string
    {
        var sum, index, value, val2;

    	if typeof values2 != "null" {
            if typeof values2 != "array" {
                // Given scalar: use this value in branch (b) below for every value in `values`
                let values2 = array_fill_keys(array_keys(values), strval(values2));
            }
    	}

    	let sum = "0";

        for index, value in values {

    		if typeof values2 == "null" {
                // (a) Square this value
    			let sum = self::add(sum, self::pow(value, 2));
    		} else {
                if fetch val2, values2[index] {
                    // (b) Square the difference of this value and the value in values2 with the same key
                    let sum = self::add(sum, self::pow(self::sub(value, val2), 2));
                }
            }
        }

    	return sum;
    }

    /**
     * Calculate variance.
     *
     * @param array values
     * @param boolean is_sample Default false.
     * @return string Variance of the values.
     */
    public static function variance(const array! values, const boolean is_sample = false) -> string
    {
    	if is_sample {
    		// = SOS(r) / (COUNT(s) - 1)
    		return self::div(self::sos(values, self::mean(values)), self::count(values) - 1);
    	}

    	return self::covariance(values, values);
    }

    /**
     * Compute standard deviation.
     *
     * @param array a The array of data to find the standard deviation for.
     * @param bool sample [Optional] Set true if given a sample of the population (otherwise assumes data
     * is population); Defaults to false
     * @return string|bool The standard deviation or false on error.
     */
    public static function stddev(const array! values, const boolean sample = false) -> string|null
    {
        if unlikely self::count(values) < 2 {
    		trigger_error("The array has too few elements", E_USER_NOTICE);
    		return null;
    	}

    	return self::sqrt(self::variance(values, sample));
    }

    /**
     * Calculate covariance.
     *
     * @param array x_values Dependent variable values.
     * @param array y_values Independent variable values.
     * @return string Covariance of x and y.
     */
    public static function covariance(const array! x_values, const array! y_values) -> string
    {
        var left, right;

    	let left = self::div(self::sumxy(x_values, y_values), self::count(x_values));
    	let right = self::mul(self::mean(x_values), self::mean(y_values));

    	return self::sub(left, right);
    }

    /**
     * Compute correlation.
     *
     * @param array x_values
     * @param array y_values
     * @return string Correlation
     */
    public static function correlation(const array! x_values, const array! y_values) -> string
    {
        var sdxy;
    	let sdxy = self::mul(self::stddev(x_values, true), self::stddev(y_values, true));

    	return self::div(self::covariance(x_values, y_values), sdxy);
    }

    /**
     * Returns the present value of a cashflow.
     *
     * @param int|float|string cashflow Numeric quantity of currency.
     * @param float|string rate Discount rate
     * @param int|float|string period A number representing time period in which the
     * cash flow occurs. e.g. for an annual cashflow, start a 0 and increase by 1
     * each year (e.g. [Year] 0, [Year] 1, ...)
     * @return string Present value of the cash flow.
     */
    public static function pv(const string cashflow, const string rate, const int period = 0) -> string
    {
        if period < 1 {
    		return cashflow;
    	}

    	return self::div(cashflow, self::pow(self::add(rate, 1), period));
    }

    /**
     * Returns the Net Present Value of a series of cashflows.
     *
     * @param array cashflows Indexed array of cash flows.
     * @param number rate Discount rate applied.
     * @return string NPV of cashflows discounted at rate.
     */
    public static function npv(const array cashflows, const string rate) -> string
    {
        var npv, idx, cf;
    	let npv = "0";

        for idx, cf in cashflows {
            let npv = self::add(npv, self::pv(cf, rate, idx));
    	}

    	return npv;
    }

    /**
     * Returns the weighted average of a series of values.
     *
     * @param array values Indexed array of values.
     * @param array weights Indexed array of weights corresponding to each value.
     * @return string Weighted average of values.
     */
    public static function weightedAvg(const array values, const array weights) -> string|null
    {
        if count(values) !== count(weights) {
    		trigger_error("Must pass the same number of weights and values.", E_USER_NOTICE);
    		return null;
    	}

        var sum, idx, val;
        let sum = "0";

        for idx, val in array_values(values) {
            // sum += value * weights[index];
    		let sum = self::add(sum, self::mul(val, weights[idx]));
    	}

        return self::div(sum, self::arraySum(weights));
    }

    /**
     * Returns the % of an amount of the total.
     *
     * e.g. for operating margin, use operating income as 1st arg, revenue as 2nd.
     * e.g. for capex as a % of sales, use capex as 1st arg, revenue as 2nd.
     *
     * @param number portion An amount, a portion of the total.
     * @param number total The total amount.
     * @return string
     */
    public static function pct(var portion, var total) -> string
    {
    	return self::div(portion, total);
    }

    /**
     * Returns the % change between two values.
     *
     * @param number current The current value.
     * @param number previous The previous value.
     * @return string Percent change from previous to current.
     */
    public static function pctChange(var current, var previous) -> string
    {
    	return self::div(self::sub(current, previous), previous);
    }

    /**
     * Convert an array of values to % change.
     *
     * @param array values Raw values ordered from oldest to newest.
     * @return array Array of the % change between values.
     */
    public static function pctChangeArray(const array vals) -> array
    {
        var percents, keys, values, index, val, prev;

    	let percents = [];
    	let keys = array_keys(vals);
    	let values = array_values(vals);

        for index, val in values {

    		if index !== 0 {

    			let prev = values[(index - 1)];

                if 0 == prev {
    				let percents[index] = "0";
    			} else {
                    let percents[index] = self::div(self::sub(val, prev), prev);
    			}
    		}
    	}

    	array_shift(keys);

        return array_combine(keys, percents);
    }

}
