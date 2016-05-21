<?php

namespace Xpl;


class StringBuffer implements \ArrayAccess
{

    const CASE_LOWER = 0;


    const CASE_UPPER = 1;


    const CASE_TITLE = 2;


    const PAD_LEFT = 0;


    const PAD_RIGHT = 1;


    const PAD_BOTH = 2;


    const ERROR_THROW = 0;


    const ERROR_TRIGGER = 1;


    const ERROR_IGNORE = 2;

    /**
     * The current string value
     *
     * @var string
     */
    private $value;

    /**
     * The original string value
     *
     * @var string
     */
    private $original;

    /**
     * The string's encoding
     *
     * @var string
     */
    private $encoding;

    /**
     * HTML entities flags
     *
     * @var int
     */
    static private $htmlEntFlags = 2;

    /**
     * Error mode. One of "ERROR_*" class constants
     *
     * @var int
     */
    static private $errorMode = 0;


    /**
     * Constructor
     *
     * @param string $str 
     * @param mixed $encoding 
     * @param string $string 
     */
    public function __construct($str, $encoding = null) {}

    /**
     * Returns the string length
     *
     * @return int 
     */
    public function length() {}

    /**
     * Alias of StringBuffer::length()
     *
     * @return int 
     */
    public function len() {}

    /**
     * Finds the position of the first occurance of the given substring
     *
     * @param string $needle 
     * @param int $offset 
     * @return int 
     */
    public function pos($needle, $offset = 0) {}

    /**
     * Finds the position of the last occurance of the given substring
     *
     * @param string $needle 
     * @param int $offset 
     * @return int 
     */
    public function rpos($needle, $offset = 0) {}

    /**
     * Finds the position of the first occurance of the given substring case insensitively
     *
     * @param string $needle 
     * @param int $offset 
     * @return int 
     */
    public function ipos($needle, $offset = 0) {}

    /**
     * Finds the position of the last occurance of the given substring case insensitively
     *
     * @param string $needle 
     * @param int $offset 
     * @return int 
     */
    public function ripos($needle, $offset = 0) {}

    /**
     * Finds the last occurance of the given substring
     *
     * @param boolean part If set to TRUE, it returns the string from the beginning to the last occurrence of needle.
     * If set to FALSE, it returns the string from the last occurrence of needle to the end.
     * @param string $needle 
     * @param bool $part 
     * @return int 
     */
    public function rchr($needle, $part = false) {}

    /**
     * Whether the string starts with the given substring
     *
     * @param string $str 
     * @param bool $caseInsensitive 
     * @return bool 
     */
    public function startsWith($str, $caseInsensitive = false) {}

    /**
     * Whether the string ends with the given substring
     *
     * @param string $str 
     * @param bool $caseInsensitive 
     * @return bool 
     */
    public function endsWith($str, $caseInsensitive = false) {}

    /**
     * Returns the detected string encoding
     *
     * @return string 
     */
    public function detectEncoding() {}

    /**
     * Applies filter_var() to the string using the given filter type
     *
     * @param int $filterType 
     * @param int $options 
     * @return mixed 
     */
    public function filter($filterType, $options = 0) {}

    /**
     * Returns the current string value
     *
     * @return string 
     */
    public function get() {}

    /**
     * Returns the original string value
     *
     * @return string 
     */
    public function getOriginal() {}

    /**
     * Whether the value has been changed from the original value
     *
     * @return bool 
     */
    public function isChanged() {}

    /**
     * Returns the current string value
     *
     * @return string 
     */
    public function __toString() {}

    /**
     * Grabs a chunk of the string length characters in length starting at position
     *
     * @param int $position 
     * @param int $length [Optional] Character length of the chunk. Default 1.
     * @param int $pos Position to start
     * @return string 
     */
    public function chunk($position, $length = 1) {}

    /**
     * Returns the character at position (starting from 0)
     *
     * @param int $position 
     * @param int $pos 
     * @return string 
     */
    public function at($position) {}

    /**
     * Returns the first length number of characters
     *
     * @param int $length Number of characters to return. Default 1
     * @return string 
     */
    public function first($length = 1) {}

