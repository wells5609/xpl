<?php

namespace xpl\Framework;

class StaticFacade {
	
	private static $di;
	protected static $identifier;
	
	public static function setDI(DI $di) {
		self::$di = $di;
	}
	
	public static function __callStatic($func, array $args) {
		
		$object = self::$di[static::$identifier];
		
		if (! $object) {
			trigger_error("Cannot get object for function call: '$func'.", E_USER_WARNING);
			return null;
		}
		
		switch(count($args)) {
			case 0:
				return $object->$func();
			case 1:
				return $object->$func($args[0]);
			case 2:
				return $object->$func($args[0], $args[1]);
			case 3:
				return $object->$func($args[0], $args[1], $args[2]);
			default:
				return call_user_func_array(array($object, $func), $args);
		}
	}
	
}
