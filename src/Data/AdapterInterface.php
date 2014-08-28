<?php

namespace xpl\Data;

interface AdapterInterface {
	
	public function select($var, array $conditions = array(), $option = null);
	
	public function insert($var, array $conditions);
	
	public function update($var, array $conditions, $option = null);
	
	public function delete($var, $conditions = null);
}
