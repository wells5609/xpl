<?php

namespace xpl\Cache\Driver;

class Factory {
	
	public static function detect(array $func_class_map = array()) {
		
		if (empty($func_class_map)) {
			
			$func_class_map = array(
				'xcache_get' => 'xpl\\Cache\\Driver\\XCacheDriver',
				'apcu_fetch' => 'xpl\\Cache\\Driver\\ApcuDriver',
				'apc_fetch' => 'xpl\\Cache\\Driver\\ApcDriver',
			);
		}
		
		foreach($func_class_map as $func => $class) {
			
			if (function_exists($func)) {
				
				if ('apcu_fetch' === $func && ! apcu_enabled()) {
					continue;
				}
				
				return $class;
			}
		}
		
		return 'xpl\\Cache\\Driver\\MemoryDriver';
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
