<?php

namespace xpl\Input;

class Cookie extends Input 
{
	
	public function __construct(array $source = null, array $options = array()) {
		$this->data =& $_COOKIE;
		$this->options = $options;
	}
	
	public function set($name, $value, $expire = 0, $path = '', $domain = '', $secure = false, $httpOnly = false) {
		
		setcookie($name, $value, $expire, $path, $domain, $secure, $httpOnly);
		
		$this->data[$name] = $value;
	}
	
}
