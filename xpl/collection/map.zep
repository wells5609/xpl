namespace Xpl\Collection;

use Xpl\Type;
use ArrayIterator;

/**
 * Basic implementation of a Map.
 */
class $Map extends AbstractBaseCollection implements MapInterface, \JsonSerializable
{

	/**
	 * Constructor.
	 *
	 * @param mixed data [Optional]
	 */
    public function __construct(var data = null)
    {
        if typeof data != "null" {
            this->addAll(data);
        }
    }

	/**
	 * Import data into the object.
	 *
	 * @param mixed
	 */
	public function addAll(var data)
	{
        var key, value;

        for key, value in Type::toArray(data) {
            this->set(key, value);
        }
	}

    /**
     * Returns an item by key.
     *
     * @param mixed
     * @return mixed
     */
	public function get(var key) -> var | null
	{
		var value;

		if fetch value, this->items[key] {
			return value;
		}

		return null;
	}

    /**
     * Sets an item by key.
     *
     * @param mixed
	 * @param mixed
     */
	public function set(var key, var value)
	{
		let this->items[key] = value;
	}

    /**
     * Whether the item given by key exists.
     *
     * @param mixed
     * @return boolean
     */
	public function has(var key) -> boolean
	{
		return isset this->items[key];
	}

    /**
     * Removes an item by key.
     *
     * @param mixed
     */
	public function remove(var key)
	{
		unset this->items[key];
	}

	/**
	 * Returns an item's key in the structure.
	 *
	 * @param mixed value
	 * @return string|boolean
	 */
	public function indexOf(var value) -> var | boolean
	{
		return array_search(value, this->items, true);
	}

    /**
     * Returns an array of keys.
     *
     * @return array
     */
	public function keys() -> array
	{
		return array_keys(this->items);
	}

    /**
     * Returns an array of values.
     *
     * @return array
     */
	public function values() -> array
	{
		return array_values(this->items);
	}

    /**
     * Applies a callback function to each item in the object.
     *
     * @param callable callback
     * @param mixed userdata [Optional]
     * @return \Xpl\Collection\MapInterface
     */
    public function walk(callable callback, var userdata = null) -> <MapInterface>
    {
        array_walk(this->items, callback, userdata);
        return this;
    }

	/**
	 * Applies a callback function to each item and returns a new MapInterface containing the items.
	 *
	 * @param callable callback
	 * @return \Xpl\Collection\MapInterface
	 */
	public function map(callable callback) -> <MapInterface>
	{
        var calledClass, newObject;

		let calledClass = get_called_class();
        let newObject = new {calledClass}();

		newObject->addAll(array_map(callback, this->items));

        return newObject;
	}

	/**
	 * Filters the elements using a callback function and returns a new MapInterface.
	 *
	 * @param callable callback
	 * @return \Xpl\Collection\MapInterface
	 */
	public function filter(callable callback) -> <MapInterface>
    {
        var calledClass, newObject;

		let calledClass = get_called_class();
        let newObject = new {calledClass}();

		newObject->addAll(array_filter(this->items, callback));

        return newObject;
	}

	/**
	 * Merges the given items into the object.
	 *
	 * @param mixed data
	 * @return \Xpl\Collection\MapInterface
	 */
	public function merge(var data) -> <MapInterface>
    {
		var key, value, objectData;

		let objectData = this->items;

        for key, value in Type::toArray(data) {
            let objectData[key] = value;
        }

		let this->items = objectData;

        return this;
	}

	/**
	 * Replaces items in the collection with those given.
	 *
	 * @param mixed data
	 * @return \Xpl\Collection\MapInterface
	 */
	public function replace(var data) -> <MapInterface>
    {
        var key, value, objectData;

        let objectData = this->items;

        for key, value in Type::toArray(data) {
            if isset objectData[key] {
                let objectData[key] = value;
            }
        }

		let this->items = objectData;

        return this;
	}

    /**
     * Returns an iterator for the object.
     *
     * @return \ArrayIterator
     */
    public function getIterator() -> <ArrayIterator>
    {
        return new ArrayIterator(this->items);
    }

    /**
     * Implements \ArrayAccess
     */
	public function offsetGet(var index) -> var | null
	{
        return this->get(index);
	}

    /**
     * Implements \ArrayAccess
     */
	public function offsetSet(var index, var newval) -> void
	{
        this->set(index, newval);
	}

    /**
     * Implements \ArrayAccess
     */
	public function offsetExists(var index) -> boolean
	{
        return this->has(index);
	}

    /**
     * Implements \ArrayAccess
     */
	public function offsetUnset(var index) -> void
	{
        this->remove(index);
	}

	/**
	 * Returns the structure as a native PHP array.
	 *
	 * Implements \JsonSerializable
	 *
	 * @return array
	 */
	public function jsonSerialize() -> array
	{
		return this->toArray();
	}

}
