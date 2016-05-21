namespace Xpl;

use RuntimeException;
use OverflowException;
use ReflectionClass;

/**
 * Base class for an enum
 */
abstract class Enum
{

	/**
	 * This enum value.
	 *
	 * @var mixed
	 */
	protected value;

	/**
	 * Set the value or pass a constant name.
	 *
	 * If a '_default' constant is set, null is also accepted.
	 *
	 * @param mixed value [Optional]
	 *
	 * @throws \RuntimeException if given null and no default exists, or if the value is invalid.
	 */
	public function __construct(var value = null)
    {
		let this->value = this->filterValidateValue(value);
	}

	/**
	 * Returns the enum value.
	 *
	 * @return mixed
	 */
	public function getValue() -> var
    {
		return this->value;
	}

	/**
	 * Evaluates the enum to a value.
	 *
	 * @param ... [Optional]
	 * @return mixed
	 */
    public function evaluate() -> var
    {
        var value;
        let value = this->value;

        if method_exists(this, value) {
            return call_user_func_array([this, value], func_get_args());
        }

        return value;
    }

	/**
	 * Returns the name of the current enum value.
	 *
	 * @return string
	 */
	public function getConstantName() -> string
    {
		return array_search(this->getValue(), this->getConstants(), true);
	}

	/**
	 * Returns the default enum value, if it exists.
	 *
	 * @return mixed
	 */
	public function getDefaultValue() -> var | null
    {
        var constants, defaultValue;

        let constants = this->getConstants();

        if fetch defaultValue, constants["_default"] {
            return defaultValue;
        }

        return null;
	}

	/**
	 * Checks whether the enum value is the default value.
	 *
	 * @return boolean
	 */
	public function isDefault() -> boolean
    {
		return this->value === this->getDefaultValue();
	}

	/**
	 * Allows read-only access to the "value" property, "constant" name, and "default" value.
	 *
	 * @param string var One of "value", "constant" or "default".
	 * @return mixed
	 *
	 * @throws \OverflowException if var is not "value", "constant" or "default".
	 */
	public function __get(string property)
    {
		switch strtolower(property) {
			case "value":
				return this->getValue();
			case "constant":
				return this->getConstantName();
			case "default":
				return this->getDefaultValue();
			default:
				throw new OverflowException("Invalid property: " . property);
		}
	}

	/**
	 * Returns the value as a string.
	 *
	 * @return string
	 */
	public function __toString() -> string
    {
		return (string)this->value;
	}

	/**
	 * Returns the constants for a given class or the current class.
	 *
	 * @param string classname [Optional]
	 * @return array
	 */
	public static function getConstants(var classname = null) -> array
    {
        var reflection;

        if typeof classname == "null" {
			let classname = get_called_class();
		}

        let reflection = new ReflectionClass(classname);

        return reflection->getConstants();
	}

	/**
	 * Validates a value against the class constants.
	 *
	 * If value is a valid constant name, returns the corresponding value.
	 *
	 * If value is null and a default is set, returns the default value.
	 *
	 * @param mixed value
	 *
	 * @return mixed
	 *
	 * @throws \RuntimeException if value is null and no default exists, or if given an invalid value.
	 */
	protected function filterValidateValue(var value = null) -> var
    {
        var reflection, constants;

        let reflection = new ReflectionClass(get_class(this));
        let constants = reflection->getConstants();

		if typeof value == "null" {

            if fetch value, constants["_default"] {
                return value;
            }

	        throw new RuntimeException("Missing value: no default exists");
        }

        if typeof value == "string" {

            if isset constants[value] {
    			let value = constants[value];
    		}

            if method_exists(this, value) {
                return this->{value}();
            }
        }


        if ! in_array(value, constants, true) {
			throw new RuntimeException("Invalid enum value");
		}

		return value;
	}

}
