<?php

namespace xpl\System;

/**
 * Static class with info on the web server.
 */
class Server {
	
	const DOMAIN = 1;
	const TLD = 2;
	const SUBDOMAIN = 4;
	const DOMAIN_ALL = 7;
	
	protected static $domainInfo;
	protected static $sslEnabled;
	protected static $subDomains;
	
	public static function getDomainInfo($flags = null) {
		
		if (null === static::$domainInfo) {
			static::setHttpHost();
		}
		
		empty($flags) and $flags = static::DOMAIN_ALL;
		
		$return = array();
		
		if ($flags & static::SUBDOMAIN) {
			$return['subdomain'] = static::$domainInfo['subdomain'];
		}
		
		if ($flags & static::DOMAIN) {
			$return['domain'] = static::$domainInfo['domain'];
		}
		
		if ($flags & static::TLD) {
			$return['tld'] = static::$domainInfo['tld'];
		}
		
		return $return;
	}
	
	public static function isSslEnabled() {
		
		if (! isset(static::$sslEnabled)) {
			
			if ($https = getenv('HTTPS')) {
				static::$sslEnabled = ('on' === strtolower($https) || 1 == $https);
			
			} else if ('https' === getenv('HTTP_X_FORWARDED_PROTO') || 443 == getenv('SERVER_PORT')) {
				static::$sslEnabled = true;
			
			} else {
				static::$sslEnabled = false;
			}
		}
		
		return static::$sslEnabled;
	}
	
	public static function getDomainName($flags = null) {
		return implode('.', array_filter(static::getDomainInfo($flags)));
	}
	
	public static function getSubDomains() {
		return isset(static::$subDomains) ? static::$subDomains : null;
	}
	
	public static function getHttpScheme() {
		return static::isSslEnabled() ? 'https' : 'http';
	}
	
	public static function setHttpHost($HTTP_HOST = null) {
		
		$domain = $subdomain = $tld = null;
		
		if (empty($HTTP_HOST)) {
			
			if (! isset($_SERVER['HTTP_HOST'])) {
				throw new \RuntimeException("Cannot get domain info: HTTP host not available.");
			}
			
			$HTTP_HOST = $_SERVER['HTTP_HOST'];
		}
		
		if (false === strpos($HTTP_HOST, '.')) {
			$domain = $HTTP_HOST;
		
		} else {
			
			$parts = explode('.', $HTTP_HOST);
			$tld = array_pop($parts);
			$domain = array_pop($parts);
			
			if (! empty($parts)) {
				
				static::$subDomains = $parts;
				
				$subdomain = count($parts) === 1 ? reset($parts) : implode('.', $parts);
			}
		}
	
		static::$domainInfo = array(
			'domain' => $domain,
			'subdomain' => $subdomain,
			'tld' => $tld,
		);
	}
	
}
