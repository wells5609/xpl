<?php

namespace xpl\Data\Provider;

class AbstractValidatedDatabase extends AbstractDatabase 
{
	
	abstract public function isField($field);
	
	abstract public function isRequired($field);
	
	abstract public function hasDefault($field);
	
	abstract public function getDefault($field);
	
	/**
	 * Validates an array of data and returns boolean.
	 * 
	 * @param array $data
	 * @return boolean
	 */
	public function validateData(array $data) {
		
		foreach($data as $key => $value) {
			
			if (! $this->isField($key)) {
				return false;
			}
			
			if (empty($value) && $this->isRequired($key) && ! $this->hasDefault($field)) {
				return false;
			}
		}
		
		return true;
	}
	
	public function cleanData(array $data) {
		
		$clean = array();
		
		foreach($data as $key => $value) {
			
			if ($this->isField($key)) {
				
				if (empty($value)) {
					
					if ($this->hasDefault($key)) {
						$clean[$key] = $this->getDefault($key);
						
					} else if ($this->isRequired($key)) {
						throw new \InvalidArgumentException("Missing required field: '$key'.");
					}
				
				} else {
					$clean[$key] = $value;
				}
			}
		}
		
		return $clean;
	}
	
}
