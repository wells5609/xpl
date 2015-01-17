<?php

namespace xpl\Framework;

use xpl\System\Server;

class Env extends \xpl\Common\Storage\Container 
{	
	protected $type;
	protected $paths;
	
	public function __construct($type, $root_path) {
			
		$this->type = $type;
		$this->paths = array();
		
		if (! $realpath = realpath($root_path)) {
			throw new \InvalidArgumentException("Invalid root path given: '$root_path'.");
		}
		
		$this->paths['root'] = $realpath.DIRECTORY_SEPARATOR;
	}
	
	public function getType() {
		return $this->type;
	}
	
	public function is($type) {
		return $type === $this->type;
	}
	
	public function setPath($name, $path) {
		
		$this->paths[$name] = rtrim($path, '/\\').DIRECTORY_SEPARATOR;
		
		return $this;
	}
	
	public function setPaths(array $paths) {
		
		foreach($paths as $name => $path) {
			$this->setPath($name, $path);
		}
		
		return $this;
	}
	
	public function getPath($name = null) {
		
		if (! isset($name)) {
			return $this->paths['root'];
		}
		
		return isset($this->paths[$name]) ? $this->paths[$name] : null;
	}
	
	public function makeDirIfNotExists($path, $mkdir_mode = 0777) {
		return is_dir($path) ? true : mkdir($path, $mkdir_mode, true);
	}
	
	public function setVars(array $vars) {
		$this->import($vars);
		return $this;
	}
	
	public function getVars() {
		return $this->toArray();
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
	
}
