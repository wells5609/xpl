<?php

namespace xpl\View;

class Data extends \xpl\Common\Structure\Map {
	
	/**
	 * @param string|int $var Element key/index.
	 * @return mixed
	 */
	public function __get($var) {
		return $this->get($var);
	}

	/**
	 * @param string|int $var Element key/index.
	 * @param mixed $val Element value.
	 * @return void
	 */
	public function __set($var, $val) {
		$this->set($var, $val);
	}

	/**
	 * @param string|int $var Element key/index.
	 * @return boolean
	 */
	public function __isset($var) {
		return $this->exists($var);
	}

	/**
	 *@param string|int $var Element key/index.
	 * @return void
	 */
	public function __unset($var) {
		$this->remove($var);
	}
	
}
