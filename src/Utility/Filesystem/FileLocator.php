<?php

namespace xpl\Utility\Filesystem;

/**
 * FileLocator uses an array of pre-defined paths to find files.
 *
 * @author Fabien Potencier <fabien@symfony.com>
 */
class FileLocator extends Container
{
	
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

}
