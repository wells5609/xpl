<?php

namespace Xpl;


class OutputBuffer
{

    static private $root = null;


    private $valid = false;


    private $level;


    private $callback;


    /**
     * @param mixed $outputCallback 
     * @return OutputBuffer 
     */
    public static function start($outputCallback = null) {}

    /**
     * @return bool 
     */
    public static function finish() {}

    /**
     * @param mixed $outputCallback 
     */
    public function __construct($outputCallback = null) {}

    /**
     * @return string|null 
     */
    public function getContents() {}

    /**
     * @return string|null 
     */
    public function getClean() {}

    /**
     * @return string|null 
     */
    public function getFullClean() {}

    /**
     * @return bool 
     */
    public function clean() {}

    /**
     * @return bool 
     */
    public function fullClean() {}


    public function flush() {}

    /**
     * @return bool 
     */
    public function endFlush() {}

    /**
     * @return bool 
     */
    public function valid() {}

    /**
     * @return bool 
     */
    public function active() {}

    /**
     * @return int 
     */
    public function getLevel() {}

    /**
     * @return mixed|null 
     */
    public function getOutputCallback() {}

}
