<?php

namespace xpl\Framework;

class BundleManager extends \xpl\Bundle\Manager 
{
	
	protected $events;
	
	public function __construct(\xpl\Event\Manager $events) {
		$this->events = $events;
	}
	
	public function boot($name) {
		
		if (parent::boot($name)) {
			
			$bundle = $this->getBundle($name);
			
			if ($bundle->isBooted()) {
				
				$type = $bundle->getType();
				
				$this->events->trigger("boot_{$type}", $bundle);
				
				$this->events->trigger("boot_{$type}/".$bundle->getName(), $bundle);
			}
			
			return true;
		}
		
		return false;
	}
	
}
