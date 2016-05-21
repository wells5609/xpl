<?php

namespace Xpl;


class Date
{

    const MINUTE = 60;


    const HOUR = 3600;


    const DAY = 86400;


    const WEEK = 604800;


    const MONTH = 2592000;


    const YEAR = 31536000;


    const FORMAT_HUMAN = "d M Y H:i";


    const FORMAT_SQL = "Y-m-d H:i:s";


    /**
     * @param mixed $dateTime 
     * @return bool 
     */
    public static function isValid($dateTime) {}

    /**
     * @param mixed $time 
     * @return int 
     */
    public static function time($time = null) {}

    /**
     * @param mixed $time 
     * @param mixed $timezone 
     * @return \DateTime 
     */
    public static function make($time = null, $timezone = null) {}

    /**
     * @param mixed $timezone 
     * @return \DateTimeZone 
     */
    public static function timezone($timezone = null) {}

    /**
     * @param mixed $dateTime 
     * @param string $format 
     * @return string 
     */
    public static function format($dateTime, $format) {}

    /**
     * @param mixed $dateTime 
     * @param mixed $format 
     * @return string 
     */
    public static function formatHuman($dateTime, $format = null) {}

    /**
     * @param mixed $dateTime 
     * @return string 
     */
    public static function formatSql($dateTime) {}

}
