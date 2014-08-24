<?php

use xpl\Utility\Filesystem\Container as Paths;

class Env {
	
	const DEV	= 'development';
	const PROD	= 'production';
	const STAGE	= 'staging';
	
	protected static $type;
	protected static $paths;
	protected static $vars = array(
		'charset' => 'UTF-8',
		'timezone' => 'UTC',
		'debug' => false,
		'domain' => null,
		'subdomain' => null,
	);
	
	public static function init($type, Paths $paths = null) {
		static::setType($type);
		static::$paths = $paths ?: new Paths;
	}
	
	/**
	 * Returns a directory path.
	 * 
	 * @param string $name [Optional] Name of directory, or null for root.
	 * @return string Filesystem path.
	 */
	public static function getPath($name = null) {
		
		if (null === $name) {
			return static::$paths->getRootPath();
		}
		
		if ($path = static::$paths->getPath($name)) {
			return $path;
		}
		
		return static::$paths->getRootPath().trim($name, '/\\').DIRECTORY_SEPARATOR;
	}
	
	public static function setType($type) {
		
		if (! in_array($type, array(static::DEV, static::PROD, static::STAGE), true)) {
			throw new \InvalidArgumentException("Invalid environment type: '$type'.");
		}
		
		static::$type = $type;
	}
	
	public static function getType() {
		return static::$type;
	}
	
	public static function isDev() {
		return static::$type === static::DEV;
	}
	
	public static function isProd() {
		return static::$type === static::PROD;
	}
	
	public static function isStaging() {
		return static::$type === static::STAGE;
	}
	
	public static function set($var, $value) {
		static::$vars[$var] = $value;
	}
	
	public static function get($var) {
		return isset(static::$vars[$var]) ? static::$vars[$var] : null;
	}
	
	public static function has($var) {
		return array_key_exists($var, static::$vars);
	}
	
	/**
	 * Whether debugging is enabled.
	 * 
	 * @return boolean
	 */
	public function isDebug() {
		return (bool) static::$vars['debug'];
	}
	
	/**
	 * Returns the environment character set.
	 * 
	 * @return string
	 */
	public function getCharset() {
		return static::$vars['charset'];
	}

	/**
	 * Returns the environment timezone.
	 * 
	 * @return string
	 */
	public function getTimezone() {
		return static::$vars['timezone'];
	}
	
	/**
	 * Returns the current main domain.
	 * 
	 * @return string
	 */
	public function getDomain() {
		
		if (empty(static::$vars['domain'])) {
			
			$host = getenv('HTTP_HOST');
			
			if (substr_count($host, '.') === 1) {
				$domain = $host;
				$subdomain = 'main';
			} else {
				list($subdomain, $domain) = explode('.', $host, 2);
			}
			
			static::$vars['domain'] = $domain;
			static::$vars['subdomain'] = $subdomain;
		}
		
		return static::$vars['domain'];
	}
	
	/**
	 * Returns the subdomain, or "main" if none.
	 * 
	 * @return string
	 */
	public function getSubdomain() {
		
		if (empty(static::$vars['subdomain'])) {
			static::getDomain();
		}
		
		return static::$vars['subdomain'];
	}
	
}
