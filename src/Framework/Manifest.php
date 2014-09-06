<?php

namespace xpl\Framework;

use xpl\Dependency\DiAwareInterface;
use xpl\Dependency\DI;

class Manifest implements DiAwareInterface 
{
	
	protected $file;
	protected $di;
	
	public function __construct($file) {
		
		if (! is_readable($file)) {
			throw new \InvalidArgumentException("Unreadable manifest file: '$file'.");
		}
		
		$this->file = $file;
	}
	
	public function setDI(DI $di) {
		$this->di = $di;
		$this->init($di);
	}
	
	public function getDI() {
		return isset($this->di) ? $this->di : null;
	}
	
	protected function init(DI $di) {
		
		$manifest = include $this->file;
		
		$env = $di['env'];
		
		if (! empty($manifest['vars'])) {
			$env->import($manifest['vars']);
		}
		
		if (! empty($manifest['dirs'])) {
			$env->setPaths($manifest['dirs']);
		}
		
		// var set with Apache SetEnvIf
		if ($subdomain = getenv('SUBDOMAIN')) {
			$env->set('subdomain', $subdomain);
		}
	}
	
}
