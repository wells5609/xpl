<?php

namespace xpl\Bundle;

abstract class Plugin extends Bundle {
	
	final public function getType() {
		return 'plugin';
	}
	
}
