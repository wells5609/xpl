<?php

namespace xpl\Utility;

use xpl\Http\Request;

class Url {
	
	protected $current_url;
	protected $request;
	protected $schemas = array();
	
	public function __construct(Request $request) {
		$this->request = $request;
		$this->current_url = $this->to($request->getUri(), $request->getQuery());
	}
	
	/**
	 * The current request URL.
	 */
	public function getCurrent() {
		return $this->current_url;
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
		
		$parts = array('host' => $this->getDomain($id));
		
		isset($path) AND $parts['path'] = '/'.trim($path, '/');
		isset($query) AND $parts['query'] = $query;
		
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
