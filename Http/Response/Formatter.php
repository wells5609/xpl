<?php

namespace xpl\Http\Response;

use xpl\Http\Response as HttpResponse;

class Formatter {
	
	protected $type;
	protected $default_type;
	protected $mimetype;
	protected $strategies;
	protected $default_strategies = array(
		'html' => 'Strategy\\Html',
		'json' => 'Strategy\\Json',
		'jsonp' => 'Strategy\\Jsonp',
		'xml' => 'Strategy\\Xml',
	);
	
	public function __construct() {
		$this->strategies = array();
	}
	
	public function addStrategy($type, $strategy) {
		
		if ($strategy instanceof \Closure 
			|| is_subclass_of($strategy, 'xpl\\Http\\Response\\FormatStrategyInterface')
		) {
			$this->strategies[$type] = $strategy;
		} else {
			$given = is_object($strategy) ? get_class($strategy) : gettype($strategy);
			$message = "Strategy must be instance of FormatStrategyInterface or closure, given: '{$given}'.";
			throw new \InvalidArgumentException($message);
		}
		
		return $this;
	}
	
	public function setType($type) {
		$this->type = $type;
		return $this;
	}
	
	public function setDefaultType($type) {
		$this->default_type = $type;
		return $this;
	}
	
	public function getType() {
		return $this->type;
	}
	
	public function getDefaultType() {
		return $this->default_type;
	}
	
	public function getTypes() {
		return empty($this->strategies)
			? array_keys($this->default_strategies)
			: array_merge(array_keys($this->default_strategies), array_keys($this->strategies));
	}
	
	public function getStrategy($type) {
		return isset($this->strategies[$type]) ? $this->strategies[$type] : null;
	}
	
	public function getDefaultStrategyClass($type) {
		return isset($this->default_strategies[$type]) ? $this->default_strategies[$type] : null;
	}
	
	public function format(HttpResponse $response) {
		
		if (! isset($this->type)) {
			$this->setType($this->getDefaultType() ?: 'html');
		}
		
		$type = $this->getType();
		
		if (! $strategy = $this->getStrategy($type)) {
			
			if (! $class = $this->getDefaultStrategyClass($type)) {
				throw new \InvalidArgumentException("Cannot format response: no formatter type '$type'.");
			}
			
			$class = __NAMESPACE__.'\\'.$class;
			
			$strategy = new $class();
		}
		
		if ($strategy instanceof \Closure) {
			$body = $strategy($response, $this->mimetype);
		
		} else {
			
			if (is_string($strategy)) {
				$strategy = new $strategy();
			}
			
			$body = $strategy->format($response);
			$this->mimetype = $strategy->getMimetype();
		}
		
		return $body;
	}
	
	public function getMimetype() {
			
		if (isset($this->mimetype)) {
			return $this->mimetype;
		}
		
		switch($this->getType()) {
			case 'html':
			default:
				return 'text/html';
			case 'json':
				return 'application/json';
			case 'xml':
				return 'text/xml';
			case 'text':
				return 'text/plain';
			case 'csv':
				return 'text/csv';
		}
	}
	
}
