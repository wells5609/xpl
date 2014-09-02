<?php

namespace xpl\Routing\REST;

use xpl\Routing\Group;

class Route extends \xpl\Routing\Route {
	
	public function __construct(Group $group, $name, $uri, $method, array $options = array()) {
		
		// Name is used as action - prefixed in definition with lowercase method
		// e.g. a GET request to a route originally named "foo" would have an action "getFoo"
		
		parent::__construct($group, $name, $uri, array($method), $name, $options);
	}
	
}
