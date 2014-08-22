<?php

namespace Cache;

class StaticFacade extends \Common\StaticFacade {
	
	protected static function getObject() {
		return Cache::instance();
	}
		
}
