<?php

namespace xpl\Framework\Web;

use xpl\Http\Response as HttpResponse;
use xpl\Http\Request as HttpRequest;
use xpl\Framework\Web\Response\TypeInterface as ResponseType;

class Response extends HttpResponse {
	
	protected $type;
	
	public function setType(ResponseType $type) {
		$this->type = $type;
		return $this;
	}
	
	public function getType($as_object = false) {
		
		if (! isset($this->type)) {
			return null;
		}
		
		return $as_object ? $this->type : $this->type->getName();
	}
	
	public function send($exit = true) {
		
		if ($this->send_body) {
			
			if (! isset($this->type)) {
				$this->type = new Response\Html();
			}
			
			$this->setBody($this->type->format($this->getBody()));
			
			$this->setContentType($this->type->getMimetype());
		}
		
		parent::send($exit);
	}

}
