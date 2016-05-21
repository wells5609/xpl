namespace Xpl\Collection;

/**
 * Contract for a list-based collection.
 *
 * In a list, the order of data items is significant, and duplicate data items are permitted.
 *
 * Stack and Queue are types of lists.
 *
 * @link http://en.wikipedia.org/wiki/List_(abstract_data_type)
 */
interface ListInterface extends \Xpl\Collection, \Iterator
{

	/**
	 * Add a value to the list by index.
	 *
	 * @param int index
	 * @param mixed value
	 */
	public function add(int index, var value);

    /**
     * Removes a value from the list by index.
     *
     * @param int index
     */
    public function remove(int index);

}
