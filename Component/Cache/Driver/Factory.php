<?php

namespace xpl\Component\Cache\Driver;

class Factory {
	
	public static function detect(array $func_class_map = array()) {
		
		if (empty($func_class_map)) {
			$func_class_map = array(
				'apc_fetch' => 'xpl\\Component\\Cache\\Driver\\ApcDriver',
				'xcache_get' => 'xpl\\Component\\Cache\\Driver\\XCacheDriver',
			);
		}
		
		foreach($func_class_map as $func => $class) {
			if (function_exists($func)) {
				return $class;
			}
		}
		
		return 'xpl\\Component\\Cache\\Driver\\MemoryDriver';
	}
	
	public static function create($driver_class = null) {
		
		if (empty($driver_class)) {
			$driver_class = static::detect();
		} else if (is_array($driver_class)) {
			$driver_class = static::detect($driver_class);
		}
		
		return new $driver_class;
	}
	
}
