namespace Xpl\Collection;

use Xpl\Type;
use ArrayIterator;

/**
 * Queue is an extended \SplQueue that implements QueueInterface.
 */
class Queue extends \SplQueue implements QueueInterface
{

    /**
     * Constructor.
     *
     * @param mixed data [Optional]
     */
	public function __construct(var data = null) {
		if typeof data != "null" {
			this->addAll(data);
		}
	}

    /**
     * Removes an item by index.
     *
     * @param int index
     */
	public function remove(int index)
    {
		unset this[index];
	}

	/**
	 * Checks whether the object contains a given value.
	 *
	 * @param mixed value
	 * @return boolean
	 */
	public function contains(var value) -> boolean
    {
		return in_array(value, iterator_to_array(this), true);
	}

	/**
	 * Returns the object data as an array.
	 *
	 * @return array
	 */
	public function toArray() -> array
    {
		return iterator_to_array(this);
	}

	/**
	 * Adds data to the collection.
	 *
	 * @param mixed data
	 */
	public function addAll(var data)
    {
        var value;
        for value in Type::iterate(data) {
			this->enqueue(value);
		}
	}

}
