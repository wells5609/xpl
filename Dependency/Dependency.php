<?php

namespace xpl\Dependency;

class Dependency {
	
	protected $type;
	protected $value;
	
	public function __construct($value) {
		
		if ($value instanceof \Closure) {
			$this->type = 'closure';
		} else if (is_string($value)) {
			$this->type = 'class';
		} else {
			throw new \InvalidArgumentException("Only closures and classes can be registered, given: ".gettype($value));
		}
		
		$this->value = $value;
	}
	
	public function __invoke(Container $di) {
		switch($this->type) {
			case 'closure':
				return call_user_func($this->value, $di);
			case 'class':
				$class = $this->value;
				return new $class($di);
		}
	}
	
}
