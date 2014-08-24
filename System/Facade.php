<?php

namespace xpl\System;

use \xpl\Dependency\Container;

/**
 * Static class that holds the global DI container.
 * 
 * Meant to be aliased with something more friendly...
 */
class Facade {
	
	/**
	 * @var \xpl\Dependency\Container
	 */
	protected static $instance;
	
	/**
	 * @param \xpl\Dependency\Container
	 */
	public static function setInstance(Container $instance) {
		static::$instance = $instance;
	}
	
	/**
	 * @return \xpl\Dependency\Container
	 */
	public static function getInstance() {
		return static::$instance;
	}
	
	public static function __callStatic($func, array $args) {
		return empty($args)
			? static::getInstance()->$func()
			: call_user_func_array(array(static::getInstance(), $func), $args);
	}
	
}
