namespace Xpl;

/**
 * Contract for a collection.
 */
interface Collection extends Arrayable, \Countable, \Serializable
{

	/**
	 * Checks whether the collection is empty (i.e. has 0 elements).
	 *
	 * @return boolean
	 */
	public function isEmpty() -> boolean;

	/**
	 * Checks whether the collection contains the given value.
	 *
	 * @param mixed value
	 *
	 * @return boolean
	 */
	public function contains(var value) -> boolean;

	/**
	 * Adds all the elements of data into the collection.
	 *
	 * @param mixed data
	 */
	public function addAll(var data);

}
