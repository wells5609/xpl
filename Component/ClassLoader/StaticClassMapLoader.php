<?php

namespace xpl\Component\ClassLoader;

class StaticClassMapLoader {
	
	protected static $loader;
	
	public static function setLoader(ClassMapLoader $loader) {
		static::$loader = $loader;
	}
	
	public static function getLoader() {
		return isset(static::$loader) ? static::$loader : null;
	}
}
