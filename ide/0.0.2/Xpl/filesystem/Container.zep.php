<?php

namespace Xpl\Filesystem;

class Container implements \Countable
{
    /**
     * @var string
     */
    protected $basePath;
    /**
     * @var array
     */
    protected $directoryPaths;

    /**
     * @return string 
     */
	public function getBasePath() {}

    /**
     * @param string $basePath 
     */
	public function __construct($basePath) {}

    /**
     * @param string $path 
     * @return string|null 
     */
	public function getRelativePath($path) {}

    /**
     * @return array 
     */
	public function getDirectoryPaths() {}

    /**
     * @param string $filename 
     * @param bool $first 
     * @return string|array|bool 
     */
	public function find($filename, $first = true) {}

    /**
     * @return int 
     */
	public function count() {}

}
