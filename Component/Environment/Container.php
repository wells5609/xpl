<?php

namespace xpl\Component\Environment;

/**
 * Environment container holds information about the current server environment.
 */
class Container extends \xpl\Component\Foundation\Container {
	
	const DEVELOPMENT	= 'development';
	const PRODUCTION	= 'production';
	const STAGING		= 'staging';
	
	protected $type;
	private $configured = false;
	
	public function __construct($type = self::PRODUCTION) {
		$this->setType($type);
	}
	
	public function setType($type) {
		
		// execute detection callback
		is_callable($type) and $type = call_user_func($type);
		
		$types = array(static::DEVELOPMENT, static::PRODUCTION, static::STAGING);
		
		if (! in_array($type, $types, true)) {
			throw new \DomainException("Invalid environment type: '$type'.");
		}
		
		$this->type = $type;
		
		return $this;
	}
	
	public function getType() {
		return $this->type;
	}
	
	public function isConfigured() {
		return $this->configured;
	}
	
	public function isDev() {
		return $this->type === static::DEVELOPMENT;
	}
	
	public function isProd() {
		return $this->type === static::PRODUCTION;
	}
	
	public function isStaging() {
		return $this->type === static::STAGING;
	}
	
	public function __toString() {
		return (string) $this->type;
	}
	
	/**
	 * Configures PHP using an optional user closure.
	 * 
	 * @param \Closure $callback [Optional] Closure that configures PHP settings.
	 * @return void
	 */
	public function configure(\Closure $callback = null) {
		
		if ($this->configured) {
			throw new \RuntimeException("Environment has already been configured.");
		}
		
		if (null !== $callback) {
			$callback->bindTo($this, get_called_class());
		} else {
			$callback = array($this, 'defaultConfig');
		}
		
		call_user_func($callback);
		
		$this->configured = true;
	}
	
	/**
	 * Whether debugging is enabled.
	 * 
	 * @return boolean
	 */
	public function isDebug() {
		return (bool) $this->get('debug');
	}
	
	/**
	 * Returns the environment character set.
	 * 
	 * @return string
	 */
	public function getCharset() {
		return $this->get('charset');
	}

	/**
	 * Returns the environment timezone.
	 * 
	 * @return string
	 */
	public function getTimezone() {
		return $this->get('timezone');
	}
	
	/**
	 * Returns the current main domain.
	 * 
	 * @return string
	 */
	public function getDomain() {
		
		if (! $domain = $this->get('domain')) {
			
			$host = getenv('HTTP_HOST');
			
			if (substr_count($host, '.') === 1) {
				$domain = $host;
				$subdomain = 'main';
			} else {
				list($subdomain, $domain) = explode('.', $host, 2);
			}
			
			$this->set('domain', $domain);
			$this->set('subdomain', $subdomain);
		}
		
		return $domain;
	}
	
	/**
	 * Returns the subdomain, or "main" if none.
	 * 
	 * @return string
	 */
	public function getSubdomain() {
		
		if (! $this->has('subdomain')) {
			$this->getDomain();
		}
		
		return $this->get('subdomain');
	}
	
	/**
	 * Default method for configuring PHP when no user callback is supplied.
	 * @return void
	 */
	protected function defaultConfig() {
		
		// Set debug
		if ($debug = getenv('DEBUG') === false) {
			$debug = $this->isDev() ? '1' : '0';
			putenv("DEBUG={$debug}");
		}
		
		$this->set('debug', $debug);
		
		if ($debug) {
			// In development environments, report and display all errors.
			error_reporting(E_ALL);
			ini_set('display_errors', '1');
		} else {
			// In non-dev environments, supress notices and strict/deprecated errors
			error_reporting(E_ALL & ~(E_NOTICE|E_STRICT|E_DEPRECATED));
			ini_set('display_errors', '0');
		}
		
		// Set charset
		if (! $charset = getenv('CHARSET')) {
			$charset = ini_get('default_charset') ?: 'UTF-8';
			putenv("CHARSET={$charset}");
		}
		
		$this->set('charset', $charset);
		
		// Set timezone
		if (! $tz = getenv('TZ')) {
			$tz = ini_get('date.timezone') ?: 'UTC';
			putenv("TZ={$tz}");
		}
		
		$this->set('timezone', $tz);
			
		try {
			date_default_timezone_set($tz);
		} catch (\Exception $e) {
			date_default_timezone_set('UTC');
			throw $e;
		}
	}
	
}
