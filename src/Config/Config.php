<?php

namespace xpl\Config;

use xpl\Common\Storage\Config;
use xpl\Utility\Arr;

/**
 * A basic Config object.
 */
class Container extends Config
{
	/**
	 * @var boolean
	 */
	private $readonly;
	
	/**
	 * @var array|boolean
	 */
	private $defaults;
	
	/**
	 * Constructor.
	 * 
	 * Set up object with any initial data.
	 * 
	 * @param mixed $data [Optional]
	 * @param array $defaults [Optional] Default values. Pass boolean false to disable defaults.
	 * @param boolean $read_only [Optional] Whether object is read-only. Default false.
	 */
	public function __construct($data = null, $defaults = array(), $read_only = false) {
		
		$this->defaults = $defaults;
		$this->readonly = (bool)$read_only;
		
		if (isset($data)) {
			$this->import($data);
		}
	}

	/**
	 * Set method returns the previous value.
	 * 
	 * @param string $key Item key.
	 * @param mixed $value New value.
	 * 
	 * @return mixed Previous item value.
	 * 
	 * @throws \RuntimeException if object is read-only.
	 */
	public function set($key, $value) {
		
		if ($this->readonly) {
			throw new \RuntimeException("Cannot set read-only configuration values.");
		}
		
		$prev = $this->get($key);
		
		Arr::set($this->_data, $key, $value);
		
		return $prev;
	}

	/**
	 * Returns a config item value.
	 * 
	 * @param string $key
	 * 
	 * @return mixed
	 */
	public function get($key) {

		if ($value = parent::get($key)) {
			return $value;
		}

		return $this->defaults ? $this->getDefault($key) : null;
	}

	/**
	 * Whether a config item exists.
	 * 
	 * @param string $key
	 * 
	 * @return boolean
	 */
	public function has($key) {

		if (parent::has($key)) {
			return true;
		}

		return $this->defaults ? $this->hasDefault($key) : false;
	}

	/**
	 * Removes a config item.
	 * 
	 * @param string $key
	 * 
	 * @throws \RuntimeException if config is read-only.
	 */
	public function remove($key) {

		if ($this->readonly) {
			throw new \RuntimeException("Cannot unset read-only configuration values.");
		}
		
		parent::remove($key);
	}

	/**
	 * Set whether the config items are read-only.
	 * 
	 * @param boolean $value
	 */
	public function setReadOnly($value) {
		$this->readonly = (bool)$value;
	}

	/**
	 * Whether the config items are read-only.
	 */
	public function isReadOnly() {
		return $this->readonly;
	}

	/**
	 * Enables default values for config items.
	 */
	public function enableDefaults() {
		$this->defaults = array();
	}
	
	/**
	 * Disables default values for config items.
	 */
	public function disableDefaults() {
		$this->defaults = false;
	}

	/**
	 * Whether the config items can have default values.
	 * 
	 * @return boolean
	 */
	public function defaultsEnabled() {
		return false !== $this->defaults;
	}

	/**
	 * Set an item's default value.
	 * 
	 * @param string $key
	 * @param mixed $value
	 * 
	 * @throws \RuntimeException if defaults are disabled.
	 */
	public function setDefault($key, $value) {

		if (false === $this->defaults) {
			throw new \RuntimeException("Configuration may not have defaults.");
		}

		Arr::set($this->defaults, $key, $value);
	}

	/**
	 * Get an item's default value.
	 * 
	 * @param string $key
	 * 
	 * @return mixed
	 * 
	 * @throws \RuntimeException if defaults are disabled.
	 */
	public function getDefault($key) {

		if (false === $this->defaults) {
			throw new \RuntimeException("Configuration does not have defaults.");
		}
		
		if (! $value = Arr::get($this->defaults, $key)) {
			return false;
		}
		
		return is_callable($value) ? call_user_func($value, $this) : $value;
	}
	
	/**
	 * Checks whether an item has a default value.
	 * 
	 * @param string $key
	 * 
	 * @return boolean
	 * 
	 * @throws \RuntimeException if defaults are disabled.
	 */
	public function hasDefault($key) {
		
		if (false === $this->defaults) {
			throw new \RuntimeException("Configuration does not have defaults.");
		}
		
		return Arr::exists($this->defaults, $key);
	}

}