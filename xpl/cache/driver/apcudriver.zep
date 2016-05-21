namespace Xpl\Cache\Driver;

use Xpl\Cache\Item;
use DateTime;

class ApcuDriver extends AbstractDriver
{

	/**
	 * Checks whether the driver is available for use.
	 *
	 * @return boolean
	 */
	public static function isAvailable() -> boolean
    {
		if extension_loaded("apcu") {
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
		return apcu_exists(key);
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
		return apcu_fetch(key);
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
		apcu_store(key, value, ttl);
	}

	/**
	 * Removes an item from the cache.
	 *
	 * @param string key Item key
	 */
	public function delete(string key) -> void
    {
		apcu_delete(key);
	}

	/**
	 * Clears all items from the cache.
	 */
	public function clear() -> void
    {
		apcu_clear_cache();
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
		var item, cacheInfo, ttl, mtime;

		let item = new Item(key, true, value);
		let cacheInfo = apcu_key_info(key);

		if typeof cacheInfo == "array" {
			if fetch ttl, cacheInfo["ttl"] {
				if fetch mtime, cacheInfo["mtime"] {
					item->expiresAt(new DateTime("@" . (mtime + ttl)));
				}
			}
		}

		return item;
	}
}
