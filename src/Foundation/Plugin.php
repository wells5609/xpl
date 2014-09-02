<?php

namespace xpl\Foundation;

abstract class Plugin extends AbstractDiAwareBundle {
	
	final public function getType() {
		return 'plugin';
	}
	
}
