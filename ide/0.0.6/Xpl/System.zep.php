<?php

namespace Xpl;

/**
 * System/server utilities.
 */
class System
{

    /**
     * @return string 
     */
    public static function sapi() {}

    /**
     * @return string 
     */
    public static function os() {}

    /**
     * @param mixed $extension 
     * @return string 
     */
    public static function version($extension = null) {}

    /**
     * @return bool 
     */
    public static function isCli() {}

    /**
     * @return bool 
     */
    public static function isWin() {}

    /**
     * @param bool $megabytes 
     * @return double 
     */
    public static function memoryUsage($megabytes = true) {}

    /**
     * @param bool $megabytes 
     * @return double 
     */
    public static function memoryPeakUsage($megabytes = true) {}

    /**
     * @param bool $milliseconds 
     * @return double|int|null 
     */
    public static function timer($milliseconds = true) {}

    /**
     * @return bool 
     */
    public static function apc() {}

    /**
     * @return bool 
     */
    public static function apcu() {}

    /**
     * @return bool 
     */
    public static function xdebug() {}

    /**
     * @return bool 
     */
    public static function mbstring() {}

    /**
     * @param string $path 
     * @return string 
     */
    public static function normalizePath($path) {}

    /**
     * @return string 
     */
    public static function tempDir() {}

}
