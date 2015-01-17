<?php

namespace xpl\Framework;

/**
 * Static class that holds the global DI container.
 * 
 * Meant to be aliased with something more friendly...
 */
class DiFacade 
{
		
	/**
	 * @var \xpl\Dependency\DI
	 */
	protected static $instance;
	
	/**
	 * @param \xpl\Dependency\DI
	 */
	public static function setInstance(\xpl\Dependency\DI $instance) {
		static::$instance = $instance;
	}
	
	/**
	 * @return \xpl\Dependency\DI
	 */
	public static function getInstance() {
		
		if (! isset(static::$instance)) {
			throw new \RuntimeException("Instance not set.");
		}
		
		return static::$instance;
	}
	
	/**
	 * @param string $key
	 * @return mixed
	 */
	public static function get($key) {
		
		if (! isset(static::$instance)) {
			throw new \RuntimeException("Instance not set.");
		}
		
		return static::$instance->offsetGet($key);
	}
	
	/**
	 * @param string $key
	 * @param mixed $value
	 */
	public static function set($key, $value) {
		
		if (! isset(static::$instance)) {
			throw new \RuntimeException("Instance not set.");
		}
		
		static::$instance->offsetSet($key, $value);
	}
	
	/**
	 * @param string $key
	 * @return boolean
	 */
	public static function has($key) {
		
		if (! isset(static::$instance)) {
			throw new \RuntimeException("Instance not set.");
		}
		
		return static::$instance->offsetExists($key);
	}
	
}
