<?php

namespace xpl\Component\System;

use xpl\Component\Kernel\ServerKernel;
use xpl\Component\Bundle\Manager as BundleManager;
use xpl\Component\Foundation\LockableRegistry;

class Registry extends LockableRegistry {
	
	public static function create(ServerKernel $kernel, BundleManager $bundleManager) {
		static $created;
		
		if ($created) {
			throw new \LogicException("Already created system.");
		}
		
		$instance = new static();
		
		$instance->init($kernel, $bundleManager);
		
		$created = true;
		
		return $instance;
	}
	
	/**
	 * @param \xpl\Component\Kernel\ServerKernel
	 * @param \xpl\Component\Bundle\Manager
	 */
	protected function init(ServerKernel $kernel, BundleManager $bundleManager) {
		$this->set('server_kernel', $kernel);
		$this->set('bundle_manager', $bundleManager);
		$this->lock('server_kernel', 'bundle_manager');
	}
	
	/**
	 * @return \xpl\Component\Kernel\ServerKernel
	 */
	public function getServerKernel() {
		return $this->get('server_kernel');
	}
	
	/**
	 * @return \xpl\Component\Bundle\Manager
	 */
	public function getBundleManager() {
		return $this->get('bundle_manager');
	}
	
}
