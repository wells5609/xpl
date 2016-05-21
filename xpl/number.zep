namespace Xpl;

use InvalidArgumentException;

class Number
{

    /**
     * @var int
     */
    const PRECISION = 128;

    /**
     * @var number
     */
    protected value;

    /**
     * @var integer
     */
    private precision;

    /**
     * Constructor.
     *
     * @param number number
     *
     * @throws InvalidArgumentException if argument is not numeric or instance of Number.
     */
	public function __construct(var number, var precision = null)
    {
        if typeof number == "object" {
            if number instanceof Number {
                let this->value = number->asString();
            } else {
                throw new InvalidArgumentException("Object must be instance of Number, given: " . get_class(number));
            }
        } else {
            if is_numeric(number) {
                let this->value = rtrim(number, "0") . "0";
    		} else {
                throw new InvalidArgumentException("Argument must be numeric, given: " . gettype(number));
    		}
        }

        if typeof precision == "null" {
            let this->precision = self::PRECISION;
        } else {
            let this->precision = (int)precision;
        }
	}

    /**
     * Returns the number of digits to use after the decimal.
     *
     * @return int
     */
    public function getPrecision() -> int
    {
        return this->precision;
    }

    /**
     * Sets the number of digits to the right of the decimal.
     *
     * @param int digits
     */
    public function setPrecision(const int! digits) -> void
    {
        let this->precision = digits;
    }

    /**
     * Returns the number as a floating point number.
     *
     * @return float
     */
	public function asFloat() -> float
    {
		return (float)this->value;
	}

    /**
     * Returns the number as a double.
     *
     * @return double
     */
	public function asDouble() -> double
    {
		return (double)this->value;
	}

    /**
     * Returns the number as an integer
     *
     * @return int
     */
	public function asInt() -> int
    {
		return (int)this->value;
	}

    /**
     * Returns the number as an integer
     *
     * @return int
     */
	public function asInteger() -> int
    {
		return (int)this->value;
	}

    /**
     * Returns the number as a string.
     *
     * @return string
     */
	public function asString() -> string
    {
		return this->value;
	}

    /**
     * Returns the number as a string.
     *
     * @return string
     */
	public function __toString() -> string
    {
		return this->value;
	}

    /**
     * Returns the number as a string or integer.
     *
     * @return string|int
     */
	public function safe() -> string | int
    {
        var integerValue;
        let integerValue = (int)this->value;

		if this->cmp(integerValue) === 0 {
			return integerValue;
		}

		return this->display();
	}

    /**
     * Returns the number with the least amount of formatting suitable for display.
     *
     * @return string
     */
	public function display() -> string
    {
		return this->value;
	}

    /**
     * Applies the number_format() function to the number.
     *
     * @param int decimals
     * @return string
     */
	public function format(int decimals) -> string
    {
		return number_format(this->value, decimals);
	}

    /**
     * Compares a given number to this number.
     *
     * @param mixed number
     * @return int
     */
	public function cmp(var number) -> int
    {
		return bccomp(this->value, (string)number, this->precision);
	}

    /**
     * Checks whether the given number is equal to this one.
     *
     * Unlike a "===" comparison in PHP, the argument type does not need to match.
     * Only the value of the numbers must be equal for this method to return true.
     *
     * @param mixed number
     * @return boolean
     */
	public function equals(var number) -> boolean
    {
		return bccomp(this->value, (string)number, this->precision) === 0;
	}

    /**
     * Adds a number to this one and returns a new instance.
     *
     * @param mixed number
     *
     * @return \Xpl\Number
     */
	public function add(var number) -> <Number>
    {
        return this->newInstance(bcadd(this->value, (string)number, this->precision));
	}

    /**
     * Subtracts a number from this one and returns a new instance.
     *
     * @param mixed number
     *
     * @return \Xpl\Number
     */
	public function sub(var number) -> <Number>
    {
        return this->newInstance(bcsub(this->value, (string)number, this->precision));
	}

    /**
     * Multiplies a number by this one and returns a new instance.
     *
     * @param mixed number
     *
     * @return \Xpl\Number
     */
	public function mul(var number) -> <Number>
    {
        return this->newInstance(bcmul(this->value, (string)number, this->precision));
	}

    /**
     * Divides by the given number and returns a new instance.
     *
     * @param mixed number
     *
     * @return \Xpl\Number
     */
	public function div(var number) -> <Number>
    {
        return this->newInstance(bcdiv(this->value, (string)number, this->precision));
	}

    /**
     * Raises the number to a given exponent and returns a new instance.
     *
     * @param mixed exponent
     *
     * @return \Xpl\Number
     */
	public function pow(var exponent) -> <Number>
    {
        return this->newInstance(bcpow(this->value, (string)exponent, this->precision));
	}

    /**
     * Computes the square root of the number and returns a new instance.
     *
     * @return \Xpl\Number
     */
	public function sqrt() -> <Number>
    {
        return this->newInstance(bcsqrt(this->value, this->precision));
	}

    /**
     * Creates a new instance of the late-bound class from the given value.
     *
     * @param mixed number
     * @param int precision [Optional]
     *
     * @return \Xpl\Number
     */
    public static function create(var number, var precision = null) -> <Number>
    {
        var calledClass;
        let calledClass = get_called_class();
        return new {calledClass}(number, precision);
    }

    /**
     * Casts a numeric value to an int or float.
     *
     * @param string|int|float number
     * @return int|float
     */
    public static function cast(var number) -> int | float
    {
        float floated, floored;

		let floated = (float)number;
		let floored = (float)floor(number);

		if floated === floored {
			return (int)number;
		}

		return floated;
    }

    /**
     * Checks whether the given number is a non-integer.
     *
     * @param mixed
     * @return boolean
     */
    public static function isMixedNumber(var number) -> boolean
    {
        float floated, floored;

		let floated = (float)number;
		let floored = (float)floor(number);

        return floated !== floored;
    }

    /**
     * Returns a new instance of the current class.
     */
    protected function newInstance(const string number) -> <Number>
    {
        var thisClass;
        let thisClass = get_class(this);
        return new {thisClass}(number, this->precision);
    }

}
