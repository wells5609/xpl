<?php

namespace xpl\Component\Cache\Driver;

use xpl\Component\Cache\Cache;

class ApcDriver extends AbstractDriver
{

	public function exists($id, $group = Cache::DEFAULT_GROUP) {
		return apc_exists($this->getPrefix($group).$id);
	}

	public function getGroup($group = Cache::DEFAULT_GROUP) {
		return apc_fetch($this->getPrefix($group));
	}

	public function get($id, $group = Cache::DEFAULT_GROUP) {
		return apc_fetch($this->getPrefix($group).$id);
	}

	public function set($id, $value, $group = Cache::DEFAULT_GROUP, $ttl = Cache::DEFAULT_TTL) {
		return apc_store($this->getPrefix($group).$id, $value, $ttl);
	}

	public function delete($id, $group = Cache::DEFAULT_GROUP) {
		return apc_delete($this->getPrefix($group).$id);
	}

	public function incr($id, $val = 1, $group = Cache::DEFAULT_GROUP, $ttl = Cache::DEFAULT_TTL) {
		return apc_inc($this->getPrefix($group).$id, $val);
	}

	public function decr($id, $val = 1, $group = Cache::DEFAULT_GROUP, $ttl = Cache::DEFAULT_TTL) {
		return apc_dec($this->getPrefix($group).$id, $val);
	}

	public function flush() {
		return apc_delete($this->prefix);
	}

	public function flushGroup($group) {
		return apc_delete($this->getPrefix($group));
	}

}
