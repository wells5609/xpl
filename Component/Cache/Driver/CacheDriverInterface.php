<?php

namespace xpl\Component\Cache\Driver;

use xpl\Component\Cache\Cache;

interface CacheDriverInterface {
	
	public function getPrefix($group = Cache::DEFAULT_GROUP);
	
	public function exists($id, $group = Cache::DEFAULT_GROUP);
	
	public function get($id, $group = Cache::DEFAULT_GROUP);

	public function set($id, $value, $group = Cache::DEFAULT_GROUP, $ttl = Cache::DEFAULT_TTL);

	public function delete($id, $group = Cache::DEFAULT_GROUP);

	public function incr($id, $val = 1, $group = Cache::DEFAULT_GROUP, $ttl = Cache::DEFAULT_TTL);

	public function decr($id, $val = 1, $group = Cache::DEFAULT_GROUP, $ttl = Cache::DEFAULT_TTL);

	public function flush();

	public function flushGroup($group);
}
