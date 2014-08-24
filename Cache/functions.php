<?php

namespace xpl\Cache {
	class functions {
		// dummy class
	}
}

namespace {
	
	use xpl\Cache\Cache;
		
	/**
	 * Returns a cached value.
	 */
	function cache_get($id, $group = Cache::DEFAULT_GROUP) {
		return Cache::instance()->get($id, $group);
	}
	
	/**
	 * Sets a cached value.
	 */
	function cache_set($id, $value, $group = Cache::DEFAULT_GROUP, $ttl = Cache::DEFAULT_TTL) {
		return Cache::instance()->set($id, $value, $group, $ttl);
	}
	
	/**
	 * Returns whether a given key is cached.
	 */
	function cache_isset($id, $group = Cache::DEFAULT_GROUP) {
		return Cache::instance()->exists($id, $group);
	}
	
	/**
	 * Deletes a cached value.
	 */
	function cache_unset($id, $group = Cache::DEFAULT_GROUP) {
		return Cache::instance()->delete($id, $group);
	}
	
	/** &Alias of cache_unset() */
	function cache_delete($id, $group = Cache::DEFAULT_GROUP) {
		return Cache::instance()->delete($id, $group);
	}
	
	/**
	 * Increments a cached value.
	 */
	function cache_incr($id, $value = 1, $group = Cache::DEFAULT_GROUP, $ttl = Cache::DEFAULT_TTL) {
		return Cache::instance()->incr($id, $group);
	}
	
	/**
	 * Decrements a cached value.
	 */
	function cache_decr($id, $value = 1, $group = Cache::DEFAULT_GROUP, $ttl = Cache::DEFAULT_TTL) {
		return Cache::instance()->decr($id, $group);
	}
	
	/**
	 * Flushes all values from a cache group.
	 */
	function cache_flush_group($group) {
		return Cache::instance()->flushGroup($group);
	}
	
	/**
	 * Flushes the entire cache, or only a group if given.
	 */
	function cache_flush($group = null) {
		return empty($group) 
			? Cache::instance()->flush() 
			: Cache::instance()->flushGroup($group);
	}
	
	/**
	 * Whether the cache persists (i.e. we have a "real" driver, not memory).
	 */
	function cache_persists() {
		return (! Cache::instance()->getDriver() instanceof \xpl\Cache\Driver\MemoryDriver);
	}
	
}
