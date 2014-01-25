<?php
/**
* class XplDirectory
*
* Object representation of a filesystem directory.
*
* Sort of like an enhanced Directory class (SPL).
* Finds or includes files matching a shell wildcard pattern, 
* optionally recursive. Also does directories.
*
* @since 0.3
*/
class XplDirectory {
	
	protected $dir;
	
	protected $_dirs;
	
	function __construct( $directory ){
		
		if ( !is_dir($directory) ){
			throw new InvalidArgumentException('XplDirectory: $directory ' . $directory . ' is not a directory');
		}
		
		$this->dir = dir( $directory );
	}
	
	function getHandle(){
		return $this->dir->handle;	
	}
	
	function getPath( $item = null ){
		if ( null !== $item ){
			return rtrim($this->dir->path, '/') . '/' . ltrim($item, '/');
		}
		return $this->dir->path;
	}
	
	public function read(){
		return readdir( $this->getHandle() );	
	}
	
	public function close(){
		return closedir( $this->getHandle() );
	}
	
	public function reset(){
		unset($this->scanned);	
	}
	
	public function url(){
		return url( $this->getPath() );
	}
	
	public function includeFiles( $pattern = "*.php", $recursive = false ){
		
		$dir = $this->getPath();
		
		foreach(glob("$dir/*") as $path){
			
			if ( fnmatch($pattern, $path) ){
				include_once $path;
			} elseif ( $recursive && is_dir($path) ){
				dir_object($path)->includeFiles($pattern, $recursive);
			}
		}
		
	}
	
	public function scan( $sort = SCANDIR_SORT_ASCENDING, $force_reset = false ){
		
		if ( !isset($this->scanned) || $force_reset ){
			
			$this->scanned = array_diff( scandir($this->getPath(), $sort), array('..', '.') ); // remove '.' and '..'
		}
		
		return $this->scanned;
	}
	
	public function scanDeep( $sort = SCANDIR_SORT_ASCENDING, $force_reset = false ){
		
		$r = array();
		
		foreach($this->scan($sort, $force_reset) as $item){
			
			$path = $this->getPath($item);
			
			if ( is_dir($path) ){
				$r[ $item ]	= dir_object($path)->scanDeep();
			} else {
				$r[ $item ] = $path;	
			}
		}
		
		return $r;
	}
	
	public function dirs( $reset = false ){
		
		if ( empty($this->_dirs) || $reset ){
			
			foreach($this->scan() as $item){
				
				if ( ! pathinfo_extension($item) ){
				
					$this->_dirs[ $item ] = dir_object( $this->getPath($item) );
				}
			}
		}

		return $this->_dirs;
	}
		
	public function files( $pattern = '*', $fnmatch_flags = 0 ){
		
		$files = array();
		
		foreach($this->scan() as $item){
		
			if ( ! $extension = pathinfo_extension($item) )
				continue; // no extension => not a file
			
			if ( fnmatch($pattern, $item, $fnmatch_flags) || $pattern === $extension ){
				$files[ $item ] = $this->getPath() . '/' . $item;
			}
		}
		
		return $files;
	}
		
}