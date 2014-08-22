<?php

namespace xpl\Component\Data\Service;

use xpl\Component\Data\ReadOnlyInterface;

abstract class AbstractReadOnly extends AbstractService implements ReadOnlyInterface {
	
	final public function isReadOnly() {
		return true;
	}
	
}
