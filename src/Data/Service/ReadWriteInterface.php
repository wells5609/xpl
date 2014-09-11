<?php

namespace xpl\Data\Service;

interface ReadWriteInterface extends \xpl\Data\ServiceInterface {
	
	/**
	 * Creates a new record in storage.
	 * 
	 * @param array $data
	 */
	public function create(array $data);
	
}
