<?php

namespace xpl\Kernel;

use Composer\Autoload\ClassLoader;
use xpl\System\Environment;
use xpl\Utility\Filesystem\Container as Paths;

class ServerKernel extends Kernel 
{	
	/**
	 * @var \xpl\Utility\Filesystem\Container
	 */
	protected $pathContainer;
	
	/**
	 * @var \Composer\Autoload\ClassLoader
	 */
	protected $composer;
	
	/**
	 * Construct with path container.
	 * 
	 * @param \xpl\Utility\Filesystem\Container
	 * @param \xpl\Component\Kernel\KernelInterface
	 */
	public function __construct(Paths $pathContainer, KernelInterface $parentKernel = null) {
		
		$this->pathContainer = $pathContainer;
		
		parent::__construct($parentKernel);
	}
	
	/**
	 * Sets Composer ClassLoader.
	 * 
	 * @param \Composer\Autoload\ClassLoader $classLoader
	 * @return $this
	 */
	public function setComposer(ClassLoader $classLoader) {
		$this->composer = $classLoader;
		return $this;
	}
	
	/**
	 * Returns the Composer class loader.
	 * 
	 * @return \Composer\Autoload\ClassLoader
	 */
	public function getComposer() {
		return isset($this->composer) ? $this->composer : null;
	}
	
	/**
	 * Returns the file locator instance.
	 * 
	 * @return \xpl\Utility\Filesystem\FileLocator
	 */
	public function getPathContainer() {
		return $this->pathContainer;
	}
	
	/**
	 * @return \xpl\Component\System\Environment
	 */
	public function getEnvironment() {
		return Environment::instance();
	}
	
	/**
	 * Returns a directory path.
	 * 
	 * @param string $name [Optional] Name of directory, or null for root.
	 * @return string Filesystem path.
	 */
	public function getPath($name = null) {
		
		if (null === $name) {
			return $this->pathContainer->getRootPath();
		}
		
		if ($path = $this->pathContainer->getPath($name)) {
			return $path;
		}
		
		return $this->pathContainer->getRootPath().trim($name, '/\\').DIRECTORY_SEPARATOR;
	}
	
}
