<?php

namespace xpl\Dependency;

trait ContainerAwareTrait implements ContainerAwareInterface {
	
	/**
	 * @var \xpl\Dependency\Container
	 */
	protected $container;
	
	public function setContainer(Container $container) {
		$this->container = $container;
	}
	
}
