<?php

namespace xpl\Web\Api\Response;

use xpl\Web\Api\Manager;
use xpl\Web\Response\TypeInterface;

class Type implements TypeInterface {
	
	protected $accept = array(
		'application/json' => 'Json', 
		'text/javascript' => 'Jsonp', 
		'text/xml' => 'Xml',
		'application/xml' => 'Xml',
	);

	protected $api;
	protected $mimetype;
	
	public function __construct(Manager $api_manager, $mimetype = null) {
			
		$this->api = $api_manager;
		
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
		$type_class = 'xpl\\Web\\Response\\'.$classname;
		
		$type = new $type_class();
		
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
			'Memory' => array(
				'Usage' => memory_usage(3).' MB',
				'RealUsage' => memory_usage(3, true).' MB',
				'PeakUsage' => number_format(memory_get_peak_usage()/1024/1024, 3).' MB',
			),
			'TimeElapsed' => (time_elapsed(5)*1000).' ms'
		));
		
		return $structure;
	}
}
