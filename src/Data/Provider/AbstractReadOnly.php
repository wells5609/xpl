<?php

namespace xpl\Data\Provider;

use xpl\Data\ReadOnlyInterface;

abstract class AbstractReadOnly extends AbstractProvider implements ReadOnlyInterface 
{
	
	final public function isReadOnly() {
		return true;
	}
	
}
