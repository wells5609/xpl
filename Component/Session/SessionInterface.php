<?php

namespace xpl\Component\Session;

interface SessionInterface {
	
	public function setDriver(Driver\SessionDriverInterface $driver);
	
	public function start();
	
	public function isStarted();
	
	public function destroy();
	
	public function getId();
	
	public function getName();
	
}
