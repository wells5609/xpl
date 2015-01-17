<?php

namespace xpl\Data\Service;

use xpl\Data\ServiceInterface;

class Composite 
{
	
	protected $services;
	
	public function __construct() {
		$this->services = array();
	}
	
	/**
	 * Add a service.
	 * 
	 * @param \xpl\Data\ServiceInterface Service instance.
	 * @param string $key [Optional] Key identifier for the service.
	 * 
	 * @return $this
	 */
	public function add(ServiceInterface $service, $key = null) {
		isset($key) or $key = get_class($service);
		$this->services[$key] = $service;
	}
	
	/**
	 * Get a service.
	 * 
	 * @param string $key Service identifier.
	 * 
	 * @return \xpl\Data\ServiceInterface
	 */
	public function get($key) {
		return isset($this->services[$key]) ? $this->services[$key] : null;
	}
	
	/**
	 * Fetch a record from a service.
	 * 
	 * @param string $key Service identifier.
	 * @param array $conditions Arguments, those normally passed to getOne()
	 * 
	 * @return \xpl\Common\Object
	 */
	public function getOneFrom($service, array $conditions = array()) {
			
		if ($svc = $this->get($service)) {
			return $svc->getOne($conditions);
		}
		
		throw new \RuntimeException("Invalid service requested: '$service'");
	}
	
	public function getAllFrom($service, array $conditions = array()) {
		
		if ($svc = $this->get($service)) {
			return $svc->getAll($conditions);
		}
		
		throw new \RuntimeException("Invalid service requested: '$service'");
	}
	
}
