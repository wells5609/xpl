<?php

namespace xpl\Kernel;

abstract class Kernel implements KernelInterface {
	
	/**
	 * @var string
	 */
	protected $name;
	
	/**
	 * @var string
	 */
	protected $namespace;
	
	/**
	 * @var string
	 */
	protected $filepath;
	
	/**
	 * @var \xpl\Component\Kernel\KernelInterface
	 */
	protected $parent;
	
	public function __construct(KernelInterface $parentKernel = null) {
		
		if (null !== $parentKernel) {
			$this->setParent($parentKernel);
		}
	}
	
	public function setParent(KernelInterface $kernel) {
		$this->parent = $kernel;
		return $this;
	}
	
	public function getParent() {
		return isset($this->parent) ? $this->parent : null;
	}
	
	public function getName() {
		
		if (null === $this->name) {
			$class = get_class();
			$this->name = str_replace('kernel', '', strtolower(substr($class, strrpos($class, '\\')+1)));
		}
		
		return $this->name;
	}
	
	public function getNamespace() {
			
		if (null === $this->namespace) {
			$class = get_class();
			$this->namespace = substr($class, 0, strrpos($class, '\\'));
		}
		
		return $this->namespace;
	}
	
	public function getFilepath() {
			
		if (null === $this->filepath) {
			$refl = new \ReflectionObject($this);
			$this->filepath = str_replace('\\', '/', dirname($refl->getFileName())).'/';
		}
		
		return $this->filepath;
	}
	
}
