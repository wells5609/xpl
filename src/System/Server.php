<?php

namespace xpl\System;

/**
 * Static class with info on the web server.
 */
class Server 
{	
	const DOMAIN = 1;
	const TLD = 2;
	const SUBDOMAIN = 4;
	const DOMAIN_ALL = 7;
	
	protected static $domain_info;
	protected static $ssl_enabled;
	protected static $subdomains;
	
	public static function getDomainInfo($flags = null) {
		
		if (! isset(static::$domain_info)) {
			static::setHttpHost();
		}
		
		if (empty($flags)) {
			$flags = static::DOMAIN_ALL;
		}
		
		$return = array();
		
		if ($flags & static::SUBDOMAIN) {
			$return['subdomain'] = static::$domain_info['subdomain'];
		}
		
		if ($flags & static::DOMAIN) {
			$return['domain'] = static::$domain_info['domain'];
		}
		
		if ($flags & static::TLD) {
			$return['tld'] = static::$domain_info['tld'];
		}
		
		return $return;
	}
	
	public static function isSslEnabled() {
		
		if (! isset(static::$ssl_enabled)) {
			
			if ($https = getenv('HTTPS')) {
				static::$ssl_enabled = ('on' === strtolower($https) || 1 == $https);
			
			} else if ('https' === getenv('HTTP_X_FORWARDED_PROTO') || 443 == getenv('SERVER_PORT')) {
				static::$ssl_enabled = true;
			
			} else {
				static::$ssl_enabled = false;
			}
		}
		
		return static::$ssl_enabled;
	}
	
	public static function getDomainName($flags = null) {
		return implode('.', array_filter(static::getDomainInfo($flags)));
	}
	
	public static function getSubDomains() {
		return isset(static::$subdomains) ? static::$subdomains : null;
	}
	
	public static function getHttpScheme() {
		return static::isSslEnabled() ? 'https' : 'http';
	}
	
	public static function setHttpHost($http_host = null) {
		
		$domain = $subdomain = $tld = null;
		
		if (empty($http_host)) {
			
			if (! isset($_SERVER['HTTP_HOST'])) {
				throw new \RuntimeException("Cannot get domain info: HTTP host not available.");
			}
			
			$http_host = $_SERVER['HTTP_HOST'];
		}
		
		if (false === strpos($http_host, '.')) {
			$domain = $http_host;
		
		} else {
			
			$parts = explode('.', $http_host);
			$tld = array_pop($parts);
			$domain = array_pop($parts);
			
			if (! empty($parts)) {
				static::$subdomains = $parts;
				$subdomain = (count($parts) === 1) ? reset($parts) : implode('.', $parts);
			}
		}
	
		static::$domain_info = array(
			'domain' => $domain,
			'subdomain' => $subdomain,
			'tld' => $tld,
		);
	}
	
}
