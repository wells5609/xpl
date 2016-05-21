<?php

namespace Xpl;

/**
 * String utilities.
 */
class Str
{
    /**
     * @var string
     */
    const NULL_STRING = "";

    /**
     * @var string
     */
    const WHITESPACE = " ";

    /**
     * Last error string.
     *
     * @var string
     */
    static protected $lastError;


    /**
     * @param mixed $obj 
     * @param mixed $params 
     * @param mixed $extra 
     * @return string|mixed 
     */
    public static function ukey($obj, $params, $extra = null) {}

    /**
     * Camelizes an underscored string to camelcase.
     *
     * @param string $str 
     * @return string 
     */
    public static function camelize($str) {}

    /**
     * Uncamelizes a camelcase string to underscored.
     *
     * @param string $str 
     * @return string 
     */
    public static function uncamelize($str) {}

    /**
     * Returns true if $haystack starts with $needle.
     *
     * @param string $haystack 
     * @param string $needle 
     * @param bool $case_insensitive 
     * @param string $$haystack String to search within.
     * @param string $$needle String to find.
     * @param boolean $$case_insensitive Whether to check case-insensitive. Default true.
     * @return boolean 
     */
    public static function startsWith($haystack, $needle, $case_insensitive = true) {}

    /**
     * Returns true if $haystack ends with $needle.
     *
     * @param string $haystack 
     * @param string $needle 
     * @param bool $case_insensitive 
     * @param string $$haystack String to search within.
     * @param string $$needle String to find.
     * @param boolean $$case_insensitive Whether to check case-insensitive. Default true.
     * @return boolean 
     */
    public static function endsWith($haystack, $needle, $case_insensitive = true) {}

    /**
     * Whether the given string contains any of the characters in $charlist
     *
     * @param string $str 
     * @param string $charlist 
     * @return boolean if str contains any of the characters in charlist, otherwise false
     */
    public static function hasChars($str, $charlist) {}

    /**
     * Converts a string to a PEAR-like class name. (e.g. "Http_Request2_Response")
     *
     * @param string $str 
     * @param string  
     * @return string 
     */
    public static function pearCase($str) {}

    /**
     * Converts a string to "snake_case"
     *
     * @param string $str 
     * @param string  
     * @return string 
     */
    public static function snakeCase($str) {}

    /**
     * Converts a string to "StudlyCaps"
     *
     * @param string $str 
     * @param string  
     * @return string 
     */
    public static function studlyCase($str) {}

    /**
     * Converts a string to "camelCase"
     *
     * @param string $str 
     * @param string  
     * @return string 
     */
    public static function camelCase($str) {}

    /**
     * Sanitizes a string to contain only ASCII characters
     *
     * @param string $str 
     * @param string $$str 
     * @return string 
     */
    public static function ascii($str) {}

    /**
     * Strips non-alphabetic characters from a string.
     *
     * @param string $str 
     * @param string  
     * @return string 
     */
    public static function alpha($str) {}

    /**
     * Strips non-alphanumeric characters from a string.
     *
     * @param string $str 
     * @param string  
     * @return string 
     */
    public static function alnum($str) {}

    /**
     * Strips invalid unicode from a string.
     *
     * @param string $str 
     * @param string  
     * @return string 
     */
    public static function unicode($str) {}

    /**
     * Sanitizes a string to a "slug" format: lowercase alphanumeric string with given separator.
     *
     * @param string $str 
     * @param string $separator 
     * @param string $$string Dirty string.
     * @param string $$separator [Optional] Character used to replace non-alphanumeric characters. Default "-".
     * @return string string.
     */
    public static function slug($str, $separator = "-") {}

    /**
     * Removes single and double quotes from a string.
     *
     * @param string $str 
     * @param string  
     * @return string 
     */
    public static function stripQuotes($str) {}

    /**
     * Removes non-printing ASCII control characters from a string.
     *
     * @param string $str 
     * @param string  
     * @return string 
     */
    public static function stripControl($str) {}

    /**
     * Escapes text for SQL LIKE special characters % and _.
     *
     * @param string $str 
     * @param string $$text The text to be escaped.
     * @return string safe for inclusion in LIKE query.
     */
    public static function filterSqlLike($str) {}

    /**
     * Sanitizes a URL, decoding using rawurldecode() and filter_var().
     *
     * @param string $url URL, possibly containing encoded characters
     * @param int $flags [Optional] Optional filter_var() flags
     * @return string URL with "%##" characters translated
     */
    public static function filterUrl($url, $flags = 0) {}

    /**
     * Returns whether the given variable is a valid JSON string.
     *
     * @param string $str 
     * @param string  
     * @return boolean 
     */
    public static function isJson($str) {}

    /**
     * Checks whether the given value is a valid XML string.
     *
     * @param string $str 
     * @param string $$arg Value to check if XML.
     * @return boolean if value is a valid XML string, otherwise false.
     */
    public static function isXml($str) {}

    /**
     * Checks whether the given value is a valid serialized string.
     *
     * @param string $str 
     * @param string $$data Value to check if serialized
     * @return boolean If value is a valid serialized string, otherwise false.
     */
    public static function isSerialized($str) {}

    /**
     * Formats a string by injecting non-numeric characters into
     * the string in the positions they appear in the template.
     *
     * @param string $str 
     * @param string $template 
     * @param string $$string The string to format
     * @param string $$template String format to apply
     * @return string string.
     */
    public static function format($str, $template) {}

    /**
     * Returns 1st occurance of text between two strings.
     * The "between" strings are not included in output.
     *
     * @param string $str 
     * @param string $substr_start 
     * @param string $substr_end 
     * @param string $$string The string in which to search.
     * @param string $$substr_start The starting string.
     * @param string $$substr_end The ending string.
     * @return string between $start and $end.
     */
    public static function between($str, $substr_start, $substr_end) {}

    /**
     * Get a given number of sentences from a string.
     *
     * @param boolean|array $strip_abbr Whether to strip abbreviations (they break the function).
     * Pass an array to account for those abbreviations as well.
     * @param string $str 
     * @param int $num 
     * @param mixed $strip_abbr 
     * @param string $$text The full string of sentences.
     * @param int $$num Number of sentences to return. Default 1.
     * @return string number of sentences.
     */
    public static function sentences($str, $num = 1, $strip_abbr = false) {}

    /**
     * Class error handler
     *
     * @param int $errorNum 
     * @param string $errorMsg 
     */
    public static function handleError($errorNum, $errorMsg) {}

}
