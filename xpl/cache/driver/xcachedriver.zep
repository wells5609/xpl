namespace Xpl\Cache\Driver;

class XCacheDriver extends AbstractDriver
{

	/**
	 * Checks whether the driver is available for use.
	 *
	 * @return boolean
	 */
	public static function isAvailable() -> boolean
    {
		return extension_loaded("xcache");
	}

	/**
	 * Whether the given item exists in the cache.
	 *
	 * @param string key Item key.
	 *
	 * @return boolean True if a cached value exists, otherwise false.
	 */
	public function exists(string key) -> boolean
    {
		return xcache_isset(key);
	}

	/**
	 * Returns a value from the cache.
	 *
	 * @param string key Item key.
	 * @return mixed Cached value, if it exists, otherwise null.
	 */
	protected function get(string key) -> var | null
    {
		return xcache_get(key);
	}

	/**
	 * Saves a value in the cache.
	 *
	 * @param string key Item key
	 * @param scalar value Item value
	 * @param int ttl [Optional] Cache lifetime in seconds
	 */
	protected function save(string key, var value, int ttl) -> void
    {
		xcache_set(key, value, ttl);
	}

	/**
	 * Removes an item from the cache.
	 *
	 * @param string key Item key
	 */
	public function delete(string key) -> void
    {
		xcache_unset(key);
	}

	/**
	 * Clears all items from the cache.
	 */
	public function clear() -> void
    {
		xcache_clear_cache(XC_TYPE_VAR);
	}

}
