<?php

namespace xpl\System;

trait ConnectionTrait {
	
	/**
	 * @return \xpl\System\Container
	 */
	final public function getContainer() {
		return StaticFacade::getInstance();
	}
	
	/**
	 * @return \xpl\Bundle\Manager
	 */
	final public function getBundleManager() {
		return $this->getContainer()->getBundleManager();
	}
	
	/**
	 * @return \xpl\Kernel\ServerKernel
	 */
	final public function getServerKernel() {
		return $this->getContainer()->getServerKernel();
	}
	
	/**
	 * @return \xpl\Environment\Container
	 */
	final public function getEnvironment() {
		return $this->getContainer()->getServerKernel()->getEnvironment();
	}
	
	/**
	 * @return \xpl\Kernel\ServerKernel
	 */
	final public function getComposer() {
		return $this->getContainer()->getServerKernel()->getComposer();
	}
	
}
