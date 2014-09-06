<?php

namespace xpl\Http;

class Cookie extends \xpl\Common\Object {
	
	protected $name;
	protected $value;
	protected $expire;
	protected $path;
	protected $domain;
	protected $secure;
	protected $httponly;
	
	public function __construct($name, $value, $expire = 0, $path = '/', $domain = null, $secure = false, $httponly = false) {
		$this->name = $name;
		$this->value = $value;
		$this->expire = $expire;
		$this->path = $path;
		$this->domain = $domain;
		$this->secure = $secure;
		$this->httponly = $httponly;
	}
	
	public function send() {
		return setcookie($this->name, $this->value, $this->expire, $this->path, $this->domain, $this->secure, $this->httponly);
	}
	
	public function delete() {
		return setcookie($this->name, '', $this->expire - 86400, $this->path, $this->domain, $this->secure, $this->httponly);
	}
	
}
