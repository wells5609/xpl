<?php

namespace xpl\View;

use xpl\Dependency\DI;
use xpl\Dependency\DiAwareInterface;
use xpl\Utility\Filesystem\FileLocator;

class Manager extends DataWrapper implements DiAwareInterface 
{	
	protected $di;
	protected $views;
	protected $data;
	protected $locator;
	protected $cache_path;
	
	public function __construct($template_path, $cache_path = null) {
		
		$this->views = array();
		$this->data = new Data();
		$this->locator = new FileLocator();
		
		if (isset($cache_path)) {
			$this->cache_path = realpath($cache_path).DS;
		}
		
		$template_path = realpath($template_path).DS;
		
		$this->locator->setRootPath($template_path);
		$this->locator->setPath('templates', 'templates/');
		$this->locator->setPath('partials', 'partials/');
		$this->locator->setPath('assets', 'public/');
		
		if (file_exists($template_path.'theme-init.php')) {
			include $template_path.'theme-init.php';
		}
	}
	
	public function setDI(DI $di) {
		$this->di = $di;
	}
	
	public function getDI() {
		return isset($this->di) ? $this->di : null;
	}
	
	public function locateFile($filename) {
		return $this->locator->locateFile($filename);
	}
	
	public function view($template, $refresh_cache = false) {
		
		if (isset($this->views[$template])) {
			return $this->views[$template];
		}
		
		if (! $file = $this->locateFile($template)) {
			return null;
		}
	
		if (isset($this->cache_path)) {
			
			$cache_file = $this->getCacheFile($file);
			
			if ($refresh_cache || ! file_exists($cache_file)) {
				$this->cacheFile($cache_file, $this->parseFile($file));
			}
			
			$file = $cache_file;
		}
		
		return $this->views[$template] = new View($file, $this->data);
	}
	
	protected function parseFile($file) {
		return str_replace(
			array('{URL}', '{ASSETS}', '{SITE_TITLE}', '{COPYRIGHT}'), 
			array(rtrim(http_build_url('/'), '/'), $this->locator->getPath('assets'), $this['site_title'], '&copy; '.date('Y')),
			file_get_contents($file)
		);
	}
	
	protected function cacheFile($cache_file, $contents) {
		return file_put_contents($cache_file, $contents, LOCK_EX);
	}
	
	protected function getCacheFile($file) {
		return $this->cache_path.pathinfo($file, PATHINFO_BASENAME).'.cache';
	}
	
}
