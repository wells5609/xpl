<?php

namespace xpl\Data\Service;

abstract class AbstractRemoteReadWrite extends AbstractRemoteService implements ReadWriteInterface
{
	
	public function isReadOnly() {
		return false;
	}
	
}
