<?php

namespace xpl\Data\Remote;

abstract class AbstractFormatter implements FormatterInterface
{
	
	abstract public function formatSourceData(array $data);
	
	abstract public function formatStorageData(array $data);
	
	protected function replaceKeys(array $data, array $key_map) {
		$return = array();
		foreach($key_map as $src_key => $db_key) {
			if (! empty($db_key) && array_key_exists($src_key, $data)) {
				$return[$db_key] = $data[$src_key];
			}
		}
		return $return;
	}
	
}
