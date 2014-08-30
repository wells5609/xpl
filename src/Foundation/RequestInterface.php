<?php

namespace xpl\Foundation;

/**
 * Contract for a request (both HTTP and HMVC).
 */
interface RequestInterface extends \xpl\Common\Arrayable {
	
	public function getMethod();
	
	public function getUri();
	
	public function getQuery();
	
	public function getHeaders();
	
	public function getHeader($name);
	
	public function getParams();
	
	public function getParam($name);
	
	public function isHttp();
	
	public function isHmvc();
}
