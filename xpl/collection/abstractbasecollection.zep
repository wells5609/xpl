namespace Xpl\Collection;

/**
 * Abstract implementation of Collection.
 */
abstract class AbstractBaseCollection implements \Xpl\Collection
{

    /**
     * @var array
     */
    protected items = [];

    /**
     * Returns the structure as a native PHP array.
     *
     * @return array
     */
    public function toArray() -> array
    {
        return this->items;
    }

    /**
     * Whether the structure is empty.
     *
     * @return boolean
     */
    public function isEmpty() -> boolean
    {
        return empty this->items;
    }

    /**
     * Whether the structure contains the given value.
     *
     * @param mixed value
     * @return boolean
     */
    public function contains(var value) -> boolean
    {
        return in_array(value, this->items, true);
    }

    /**
     * Returns the number of items in the structure
     *
     * @return int
     */
    public function count() -> int
    {
        return count(this->items);
    }

    /**
     * Serializes the object data
     *
     * @return string
     */
    public function serialize() -> string
    {
        return serialize(this->items);
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
