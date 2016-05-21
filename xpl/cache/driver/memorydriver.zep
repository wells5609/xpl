namespace Xpl\Cache\Driver;

class MemoryDriver extends AbstractDriver
{

	/**
	 * @var array
	 */
	protected storage = [];

	/**
	 * Whether the given item exists in the cache.
	 *
	 * @param string key Item key.
	 * @return boolean True if a cached value exists, otherwise false.
	 */
	public function exists(string key) -> boolean
    {
		return isset this->storage[key];
	}

	/**
	 * Returns a value from the cache.
	 *
	 * @param string key Item key.
	 * @return mixed Cached value, if it exists, otherwise null.
	 */
	protected function get(string key) -> var | null
    {
        var value;

        if fetch value, this->storage[key] {
            return value;
        }

        return null;
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
		let this->storage[key] = value;
	}

	/**
	 * Removes an item from the cache.
	 *
	 * @param string key Item key
	 */
	public function delete(string key) -> void
    {
		unset this->storage[key];
	}

	/**
	 * Clears all items from the cache.
	 */
	public function clear() -> void
    {
		let this->storage = [];
	}

}
