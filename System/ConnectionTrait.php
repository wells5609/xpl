<?php

namespace xpl\System;

trait ConnectionTrait {
	
	/**
	 * @return \xpl\Dependency\Container
	 */
	final public function di() {
		return Facade::getInstance();
	}
	
	/**
	 * @return \xpl\Bundle\Manager
	 */
	final public function getBundleManager() {
		return $this->di()->resolve('bundles');
	}
	
	/**
	 * @return \xpl\System\Env
	 */
	final public function getEnvironment() {
		return $this->di()->resolve('env');
	}
	
	/**
	 * @return \Composer\Autoload\ClassLoader
	 */
	final public function getComposer() {
		return $this->di()->resolve('env')->getComposer();
	}
	
}
