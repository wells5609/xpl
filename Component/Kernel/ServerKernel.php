<?php

namespace xpl\Component\Kernel;

use Composer\Autoload\ClassLoader;
use xpl\Component\Environment\Container as Env;
use xpl\Utility\Filesystem\FileLocator;

class ServerKernel extends Kernel 
{	
	/**
	 * @var \xpl\Utility\Filesystem\FileLocator
	 */
	protected $fileLocator;
	
	/**
	 * @var \xpl\Component\Environment\Container
	 */
	protected $environment;
	
	/**
	 * @var \Composer\Autoload\ClassLoader
	 */
	protected $composer;
	
	/**
	 * Construct with environment container.
	 * 
	 * @param \xpl\Component\Environment\Container
	 * @param \xpl\Utility\Filesystem\FileLocator
	 * @param \xpl\Component\Kernel\KernelInterface
	 */
	public function __construct(Env $environment, FileLocator $fileLocator, KernelInterface $parentKernel = null) {
		
		$this->environment = $environment;
		$this->fileLocator = $fileLocator;
		
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
	public function getFileLocator() {
		return $this->fileLocator;
	}
	
	/**
	 * @return \xpl\Component\Environment\Container
	 */
	public function getEnvironment() {
		return $this->environment;
	}
	
	/**
	 * Returns a directory path.
	 * 
	 * @param string $name [Optional] Name of directory, or null for root.
	 * @return string Filesystem path.
	 */
	public function getPath($name = null) {
		
		if (null === $name) {
			return $this->fileLocator->getRootPath();
		}
		
		if ($path = $this->fileLocator->getPath($name)) {
			return $path;
		}
		
		return $this->fileLocator->getRootPath().trim($name, '/\\').DIRECTORY_SEPARATOR;
	}
	
}
