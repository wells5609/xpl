<?php

namespace xpl\Dependency;

/**
 * Interface for a class that is aware of the DI container.
 */
interface ContainerAwareInterface {
	
	/**
	 * Sets the DI container.
	 * 
	 * @param \xpl\Dependency\Container
	 */
	public function setContainer(Container $container);
	
	/**
	 * Returns the DI container.
	 * 
	 * @return \xpl\Dependency\Container
	 */
	public function getContainer();
	
}
