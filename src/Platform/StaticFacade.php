<?php

namespace xpl\Platform;

class StaticFacade {
	
	protected static $identifier;
	
	public static function __callStatic($func, array $args) {
		
		$object = Platform::get(static::$identifier);
		
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
