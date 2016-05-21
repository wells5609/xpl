namespace Xpl\Collection;

use SplFixedArray;
use Xpl\Type;

/**
 * Sequence is a list of a fixed size.
 */
class Sequence extends SplFixedArray implements ListInterface
{

    /**
     * Constructor.
     *
     * @param mixed data [Optional]
     */
	public function __construct(var data = null) {
		if typeof data != "null" {
            parent::__construct(count(data));
            this->addAll(data);
		} else {
            parent::__construct();
        }
	}

	/**
	 * Add a value to the list by index.
	 *
	 * @param int index
	 * @param mixed value
	 */
	public function add(int index, var value)
    {
        this->offsetSet(index, value);
    }

    /**
     * Removes a value from the list by index.
     *
     * @param int index
     */
    public function remove(int index)
    {
        this->offsetUnset(index);
    }

	/**
	 * Checks whether the collection is empty (i.e. has 0 elements).
	 *
	 * @return boolean
	 */
	public function isEmpty() -> boolean
    {
        return this->count() === 0;
    }

	/**
	 * Checks whether the collection contains the given value.
	 *
	 * @param mixed value
	 *
	 * @return boolean
	 */
	public function contains(var value) -> boolean
    {
        return in_array(value, this->toArray(), true);
    }

	/**
	 * Adds all the elements of data into the collection.
	 *
	 * @param mixed data
	 */
    public function addAll(var values)
    {
        var size, value;
        
        let size = this->count();

        this->setSize(size + count(values));

        for value in Type::iterate(values) {
            this->offsetSet(size, value);
            let size += 1;
        }
    }

    /**
     * Serializes the object data
     *
     * @return string
     */
    public function serialize() -> string
    {
        return serialize(this->toArray());
    }

    /**
     * Constructs the object from a serialized string
     *
     * @param string serialized
     */
    public function unserialize(string serialized) -> void
    {
        this->addAll(unserialize(serialized));
    }

}
