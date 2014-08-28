<?php

namespace xpl\System;

use xpl\Dependency\ContainerAwareInterface;
use xpl\Dependency\Container;

class Manifest implements ContainerAwareInterface 
{
	
	protected $file;
	protected $container;
	
	public function __construct($file) {
		
		if (! is_readable($file)) {
			throw new \InvalidArgumentException("Unreadable manifest file: '$file'.");
		}
		
		$this->file = $file;
	}
	
	public function setContainer(Container $container) {
		$this->container = $container;
		$this->init($container);
	}
	
	public function getContainer() {
		return isset($this->container) ? $this->container : null;
	}
	
	protected function init(Container $di) {
		
		$manifest = import($this->file);
		
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
