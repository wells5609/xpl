<?php

namespace xpl\Dependency;

interface DiAwareInterface {
	
	/**
	 * @param \xpl\Dependency\DI $di
	 * @return void
	 */
	public function setDI(DI $di);
	
	/**
	 * @return \xpl\Dependency\DI
	 */
	public function getDI();
	
}
