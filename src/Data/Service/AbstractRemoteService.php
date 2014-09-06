<?php

namespace xpl\Data\Service;

use xpl\Data\Remote\NullFormatter;

abstract class AbstractRemoteService implements RemoteServiceInterface
{
	
	/**
	 * Returns data from storage or source.
	 */
	public function getOne(array $conditions = array()) {
		
		$provider = $this->getProvider();
		
		// Fetch a record from storage
		if ($stored = $provider->fetchOne($conditions)) {
			
			// If records are not updated, or the record is not expired, return it
			if (! $this->isUpdated() || (isset($stored->updated) && ($stored->updated + $this->getUpdateTTL()) > time())) {
				return $stored;
			}
		}
		
		// Fetch data from source
		if ($sourced = $this->getSource()->query($conditions)) {
			
			// Format source data for storage
			$data = $this->getFormatter()->formatSourceData($sourced);
			
			// Insert if not updated or if update failed (record does not exist)
			if (! $this->isUpdated() || ! $provider->update($data)) {
				$provider->insert($data);
			}
			
			// Fetch the object we just stored
			return $provider->fetchOne($conditions);
		}
		
		return null;
	}
	
	public function getAll(array $conditions = array()) {
		return $this->getProvider()->fetchAll($conditions);
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
