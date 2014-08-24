<?php

namespace xpl\Dependency;

/**
 * Interface for a class that is aware of the DI container.
 */
interface ContainerAwareInterface {
	
	/**
	 * Sets the container.
	 * 
	 * @param \xpl\Dependency\Container
	 */
	public function setContainer(Container $container);
	
}
