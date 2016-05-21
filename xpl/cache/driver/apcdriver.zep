namespace Xpl\Cache\Driver;

use Xpl\Cache\Item;
use DateTime;

class ApcDriver extends AbstractDriver
{

	/**
	 * Checks whether the driver is available for use.
	 *
	 * @return boolean
	 */
	public static function isAvailable() -> boolean
    {
		if extension_loaded("apc") {
            if ini_get("apc.enabled") {
                if php_sapi_name() !== "cli" || ini_get("apc.enable_cli") {
                    return true;
                }
            }
		}

        return false;
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
		return apc_exists(key);
	}

	/**
	 * Returns a value from the cache.
	 *
	 * @param string key Item key.
	 *
	 * @return mixed Cached value, if it exists, otherwise null.
	 */
	protected function get(string key) -> var | null
    {
		return apc_fetch(key);
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
		apc_store(key, value, ttl);
	}

	/**
	 * Removes an item from the cache.
	 *
	 * @param string key Item key
	 */
	public function delete(string key) -> void
    {
		apc_delete(key);
	}

	/**
	 * Clears all items from the cache.
	 */
	public function clear() -> void
    {
		apc_clear_cache("user");
	}

	/**
	 * Returns a new Item on hit.
	 *
	 * @param string key
	 * @param mixed value
	 *
	 * @return \Xpl\Cache\Item
	 */
	protected function hit(string! key, var value) -> <Item>
	{
		var cacheInfo, itemInfo, ttl, mtime, item;

		let item = new Item(key, true, value);

		let cacheInfo = apc_cache_info("user");

		for itemInfo in cacheInfo["cache_list"] {
			if itemInfo["key"] === key {
				if fetch ttl, itemInfo["ttl"] {
					if fetch mtime, itemInfo["mtime"] {
						item->expiresAt(new DateTime("@" . (mtime + ttl)));
					}
				}
				break;
			}
		}

		return item;
	}

}
