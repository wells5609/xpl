<?php

namespace xpl\Routing;

interface RouteInterface extends \Serializable
{
	
	public function getID();
	
	public function getUri();
	
	public function getMethod();
	
	public function getAction();
	
	public function setTokens(array $tokens = array());
	
	public function getTokens();
	
	public function setCompiledUri($compiled_uri);
	
	public function getCompiledUri();
	
	public function isCompiled();
	
	public function setParams(array $params = array());
	
	public function getParams();
	
	public function prefixUri($uri_prefix);
	
}
