<?php

namespace xpl\View;

class View extends DataWrapper 
{
	
	protected $template;
	protected $data;
	protected $content;
	
	public function __construct($template, Data $data = null) {
		
		if (! is_readable($template)) {
			throw new \InvalidArgumentException("Unreadable file template: '$template'.");
		}
		
		$this->template = $template;
		$this->data = $data ?: new Data();
	}
	
	public function __toString() {
		try {
			return $this->render();
		} catch (\Exception $e) {
			xpl_log((string)$e);
			return getenv('DEBUG') ? (string)$e : ' --- Rendering error --- ';
		}
	}
	
	public function addStyleToHead($url) {
		$this->addStyle('head', $url);
	}
	
	public function addScriptToHead($url) {
		$this->addScript('head', $url);
	}
	
	public function addStyleToFooter($url) {
		$this->addStyle('footer', $url);
	}
	
	public function addScriptToFooter($url) {
		$this->addScript('footer', $url);
	}
	
	public function render() {
		
		ob_start();
		
		extract($this->data->toArray(), EXTR_REFS);
		
		$view = $this;
		
		include $this->template;
		
		return ob_get_clean();
	}
	
	protected function addStyle($location, $url) {
		$this['assets_'.$location] .= PHP_EOL.'<link href="'.$url.'" rel="stylesheet" type="text/css">';
	}
	
	protected function addScript($location, $url) {
		$this['assets_'.$location] .= PHP_EOL.'<script src="'.$url.'" type="text/javascript"></script>';
	}
	
}
