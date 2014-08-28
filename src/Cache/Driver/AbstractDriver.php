<?php

namespace xpl\Cache\Driver;

use xpl\Cache\Cache;

abstract class AbstractDriver implements CacheDriverInterface
{

	protected $prefix;

	protected $serializer;

	protected $unserializer;

	public function __construct($prefix = null) {
		$this->setPrefix($prefix);
		$this->setSerializeFunctions();
	}

	public function getPrefix($group = Cache::DEFAULT_GROUP) {
		return $this->prefix.$group.'|';
	}
	
	public function setPrefix($prefix = null) {
		$this->prefix = isset($prefix) 
			? $prefix 
			: defined('CACHE_PREFIX') 
				? CACHE_PREFIX 
				: md5($_SERVER['DOCUMENT_ROOT']).'|';
	}
	
	abstract public function exists($id, $group = Cache::DEFAULT_GROUP);

	abstract public function get($id, $group = Cache::DEFAULT_GROUP);

	abstract public function set($id, $value, $group = Cache::DEFAULT_GROUP, $ttl = Cache::DEFAULT_TTL);

	abstract public function delete($id, $group = Cache::DEFAULT_GROUP);

	abstract public function incr($id, $val = 1, $group = Cache::DEFAULT_GROUP, $ttl = Cache::DEFAULT_TTL);

	abstract public function decr($id, $val = 1, $group = Cache::DEFAULT_GROUP, $ttl = Cache::DEFAULT_TTL);

	abstract public function flush();

	abstract public function flushGroup($group);
	
	protected function setSerializeFunctions() {
		$this->serializer = function_exists('igbinary_serialize') ? 'igbinary_serialize' : 'serialize';
		$this->unserializer = function_exists('igbinary_unserialize') ? 'igbinary_unserialize' : 'unserialize';
	}

}
