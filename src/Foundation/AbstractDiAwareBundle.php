<?php

namespace xpl\Foundation;

use xpl\Dependency\DiAwareInterface;
use xpl\Dependency\DI;

abstract class AbstractDiAwareBundle extends AbstractBundle implements DiAwareInterface {
	
	protected $di;
	
	public function setDI(DI $di) {
		$this->di = $di;
	}
	
	public function getDI() {
		return isset($this->di) ? $this->di : null;
	}
	
}
