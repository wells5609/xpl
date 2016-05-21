<?php

namespace Xpl\Cache\Driver;


class XCacheDriver extends \Xpl\Cache\Driver\AbstractDriver
{

    /**
     * Checks whether the driver is available for use.
     *
     * @return boolean 
     */
    public static function isAvailable() {}

    /**
     * Whether the given item exists in the cache.
     *
     * @param string $key Item key.
     * @return boolean if a cached value exists, otherwise false.
     */
    public function exists($key) {}

    /**
     * Returns a value from the cache.
     *
     * @param string $key Item key.
     * @return mixed value, if it exists, otherwise null.
     */
    protected function get($key) {}

    /**
     * Sets a value in the cache.
     *
     * @param string $key Item key
     * @param scalar $value Item value
     * @param int $ttl [Optional] Cache lifetime in seconds
     */
    protected function set($key, $value, $ttl) {}

    /**
     * Removes an item from the cache.
     *
     * @param string $key Item key
     */
    public function delete($key) {}

    /**
     * Clears all items from the cache.
     */
    public function clear() {}

}
