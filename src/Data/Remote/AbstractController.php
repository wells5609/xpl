<?php

namespace xpl\Data\Remote;

abstract class AbstractController implements ControllerInterface 
{
	
	/**
	 * @return \xpl\Data\Remote\SourceInterface
	 */
	abstract public function getSource();
	
	/**
	 * @return \xpl\Data\Provider\ProviderInterface
	 */
	abstract public function getProvider();
	
	/**
	 * Returns data from storage or source.
	 */
	public function getOne(array $args) {
		
		$provider = $this->getProvider();
		
		// Fetch a record from storage
		if ($stored = $provider->fetchOne($args)) {
			
			// If records are not updated, or the record is not expired, return it
			if (! $this->isUpdated() || (isset($stored->updated) && ($stored->updated + $this->getUpdateTTL()) > time())) {
				return $stored;
			}
		}
		
		// Fetch data from source
		if ($sourced = $this->getSource()->query($args)) {
			
			// Format source data for storage
			$data = $this->getFormatter()->formatSourceData($sourced);
			
			// Insert if not updated or if update failed (record does not exist)
			if (! $this->isUpdated() || ! $provider->update($data)) {
				$provider->insert($data);
			}
			
			// Fetch the object we just stored
			return $provider->fetchOne($args);
		}
		
		return null;
	}
	
	/**
	 * @return \xpl\Data\Remote\FormatterInterface
	 */
	public function getFormatter() {
		return new NullFormatter();
	}
	
	/**
	 * @return boolean
	 */
	public function isUpdated() {
		return false;
	}
	
	/**
	 * @return int
	 */
	public function getUpdateTTL() {
		return 86400;
	}
	
}
