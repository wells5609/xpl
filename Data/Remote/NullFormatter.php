<?php

namespace xpl\Data\Remote;

final class NullFormatter extends AbstractFormatter {
	
	public function formatSourceData(array $data) {
		return $data;
	}
	
	public function formatStorageData(array $data) {
		return $data;
	}
	
}
