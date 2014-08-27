<?php

namespace xpl\System;

/**
 * Static class with info on the web server.
 */
class Server {
	
	const DOMAIN = 1;
	const TLD = 2;
	const SUBDOMAIN = 4;
	
	protected static $domain_info;
	protected static $ssl_enabled;
	
	public static function getDomainInfo($flags = null) {
		
		if (! isset(static::$domain_info)) {
			static::setDomainInfo();
		}
		
		empty($flags) and $flags = static::DOMAIN|static::TLD|static::SUBDOMAIN;
		
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
	
	public static function getDomainName($flags = null) {
		return implode('.', array_filter(static::getDomainInfo($flags)));
	}
	
	public static function isSslEnabled() {
		
		if (! isset(static::$ssl_enabled)) {
			if ($https = getenv('https')) {
				static::$ssl_enabled = ('on' === strtolower($https) || 1 == $https);
			} else if ('https' === getenv('http_x_forwarded_proto') || 443 == getenv('server_port')) {
				static::$ssl_enabled = true;
			} else {
				static::$ssl_enabled = false;
			}
		}
		
		return static::$ssl_enabled;
	}
	
	public static function getHttpScheme() {
		return static::isSslEnabled() ? 'https' : 'http';
	}
	
	protected static function setDomainInfo() {
	
		if (! isset($_SERVER['HTTP_HOST'])) {
			throw new \RuntimeException("Cannot get domain info - no HTTP host name available.");
		}
		
		$host = $_SERVER['HTTP_HOST'];
		
		if (false === strpos($host, '.')) {
		
			static::$domain_info = array(
				'domain' => $host,
				'subdomain' => null,
				'tld' => null,
			);
		
		} else {
			
			$parts = explode('.', $host);
			
			$tld = array_pop($parts);
			$domain = array_pop($parts);
			
			$subdomain = empty($parts) ? null : count($parts) === 1 ? array_pop($parts) : implode('.', $parts);
			
			static::$domain_info = array(
				'domain' => $domain,
				'subdomain' => $subdomain,
				'tld' => $tld,
			);
		}
	}
	
}
