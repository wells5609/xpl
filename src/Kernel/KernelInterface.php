<?php

namespace xpl\Kernel;

interface KernelInterface {
	
	public function getParent();
	
	public function getName();
	
	public function getNamespace();
	
	public function getFilepath();
	
}
