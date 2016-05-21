namespace Xpl\Collection;

use Xpl\Type;
use RuntimeException;

class ArrayObject extends \ArrayObject implements MapInterface, \JsonSerializable
{

    /**
     * Constructor
     *
     * @param array|object input
     * @param string iterator_class Iterator classname. Default "ArrayIterator"
     */
	public function __construct(var input = [], string! iterator_class = "ArrayIterator")
	{
		parent::__construct(input, \ArrayObject::ARRAY_AS_PROPS, iterator_class);
	}

    /**
     * Flags cannot be changed from \ArrayObject::ARRAY_AS_PROPS
     *
     * @throws \RuntimeException
     */
	public function setFlags(var flags)
    {
		throw new RuntimeException("Flags are immutable");
	}

	/**
	 * Import data into the object
	 *
	 * @param mixed
	 */
	public function addAll(var data)
	{
		var key, value;
		for key, value in Type::toArray(data) {
			let this->{key} = value;
		}
	}

    /**
     * Returns the structure as a native PHP array
     *
     * @return array
     */
	public function toArray() -> array
	{
		return this->getArrayCopy();
	}

    /**
     * Whether the structure is empty
     *
     * @return boolean
     */
	public function isEmpty() -> boolean
	{
		return this->count() == 0;
	}

    /**
     * Whether the structure contains the given value
     *
     * @param mixed value
     * @return boolean
     */
	public function contains(var value) -> boolean
	{
		return in_array(value, this->getArrayCopy(), true);
	}

	/**
	 * Returns an item's key in the structure
	 *
	 * @param mixed value
	 * @return string|boolean
	 */
	public function indexOf(var value)
	{
		return array_search(value, this->getArrayCopy());
	}

    /**
     * Returns an item by key
     *
     * @param string
     * @return mixed
     */
	public function get(const string key)
	{
		return isset this->{key} ? this->{key} : null;
	}

    /**
     * Sets an item by key
     *
     * @param string
     */
	public function set(const string key, var value)
	{
		let this->{key} = value;
	}

    /**
     * Whether the item given by key exists
     *
     * @param string
     * @return boolean
     */
	public function has(const string key) -> boolean
	{
		return isset this->{key};
	}

    /**
     * Removes an item by key
     *
     * @param string
     */
	public function remove(const string key)
	{
		this->offsetUnset(key);
	}

    /**
     * Returns an array of keys
     *
     * @return array
     */
	public function keys() -> array
	{
		return array_keys(this->getArrayCopy());
	}

    /**
     * Returns an array of values
     *
     * @return array
     */
	public function values() -> array
	{
		return array_values(this->getArrayCopy());
	}

	/**
	 * Returns the sum of all values
	 *
	 * @return float|int
	 */
	public function sum() -> float | int
	{
		return array_sum(this->getArrayCopy());
	}

	/**
	 * Returns the first value
	 *
	 * @return mixed
	 */
	public function first()
	{
		var arr;
		let arr = this->getArrayCopy();
		return reset(arr);
	}

	/**
	 * Returns the last value
	 *
	 * @return mixed
	 */
	public function last()
	{
		var arr;
		let arr = this->getArrayCopy();
		return end(arr);
	}

    /**
     * Implements \JsonSerializable
     *
     * @return array
     */
	public function jsonSerialize()
	{
		return this->getArrayCopy();
	}

    /**
     * Applies a callback function to each item in the object
     *
     * @param callable callback
     * @param mixed userdata [Optional]
     */
    public function walk(callable callback, var userdata = null) -> <ArrayObject>
    {
        var data;
        let data = this->getArrayCopy();

        array_walk(data, callback, userdata);

        this->exchangeArray(data);

		return this;
    }

	/**
	 * Applies a callback function to each item and returns a new ArrayObject.
	 *
	 * @param callable callback
	 * @return \Xpl\Collection\ArrayObject
	 */
	public function map(callable callback) -> <ArrayObject>
	{
		return new ArrayObject(array_map(callback, this->getArrayCopy()), this->getIteratorClass());
	}

	/**
	 * Filters the elements using a callback function and returns a new ArrayObject.
	 *
	 * @param callable callback
	 * @return \Xpl\Collection\ArrayObject
	 */
	public function filter(callable callback) -> <ArrayObject>
    {
		return new ArrayObject(array_filter(this->getArrayCopy(), callback), this->getIteratorClass());
	}

	/**
	 * Merges items into the object
	 *
	 * @param mixed data
	 */
	public function merge(var data) -> <ArrayObject>
    {
		this->exchangeArray(array_merge(this->getArrayCopy(), Type::toArray(data)));
		return this;
	}

	/**
	 * Replaces items in the object
	 *
	 * @param mixed data
	 */
	public function replace(var data) -> <ArrayObject>
    {
		this->exchangeArray(array_replace(this->getArrayCopy(), Type::toArray(data)));
		return this;
	}

}
