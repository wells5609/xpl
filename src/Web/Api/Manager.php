<?php

namespace xpl\Web\Api;

use xpl\Common\Storage\Config;

class Manager 
{
	
	protected $config;
	protected $structure;
	protected $errors;
	
	public function __construct(Config $config = null) {
		$this->config = $config ?: new Config();
		$this->config->setParent($this);
		$this->errors = array();
	}
	
	public function configure(array $settings) {
		$this->config->import($settings);
	}
	
	public function config($item = null, $value = null) {
		
		if (! isset($item)) {
			return $this->config;
		}
		
		if (! isset($value)) {
			return $this->config->get($item);
		}
		
		$this->config->set($item, $value);
	}
	
	public function setStructure($struct = null) {
		
		if (empty($struct) || is_array($struct)) {
			$struct = new Response\Structure($struct);
		
		} else if (! $struct instanceof Response\Structure) {
			throw new \InvalidArgumentException("API structure must be array or ResponseStructure, given: ".gettype($struct));
		}
		
		$this->structure = $struct;
	}
	
	public function hasStructure() {
		return isset($this->structure);
	}
	
	public function getStructure() {
		return $this->structure;
	}
	
	public function reportError(Exception $exception) {
		$this->errors[] = $exception;
	}
	
	public function hasErrors() {
		return ! empty($this->errors);
	}
	
	public function getErrors() {
		return $this->errors;
	}
	
	public function getErrorOutput() {
		$errors = array();
		foreach($this->errors as $e) {
			$errors[$e->getCode()] = $e->getMessage();
		}
		return $errors;
	}
	
}
