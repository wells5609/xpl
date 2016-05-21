<?php

namespace Xpl\Cache;

/**
 * CacheItemPoolInterface generates CacheItemInterface objects.
 * The primary purpose of Cache\CacheItemPoolInterface is to accept a key from
 * the Calling Library and return the associated Cache\CacheItemInterface object.
 * It is also the primary point of interaction with the entire cache collection.
 * All configuration and initialization of the Pool is left up to an
 * Implementing Library.
 */
class ItemPool implements \Psr\Cache\CacheItemPoolInterface
{
    /**
     * @var string
     */
    protected $prefix;

    /**
     * @var \Xpl\Cache\DriverInterface
     */
    protected $driver;

    /**
     * @var array
     */
    protected $items = array();

    /**
     * @var array
     */
    protected $deferred = array();

    /**
     * @var boolean
     */
    protected $commitOnClear = true;

    /**
     * @var boolean
     */
    protected $commitOnSave = false;


    /**
     * Constructor.
     *
     * @param mixed $driver 
     * @param string $prefix 
     * @param int $defaultTtl 
     */
    public function __construct(DriverInterface $driver, $prefix = "", $defaultTtl = 0) {}

    /**
     * Returns the cache driver.
     *
     * @return \Xpl\Cache\DriverInterface
     * The current cache driver instance.
     * @return DriverInterface 
     */
    public function getDriver() {}

    /**
     * Returns a Cache Item representing the specified key.
     * This method must always return a CacheItemInterface object, even in case of
     * a cache miss. It MUST NOT return null.
     *
     * @param string key
     * The key for which to return the corresponding Cache Item.
     * @throws \Xpl\Cache\InvalidArgumentException
     * If the key string is not a legal value a \Psr\Cache\InvalidArgumentException
     * MUST be thrown.
     * @return \Psr\Cache\CacheItemInterface
     * The corresponding Cache Item.
     * @param string $key 
     * @return \Psr\Cache\CacheItemInterface 
     */
    public function getItem($key) {}

    /**
     * Returns a traversable set of cache items.
     *
     * @param array keys
     * An indexed array of keys of items to retrieve.
     * @throws \Psr\Cache\InvalidArgumentException
     * If any of the keys in keys are not a legal value a \Psr\Cache\InvalidArgumentException
     * MUST be thrown.
     * @return array|\Traversable
     * A traversable collection of Cache Items keyed by the cache keys of
     * each item. A Cache item will be returned for each key, even if that
     * key is not found. However, if no keys are specified then an empty
     * traversable MUST be returned instead.
     * @param array $keys 
     * @return \Traversable|\Psr\Cache\CacheItemInterface 
     */
    public function getItems($keys = array()) {}

    /**
     * Confirms if the cache contains specified cache item.
     * Note: This method MAY avoid retrieving the cached value for performance reasons.
     * This could result in a race condition with CacheItemInterface::get(). To avoid
     * such situation use CacheItemInterface::isHit() instead.
     *
     * @param string key
     * The key for which to check existence.
     * @throws \Psr\Cache\InvalidArgumentException
     * If the key string is not a legal value a \Psr\Cache\InvalidArgumentException
     * MUST be thrown.
     * @return bool
     * True if item exists in the cache, false otherwise.
     * @param string $key 
     * @return bool 
     */
    public function hasItem($key) {}

    /**
     * Deletes all items in the pool.
     *
     * @return bool
     * True if the pool was successfully cleared. False if there was an error.
     * @return bool 
     */
    public function clear() {}

    /**
     * Removes the item from the pool.
     *
     * @param string key
     * The key for which to delete
     * @throws \Psr\Cache\InvalidArgumentException
     * If the key string is not a legal value a \Psr\Cache\InvalidArgumentException
     * MUST be thrown.
     * @return bool
     * True if the item was successfully removed. False if there was an error.
     * @param string $key 
     * @return bool 
     */
    public function deleteItem($key) {}

    /**
     * Removes multiple items from the pool.
     *
     * @param array keys
     * An array of keys that should be removed from the pool.
     * @throws \Psr\Cache\InvalidArgumentException
     * If any of the keys in keys are not a legal value a \Psr\Cache\InvalidArgumentException
     * MUST be thrown.
     * @return bool
     * True if the items were successfully removed. False if there was an error.
     * @param array $keys 
     * @return bool 
     */
    public function deleteItems($keys) {}

    /**
     * Persists a cache item immediately.
     *
     * @param \Psr\Cache\CacheItemInterface item
     * The cache item to save.
     * @return bool
     * True if the item was successfully persisted. False if there was an error.
     * @param mixed $item 
     * @return bool 
     */
    public function save(\Psr\Cache\CacheItemInterface $item) {}

    /**
     * Sets a cache item to be persisted later.
     *
     * @param \Psr\Cache\CacheItemInterface item
     * The cache item to save.
     * @return bool
     * False if the item could not be queued or if a commit was attempted and failed. True otherwise.
     * @param mixed $item 
     * @return bool 
     */
    public function saveDeferred(\Psr\Cache\CacheItemInterface $item) {}

    /**
     * Persists any deferred cache items.
     *
     * @return bool
     * True if all not-yet-saved items were successfully saved or there were none. False otherwise.
     * @return bool 
     */
    public function commit() {}

    /**
     * Resets the cache items in memory.
     *
     * @return void 
     */
    public function reset() {}

    /**
     * Checks if an item key is valid.
     *
     * @param string $key 
     * @return boolean 
     */
    public function isValidKey($key) {}

    /**
     * Checks whether the given item is expired.
     *
     * @param mixed $cacheItem 
     * @param \Xpl\Cache\Item  
     * @return boolean 
     */
    public function isItemExpired(Item $cacheItem) {}

}
