<?php

namespace xpl\System;

use xpl\Dependency\ContainerAwareInterface;
use xpl\Dependency\Container;

class Manifest implements ContainerAwareInterface 
{
	
	protected $file;
	protected $manifest;
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
		
		$this->manifest = import($this->file);
		
		$env = $di['env'];
		
		if (! empty($this->manifest['vars'])) {
			$env->import($this->manifest['vars']);
		}
		
		if (! empty($this->manifest['dirs'])) {
			$env->setPaths($this->manifest['dirs']);
		}
		
		// var set with Apache SetEnvIf
		if ($subdomain = getenv('SUBDOMAIN')) {
			$env->set('subdomain', $subdomain);
		}
	}
	
}
