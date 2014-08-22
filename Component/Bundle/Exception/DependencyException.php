<?php

namespace xpl\Component\Bundle\Exception;

class DependencyException extends BootException {
	
	protected $missing;
	
	public function setMissing(array $missing) {
		$this->missing = $missing;
	}
	
	public function getMissing() {
		return isset($this->missing) ? $this->missing : array();
	}
	
}
