<?php

namespace xpl\Component\Data\Provider;

use xpl\Component\Data\ReadOnlyInterface;

abstract class AbstractReadOnly extends AbstractProvider implements ReadOnlyInterface {
	
	final public function isReadOnly() {
		return true;
	}
	
}
