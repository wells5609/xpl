<?php

namespace xpl\View;

use xpl\Utility\Filesystem\FileLocator;

class Manager extends DataWrapper {
	
	protected $template_path;
	protected $cache_path;
	protected $locator;
	protected $data;
	protected $views;
	protected $blocks;
	protected $replacements;
	
	public function __construct($template_path) {
		
		$this->locator = new FileLocator();
		$this->data = new Data();
		$this->views = array();
		$this->blocks = array();
		$this->replacements = array();
		
		$this->template_path = realpath($template_path).DIRECTORY_SEPARATOR;
		
		$this->locator->setRootPath($this->template_path);
		
		if (file_exists($this->template_path.'theme-init.php')) {
			
			$paths = include $this->template_path.'theme-init.php';
			
			if (is_array($paths)) {
				foreach($paths as $name => $dir) {
					$this->locator->setPath($name, $dir);
				}
			}
		}
	}
	
	public function getTemplatePath() {
		return $this->template_path;
	}
	
	public function setCachePath($path) {
		$this->cache_path = realpath($path).DIRECTORY_SEPARATOR;
	}
	
	public function getCachePath() {
		return isset($this->cache_path) ? $this->cache_path : null;
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
	
	public function block($template) {
		
		$is_object = is_object($template);
		$id = $is_object ? spl_object_hash($template) : $template;
		
		if (isset($this->blocks[$id])) {
			return $this->blocks[$id];
		}
		
		if ($is_object) {
			return $this->blocks[$id] = new Block($template, $this->data);
		}
		
		if (! $file = $this->locateFile($template)) {
			return null;
		}
		
		return $this->blocks[$id] = new Block($file, $this->data);
	}
	
	public function replace($search, $replace) {
		$this->replacements[$search] = $replace;
	}
	
	public function getReplacements() {
		return $this->replacements;
	}
	
	public function getDefaultReplacements() {
		return array(
			'{URL}' => rtrim(http_build_url('/'), '/'),
			'{ASSETS}' => $this->locator->getPath('assets'),
			'{SITE_TITLE}' => $this['site_title'],
			'{COPYRIGHT}' => '&copy; '.date('Y'),
		);
	}
	
	protected function parseFile($file) {
		
		$replacements = $this->getReplacements();
		
		$search = array_keys($replacements);
		$replace = array_values($replacements);
		
		return str_replace($search, $replace, file_get_contents($file));
	}
	
	protected function cacheFile($cache_file, $contents) {
		return file_put_contents($cache_file, $contents, LOCK_EX);
	}
	
	protected function getCacheFile($file) {
		return $this->cache_path.pathinfo($file, PATHINFO_BASENAME).'.cache';
	}
	
}
