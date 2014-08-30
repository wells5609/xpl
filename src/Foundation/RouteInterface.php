<?php

namespace xpl\Foundation;

interface RouteInterface {
	
	public function getUri();
	
	public function getCompiledUri();
	
	public function getStrippedUri();
	
	public function getAction();
	
	public function getParams();
	
	public function getMethods();
	
	public function hasMethod($method);
	
	public function getOption($var);
	
	public function setOption($var, $value);
	
	public function getOptions();
	
	public function setOptions(array $options);
	
}
