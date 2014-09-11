<?php

namespace xpl\Data\Remote;

interface ServiceInterface extends \xpl\Data\ServiceInterface 
{
	
	/**
	 * @return \xpl\Data\Remote\SourceInterface
	 */
	public function getSource();
	
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
