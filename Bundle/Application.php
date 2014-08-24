<?php

namespace xpl\Bundle;

use xpl\Common\Storage\Config;
use xpl\Common\Storage\Registry;

/**
 * Application is a bundle representing an application.
 */
class Application extends Bundle 
{
	
	/**
	 * @var \xpl\Component\Foundation\Config
	 */
	protected $config;
	
	/**
	 * @var \xpl\Component\Foundation\Registry
	 */
	protected $registry;
	
	/**
	 * @var boolean
	 */
	private $booted = false;
	
	/**
	 * Constructor takes a config instance.
	 * 
	 * @param \xpl\Component\Foundation\Config $config
	 */
	public function __construct(Config $config) {
		
		$this->config = $config;
		$this->registry = new Registry;
		
		$this->config->setParent($this);
		
		$this->onInit();
	}
	
	/**
	 * Boots the application.
	 * 
	 * @throws \RuntimeException if already booted.
	 */
	public function boot() {
		
		if ($this->booted) {
			throw new \RuntimeException("Application has already been loaded.");
		}
		
		$this->booted = true;
		
		$this->onBoot();
	}
	
	public function shutdown() {
		return null;
	}
	
	final public function getType() {
		return 'app';
	}
	
	/**
	 * Returns the application name.
	 * 
	 * @return string
	 */
	public function getName() {
		return $this->config->get('name');
	}
	
	/**
	 * Returns the app's namespace, if set, otherwise null.
	 * 
	 * @return string
	 */
	public function getNamespace() {
		return $this->config->get('namespace');
	}
	
	/**
	 * Checks whether the app has been booted.
	 * 
	 * @return boolean
	 */
	public function isBooted() {
		return $this->booted;
	}
	
	/**
	 * Called at end of `__construct()`
	 */
	protected function onInit() {}
	
	/**
	 * Called at end of `boot()`
	 */
	protected function onBoot() {}
	
}
