<?php

namespace xpl\Component\Data\Provider;

interface ReadWriteInterface extends ProviderInterface {
	
	public function insert(array $data);
	
	public function update(array $data, array $conditions);
	
	public function delete(array $conditions);
	
}
