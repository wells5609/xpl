<?php

namespace xpl\Common\Structure;

class Map extends BaseMap {
	
	public function __construct($data = null) {
		isset($data) and $this->import($data);
	}
	
}
