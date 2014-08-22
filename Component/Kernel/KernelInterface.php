<?php

namespace xpl\Component\Kernel;

interface KernelInterface {
	
	public function getParent();
	
	public function getName();
	
	public function getNamespace();
	
	public function getFilepath();
	
}
