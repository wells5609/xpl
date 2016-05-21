namespace Xpl;

use InvalidArgumentException;

/**
 * Provides utilities to cast PHP variables to other types.
 */
class Type
{

	const CAST_NUMERIC = 0;
	const FORCE_STRING = 1;
	const IGNORE_ERROR = 5;

    /**
     * The locale-dependent decimal point character.
     *
     * @var string
     */
	protected static decimalPoint;

    /**
     * Returns an iterator for the given argument.
     *
     * @param mixed arg
     *
     * @throws \InvalidArgumentException if not given an array or object.
     *
     * @return array|\Traversable
     */
    public static function iterate(var argument) -> array | <\Traversable>
    {
        if typeof argument == "array" {
			return argument;
		}

		if argument instanceof \Traversable {
            return argument;
        }

        if typeof argument == "object" {

			if method_exists(argument, "toArray") {
	            return argument->toArray();
	        }

	        return get_object_vars(argument);
		}

		throw new InvalidArgumentException("Cannot get iterator from type: " . gettype(argument));
    }

	/**
	 * Converts a value to an array.
	 *
	 * @param mixed
	 *
	 * @return array
	 */
	public static function toArray(var arg) -> array
	{
		if typeof arg == "array" {
			return arg;
		}

		if typeof arg == "object" {

			if method_exists(arg, "toArray") {
				return arg->toArray();
			}

			if arg instanceof \Traversable {
				return iterator_to_array(arg);
			}

			return get_object_vars(arg);
		}

		return (array)arg;
	}

	/**
	 * Converts a value to an object
	 *
	 * @param mixed
	 *
	 * @return object
	 */
	public static function toObject(var arg) -> object
	{
		if typeof arg == "object" {
			return (arg instanceof \stdClass) ? arg : (object)Type::toArray(arg);
		}

		return (object)arg;
	}

	/**
	 * Converts a value to arrays recursively.
	 *
	 * Objects and arrays are converted to arrays.
	 *
	 * @param mixed
	 *
	 * @return array
	 */
	public static function toArrays(var arg) -> array
	{
		var arr, key, value;

		let arr = [];

		for key, value in Type::toArray(arg) {

			if typeof value == "array" || typeof value == "object" {
				let arr[key] = Type::toArrays(value);
			} else {
				let arr[key] = value;
			}
		}

		return arr;
	}

	/**
	 * Converts a value to objects recursively.
	 *
	 * Objects and arrays are converted to instances of stdClass.
	 *
	 * @param mixed
	 *
	 * @return object
	 */
	public static function toObjects(var arg) -> object
	{
		var arr, key, value;

		let arr = [];

		for key, value in Type::toArray(arg) {

			if typeof value === "array" || typeof value === "object" {
				let arr[key] = Type::toObjects(value);
			} else {
				let arr[key] = value;
			}
		}

		return (object)arr;
	}

	/**
	 * Casts a variable to its "natural" type.
	 *
	 * This function will:
	 *   - Convert numeric strings to integer or float
	 *   - Convert boolean strings to bool
	 *   - Return the given variable if neither of these two conditions match.
	 *
	 * @param mixed variable
	 *
	 * @return mixed
	 */
	public static function natcast(var variable) -> float | int | string | boolean | var | null
	{
		var floated, floored;

		if typeof variable == "string" {

			if is_numeric(variable) {

				let floated = (float)variable;
				let floored = (float)floor(variable);

				if floated !== floored {
					return floated;
				}

				return (int)variable;
			}

			switch strtolower(variable) {
				case "n":
				case "no":
				case "false":
				case "off":
					return false;
				case "y":
				case "yes":
				case "true":
				case "on":
					return true;
				case "null":
					return null;
			}
		}

		return variable;
	}

	/**
	 * Converts a variable to a boolean value
	 *
	 * @param mixed arg
	 * @return boolean
	 */
	public static function toBool(var arg) -> boolean
	{
		if typeof arg == "boolean" {
			return arg;
		}

		if is_numeric(arg) {
			return arg > 0;
		}

		if typeof arg == "string" {

			let arg = strtolower(arg);

			if arg === "n" || arg === "no" || arg === "false" || arg === "off" {
				return false;
			}

			if arg === "y" || arg === "yes" || arg === "true" || arg === "on" {
				return true;
			}
		}

		return (bool)arg;
	}

