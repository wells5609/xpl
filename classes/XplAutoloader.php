<?php
/**
* class XplAutoloader
*
* A flexible class/interface/trait autoloader.
*
* Believed to be PSR-0 compliant.
* Features:
* - Can have multiple instances (pass a string to XplAutoloader::instance()).
* - Can map classes to a single file or to directories based on a prefix.
* - Can add fallback directories to search when no prefixed match is found.
* - Can restrict loading to only those paths explicitly mapped (for performance).
* - Can optionally fallback to PHP's stream_resolve_include_path() for PHP >= 5.3.2
*
* @since 0.2
*/
class XplAutoloader {
	
	public $classMap = array();
	
	public $paths = array();
	
	public $fallbackDirs = array();
	
	public $uid;
	
	protected $strict = false;
	
	protected $useIncludePath = false;
	
	static private $_instances = array();
	
	static function instance( $uid = 'default' ){
		if ( !isset(self::$_instances[ $uid ]) )
			self::$_instances[ $uid ] = new self( $uid );
		return self::$_instances[ $uid ];
	}
	
	/**
	* Adds a file path to load a single class.
	*/
	public function addClass( $class, $filepath ){
		
		$this->classMap[ $class ] = $filepath;
	}
	
	/**
	* Adds array of directory paths to search when class begins with $prefix.
	*/
	public function addPaths( $prefix, $paths, $prepend = false ){
		
		if (!$prefix){
			$this->addFallbackPaths($paths, $prepend);
			return;	
		}
		if (!isset($this->paths[$prefix])) {
			$this->paths[$prefix] = (array) $paths;
			return;
		}
		if ($prepend) {
			$this->paths[$prefix] = array_merge((array) $paths, $this->paths[$prefix]);
		} 
		else {
			$this->paths[$prefix] = array_merge($this->paths[$prefix], (array) $paths);
		}
	}
	
	/**
	* Adds array of directory paths to search as fallback.
	*/
	public function addFallbackPaths( $paths, $prepend = false ){
		
		if ($prepend) {
			$this->fallbackDirs = array_merge((array) $paths, $this->fallbackDirs);
		} 
		else {
			$this->fallbackDirs = array_merge($this->fallbackDirs, (array) $paths);
		}
	}
	
	/**
	* Sets whether to search PHP include path as last resort.
	*/
	public function setUseIncludePath( $value ){
		
		$this->useIncludePath = (bool) $value;	
	}
	
	public function setStrict( $value = true ){
		
		$this->strict = (bool) $value;	
	}
	
	public function isScrict(){
		return $this->strict;	
	}
	
	
	/**
	* Finds and loads a class (or interface or trait).
	*/
	public function load( $class ){
		
		if ( false !== strpos($class, '\\') ){
			$class = str_replace('\\\\', '', $class);
		}
		
		if ( $file = $this->find($class) ){
			require $file;
			return true;
		}
	}
	
	/**
	* Tries to find a class file and returns its path.
	*/
	protected function find($class){
		
		if ( isset($this->classMap[$class]) ) {
			return $this->classMap[$class];	
		}
		
		$classPath = str_replace(array('_','\\'), '/', $class) . '.php';

        foreach ($this->paths as $prefix => $dirs) {
            if ( 0 === strpos($class, $prefix) ) {
                foreach ($dirs as $dir) {
                    if ( file_exists($dir . '/' . $classPath) ) {
                        return $dir . '/' . $classPath;
                    }
                }
            }
        }
		
		if ( ! $this->isScrict() ){
				
			foreach ($this->fallbackDirs as $dir) {
				if ( file_exists($dir . '/' . $classPath) ) {
					return $dir . '/' . $classPath;
				}
			}
	
			if ($this->useIncludePath && $file = stream_resolve_include_path($classPath)) {
				return $file;
			}
		}
		
        return $this->classMap[$class] = false;
	}
		
	private function __construct( $uid ){
		
		$this->uid = $uid;
	}
	
	public function register(){
		
		spl_autoload_register( array($this, 'load') );	
	}
	
	public function unregister(){
		
		spl_autoload_unregister( array($this, 'load') );
	}
	
}

XplAutoloader::instance()->register();