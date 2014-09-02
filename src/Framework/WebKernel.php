<?php

namespace xpl\Framework;

use xpl\Dependency\DiAwareInterface;
use xpl\Dependency\DI;

class WebKernel implements DiAwareInterface {
	
	protected $di;
	
	public function setDI(DI $di) {
		$this->di = $di;
	}
	
	public function getDI() {
		return isset($this->di) ? $this->di : null;
	}
	
	public function __invoke(Application\AppInterface $app) {
		
		$di = $this->getDI();
		
		try {
			
			return $di['dispatcher']->__invoke($di['router'], $di['request'], $app, $di['events']);
		
		} catch (\xpl\Web\Api\Exception $e) {
			
			$di['api']->reportError($e);
		}
	}
	
}
