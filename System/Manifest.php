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
		
		if ($di['cache']->exists('system.manifest')) {
			$manifest = $di['cache']->get('system.manifest');
		} else {
			$manifest = file_get_contents($this->file);
		}
		
		$this->manifest = json_decode($manifest, true);
		
		if (! empty($this->manifest['vars'])) {
			$di['env']->import($this->manifest['vars']);
		}
		
		if (! empty($this->manifest['dirs'])) {
			$di['env']->setPaths($this->manifest['dirs']);
		}
		
		// var set with Apache SetEnvIf
		if ($subdomain = getenv('SUBDOMAIN')) {
			$di['env']->set('subdomain', $subdomain);
		}
		
		register_shutdown_function(array($this, 'cacheManifest'));
	}
	
	public function cacheManifest() {
		
		$di = $this->getContainer();
		
		$save = array(
			'dirs' => $di['env']->getPaths(),
			'vars' => $di['env']->toArray(),
		);
		
		// don't cache the subdomain
		unset($save['vars']['subdomain']);
		
		$di['cache']->set('system.manifest', json_encode($save, JSON_NUMERIC_CHECK));
	}
	
}
