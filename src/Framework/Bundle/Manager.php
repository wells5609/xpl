<?php

namespace xpl\Framework\Bundle;

use xpl\Foundation\BundleManager;
use xpl\Foundation\BundleInterface;
use xpl\Dependency\Container;
use xpl\Dependency\ContainerAwareInterface;

class Manager extends BundleManager implements ContainerAwareInterface {
	
	/**
	 * Dependency injection container.
	 * @var \xpl\Dependency\Container
	 */
	protected $container;
	
	/**
	 * Sets the DI container.
	 * 
	 * @param \xpl\Dependency\Container $di
	 */
	public function setContainer(Container $di) {
		$this->container = $di;
	}
	
	/**
	 * Returns the DI container.
	 * 
	 * @return \xpl\Dependency\Container
	 */
	public function getContainer() {
		return isset($this->container) ? $this->container : null;
	}
	
	public function setBundle(BundleInterface $bundle) {
		
		if ($bundle instanceof ContainerAwareInterface) {
			$bundle->setContainer($this->container);
		}
		
		parent::setBundle($bundle);
	}
}
