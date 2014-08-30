<?php

namespace xpl\Foundation;

abstract class Plugin extends AbstractBundle {
	
	final public function getType() {
		return 'plugin';
	}
	
}
