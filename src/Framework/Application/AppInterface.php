<?php

namespace xpl\Framework\Application;

use xpl\Foundation\BundleInterface;

interface AppInterface extends BundleInterface 
{
	
	public function setPath($key, $value);
	
	public function getPath($key);
	
	public function setConfig($key, $value);
	
	public function getConfig($key);
	
}
