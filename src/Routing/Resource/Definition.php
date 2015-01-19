<?php

namespace xpl\Routing\Resource;

use xpl\Cache\Cache;
use xpl\Routing\Resource;
use xpl\Routing\Route;
use xpl\Routing\Route\Tokens;

abstract class Definition {
	
	abstract public function getName();
	
	abstract public function getControllerClass();
	
	abstract public function getRoutes();
	
	public function getDomain() {
		return null;
	}
	
	public function getParams() {
		return array();
	}
	
	public function getOptions() {
		return array();
	}
	
	public function getPathPrefix() {
		return '/';
	}
	
}
