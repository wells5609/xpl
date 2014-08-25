<?php

namespace xpl\Data\Remote;

interface ControllerInterface {
	
	/**
	 * Fetches a single record.
	 * 
	 * If the record exists in storage and is not expired (or never expires),
	 * the record is returned. Otherwise data is fetched from source and saved.
	 * 
	 * @param array $args
	 * @return mixed
	 */
	public function getOne(array $args);
	
	/**
	 * @return \xpl\Data\Remote\SourceInterface
	 */
	public function getSource();
	
	/**
	 * @return \xpl\Data\Provider\ProviderInterface
	 */
	public function getProvider();
	
	/**
	 * @return \xpl\Data\Remote\FormatterInterface
	 */
	public function getFormatter();
	
	/**
	 * @return boolean
	 */
	public function isUpdated();
	
	/**
	 * @return int
	 */
	public function getUpdateTTL();
	
}
