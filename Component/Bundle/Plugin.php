<?php

namespace xpl\Component\Bundle;

abstract class Plugin extends Bundle {
	
	final public function getType() {
		return 'plugin';
	}
	
}
