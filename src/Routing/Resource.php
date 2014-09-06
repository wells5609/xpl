<?php

namespace xpl\Routing;

class Resource extends Group implements \Serializable 
{
	
	public function getUriTemplate($route_name) {
		
		if (! $route = $this->getRoute($route_name)) {
			throw new \InvalidArgumentException("Unknown route given: '$route_name'.");
		}
		
		return $route->getUriTemplate();
	}
	
	public function serialize() {
		return serialize(get_object_vars($this));
	}
	
	public function unserialize($serial) {
		foreach(unserialize($serial) as $key => $value) {
			$this->$key = $value;
		}
	}
	
}