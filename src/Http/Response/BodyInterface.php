<?php

namespace xpl\Http\Response;

interface BodyInterface extends \xpl\Common\Arrayable {
	
	public function get();
	
	public function set($data);
	
	public function __toString();
	
}
