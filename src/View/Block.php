<?php

namespace xpl\View;

class Block extends DataWrapper {
	
	protected $template;
	protected $data;
	
	public function __construct($template, Data $data = null) {
		
		if (! is_readable($template) && ! is_callable($template)) {
			throw new \InvalidArgumentException("Template must be readable file or callable, given: ".gettype($template));
		}
		
		$this->template = $template;
		$this->data = $data ?: new Data();
	}
	
	public function __toString() {
		try {
			return $this->render();
		} catch (\Exception $e) {
			logmsg((string)$e);
			return getenv('DEBUG') ? (string) $e : ' --- Rendering error --- ';
		}
	}
	
	public function render() {
		
		ob_start();
		
		if (is_readable($this->template)) {
				
			extract($this->data->toArray(), EXTR_REFS);
			
			include $this->template;
		
		} else {
			
			echo call_user_func($this->template, $this->data->toArray());
		}
		
		return ob_get_clean();
	}
	
}
