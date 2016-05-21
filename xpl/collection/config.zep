namespace Xpl\Collection;

use ArrayIterator;
use RuntimeException;
use Xpl\Type;

class Config implements MapInterface
{

    /**
     * Constructor.
     *
     * @param array|\Traversable data [Optional]
     * @return void
     */
    public function __construct(var data = null)
    {
        if typeof data != "null" {
            this->addAll(data);
        }
    }

	/**
	 * Checks whether the collection is empty (i.e. has 0 elements).
	 *
	 * @return boolean
	 */
	public function isEmpty() -> boolean
    {
        return count(get_object_vars(this)) === 0;
    }

    /**
     * Returns the number of properties.
     *
     * @return int
     */
    public function count()
    {
        return count(get_object_vars(this));
    }

    /**
     * Returns the object data as an array.
     *
     * @return array
     */
    public function toArray() -> array
    {
        var rtn, key, value;

        let rtn = [];

        for key, value in get_object_vars(this) {
            if typeof value == "object" && method_exists(value, "toArray") {
                let rtn[key] = value->toArray();
            } else {
                let rtn[key] = value;
            }
        }

        return rtn;
    }

    /**
     * Adds multiple entries to the Config.
     *
     * @param array|\Traversable data
     *
     * @return \Xpl\Collection\Config
     */
    public function addAll(var data) -> <Config>
    {
        var key, value;

        for key, value in Type::toArray(data) {

            let key = strval(key);

            if typeof value == "array" {
                let this->{key} = this->newStatic(value);
            } else {
                let this->{key} = value;
            }
        }

        return this;
    }

    /**
     * Returns an array of keys
     *
     * @return array
     */
    public function keys() -> array
    {
        return array_keys(get_object_vars(this));
    }

    /**
     * Returns an array of values
     *
     * @return array
     */
    public function values() -> array
    {
        return array_values(get_object_vars(this));
    }

	/**
	 * Returns an item's key in the structure
	 *
	 * @param mixed value
	 * @return mixed
	 */
    public function indexOf(var value) -> var | boolean
    {
        return array_search(value, get_object_vars(this), true);
    }

    /**
     * Whether the structure contains the given value.
     *
     * @param mixed value
     * @return boolean
     */
    public function contains(var value) -> boolean
    {
        return in_array(value, get_object_vars(this), true);
    }

    /**
     * Returns an iterator for the object.
     *
     * @return \ArrayIterator
     */
    public function getIterator() -> <ArrayIterator>
    {
        return new ArrayIterator(get_object_vars(this));
    }

    /**
     * Returns a property value using array access.
     *
     * @param string index
     *
     * @return mixed
     */
    public function offsetGet(var index) -> var | null
    {
        var value;

        let index = strval(index);

        if fetch value, this->{index} {
            return value;
        }

        return null;
    }

    /**
     * Sets a property value.
     *
     * @param string index
     * @param mixed value
     */
    public function offsetSet(var index, var value) -> void
    {
        let index = strval(index);

        if typeof value == "array" {
            let this->{index} = this->newStatic(value);
        } else {
            let this->{index} = value;
        }
    }

    /**
     * Checks if a property exists.
     *
     * @param string index
     *
     * @return boolean
     */
    public function offsetExists(var index) -> boolean
    {
        let index = strval(index);

        return typeof this->{index} != "null";
    }

    /**
     * Sets a property to null.
     *
     * @param string index
     */
    public function offsetUnset(var index) -> void
    {
        let index = strval(index);

        if typeof this->{index} != "null" {
            let this->{index} = null;
        }
    }

    /**
     * Get an item using "dot" notation.
     *
     * @param  string  key
     * @param  mixed   defaultValue
     *
     * @return mixed
     */
    public function get(var key, var defaultValue = null) -> var
    {
		let key = strval(key);

        if typeof this->{key} !== "null" {
            return this->{key};
        }

		var currentItem, segment;

		let currentItem = this;

		for segment in explode(".", key) {

            if typeof currentItem != "object" || typeof currentItem->{segment} == "null" {
                return defaultValue;
            }

			let currentItem = currentItem->{segment};
        }

        return currentItem;
    }

    /**
     * Set an item using "dot" notation.
     *
     * @param  string  key
     * @param  mixed   value
     *
     * @return \Xpl\Collection\Config
     */
    public function set(var key, var value) -> <Config>
    {
        var segments, segment, currentItem, realKey;

        let key = strval(key);

        if memstr(key, ".") {

			let segments = explode(".", key);
			let realKey = array_pop(segments);
			let currentItem = this;

			for segment in segments {

	            if typeof currentItem->{segment} != "object" {
					let currentItem->{segment} = this->newStatic();
	            }

				let currentItem = currentItem->{segment};
	        }

			if typeof value === "array" {
				let currentItem->{realKey} = this->newStatic(value);
			} else {
	        	let currentItem->{realKey} = value;
			}

		} else {

			if typeof value === "array" {
				let this->{key} = this->newStatic(value);
			} else {
	        	let this->{key} = value;
			}
		}

		return this;
    }

    /**
     * Check if an item exists using "dot" notation.
     *
     * @param  string  key
     * @return bool
     */
    public function has(var key) -> boolean
    {
		let key = strval(key);

        if typeof this->{key} !== "null" {
            return true;
        }

		var currentItem, segment;

		let currentItem = this;

		for segment in explode(".", key) {

            if typeof currentItem != "object" || typeof currentItem->{segment} == "null" {
                return false;
            }

			let currentItem = currentItem->{segment};
        }

        return true;
    }

    /**
     * Returns a Config object for a given component.
     *
     * @param string component
     *
     * @return \Xpl\Collection\Config
     */
    public function getConfig(string! component) -> <Config>
    {
        var configObject;

        if fetch configObject, this->{component} {
            if typeof configObject != "object" || ! (configObject instanceof Config) {
                throw new RuntimeException("Item with given key is not a Config");
            }
        } else {
            let configObject = this->newStatic();
            let this->{component} = configObject;
        }

        return configObject;
    }

    public function __get(var key)
    {
        return this->offsetGet(key);
    }

    public function __isset(var key)
    {
        return this->offsetExists(key);
    }

    public function __set(var key, var value)
    {
        this->offsetSet(key, value);
    }

    public function __unset(var key)
    {
        this->offsetUnset(key);
    }

    /**
     * Serializes the object.
     *
     * @return string
     */
    public function serialize() -> string
    {
        return serialize(get_object_vars(this));
    }

    /**
     * Restores the object from a serial string.
     *
     * @param string serial
     * @return void
     */
    public function unserialize(string! serial) -> void
    {
        this->addAll(unserialize(serial));
    }

	/**
	 * Restores the state of a Config object.
	 */
	public static function __set_state(array! data) -> <Config>
	{
		var calledClass;
        let calledClass = get_called_class();
        return new {calledClass}(data);
	}

    /**
     * Provides Zephir compatibility for "new static()" construct.
     *
     * @param array data
     * @return \Xpl\Collection\Config
     */
    protected function newStatic(var data = null) -> <Config>
    {
        var calledClass;
        let calledClass = get_called_class();
        return new {calledClass}(data);
    }

}
