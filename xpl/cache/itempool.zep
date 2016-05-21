namespace Xpl\Cache;

use Closure;
use ArrayObject;
use Psr\Cache\CacheItemInterface;
use Psr\Cache\CacheItemPoolInterface;

/**
 * CacheItemPoolInterface generates CacheItemInterface objects.
 *
 * The primary purpose of Cache\CacheItemPoolInterface is to accept a key from
 * the Calling Library and return the associated Cache\CacheItemInterface object.
 * It is also the primary point of interaction with the entire cache collection.
 * All configuration and initialization of the Pool is left up to an
 * Implementing Library.
 */
class ItemPool implements CacheItemPoolInterface
{

	/**
	 * @var string
	 */
	protected prefix;

	/**
	 * @var \Xpl\Cache\DriverInterface
	 */
	protected driver;

	/**
	 * @var array
	 */
	protected items = [];

	/**
	 * @var array
	 */
	protected deferred = [];

	/**
	 * @var boolean
	 */
	protected commitOnClear = true;

	/**
	 * @var boolean
	 */
	protected commitOnSave = false;

	/**
	 * Constructor.
	 */
	public function __construct(<DriverInterface> driver, string! prefix = "", int! defaultTtl = 0)
    {
		let this->driver = driver;
		let this->prefix = prefix;
	}

	/**
	 * Returns the cache driver.
	 *
	 * @return \Xpl\Cache\DriverInterface
	 * 	 The current cache driver instance.
	 */
	public function getDriver() -> <DriverInterface>
    {
		return this->driver;
	}

    /**
     * Returns a Cache Item representing the specified key.
     *
     * This method must always return a CacheItemInterface object, even in case of
     * a cache miss. It MUST NOT return null.
     *
     * @param string key
     *   The key for which to return the corresponding Cache Item.
     *
     * @throws \Xpl\Cache\InvalidArgumentException
     *   If the key string is not a legal value a \Psr\Cache\InvalidArgumentException
     *   MUST be thrown.
     *
     * @return \Psr\Cache\CacheItemInterface
     *   The corresponding Cache Item.
     */
    public function getItem(string! key) -> <CacheItemInterface>
    {
        var item;

		if ! this->isValidKey(key) {
			throw new InvalidArgumentException("Invalid item key: '" . key . "'.");
		}

        if fetch item, this->items[key] {
			if ! this->isItemExpired(item) {
				return item;
			}
        }

		let item = this->driver->$fetch(this->prefix.key);

		if item->isHit() {
			let this->items[key] = item;
		}

		return item;
	}

    /**
     * Returns a traversable set of cache items.
     *
     * @param array keys
     * An indexed array of keys of items to retrieve.
     *
     * @throws \Psr\Cache\InvalidArgumentException
     *   If any of the keys in keys are not a legal value a \Psr\Cache\InvalidArgumentException
     *   MUST be thrown.
     *
     * @return array|\Traversable
     *   A traversable collection of Cache Items keyed by the cache keys of
     *   each item. A Cache item will be returned for each key, even if that
     *   key is not found. However, if no keys are specified then an empty
     *   traversable MUST be returned instead.
     */
    public function getItems(array! keys = []) -> <\Traversable> | <CacheItemInterface[]>
    {
		var items;

		if count(keys) === 0 {
			return new ArrayObject();
		}

		let items = array_map([this, "getItem"], keys);

		return array_combine(keys, items);
    }

    /**
     * Confirms if the cache contains specified cache item.
     *
     * Note: This method MAY avoid retrieving the cached value for performance reasons.
     * This could result in a race condition with CacheItemInterface::get(). To avoid
     * such situation use CacheItemInterface::isHit() instead.
     *
     * @param string key
     *    The key for which to check existence.
     *
     * @throws \Psr\Cache\InvalidArgumentException
     *   If the key string is not a legal value a \Psr\Cache\InvalidArgumentException
     *   MUST be thrown.
     *
     * @return bool
     *  True if item exists in the cache, false otherwise.
     */
    public function hasItem(string! key) -> boolean
    {
		if ! this->isValidKey(key) {
			throw new InvalidArgumentException("Invalid item key: '" . key . "'.");
		}

    	return this->driver->exists(this->prefix.key);
    }

