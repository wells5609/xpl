<?php

namespace xpl\Cache;

use xpl\Cache\Driver\CacheDriverInterface;

class Cache
{
	use \xpl\Common\Singleton;
	
	/**
	 * Default TTL (2 days)
	 * @var int
	 */
	const DEFAULT_TTL = 172800;
	
	/**
	 * Default group ('default').
	 * @var string
	 */
	const DEFAULT_GROUP = 'default';

	/**
	 * Cache driver
	 * @var \Cache\Driver\CacheDriverInterface
	 */
	protected $driver;
	
	public function start() {
		if (! isset($this->driver)) {
			$factory = new Driver\Factory();
			$this->setDriver($factory->create());
		}
	}
	
	public function setDriver(CacheDriverInterface $driver) {
		$this->driver = $driver;
	}
	
	public function getDriver() {
		return $this->driver;
	}

	public function getPrefix($group = self::DEFAULT_GROUP) {
		return $this->driver->getPrefix($group);
	}

	public function exists($id, $group = self::DEFAULT_GROUP) {
		return $this->driver->exists($id, $group);
	}

	public function get($id, $group = self::DEFAULT_GROUP) {
		return $this->driver->get($id, $group);
	}

	public function set($id, $value, $group = self::DEFAULT_GROUP, $ttl = self::DEFAULT_TTL) {
		return $this->driver->set($id, $value, $group, $ttl);
	}

	public function delete($id, $group = self::DEFAULT_GROUP) {
		return $this->driver->delete($id, $group);
	}

	public function incr($id, $val = 1, $group = self::DEFAULT_GROUP, $ttl = self::DEFAULT_TTL) {
		return $this->driver->incr($id, $val, $group, $ttl);
	}

	public function decr($id, $val = 1, $group = self::DEFAULT_GROUP, $ttl = self::DEFAULT_TTL) {
		return $this->driver->decr($id, $val, $group, $ttl);
	}

	public function flush() {
		return $this->driver->flush();
	}

	public function flushGroup($group) {
		return $this->driver->flushGroup($group);
	}

}
