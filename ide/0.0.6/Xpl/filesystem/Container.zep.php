<?php

namespace Xpl\Filesystem;


class Container implements \Countable
{
    /**
     * @var string
     */
    protected $rootPath;

    /**
     * @var array
     */
    protected $paths = array();


    /**
     * @return string 
     */
    public function getRootPath() {}

    /**
     * @param string $rootPath 
     */
    public function __construct($rootPath) {}

    /**
     * @param array $paths 
     * @return Container 
     */
    public function setPaths($paths) {}

    /**
     * @return array 
     */
    public function getPaths() {}

    /**
     * @param string $path 
     * @return Container 
     */
    public function addPath($path) {}

    /**
     * @param string $path 
     * @return bool 
     */
    public function hasPath($path) {}

    /**
     * @param string $path 
     * @return string|null 
     */
    public function getRelativePath($path) {}

    /**
     * @param string $filename 
     * @return string|null 
     */
    public function find($filename) {}

    /**
     * @param string $filename 
     * @return array|null 
     */
    public function search($filename) {}

    /**
     * @return int 
     */
    public function count() {}

}
