<?php

namespace Xpl\Cache;


interface DriverInterface
{

    /**
     * Whether the given item exists in the cache.
     *
     * @param string $key Item key.
     * @return boolean if a cached value exists, otherwise false.
     */
    public function exists($key);

    /**
     * Fetches an Item from the cache backend.
     *
     * @param string $key 
     * @return \Xpl\Cache\Item 
     */
    public function fetch($key);

    /**
     * Saves the given Item to the cache backend.
     *
     * @param mixed $cacheItem 
     * @param \Xpl\Cache\Item  
     * @return boolean 
     */
    public function put(Item $cacheItem);

    /**
     * Removes an item from the cache.
     *
     * @param string $key Item key
     * @return void 
     */
    public function delete($key);

    /**
     * Clears all items from the cache.
     *
     * @return void 
     */
    public function clear();

}
