<?php

namespace xpl\Foundation\Exception;

class BundleDependency extends \xpl\Foundation\Exception {
	
	protected $missing;
	
	public function setMissing(array $missing) {
		$this->missing = $missing;
	}
	
	public function getMissing() {
		return isset($this->missing) ? $this->missing : array();
	}
	
}
