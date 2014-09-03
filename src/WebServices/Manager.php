<?php

namespace xpl\WebServices;

class Manager
{
	
	/**
	 * @var \xpl\WebServices\Client
	 */
	protected $client;
	
	/**
	 * @param \xpl\WebServices\Client
	 */
	public function setClient(Client $client) {
		$this->client = $client;
	}
	
	/**
	 * @return boolean
	 */
	public function hasClient() {
		return isset($this->client);
	}
	
	/**
	 * @return \xpl\WebServices\Client
	 */
	public function getClient() {
		return isset($this->client) ? $this->client : null;
	}
	
}
