<?php

namespace xpl\Component\System;

use \xpl\Component\Dependency\Container;

/**
 * Static class that holds the "global" system registry.
 * 
 * Meant to be aliased with something more friendly (e.g. "System").
 */
class StaticFacade {
	
	/**
	 * @var \xpl\Component\Dependency\Container
	 */
	protected static $instance;
	
	/**
	 * @param \xpl\Component\Dependency\Container
	 */
	public static function setInstance(Container $instance) {
		static::$instance = $instance;
	}
	
	/**
	 * @return \xpl\Component\Dependency\Container
	 * 
	 * @throws \RuntimeException if container instance not set.
	 */
	public static function getInstance() {
		
		if (isset(static::$instance)) {
			return static::$instance;
		}
		
		throw new \RuntimeException("No dependency injection container instance set.");
	}
	
	public static function __callStatic($func, array $args) {
		return empty($args)
			? static::getInstance()->$func()
			: call_user_func_array(array(static::getInstance(), $func), $args);
	}
	
}
