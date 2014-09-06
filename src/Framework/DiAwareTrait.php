<?php

namespace xpl\Framework;

use xpl\Dependency\DI;

trait DiAwareTrait
{
	
	/**
	 * @var \xpl\Dependency\DI
	 */	
	protected $_di;
	
	/**
	 * @param \xpl\Dependency\DI
	 * 
	 * @return void
	 */	
	public function setDI(DI $di) {
		
		$this->_di = $di;
		
		if (method_exists($this, 'onSetDI')) {
			$this->onSetDI($di);
		}
	}
	
	/**
	 * @return \xpl\Dependency\DI
	 */	
	public function getDI() {
		
		if (isset($this->_di)) {
			return $this->_di;
		}
	}
	
	/**
	 * @return mixed
	 */	
	public function di($var = null) {
		
		if (isset($this->_di)) {
				
			return isset($var) ? $this->_di[$var] : $this->_di;
		}
	}
	
}
