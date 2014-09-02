<?php

namespace xpl\System;

use xpl\Dependency\DI;

/**
 * Static class that holds the global DI container.
 * 
 * Meant to be aliased with something more friendly...
 */
class Facade {
	
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
