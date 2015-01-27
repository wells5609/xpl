<?php

namespace xpl\Data;

interface FactoryInterface 
{
	
	public function getEntityClass();
	
	public function getCollectionClass();
	
	public function createEntity(array $data);
	
	public function createCollection(array $data);
	
}
