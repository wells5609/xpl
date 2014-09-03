<?php

namespace xpl\Framework;

class Env extends \xpl\Common\Storage\Container {
	
	protected $paths;
	protected $type;
	
	public function __construct($type = null, $root_path = null) {
		$this->paths = array();
		isset($type) and $this->setType($type);
		isset($root_path) and $this->setRootPath($root_path);
	}
	
	public function setType($type) {
		$this->type = $type;
		return $this;
	}
	
	public function getType() {
		return isset($this->type) ? $this->type : null;
	}
	
	public function is($type) {
		return $type === $this->type;
	}
	
	public function setRootPath($path) {
		if (! $this->setPath('root', $path)) {
			throw new \InvalidArgumentException("Invalid root path given: '$path'.");
		}
		return $this;
	}
	
	public function setVars(array $settings) {
		$this->import($settings);
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
			return $domain;
		}
		
		return null;
	}
	
	public function getSubdomain() {
		
		if ($this->has('subdomain')) {
			return $this->get('subdomain');
		}
		
		if ($subdomain = getenv('SUBDOMAIN')) {
			$this->set('subdomain', $subdomain);
			return $subdomain;
		}
		
		return 'main';
	}
	
}
