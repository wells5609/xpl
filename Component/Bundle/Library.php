<?php

namespace xpl\Component\Bundle;

class Library extends Bundle {
	
	protected $booted = false;
	
	public function __construct($directory = null) {
		
		if (isset($directory)) {
			$this->dirpath = realpath($directory).DIRECTORY_SEPARATOR;
		}
	}
	
	public function boot() {
		
		if (! $this->booted) {
			
			$bootstrap = $this->getDirpath().'bootstrap.php';
			
			if (file_exists($bootstrap)) {
				require $bootstrap;
			}
			
			$this->booted = true;
		}
		
		return true;
	}
	
	public function shutdown() {	
	}
	
	final public function getType() {
		return 'library';
	}
	
	public function isBooted() {
		return $this->booted;
	}
	
}
