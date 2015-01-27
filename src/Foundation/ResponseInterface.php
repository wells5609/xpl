<?php

namespace xpl\Foundation;

interface ResponseInterface 
{
	
	public function setBody($body);
	
	public function getBody();
	
	public function setStatus($code);
	
	public function getStatus();
	
	public function setCharset($charset);
	
	public function getCharset();
	
	public function setContentType($content_type);
	
	public function getContentType();
	
	public function setHeader($name, $value, $overwrite = true);
	
	public function getHeader($name);
	
	public function hasHeader($name);
	
	public function setHeaders(array $headers);
	
	public function addHeaders(array $headers);
	
	public function getHeaders();
	
	public function setAccessControlAllowOrigin($value);
	
	public function redirect($url, $status = 0);
	
	public function send();
	
}
