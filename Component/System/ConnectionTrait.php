<?php

namespace xpl\Component\System;

trait ConnectionTrait {
	
	/**
	 * @return \xpl\Component\System\Container
	 */
	final public function getContainer() {
		return StaticFacade::getInstance();
	}
	
	/**
	 * @return \xpl\Component\Foundation\Registry
	 */
	final public function getRegistry() {
		return $this->getContainer()->getRegistry();
	}
	
	/**
	 * @return \xpl\Component\Bundle\Manager
	 */
	final public function getBundleManager() {
		return $this->getContainer()->getBundleManager();
	}
	
	/**
	 * @return \xpl\Component\Kernel\ServerKernel
	 */
	final public function getServerKernel() {
		return $this->getContainer()->getServerKernel();
	}
	
	/**
	 * @return \xpl\Component\Environment\Container
	 */
	final public function getEnvironment() {
		return $this->getContainer()->getServerKernel()->getEnvironment();
	}
	
	/**
	 * @return \xpl\Component\Kernel\ServerKernel
	 */
	final public function getComposer() {
		return $this->getContainer()->getServerKernel()->getComposer();
	}
	
}
