<?php

namespace xpl\Framework;

use xpl\Foundation\BundleManager as BaseBundleManager;
use xpl\Foundation\BundleInterface;
use xpl\Dependency\DiAwareInterface;
use xpl\Dependency\DI;

class BundleManager extends BaseBundleManager implements DiAwareInterface {
	
	/**
	 * Dependency injection container.
	 * @var \xpl\Dependency\DI
	 */
	protected $di;
	
	/**
	 * Sets the DI container.
	 * 
	 * @param \xpl\Dependency\DI $di
	 */
	public function setDI(DI $di) {
		$this->di = $di;
	}
	
	/**
	 * Returns the DI container.
	 * 
	 * @return \xpl\Dependency\DI
	 */
	public function getDI() {
		return isset($this->di) ? $this->di : null;
	}
	
	public function setBundle(BundleInterface $bundle) {
		
		if ($bundle instanceof DiAwareInterface) {
			$bundle->setDI($this->di);
		}
		
		parent::setBundle($bundle);
	}
}
