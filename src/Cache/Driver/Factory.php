<?php

namespace xpl\Cache\Driver;

class Factory 
{
	protected $map;
	
	public function __construct(array $func_class_map = null) {
		if (! empty($func_class_map)) {
			$this->map = $func_class_map;
		} else {
			$this->map = array(
				'xcache_get' => 'xpl\\Cache\\Driver\\XCacheDriver',
				'apcu_fetch' => 'xpl\\Cache\\Driver\\ApcuDriver',
				'apc_fetch' => 'xpl\\Cache\\Driver\\ApcDriver',
			);
		}
	}
	
	public function detectClass() {
		
		foreach($this->map as $func => $class) {
			
			if (function_exists($func)) {
				
				if ('apcu_fetch' === $func && ! apcu_enabled()) {
					continue;
				}
				
				return $class;
			}
		}
		
		return 'xpl\\Cache\\Driver\\MemoryDriver';
	}
	
	public function create($driver_class = null) {
		
		$class = empty($driver_class) ? $this->detectClass() : $driver_class;
		
		return new $class();
	}
	
}
