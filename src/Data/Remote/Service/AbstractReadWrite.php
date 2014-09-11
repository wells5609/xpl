<?php

namespace xpl\Data\Remote\Service;

use xpl\Data\Service\ReadWriteInterface;

abstract class AbstractReadWrite extends AbstractService implements ReadWriteInterface
{
	
	public function isReadOnly() {
		return false;
	}
	
}
