<?php

namespace xpl\Data\Remote\Service;

use xpl\Data\ReadOnlyInterface;

abstract class AbstractReadOnly extends AbstractService implements ReadOnlyInterface
{
	
	final public function isReadOnly() {
		return true;
	}
	
}