    /**
     * Returns the last length number of characters
     *
     * @param int $length Number of characters to return. Default 1
     * @return string 
     */
    public function last($length = 1) {}

    /**
     * Splits the string into an array with each chunk being length in length.
     * Unlike str_split(), this implementation will split by characters when dealing with a multi-byte string.
     *
     * @param int $chunkSize 
     * @param int $length Length of the array chunks. Default 1
     * @return array 
     */
    public function toArray($chunkSize = 1) {}

    /**
     * Split a multibyte string using regular expression pattern and returns the result as an array.
     *
     * @param string $pattern Regex pattern
     * @param int $limit [Optional] If specified, string will be split in limit elements as maximum.
     * @return array 
     */
    public function split($pattern, $limit = -1) {}

    /**
     * Returns the character at position p (alias of at())
     *
     * @param int $offset 
     * @return string 
     */
    public function offsetGet($offset) {}

    /**
     * Whether there is a character at the given offset
     *
     * @param int $offset 
     * @return bool 
     */
    public function offsetExists($offset) {}

    /**
     * Throws an exception. Strings are immutable
     *
     * @throws \RuntimeException()
     * @param int $offset 
     * @param mixed $newval 
     */
    public function offsetSet($offset, $newval) {}

    /**
     * Throws an exception. Strings are immutable
     *
     * @throws \RuntimeException()
     * @param int $offset 
     */
    public function offsetUnset($offset) {}

    /**
     * Magic property access for "length", "charset", "encoding", "first", and "last"
     *
     * @param string $variable 
     * @return string|int|mixed|null 
     */
    public function __get($variable) {}

    /**
     * Allows print(), echo(), and return() methods
     *
     * @param string $func 
     * @param array $args 
     * @return string|null 
     */
    public function __call($func, $args) {}

    /**
     * Sets a new string value
     *
     * @param string $str 
     * @param string $string 
     * @return \Xpl\StringBuffer 
     */
    public function set($str) {}

    /**
     * Sets the string encoding
     *
     * @param string $encoding 
     * @param string  
     * @return \Xpl\StringBuffer 
     */
    public function setEncoding($encoding) {}

    /**
     * Restores the string to its original value
     *
     * @return \Xpl\StringBuffer 
     */
    public function restore() {}

    /**
     * Prepends a string to the string
     *
     * @param string $str 
     * @param string $string 
     * @return \Xpl\StringBuffer 
     */
    public function prepend($str) {}

    /**
     * Appends a string to the string
     *
     * @param string $str 
     * @param string $string 
     * @return \Xpl\StringBuffer 
     */
    public function append($str) {}

    /**
     * Wraps the string between the two given
     *
     * @param string $before String to prepend
     * @param string $after String to append
     * @return \Xpl\StringBuffer 
     */
    public function wrap($before, $after) {}

    /**
     * Strips whitespace (or characters) from the beginning and end of the string
     *
     * @param string $charlist [Optional]
     * @return \Xpl\StringBuffer 
     */
    public function trim($charlist = null) {}

    /**
     * Strips whitespace (or characters) from the beginning of the string
     *
     * @param string $charlist [Optional]
     * @return \Xpl\StringBuffer 
     */
    public function ltrim($charlist = null) {}

    /**
     * Strips whitespace (or characters) from the end of the string
     *
     * @param string $charlist [Optional]
     * @return \Xpl\StringBuffer 
     */
    public function rtrim($charlist = null) {}

    /**
     * Get part of the string
     *
     * @param int $start Start position
     * @param int $length [Optional] Length of the substring
     * @return \Xpl\StringBuffer 
     */
    public function sub($start, $length = null) {}

    /**
     * @param string $needle 
     * @param bool $before_needle 
     * @return \Xpl\StringBuffer 
     */
    public function str($needle, $before_needle = false) {}

    /**
     * @param mixed $search 
     * @param mixed $replace 
     * @return \Xpl\StringBuffer 
     */
    public function replace($search, $replace) {}

    /**
     * @param mixed $search 
     * @param mixed $replace 
     * @return \Xpl\StringBuffer 
     */
    public function ireplace($search, $replace) {}

    /**
     * @param int $length 
     * @param string $str 
     * @param int $type 
     * @return \Xpl\StringBuffer 
     */
    public function pad($length, $str = " ", $type = 1) {}

