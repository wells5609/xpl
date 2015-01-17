<?php

namespace xpl\Input;

class Server extends Input
{
	
	public function __construct(array $source = null, array $options = array()) {
		
		$source = $_SERVER;
		
		parent::__construct(array_change_key_case($source), $options);
	}
	
}
