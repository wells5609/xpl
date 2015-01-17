<?php
/**
 * @package xpl\Input
 * 
 * Based off the Joomla Framework Input package.
 */
namespace xpl\Input;

class Container
{
	
	/**
	 * @var array
	 */
	protected $inputs;
	
	/**
	 * @var array
	 */
	protected $options;
	
	/**
	 * Constructor.
	 * 
	 * @param array $options [Optional] Options
	 */
	public function __construct(array $options = array()) {
		$this->inputs = array();
		$this->options = $options;
	}
	
	/**
	 * Returns an input object for the given global variable.
	 * 
	 * @param string $key Lowercase name of the global variable to retrieve.
	 * 
	 * @return \xpl\Input\Input
	 * 
	 * @throws \RuntimeException if variable does not exist.
	 */
	public function get($key) {
		
		if (isset($this->inputs[$key])) {
			return $this->inputs[$key];
		}
		
		$class = __NAMESPACE__.'\\'.ucfirst($key);
		
		if (class_exists($class)) {
			return $this->inputs[$key] = new $class(null, $this->options);
		}
		
		$global = '_'.strtoupper($key);
		
		if (isset($GLOBALS[$global])) {
			return $this->inputs[$key] = new Input($GLOBALS[$global], $this->options);
		}
		
		throw new \RuntimeException("Cannot get input object for '$key'.");
	}
	
	public function has($key) {
		return isset($this->inputs[$key]);
	}
	
	public function set($key, Input $input) {
		$this->inputs[$key] = $input;
	}
	
	public function __get($key) {
		return $this->get($key);
	}
	
	public function __isset($key) {
		return $this->has($key);
	}
	
}
