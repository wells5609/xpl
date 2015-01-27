<?php

namespace xpl\Platform;

use xpl\Dependency\DI;
use RuntimeException;
use InvalidArgumentException;

class Platform
{

	/**
	 * @var \xpl\Dependency\DI
	 */
	protected static $di;

	/**
	 * Creates DI if not given and sets as static property.
	 *
	 * @param \xpl\Dependency\DI $di [Optional] DI container.
	 * @param string $file [Optional] File that sets the DI components.
	 * @return \xpl\Dependency\DI
	 */
	public static function init(DI $di = null, $file = null) {

		if (! isset($di)) {
			$di = new DI();
		}
		
		// Allow static access to one instance of DI container
		static::$di = $di;
		
		// Use default di.php file from /inc
		if (! isset($file)) {
			$file = __DIR__.'/inc/di.php';

		} else if (! is_readable($file)) {
			throw new InvalidArgumentException("Unreadable DI file given: '$file'.");
		}
		
		static::requireFile($file, static::$di);

		return static::$di;
	}

	/**
	 * Registers the DI components' static facades.
	 * 
	 * @param string $file [Optional] File containing the facade definitions.
	 */
	public static function loadFacades($file = null) {
			
		// Use default facades.php file from /inc
		if (! isset($file)) {
			$file = __DIR__.'/inc/facades.php';

		} else if (! is_readable($file)) {
			throw new InvalidArgumentException("Unreadable facades file given: '$file'.");
		}
		
		static::requireFile($file);
	}

	/**
	 * Loads the xpl functions.
	 * 
	 * @param string $file [Optional] File containing the function definitions.
	 */
	public static function loadFunctions($file = null) {

		// Use default functions.php file from /inc
		if (! isset($file)) {
			
			// Create a class alias "xpl".
			// The alias is used in the functions.php file below
			class_alias(__CLASS__, 'xpl');
			
			$file = __DIR__.'/inc/functions.php';

		} else if (! is_readable($file)) {
			throw new InvalidArgumentException("Unreadable functions file given: '$file'.");
		}
		
		// Include all xpl functions
		static::requireFile($file);
	}

	/**
	 * Sets the class aliases.
	 * 
	 * @param string $file [Optional] File containing the alias declarations.
	 */
	public static function loadAliases($file = null) {
		
		// Use default aliases.php file from /inc
		if (! isset($file)) {
			$file = __DIR__.'/inc/aliases.php';

		} else if (! is_readable($file)) {
			throw new InvalidArgumentException("Unreadable aliases file given: '$file'.");
		}
		
		static::requireFile($file);
	}
	
	/**
	 * Loads everything: DI, facades, functions, and aliases (in that order).
	 * 
	 * @return \xpl\Dependency\DI
	 */
	public static function load() {
		
		if (! isset(static::$di)) {
			static::init();
		}
		
		static::loadFacades();
		static::loadFunctions();
		static::loadAliases();
		
		return static::$di;
	}

	/**
	 * Includes a file using require_once in limited scope.
	 *
	 * If the 2nd argument is given, it is included within the scope as "$di".
	 *
	 * @param string $file File to load.
	 * @param \xpl\Dependency\DI $di [Optional] DI container.
	 */
	public static function requireFile($file, DI $di = null) {
		
		$require = function ($__file, DI $di = null) {
			require_once $__file;
		};
		
		$require($file, $di);
	}

	/**
	 * @return \xpl\Dependency\DI
	 */
	public static function getDi() {

		if (! isset(static::$di)) {
			throw new RuntimeException("DI instance not set.");
		}

		return static::$di;
	}

	/**
	 * @param string $key
	 * @return mixed
	 */
	public static function get($key) {

		if (! isset(static::$di)) {
			throw new RuntimeException("DI instance not set.");
		}

		return static::$di->resolve($key);
	}

	/**
	 * @param string $key
	 * @param mixed $value
	 */
	public static function set($key, $value) {

		if (! isset(static::$di)) {
			throw new RuntimeException("DI instance not set.");
		}

		static::$di->offsetSet($key, $value);
	}

	/**
	 * @param string $key
	 * @return boolean
	 */
	public static function has($key) {

		if (! isset(static::$di)) {
			throw new RuntimeException("DI instance not set.");
		}

		return static::$di->has($key);
	}

}
