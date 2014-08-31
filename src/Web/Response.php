<?php

namespace xpl\Web;

class Response extends \xpl\Http\Response {
	
	protected $type;
	
	/**
	 * Construct response.
	 */
	public function __construct(Request $request) {
		parent::__construct($request);
		$this->request_mimetype = $request->getMimetype();
	}
	
	public function getRequestMimetype() {
		return isset($this->request_mimetype) ? $this->request_mimetype : null;
	}
	
	public function setType(Response\TypeInterface $type) {
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
