namespace Xpl\Cache;

interface DriverInterface
{

	/**
	 * Whether the given item exists in the cache.
	 *
	 * @param string key Item key.
	 *
	 * @return boolean True if a cached value exists, otherwise false.
	 */
	public function exists(string key) -> boolean;

	/**
	 * Fetches an Item from the cache backend.
	 *
	 * @param string key
	 *
	 * @return \Xpl\Cache\Item
	 */
	public function $fetch(string key) -> <Item>;

	/**
	 * Saves the given Item to the cache backend.
	 *
	 * @param \Xpl\Cache\Item
	 *
	 * @return boolean
	 */
	public function put(<Item> cacheItem) -> boolean;

	/**
	 * Removes an item from the cache.
	 *
	 * @param string key Item key
	 *
	 * @return void
	 */
	public function delete(string key) -> void;

	/**
	 * Clears all items from the cache.
	 *
	 * @return void
	 */
	public function clear() -> void;

}
