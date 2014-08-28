<?php

namespace xpl\Cache\Driver;

use xpl\Cache\Cache;

class MemoryDriver extends AbstractDriver
{
	protected $cache = array();

	public function getPrefix($group = Cache::DEFAULT_GROUP) {
		return $group;
	}

	public function exists($id, $group = Cache::DEFAULT_GROUP) {
		return isset($this->cache[$group][$id]);
	}

	public function get($id, $group = Cache::DEFAULT_GROUP) {
		if (! empty($this->cache[$group]) && $this->exists($id, $group))
			return $this->cache[$group][$id];
	}

	public function set($id, $value, $group = Cache::DEFAULT_GROUP, $ttl = Cache::DEFAULT_TTL) {
		$this->cache[$group][$id] = $value;
	}

	public function delete($id, $group = self::DEFAULT_GROUP) {
		unset($this->cache[$group][$id]);
	}

	public function incr($id, $val = 1, $group = Cache::DEFAULT_GROUP, $ttl = Cache::DEFAULT_TTL) {
		$this->cache[$group][$id] += $val;
	}

	public function decr($id, $val = 1, $group = Cache::DEFAULT_GROUP, $ttl = Cache::DEFAULT_TTL) {
		$this->cache[$group][$id] -= $val;
	}

	public function flush() {
		unset($this->cache);
	}

	public function flushGroup($group) {
		unset($this->cache[$group]);
	}

}
