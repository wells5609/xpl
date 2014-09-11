<?php

namespace xpl\WebServices;

class Manager
{
	/**
	 * @var \xpl\WebServices\Client\RequestAdapterInterface
	 */
	protected static $adapter;
	
	protected static $adapter_class;
	
	public static function setAdapterClass($class) {
		static::$adapter_class = $class;
	}
	
	/**
	 * Sets the request client adapter.
	 * 
	 * @param \xpl\WebServices\Client\RequestAdapterInterface $adapter
	 * 
	 * @return void
	 */
	public static function setAdapter(Client\RequestAdapterInterface $adapter) {
		static::$adapter = $adapter;
	}
	
	/**
	 * Returns the request client adapter, if set.
	 * 
	 * @return \xpl\WebServices\Client\RequestAdapterInterface
	 */
	public static function getAdapter() {
		
		if (isset(static::$adapter)) {
			return static::$adapter;
		}
		
		if (isset(static::$adapter_class)) {
			$class = static::$adapter_class;
			static::setAdapter(new $class);
			return static::$adapter;
		}
	}
	
	/**
	 * @return boolean
	 */
	public static function hasAdapter() {
		return isset(static::$adapter) || isset(static::$adapter_class);
	}
	
	/**
	 * @return \xpl\WebServices\Client
	 */
	public static function getClient() {
		if ($adapter = static::getAdapter()) {
			return new Client($adapter);
		}
	}
}
