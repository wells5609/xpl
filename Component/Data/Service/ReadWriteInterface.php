<?php

namespace xpl\Component\Data\Service;

interface ReadWriteInterface extends ServiceInterface {
	
	/**
	 * Creates a new record in storage.
	 * 
	 * @param array $data
	 */
	public function create(array $data);
	
}
