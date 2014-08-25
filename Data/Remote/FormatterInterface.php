<?php

namespace xpl\Data\Remote;

interface FormatterInterface {
	
	public function formatSourceData(array $data);
	
	public function formatStorageData(array $data);
	
}
