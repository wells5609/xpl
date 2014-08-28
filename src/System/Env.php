<?php

namespace xpl\System;

use xpl\Common\Arrayable;
use xpl\Common\Importable;
use xpl\Common\Storage\Container;
use xpl\Utility\Filesystem\Container as Paths;
use Composer\Autoload\ClassLoader;

class Env implements \ArrayAccess, Arrayable, Importable {
	
	use \xpl\Common\Singleton;
	
	const DEV	= 'development';
	const PROD	= 'production';
	const STAGE	= 'staging';
	
	protected $type;
	protected $paths;
	protected $vars;
	protected $composer;
	
	/**
	 * Init with environment type and root directory path.
	 * 
	 * @param string $type Environment type. One of class constants.
	 * @param string $root_path [Optional] Root path.
	 */
	public function init($type, $root_path = null) {
		
		$this->paths = new Paths();
		$this->vars = new Container();
		
		$this->setType($type);
		
		isset($root_path) and $this->paths->setRootPath($root_path);
	}
	
	/**
	 * Set the environment type, one of the class constants.
	 * 
	 * @param string $type
	 * @return $this
	 */
	public function setType($type) {
		$this->type = $type;
		return $this;
	}
	
	/**
	 * Returns the environment type.
	 * 
	 * @return string
	 */
	public function getType() {
		return $this->type;
	}
	
	/**
	 * Checks whether the environment is "development".
	 * 
	 * @return boolean
	 */
	public function isDev() {
		return $this->type === static::DEV;
	}
	
	/**
	 * Checks whether the environment is "production".
	 * 
	 * @return boolean
	 */
	public function isProd() {
		return $this->type === static::PROD;
	}
	
	/**
	 * Checks whether the environment is "staging".
	 * 
	 * @return boolean
	 */
	public function isStaging() {
		return $this->type === static::STAGE;
	}
	
	/**
	 * Sets Composer ClassLoader.
	 * 
	 * @param \Composer\Autoload\ClassLoader $classLoader
	 */
	public function setComposer(ClassLoader $composer) {
		$this->composer = $composer;
		return $this;
	}
	
	/**
	 * Returns the Composer class loader.
	 * 
	 * @return \Composer\Autoload\ClassLoader
	 */
	public function getComposer() {
		return $this->composer;
	}
	
	/**
	 * Returns a directory path.
	 * 
	 * @param string $name [Optional] Name of directory, or null for root.
	 * @return string Filesystem path.
	 */
	public function getPath($name = null) {
		
		if (null === $name) {
			return $this->paths->getRootPath();
		}
		
		if ($path = $this->paths->getPath($name)) {
			return $path;
		}
		
		return $this->paths->getRootPath().trim($name, '/\\').DIRECTORY_SEPARATOR;
	}
	
	/** Alias of getPath() */
	public function path($name = null) {
		return $this->getPath($name);
	}
	
	/**
	 * Sets a directory path.
	 * 
	 * @param string $name Directory name.
	 * @param string $path Directory path (can be relative to root).
	 * @return $this
	 */
	public function setPath($name, $path) {
		$this->paths->setPath($name, $path);
		return $this;
	}
	
	/**
	 * Sets an array of directory paths.
	 * 
	 * @param array $paths
	 * @return $this
	 */
	public function setPaths(array $paths) {
		foreach($paths as $name => $path) {
			$this->paths->setPath($name, $path);
		}
		return $this;
	}
	
	/**
	 * Returns an array of directory paths.
	 * 
	 * @return array
	 */
	public function getPaths() {
		return $this->paths->getPaths();
	}
	
	/**
	 * Sets the root directory path (absolute).
	 * 
	 * @param string $path
	 * @return $this
	 */
	public function setRootPath($path) {
		$this->paths->setRootPath($path);
		return $this;
	}
	
	/**
	 * Stores an environment variable in the var container.
	 * 
	 * @param string $var Variable key.
	 * @param mixed $value Variable value.
	 * @return $this
	 */
	public function set($var, $value) {
		$this->vars->set($var, $value);
		return $this;
	}
	
	/**
	 * Returns an environment variable value.
	 * 
	 * @param string $var Variable key.
	 * @return mixed
	 */
	public function get($var) {
		return $this->vars->get($var);
	}
	
	/**
	 * Checks whether an environment variable is set.
	 * 
	 * @param string $var
	 * @return boolean
	 */
	public function has($var) {
		return $this->vars->has($var);
	}
	
	/**
	 * Unsets an environment variable.
	 * 
	 * @param string $var
	 * @return $this
	 */
	public function remove($var) {
		$this->vars->remove($var);
		return $this;
	}
	
	/**
	 * Sets an associative array of environment variables.
	 * 
	 * @param array $data
	 * @return $this
	 */
	public function import($data) {
		
		if (! is_array($data)) {
			$data = is_callable(array($data, 'toArray')) ? $data->toArray() : (array)$data;
		}
		
		$this->vars->import($data);
		
		return $this;
	}
	
	/**
	 * Returns an associative array of all environment variables.
	 * 
	 * @return array
	 */
	public function toArray() {
		return $this->vars->toArray();
	}
	
	/**
	 * Alias of toArray()
	 * For consistency with "getPaths()"
	 */
	public function getVars() {
		return $this->toArray();
	}
	
	/**
	 * Returns the environment variable storage container.
	 * 
	 * @return \xpl\Common\Storage\Container
	 */
	public function getVarContainer() {
		return $this->vars;
	}
	
	/**
	 * @param string|int $var
	 * @return mixed
	 */
	public function offsetGet($var) {
		return $this->vars->get($var);
	}

	/**
	 * @param string|int $var
	 * @param mixed $val
	 * @return void
	 */
	public function offsetSet($var, $val) {
		$this->vars->set($var, $val);
	}

	/**
	 * @param string|int $var
	 * @return boolean
	 */
	public function offsetExists($var) {
		return $this->vars->has($var);
	}

	/**
	 * @param string|int $var
	 * @return void
	 */
	public function offsetUnset($var) {
		$this->vars->remove($var);
	}
	
	/**
	 * Whether debugging is enabled.
	 * 
	 * @return boolean
	 */
	public function isDebug() {
		return (bool) $this->vars->get('debug');
	}
	
	/**
	 * Returns the environment character set.
	 * 
	 * @return string
	 */
	public function getCharset() {
		return $this->vars->get('charset');
	}

	/**
	 * Returns the environment timezone.
	 * 
	 * @return string
	 */
	public function getTimezone() {
		return $this->vars->get('timezone');
	}
	
	/**
	 * Returns the current main domain.
	 * 
	 * @return string
	 */
	public function getDomain() {
		
		if (! $this->vars->has('domain')) {
			$this->vars->set('domain', Server::getDomainName(Server::DOMAIN|Server::TLD));
		}
		
		return $this->vars->get('domain');
	}
	
	/**
	 * Returns the subdomain, or "main" if none.
	 * 
	 * @return string
	 */
	public function getSubdomain() {
		
		if (! $this->vars->has('subdomain')) {
			$this->vars->set('subdomain', Server::getDomainName(Server::SUBDOMAIN) ?: 'main');
		}
		
		return $this->vars->get('subdomain');
	}
	
}
