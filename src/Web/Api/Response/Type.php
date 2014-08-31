<?php

namespace xpl\Web\Api\Response;

use xpl\Web\Response\TypeInterface;

class Type implements TypeInterface {
	
	protected $accept = array(
		'application/json' => 'Json', 
		'text/javascript' => 'Jsonp', 
		'text/xml' => 'Xml',
		'application/xml' => 'Xml',
	);

	protected $mimetype;
	
	public function __construct($mimetype = null) {
		
		if (isset($mimetype) && isset($this->accept[$mimetype])) {
			$this->mimetype = $mimetype;
		}
	}
	
	public function getName() {
		return 'api';
	}
	
	public function format($body) {
		
		if (! isset($this->mimetype)) {
		
			$mime = di()->resolve('request')->getMimetype();
			
			if (! $mime || ! isset($this->accepted[$mime])) {
				$this->mimetype = 'application/json';
			}
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
		
		$api = di()->offsetGet('api');
		
		if (! $api->hasStructure()) {
			$api->setStructure();
		}
		
		$structure = $api->getStructure();
		
		$errors = \Error::getMessages('ApiErrorException');
		
		if ($errors) {
			$structure->setStatus(0);
			$structure->setMessage('An error occurred.');
			$structure->setErrors($errors);
		} else {
			$structure->setStatus(1);
			$structure->setMessage('Success');
			$structure->setContent($body);
		}
		
		$diagnostics = array(
			'Memory' => array(
				'Usage' => memory_usage(3).' MB',
				'RealUsage' => memory_usage(3, true).' MB',
				'PeakUsage' => number_format(memory_get_peak_usage()/1024/1024, 3).' MB',
			),
			'TimeElapsed' => (time_elapsed(5)*1000).' ms'
		);
		
		$structure->setDiagnostics($diagnostics);
		
		return $structure;
	}
}
