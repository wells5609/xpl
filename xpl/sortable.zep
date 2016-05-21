namespace Xpl;

/**
 * Contract for an object whose data can be sorted.
 */
interface Sortable
{

	/**
	 * Sort items and retain keys.
	 *
	 * @return boolean TRUE on success, or FALSE on failure.
	 */
	public function asort() -> boolean;

	/**
	 * Sort items by key.
	 *
	 * @return boolean TRUE on success, or FALSE on failure.
	 */
	public function ksort() -> boolean;

	/**
	 * Sort items using natural order algo.
	 *
	 * @return boolean TRUE on success, or FALSE on failure.
	 */
	public function natsort() -> boolean;

	/**
	 * Sort items using case-insensitive natural order algo.
	 *
	 * @return boolean TRUE on success, or FALSE on failure.
	 */
	public function natcasesort() -> boolean;

	/**
	 * Sort items using a given callback function.
	 *
	 * @param callable callback
	 * @return boolean TRUE on success, or FALSE on failure.
	 */
	public function usort(var callback) -> boolean;

	/**
	 * Sort items using a given callback function.
	 *
	 * @param callable callback
	 * @return boolean TRUE on success, or FALSE on failure.
	 */
	public function uasort(var callback) -> boolean;

	/**
	 * Sort items by key using a given callback function.
	 *
	 * @param callable callback
	 * @return boolean TRUE on success, or FALSE on failure.
	 */
	public function uksort(var callback) -> boolean;

}
