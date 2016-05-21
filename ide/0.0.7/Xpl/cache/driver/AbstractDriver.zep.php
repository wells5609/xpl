<?php

namespace Xpl\Cache\Driver;


abstract class AbstractDriver implements \Xpl\Cache\DriverInterface
{

    /**
     * Saves the given Item to the cache backend.
     *
     * @param mixed $cacheItem 
     * @param \Xpl\Cache\Item  
     * @return boolean 
     */
    public function put(\Xpl\Cache\Item $cacheItem) {}

    /**
     * Fetches an Item from the cache backend.
     *
     * @param string $key 
     * @param \Xpl\Cache\Item $cacheItem 
     * @return \Xpl\Cache\Item 
     */
    public function fetch($key) {}

    /**
     * Returns a value from the cache.
     *
     * @param string $key Item key.
     * @return mixed value, if it exists, otherwise null.
     */
    abstract protected function get($key);

    /**
     * Saves a value in the cache.
     *
     * @param string $key Item key
     * @param mixed $value Item value
     * @param int $ttl Cache lifetime in seconds
     * @return void 
     */
    abstract protected function save($key, $value, $ttl);

    /**
     * Returns a new Item on hit.
     *
     * @param string $key 
     * @param mixed $value 
     * @return \Xpl\Cache\Item 
     */
    protected function hit($key, $value) {}

    /**
     * Creates a new Item on miss.
     *
     * @param string $key 
     * @return \Xpl\Cache\Item 
     */
    protected function miss($key) {}

}
