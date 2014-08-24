<?php

namespace xpl\Cache\Driver;

use xpl\Cache\Cache;

class ApcuDriver extends AbstractDriver
{

	public function exists($id, $group = Cache::DEFAULT_GROUP) {
		return apcu_exists($this->getPrefix($group).$id);
	}

	public function getGroup($group = Cache::DEFAULT_GROUP) {
		return apcu_fetch($this->getPrefix($group));
	}

	public function get($id, $group = Cache::DEFAULT_GROUP) {
		return apcu_fetch($this->getPrefix($group).$id);
	}

	public function set($id, $value, $group = Cache::DEFAULT_GROUP, $ttl = Cache::DEFAULT_TTL) {
		return apcu_store($this->getPrefix($group).$id, $value, $ttl);
	}

	public function delete($id, $group = Cache::DEFAULT_GROUP) {
		return apcu_delete($this->getPrefix($group).$id);
	}

	public function incr($id, $val = 1, $group = Cache::DEFAULT_GROUP, $ttl = Cache::DEFAULT_TTL) {
		return apcu_inc($this->getPrefix($group).$id, $val);
	}

	public function decr($id, $val = 1, $group = Cache::DEFAULT_GROUP, $ttl = Cache::DEFAULT_TTL) {
		return apcu_dec($this->getPrefix($group).$id, $val);
	}

	public function flush() {
		return apcu_delete($this->prefix);
	}

	public function flushGroup($group) {
		return apcu_delete($this->getPrefix($group));
	}

}