	/**
	 * Convert value to a scalar value.
	 *
	 * @param string Value we"d like to be scalar.
	 * @param int $flags SCALAR_* flag bitwise mask.
	 * @return string
	 * @throws InvalidArgumentException if value can not be scalarized.
	 */
	public static function toScalar(var arg, int flags = 0) -> string | var
	{
		switch gettype(arg) {

			case "string":
				return (flags & self::CAST_NUMERIC) ? Type::toNumber(arg) : arg;

			case "double":
			case "integer":
				return (flags & self::FORCE_STRING) ? (string)arg : arg;

			case "boolean":
				return (flags & self::FORCE_STRING) ? (arg ? "1" : "") : (arg ? 1 : 0);

			case "NULL":
				return "";

			case "object":
				if arg instanceof \stdClass {
					if isset arg->{"scalar"} {
						return arg->{"scalar"};
					}
				}
				if method_exists(arg, "__toString") {
					return strval(arg);
				}
				// allow pass-thru
		}

		if (flags & self::IGNORE_ERROR) {
			return "";
		}

		throw new InvalidArgumentException("Cannot cast value to scalar (given: '" . gettype(arg) . "').");
	}

	/**
	 * If $value is a numeric string, it is converted to a float or integer depending
	 * on whether a decimal point is present. Otherwise the original value is returned.
	 *
	 * @param mixed value If numeric string, converted to integer or float.
	 *
	 * @return mixed Value as string, integer, or float.
	 */
	public static function toNumber(var value) -> float | int | var
	{
		if typeof value == "string" {

			if is_numeric(value) {

				if memstr(value, self::getDecimalPoint()) {
					return (float)value;
				}

				return (int)value;
			}
		}

		return value;
	}

	/**
	 * Checks whether a variable is a mixed number
	 */
	public static function isMixedNumber(var value) -> boolean
	{
		float floated, floored;

		if is_numeric(value) {

			let floated = (float)value;
			let floored = (float)floor(value);

			if floated !== floored {
				return true;
			}
		}

		return false;
	}

	/**
	 * Casts a numeric string to a float or integer
	 */
	public static function castNumericString(var value, boolean allowNonNumeric = true) -> float | int | var | null
	{
		if typeof value == "string" && is_numeric(value) {

			if self::isMixedNumber(value) {
				return (float)value;
			}

			return (int)value;
		}

		return allowNonNumeric ? value : null;
	}

	/**
	 * Checks whether an object was created by casting a scalar value.
	 *
	 * Objects created from scalars will be an instance of \stdClass with
	 * a property named "scalar" set to the value.
	 *
	 * @param object value
	 *
	 * @return boolean
	 */
	public static function isScalarObject(var value) -> boolean
	{
		var scalarValue;

		if typeof value == "object" {

			if property_exists(value, "scalar") {

				let scalarValue = value->{"scalar"};

				if typeof scalarValue == "null" {
					return true;
				}

				if is_scalar(scalarValue) {
					return true;
				}
			}
		}

		return false;
	}


	/**
	 * Converts an object to a scalar value.
	 *
	 * @param object value
	 * @return scalar|null
	 */
	public static function objectToScalar(const object! value) -> string | var | null
	{
		if property_exists(value, "scalar") {
			return value->{"scalar"};
		}

		if method_exists(value, "__toString") {
			return (string) value;
		}

		return null;
	}

	public static function canStringCast(var variable) -> boolean
	{
		switch typeof variable {
			case "string":
			case "integer":
			case "double":
			case "null":
				return true;
			case "object":
				return method_exists(variable, "__toString");
		}

		return false;
	}

	/**
	 * Returns the decimal point for the current locale
	 *
	 * @return string
	 */
	public static function getDecimalPoint() -> string
	{
		var decimal;
		let decimal = self::decimalPoint;

		if typeof decimal === "null" {
			var loc;
			let loc = localeconv();
			let decimal = isset loc["decimal_point"] ? loc["decimal_point"] : ".";
			let self::decimalPoint = decimal;
		}

		return decimal;
	}

}
