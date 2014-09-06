<?php

namespace xpl\Data\Service;

use xpl\Data\ReadOnlyInterface;

abstract class AbstractRemoteReadOnly extends AbstractRemoteService implements ReadOnlyInterface
{
	
	final public function isReadOnly() {
		return true;
	}
	
}
