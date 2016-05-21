namespace Xpl\Collection;

use SplObjectStorage;
use Xpl\Type;

/**
 * Implementation of an object set using SplObjectStorage.
 */
class ObjectSet extends SplObjectStorage implements SetInterface
{

	/**
	 * Add a value to the set if it does not exist.
	 *
	 * @param mixed value
	 */
	public function add(var value)
    {
        this->attach(value);
    }

    /**
     * Removes a value from the set.
     *
     * @param mixed value
     */
    public function remove(var value)
    {
        this->detach(value);
    }

    public function isEmpty() -> boolean
    {
        return this->count() === 0;
    }

    public function toArray() -> array
    {
        return iterator_to_array(this);
    }

    public function addAll(var data)
    {
        if data instanceof SplObjectStorage {
            parent::addAll(data);
        } else {
            var value;
            for value in Type::iterate(data) {
                this->add(value);
            }
        }
    }

}
