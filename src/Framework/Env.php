<?php

namespace xpl\Framework;

use xpl\System\Server;

class Env extends \xpl\Common\Storage\Container {
	
	protected $type;
	protected $paths;
	
	public function __construct($type, $root_path) {
		$this->paths = array();
		$this->type = $type;
		$this->setRootPath($root_path);
	}
	
	public function getType() {
		return $this->type;
	}
	
	public function is($type) {
		return $type === $this->type;
	}
	
	public function setRootPath($path) {
		
		if (! $realpath = realpath($path)) {
			throw new \InvalidArgumentException("Invalid root path given: '$path'.");
		}
		
		$this->paths['root'] = $realpath.DIRECTORY_SEPARATOR;
		
		return $this;
	}
	
	public function setPaths(array $paths) {
		
		foreach($paths as $name => $path) {
			$this->setPath($name, $path);
		}
		
		return $this;
	}
	
	public function setPath($name, $path) {
		
		if ($realpath = realpath($path)) {
			$this->paths[$name] = $realpath.DIRECTORY_SEPARATOR;
		}
		
		return $this;
	}
	
	public function getPath($name = null) {
		
		if (null === $name) {
			return $this->paths['root'];
		}
		
		return isset($this->paths[$name]) ? $this->paths[$name] : null;
	}
	
	public function getDomain() {
		
		if ($this->has('domain')) {
			return $this->get('domain');
		}
		
		if ($domain = getenv('DOMAIN')) {
			$this->set('domain', $domain);
		} else {
			$domain = Server::getDomainName(Server::DOMAIN|Server::TLD);
		}
		
		return $domain;
	}
	
	public function getSubdomain() {
		
		if ($this->has('subdomain')) {
			return $this->get('subdomain');
		}
		
		if ($subdomain = getenv('SUBDOMAIN')) {
			$this->set('subdomain', $subdomain);
		} else {
			$subdomain = Server::getDomainName(Server::SUBDOMAIN) ?: 'main';
		}
		
		return $subdomain;
	}
	
	public function setVars(array $settings) {
		$this->import($settings);
		return $this;
	}
	
	public function getVars() {
		return $this->toArray();
	}
	
}
