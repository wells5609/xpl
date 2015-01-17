<?php

namespace xpl\Api\Response;

use xpl\Api\Manager;

class Type implements \xpl\Web\Response\TypeInterface 
{
	
	protected $accept = array(
		'application/json' => 'Json', 
		'text/javascript' => 'Jsonp', 
		'text/xml' => 'Xml',
		'application/xml' => 'Xml',
	);

	protected $api;
	protected $mimetype;
	
	public function __construct(Manager $api, $mimetype = null) {
		
		$this->api = $api;
		
		if (isset($mimetype) && isset($this->accept[$mimetype])) {
			$this->mimetype = $mimetype;
		}
	}
	
	public function getName() {
		return 'api';
	}
	
	public function format($body) {
		
		if (! isset($this->mimetype)) {
			$this->mimetype = 'application/json';
		}
		
		$classname = $this->accept[$this->mimetype];
		// @TODO Factory
		$type_class = 'xpl\\Web\\Response\\'.$classname;
		$type = new $type_class();
		
		if ('Json' === $classname) {
			$type->setDevParam($this->api->config('json.param.dev') ?: 'dev');
		
		} else if ('Jsonp' === $classname) {
			$type->setCallbackParam($this->api->config('jsonp.param.callback') ?: 'callback');
		}
		
		$body = $type->format($this->buildStructure($body));
		
		// in case it changes on us
		$this->mimetype = $type->getMimetype();
		
		return $body;
	}
	
	public function getMimetype() {
		return $this->mimetype;
	}
	
	protected function buildStructure($body) {
		
		if (! $this->api->hasStructure()) {
			$this->api->setStructure();
		}
		
		$structure = $this->api->getStructure();
		
		if ($this->api->hasErrors()) {
			$structure->setStatus(0);
			$structure->setMessage('An error occurred.');
			$structure->setErrors($this->api->getErrorOutput());
		} else {
			$structure->setStatus(1);
			$structure->setMessage('Success');
			$structure->setContent($body);
		}
		
		$structure->setDiagnostics(array(
			'MemoryUsage' => '%memory_usage% MB',
			'TimeElapsed' => '%time_elapsed_ms% ms'
		));
		
		return $structure;
	}
}
