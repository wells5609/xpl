<?php

namespace xpl\Utility;

class Url {
	
	/** 
	 * Current URI path
	 * @var string
	 */
	protected $path;
	
	/**
	 * Current URI query.
	 * @var string
	 */
	protected $query;
	
	/**
	 * Current URL.
	 * @var string
	 */
	protected $url;
	
	public function __construct($request_path, $request_query = null) {
		
		$this->path = '/'.trim($request_path, '/');
		$this->query = (string)$request_query;
		
		$this->url = $this->to($this->path, $this->query);
	}
	
	/**
	 * The current request URL, or other information ('path' or 'query').
	 */
	public function getCurrent($var = null) {
		
		if (empty($var)) {
			return $this->url;
		}
		
		switch(strtolower($var)) {
			case 'path':
			case 'uri':
				return $this->path;
			case 'query':
				return $this->query;
			case 'url':
				return $this->url;
			default:
				return null;
		}
	}
	
	/**
	 * Returns the host (subdomain + domain) for an application.
	 */
	public function getDomain($id = APPID) {
		return ('main' === $id) ? DOMAIN : "{$id}.".DOMAIN;
	}
	
	/**
	 * URL to a path in the current application.
	 */
	public function to($path = null, $query = null) {
		return $this->toApp(APPID, $path, $query);
	}
	
	/**
	 * URL to an application.
	 */
	public function toApp($id = APPID, $path = null, $query = null) {
		
		$parts = array(
			'host' => $this->getDomain($id)
		);
		
		if (! empty($path)) {
			$parts['path'] = '/'.trim($path, '/');
		}
		
		if (! empty($query)) {
			$parts['query'] = $query;
		}
		
		return http_build_url('/', $parts);
	}
	
	/**
	 * URL to a file in DOCROOT path.
	 */
	public function toFile($filepath) {
		return http_build_url(str_replace(DOCROOT, '', '/'.ltrim($filepath, '/\\')));
	}
	
	/**
	 * URL to Google-hosted jQuery library.
	 */
	public function toJquery($version = '1.11.1') {
		return "//ajax.googleapis.com/ajax/libs/jquery/{$version}/jquery.min.js";
	}

}
