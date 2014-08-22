<?php

namespace xpl\Utility\Filesystem;

/**
 * FileLocator uses an array of pre-defined paths to find files.
 *
 * @author Fabien Potencier <fabien@symfony.com>
 */
class FileLocator
{
	
	/**
	 * @var string
	 */
	protected $root;
	
	/**
	 * @var array
	 */
	protected $paths;
	
	/**
	 * @var boolean
	 */
	protected $isWindows;

	/**
	 * Constructor.
	 *
	 * @param string|array $paths Root directory path for this locator or an array of absolute directory paths.
	 */
	public function __construct($paths = null) {
			
		$this->isWindows = DIRECTORY_SEPARATOR === '\\';
		
		if (null === $paths) {
			$this->paths = array();
		} else if (is_array($paths)) {
			$this->setPaths($paths);
		} else {
			$this->setRootPath($paths);
		}
	}
	
	/**
	 * Set the root directory path for this file locator instance.
	 * 
	 * @param string $path Absolute root directory path (top-most directory).
	 */
	public function setRootPath($path) {
		$this->root = realpath($path).DIRECTORY_SEPARATOR;
	}
	
	/**
	 * Returns the root directory path for this locator instance, if set.
	 * 
	 * @return string Root directory path.
	 */
	public function getRootPath() {
		return isset($this->root) ? $this->root : null;
	}
	
	/**
	 * Sets a named directory path.
	 * 
	 * If a root path is set, paths can be given as relative to the root directory and
	 * will be changed to absolute paths upon adding.
	 * 
	 * @param string $name Path name.
	 * @param string $path Absolute directory path, or relative path if root path set.
	 * 
	 * @throws \InvalidArgumentException if given a relative path and no root path is set.
	 */
	public function setPath($name, $path) {
		
		if (! $this->isAbsolutePath($path)) {
			
			if (null === $this->root) {
				throw new \InvalidArgumentException("Cannot set relative path without root path set.");
			}
			
			$path = $this->root.ltrim($path, '/\\');
		}
		
		if ($realpath = realpath($path)) {
			$this->paths[$name] = $realpath.DIRECTORY_SEPARATOR;
		}
	}
	
	/**
	 * Sets an array of named directory paths.
	 * 
	 * @param array $paths
	 */
	public function setPaths(array $paths) {
		foreach($paths as $name => $path) {
			$this->setPath($name, $path);
		}
	}
	
	public function getPath($name) {
		return isset($this->paths[$name]) ? $this->paths[$name] : null;
	}

	/**
	 * Returns a full path for a given file name.
	 *
	 * @param mixed   $name        The file name to locate
	 * @param string  $currentPath The current path
	 * @param bool    $first       Whether to return the first occurrence or an array of filenames
	 *
	 * @return string|array The full path to the file or an array of file paths.
	 */
	public function locateFile($name, $currentPath = null, $first = true) {

		$filepaths = array();
		
		if (null !== $currentPath) {
			
			$currentPath = rtrim($currentPath, '/\\').DIRECTORY_SEPARATOR;
			
			if (file_exists($file = $currentPath.$name)) {
				
				if (true === $first) {
					return $file;
				}
				
				$filepaths[] = $file;
			}
		}

		foreach ($this->paths as $path) {
			
			if (file_exists($file = $path.$name)) {
					
				if (true === $first) {
					return $file;
				}
				
				$filepaths[] = $file;
			}
		}

		if (! $filepaths) {
			return null;
		}

		return array_values(array_unique($filepaths));
	}

	/**
	 * Returns whether the file path is an absolute path.
	 *
	 * @param string $file A file path
	 *
	 * @return bool
	 */
	public function isAbsolutePath($file) {
		
		if (! $this->isWindows) {
			return '/' === $file[0] || null !== parse_url($file, PHP_URL_SCHEME);
		}
		
		if (
			$file[0] == '/' 
			|| $file[0] == '\\' 
			|| (strlen($file) > 3 && ctype_alpha($file[0]) && $file[1] == ':' && ($file[2] == '\\' || $file[2] == '/')) 
			|| null !== parse_url($file, PHP_URL_SCHEME)
		) {
			return true;
		}

		return false;
	}

}
