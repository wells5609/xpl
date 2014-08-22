<?php

namespace xpl\Component\Routing;

interface RouteInterface {
	
	public function getUri();
	
	public function getParams();
	
	public function getControllerInstance();
	
	public function getOption($var);
	
	public function setOption($var, $value);
	
	public function getOptions();
	
	public function setOptions(array $options);
	
}
