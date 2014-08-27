<?php

namespace xpl\Routing;

class Parameter {
	
	protected $name;
	protected $regex;
	
	public function __construct($name, $regex) {
		$this->name = $name;
		$this->regex = trim($regex, '()');
	}
	
	public function getName() {
		return $this->name;
	}
	
	public function getRegex() {
		return $this->regex;
	}
	
}