    /**
     * @param int $type 
     * @param int $options 
     * @return \Xpl\StringBuffer 
     */
    public function sanitize($type = 0, $options = 0) {}

    /**
     * @param mixed $flags 
     * @param string $charset 
     * @param bool $double_encode 
     * @return \Xpl\StringBuffer 
     */
    public function entities($flags = null, $charset = "UTF-8", $double_encode = false) {}

    /**
     * @param mixed $flags 
     * @param string $charset 
     * @return \Xpl\StringBuffer 
     */
    public function entityDecode($flags = null, $charset = "UTF-8") {}

    /**
     * @param mixed $flags 
     * @param string $charset 
     * @param bool $double_encode 
     * @return \Xpl\StringBuffer 
     */
    public function specialChars($flags = null, $charset = "UTF-8", $double_encode = false) {}

    /**
     * @param mixed $flags 
     * @return \Xpl\StringBuffer 
     */
    public function specialCharsDecode($flags = null) {}

    /**
     * Converts the string to another encoding
     *
     * @param string $to_encoding The type of encoding that the string is being converted to
     * @return \Xpl\StringBuffer 
     */
    public function convertEncoding($to_encoding) {}

    /**
     * Converts the string to the given case
     *
     * @param int $mode One of CASE_LOWER, CASE_UPPER, or CASE_TITLE
     * @return \Xpl\StringBuffer 
     */
    public function convertCase($mode) {}

    /**
     * Uppercases the string
     *
     * @return \Xpl\StringBuffer 
     */
    public function upper() {}

    /**
     * Lowercases the string
     *
     * @return \Xpl\StringBuffer 
     */
    public function lower() {}

    /**
     * Applies ucwords() to the string
     *
     * @return \Xpl\StringBuffer 
     */
    public function ucwords() {}

    /**
     * Converts the first character to uppercase
     *
     * @return \Xpl\StringBuffer 
     */
    public function ucfirst() {}

    /**
     * Converts the first character to lowercase
     *
     * @return \Xpl\StringBuffer 
     */
    public function lcfirst() {}

    /**
     * Applies md5() hash to the string
     *
     * @param bool $raw_output [Optional]
     * @return \Xpl\StringBuffer 
     */
    public function md5($raw_output = false) {}

    /**
     * Applies sha1() hash to the string
     *
     * @param bool $raw_output [Optional]
     * @return \Xpl\StringBuffer 
     */
    public function sha1($raw_output = false) {}

    /**
     * Applies a given hash algorithm to the string
     *
     * @param string $algo Hash algorithm
     * @param bool $raw_output [Optional]
     * @return \Xpl\StringBuffer 
     */
    public function hash($algo, $raw_output = false) {}

    /**
     * Applies a given HMAC hash to the string
     *
     * @param string $algo Hash algorithm
     * @param string $key HMAC key
     * @param bool $raw_output [Optional]
     * @return \Xpl\StringBuffer 
     */
    public function hashHmac($algo, $key, $raw_output = false) {}

    /**
     * @return bool 
     */
    public function isAlnum() {}

    /**
     * @return bool 
     */
    public function isAlpha() {}

    /**
     * @return bool 
     */
    public function isUpper() {}

    /**
     * @return bool 
     */
    public function isLower() {}

    /**
     * @return bool 
     */
    public function isPrintable() {}

    /**
     * @return bool 
     */
    public function isControl() {}

    /**
     * @return bool 
     */
    public function isDigit() {}

    /**
     * Sets the HTML entities flags
     *
     * @param int $flags 
     */
    public static function setHtmlEntitiesFlags($flags) {}

    /**
     * Returns the HTML entities flags
     *
     * @return int 
     */
    public static function getHtmlEntitiesFlags() {}

    /**
     * Sets the error mode
     *
     * @throws \InvalidArgumentException if given an invalid error mode
     * @param int $mode One of "ERROR_*" class constants
     */
    public static function setErrorMode($mode) {}

    /**
     * Triggers an error, throws an exception, or does nothing, based on the current error mode
     *
     * @param string $message Error message
     * @return null 
     */
    public static function error($message = "An error occurred") {}

}
