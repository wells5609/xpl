<?php

namespace xpl\Foundation;

class Library extends AbstractBundle {
	
	protected $booted = false;
	
	public function __construct($directory) {
		
		$this->dirpath = realpath($directory).DIRECTORY_SEPARATOR;
		
		$this->name = strtolower(basename($this->dirpath));
	}
	
	public function boot() {
		
		if (! $this->booted) {
			
			$bootstrap = $this->dirpath.'bootstrap.php';
			
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
