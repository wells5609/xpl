<?php

namespace xpl\Framework\Api;

use xpl\Common\Storage\Config;
use xpl\Dependency\ContainerAwareInterface;
use xpl\Dependency\Container;

class Manager implements ContainerAwareInterface {
	
	protected $config;
	protected $structure;
	protected $container;
	
	public function __construct() {
		$this->config = new Config();
		$this->config->setParent($this);
	}
	
	public function configure(array $settings) {
		$this->config->import($settings);
	}
	
	public function setContainer(Container $di) {
		$this->container = $di;
	}
	
	public function getContainer() {
		return isset($this->container) ? $this->container : null;
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
	
	public function cfg($item = null, $value = null) {
		return $this->config($item, $value);
	}
	
	public function setStructure($struct = null) {
		
		if (empty($struct) || is_array($struct)) {
			$struct = new ResponseStructure($struct);
		
		} else if (! $struct instanceof ResponseStructure) {
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
	
}
