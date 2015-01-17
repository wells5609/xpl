<?php

namespace xpl\WebServices;

class Manager
{
	/**
	 * @var \xpl\WebServices\Client\RequestAdapterInterface
	 */
	protected static $adapter;
	
	/**
	 * @var string
	 */
	protected static $adapterClass;
	
	/**
	 * Sets the request client adapter object.
	 * 
	 * @param \xpl\WebServices\Client\RequestAdapterInterface $adapter
	 */
	public static function setAdapter(Client\RequestAdapterInterface $adapter) {
		static::$adapter = $adapter;
	}
	
	/**
	 * Sets the request client adapter class.
	 * 
	 * @param string $class
	 */
	public static function setAdapterClass($class) {
		static::$adapterClass = $class;
	}
	
	/**
	 * Returns whether an adapter or adapter class is set.
	 * 
	 * @return boolean
	 */
	public static function hasAdapter() {
		return isset(static::$adapter) || isset(static::$adapterClass);
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
		
		if (isset(static::$adapterClass)) {
			
			$class = static::$adapterClass;
			
			static::setAdapter(new $class);
			
			return static::$adapter;
		}
		
		return null;
	}
	
	/**
	 * Returns a Client instance if an adapter is set.
	 * 
	 * @return \xpl\WebServices\Client
	 */
	public static function getClient() {
		
		if ($adapter = static::getAdapter()) {
		
			return new Client($adapter);
		}
		
		return null;
	}
}
