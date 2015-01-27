<?php

namespace xpl\Utility\Filesystem;

class Task
{
	
	protected $cwd;
	
	public function __construct() {
		
	}
	
	public function install() {
		
		$files = array(
			__DIR__.'/ckeditor.js',
			__DIR__.'/build-config.js',
			__DIR__.'/config.js',
			__DIR__.'/styles.js',
			__DIR__.'/contents.css',
		);
		
		foreach(array('plugins', 'skins', 'lang') as $dir) {
			$this->getDirFiles(__DIR__.'/'.$dir, $files);
		}
		
		$root_dest = DOCROOT.'/resources/assets/ckeditor/';
		
		if (! mkdir($root_dest, 0777, true)) {
			trigger_error("Could not install CKEditor.");
			return null;
		}
		
		foreach($files as $file) {
			
			$dest = $root_dest.str_replace(__DIR__.'/', '', $file);
			
			$dir = dirname($dest);
			
			if (! is_dir($dir) && ! mkdir($dir, 0777, true)) {
				trigger_error("Could not create directory: '$dir'.", E_USER_NOTICE);
			
			} else if (! copy($file, $dest)) {
				trigger_error("Could not copy '$file' to '$dest'.", E_USER_NOTICE);
			}
		}
	}
	
	protected function getDirFiles($dir, array &$files = array()) {
		
		foreach(glob(rtrim($dir, '/\\').'/*', GLOB_MARK) as $item) {
			
			if (DIRECTORY_SEPARATOR === substr($item, -1, 1)) {
				$this->getDirFiles($item, $files);
			} else {
				$files[] = $item;	
			}
		}
		
		return $files;
	}
	
}
