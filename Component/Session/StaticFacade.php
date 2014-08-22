<?php

namespace xpl\Component\Session;

class StaticFacade extends \Common\StaticFacade {
	
	protected static function getObject() {
		return Session::instance();
	}
		
}
