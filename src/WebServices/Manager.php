<?php

namespace xpl\WebServices;

class Manager
{
	/**
	 * @var \xpl\WebServices\Client\RequestAdapterInterface
	 */
	protected static $adapter;
	
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
		return isset(static::$adapter) ? static::$adapter : null;
	}
	
	/**
	 * @return boolean
	 */
	public static function hasAdapter() {
		return isset(static::$adapter);
	}
	
	/**
	 * @return \xpl\WebServices\Client
	 */
	public static function getClient() {
		if (isset(static::$adapter)) {
			return new Client(static::$adapter);
		}
	}
}
