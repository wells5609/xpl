namespace Xpl\Collection;

use Xpl\Type;
use RuntimeException;
use OutOfBoundsException;

/**
 * In a set, the order of items is insignificant, and duplicate items are not permitted.
 *
 * @link http://en.wikipedia.org/wiki/Set_(abstractitems_type)
 */
class Set extends AbstractBaseCollection implements SetInterface
{

    private iteratorPosition = 0;

    public function current()
    {
        return this->items[this->iteratorPosition];
    }

    public function key() -> var
    {
        return this->iteratorPosition;
    }

    public function next() -> void
    {
        let this->iteratorPosition += 1;
    }

    public function rewind() -> void
    {
        let this->iteratorPosition = 0;
    }

    public function valid() -> boolean
    {
        return isset this->items[this->iteratorPosition];
    }

    /**
     * Adds a value to the set
     *
     * @param mixed value
     * @throws \RuntimeException if the value already exists
     */
    public function add(var value)
    {
        if in_array(value, this->items, true) {
            throw new RuntimeException("Value already exists in set");
        }

        let this->items[] = value;
    }

    /**
     * Removes a value from the set
     *
     * @param mixed value
     * @throws \OutOfBoundsException if the value does not exist in the set
     */
    public function remove(var value)
    {
        var index;
        let index = array_search(value, this->items, true);

        if index === false {
            throw new OutOfBoundsException("Value does not exist in set");
        }

        unset this->items[index];
    }

    /**
     * Adds a value to the end of the set
     *
     * @param mixed value
     * @throws \RuntimeException if the value already exists
     */
    public function append(var value)
    {
        if in_array(value, this->items, true) {
            throw new RuntimeException("Value already exists in set");
        }

        array_push(value, this->items);
    }

    /**
     * Adds a value to the beginning of the set
     *
     * @param mixed value
     * @throws \RuntimeException if the value already exists
     */
    public function prepend(var value)
    {
        if in_array(value, this->items, true) {
            throw new RuntimeException("Value already exists in set");
        }

        array_unshift(value, this->items);
    }

    /**
     * Imports items into the set
     *
     * @param mixed data
     */
    public function addAll(var data)
    {
        var value;

        for value in Type::toArray(data) {
            if ! in_array(value, this->items, true) {
                let this->items[] = value;
            }
        }
    }

    /**
	 * Sort items and retain keys.
	 *
	 * @return boolean TRUE on success, or FALSE on failure.
	 */
	public function asort() -> boolean
    {
        return asort(this->items);
    }

	/**
	 * Sort items by key.
	 *
	 * @return boolean TRUE on success, or FALSE on failure.
	 */
	public function ksort() -> boolean
    {
        return ksort(this->items);
    }

	/**
	 * Sort items using natural order algo.
	 *
	 * @return boolean TRUE on success, or FALSE on failure.
	 */
	public function natsort() -> boolean
    {
        return natsort(this->items);
    }

	/**
	 * Sort items using case-insensitive natural order algo.
	 *
	 * @return boolean TRUE on success, or FALSE on failure.
	 */
	public function natcasesort() -> boolean
    {
        return natcasesort(this->items);
    }

	/**
	 * Sort items using a given callback function.
	 *
	 * @return boolean TRUE on success, or FALSE on failure.
	 */
	public function usort(var callback) -> boolean
    {
        return usort(this->items, callback);
    }

	/**
	 * Sort items using a given callback function.
	 *
	 * @return boolean TRUE on success, or FALSE on failure.
	 */
	public function uasort(var callback) -> boolean
    {
        return uasort(this->items, callback);
    }

	/**
	 * Sort items by key using a given callback function.
	 *
	 * @return boolean TRUE on success, or FALSE on failure.
	 */
	public function uksort(var callback) -> boolean
    {
        return uksort(this->items, callback);
    }

}
