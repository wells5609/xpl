<?php

namespace xpl\Framework;

use xpl\Dependency\ContainerAwareInterface;
use xpl\Dependency\Container;
use xpl\Web\Dispatcher;

class WebKernel implements ContainerAwareInterface {
	
	protected $container;
	
	public function setContainer(Container $container) {
		$this->container = $container;
	}
	
	public function getContainer() {
		return isset($this->container) ? $this->container : null;
	}
	
	public function __invoke(Application\AppInterface $app) {
		
		$di = $this->getContainer();
		
		return $di['dispatcher']->__invoke($di['router'], $di['request'], $app, $di['events']);
	}
	
}
