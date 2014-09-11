<?php

namespace xpl\Data\Provider;

interface ReadWriteInterface extends \xpl\Data\ProviderInterface {
	
	public function insert(array $data);
	
	public function update(array $data, array $conditions);
	
	public function delete(array $conditions);
	
}
