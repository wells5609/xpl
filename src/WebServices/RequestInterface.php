<?php

namespace xpl\WebServices;

interface RequestInterface {
	
	public function setFormat($format);
	
	public function getFormat();
	
	public function getUrl();
	
}
