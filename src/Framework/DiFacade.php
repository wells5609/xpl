<?php

namespace xpl\Framework;

use xpl\Dependency\DI;

/**
 * Static class that holds the global DI container.
 * 
 * Meant to be aliased with something more friendly...
 */
class DiFacade {
	
	/**
	 * @var \xpl\Dependency\DI
	 */
	protected static $instance;
	
	/**
	 * @param \xpl\Dependency\DI
	 */
	public static function setInstance(DI $instance) {
		static::$instance = $instance;
	}
	
	/**
	 * @return \xpl\Dependency\DI
	 */
	public static function getInstance() {
		return static::$instance;
	}
	
}
