<?php

namespace xpl\View;

class View extends Block {
	
	public function __construct($template, Data $data = null) {
		
		if (! is_readable($template)) {
			throw new \InvalidArgumentException("Unreadable file template: '$template'.");
		}
		
		parent::__construct($template, $data);
	}
	
	public function addStyle($url, $location = 'head') {
		$this['assets_'.$location] .= PHP_EOL.'<link href="'.$url.'" rel="stylesheet" type="text/css">';
	}
	
	public function addScript($url, $location = 'footer') {
		$this['assets_'.$location] .= PHP_EOL.'<script src="'.$url.'" type="text/javascript"></script>';
	}
	
	public function render() {
		
		ob_start();
		
		extract($this->data->toArray(), EXTR_REFS);
		
		include $this->template;
		
		return ob_get_clean();
	}
	
}