    /**
     * Deletes all items in the pool.
     *
     * @return bool
     *   True if the pool was successfully cleared. False if there was an error.
     */
    public function clear() -> boolean
    {
        var prefix, driver, key, e;

        let prefix = this->prefix;
        let driver = this->driver;

		try {

			for key, _ in this->items {
				driver->delete(prefix.key);
			}

			let this->items = [];

    	} catch \Exception, e {
    		return false;
    	}

		if this->commitOnClear === true {
			return this->commit();
		}

		return true;
    }

    /**
     * Removes the item from the pool.
     *
     * @param string key
     *   The key for which to delete
     *
     * @throws \Psr\Cache\InvalidArgumentException
     *   If the key string is not a legal value a \Psr\Cache\InvalidArgumentException
     *   MUST be thrown.
     *
     * @return bool
     *   True if the item was successfully removed. False if there was an error.
     */
    public function deleteItem(string! key) -> boolean
    {
        var e;

		if ! this->isValidKey(key) {
			throw new InvalidArgumentException("Invalid item key: '" . key . "'.");
		}

		try {

			this->driver->delete(this->prefix.key);

            unset this->items[key];

		} catch \Exception, e {
			return false;
		}

		return true;
	}

    /**
     * Removes multiple items from the pool.
     *
     * @param array keys
     *   An array of keys that should be removed from the pool.

     * @throws \Psr\Cache\InvalidArgumentException
     *   If any of the keys in keys are not a legal value a \Psr\Cache\InvalidArgumentException
     *   MUST be thrown.
     *
     * @return bool
     *   True if the items were successfully removed. False if there was an error.
     */
    public function deleteItems(array! keys) -> boolean
    {
        boolean success = true;
        var driver, prefix, key, e;

        let driver = this->driver;
        let prefix = this->prefix;

    	for key in keys {

    		if ! this->isValidKey(key) {
				throw new InvalidArgumentException("Invalid item key: '" . key . "'.");
			}

			try {

				driver->delete(prefix.key);

                unset this->items[key];

            } catch \Exception, e {
				let success = false;
			}
    	}

		return success;
    }

    /**
     * Persists a cache item immediately.
     *
     * @param \Psr\Cache\CacheItemInterface item
     *   The cache item to save.
     *
     * @return bool
     *   True if the item was successfully persisted. False if there was an error.
     */
    public function save(<CacheItemInterface> item) -> boolean
    {
        var e;
        try {
	    	return this->driver->put(item);
		} catch \Exception, e {
			return false;
		}
    }

    /**
     * Sets a cache item to be persisted later.
     *
     * @param \Psr\Cache\CacheItemInterface item
     *   The cache item to save.
     *
     * @return bool
     *   False if the item could not be queued or if a commit was attempted and failed. True otherwise.
     */
    public function saveDeferred(<CacheItemInterface> item) -> boolean
    {
        var e;
    	try {
			let this->deferred[] = item;
		} catch \Exception, e {
			return false;
		}

		return true;
    }

    /**
     * Persists any deferred cache items.
     *
     * @return bool
     *   True if all not-yet-saved items were successfully saved or there were none. False otherwise.
     */
    public function commit() -> boolean
    {
        int count, saved = 0;
        var deferred, item, e;

        let deferred = this->deferred;
    	let count = (int)count(deferred);

		if count === 0 {
			return true;
		}

		try {
            for item in deferred {
				if this->save(item) {
					let saved += 1;
				}
			}
		} catch \Exception, e {
			return false;
		}

		let this->deferred = [];

		return saved === count;
	}

	/**
	 * Resets the cache items in memory.
	 *
	 * @return void
	 */
	public function reset() -> void
	{
		let this->items = [];
	}

	/**
	 * Checks if an item key is valid.
	 *
	 * @param string key
	 *
	 * @return boolean
	 */
	public function isValidKey(string! key) -> boolean
    {
        var len;
        let len = strlen(key);

		if len === 0 {
			return false;
		}

        return len === strcspn(key, "{}()/\\@:");
	}

	/**
	 * Checks whether the given item is expired.
	 *
	 * @param \Xpl\Cache\Item
	 *
	 * @return boolean
	 */
	public function isItemExpired(<Item> cacheItem) -> boolean
	{
		return time() >= cacheItem->getExpiration();
	}

}
