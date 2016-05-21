namespace Xpl;

use RuntimeException;
use InvalidArgumentException;

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
	private value;

	/**
	 * The original string value
	 *
	 * @var string
	 */
	private original;

	/**
	 * The string's encoding
	 *
	 * @var string
	 */
	private encoding;

	/**
	 * HTML entities flags
	 *
	 * @var int
	 */
	private static htmlEntFlags = 2; // ENT_COMPAT

	/**
	 * Error mode. One of "ERROR_*" class constants
	 *
	 * @var int
	 */
	private static errorMode = 0; // ERROR_THROW

	/**
	 * Constructor
	 *
	 * @param string string
	 */
	public function __construct(string str, var encoding = null) -> void
	{
		let this->value = str;
		let this->original = str;

		if typeof encoding == "null" {
			let encoding = mb_detect_encoding(str);
		}

		this->setEncoding(encoding);
	}

	/**
	 * Returns the current string value
	 *
	 * @return string
	 */
	public function get() -> string
	{
		return this->value;
	}

	/**
	 * Restores the string to its original value
	 * @return \Xpl\StringBuffer
	 */
	public function restore() -> <StringBuffer>
	{
		let this->value = this->original;
		return this;
	}

	/**
	 * Returns the original string value
	 *
	 * @return string
	 */
	public function getOriginal() -> string
	{
		return this->original;
	}

	/**
	 * Whether the value has been changed from the original value
	 *
	 * @return bool
	 */
	public function isChanged() -> boolean
	{
		return this->value !== this->original;
	}

	/**
	 * Sets the string encoding
	 *
	 * @param string
	 * @return \Xpl\StringBuffer
	 */
	public function setEncoding(string encoding) -> <StringBuffer>
	{
		let this->encoding = encoding;
		return this;
	}

	/**
	 * Returns the detected string encoding
	 *
	 * @return string
	 */
	public function detectEncoding() -> string
	{
		return mb_detect_encoding(this->value);
	}

	/**
	 * Applies filter_var() to the string using the given filter type
	 *
	 * @return mixed
	 */
	public function filter(int! filterType, int! options = 0) -> string | var
	{
		return filter_var(this->value, filterType, options);
	}

	/**
	 * Returns the current string value
	 *
	 * @return string
	 */
	public function __toString() -> string
	{
		return (string)this->value;
	}

	/**
	 * Magic property access for "length", "encoding", "charset", "first", and "last"
	 */
	public function __get(string! variable) -> string | int | var | null
	{
		switch variable->lower() {
			case "length":
				return this->length();
			case "encoding":
				return this->encoding;
			case "charset":
				return mb_preferred_mime_name(this->encoding);
			case "first":
				return this->first();
			case "last":
				return this->last();
		}

		return null;
	}

	/**
	 * Allows print() and echo() as methods
	 */
	public function __call(string! func, array! args)
	{
		let func = func->lower();

		if func === "print" || func === "echo" {
			echo this->value;
		}
	}

	/**
	 * Returns the string length
	 *
	 * @return int
	 */
	public function length() -> int
	{
		return mb_strlen(this->value, this->encoding);
	}

	/**
	 * Alias of StringBuffer::length()
	 */
	public function len() -> int
	{
		return this->length();
	}

	/**
	 * Finds the position of the first occurance of the given substring
	 *
	 * @return int
	 */
	public function pos(string! needle, int offset = 0) -> int | boolean
	{
		return mb_strpos(this->value, needle, offset, this->encoding);
	}

	/**
	 * Finds the position of the last occurance of the given substring
	 *
	 * @return int
	 */
	public function rpos(string! needle, int offset = 0) -> int | boolean
	{
		return mb_strrpos(this->value, needle, offset, this->encoding);
	}

	/**
	 * Finds the position of the first occurance of the given substring case insensitively
	 *
	 * @return int
	 */
	public function ipos(string! needle, int offset = 0) -> int | boolean
	{
		return mb_stripos(this->value, needle, offset, this->encoding);
	}

	/**
	 * Finds the position of the last occurance of the given substring case insensitively
	 *
	 * @return int
	 */
	public function ripos(string! needle, int offset = 0) -> int | boolean
	{
		return mb_strripos(this->value, needle, offset, this->encoding);
	}

	/**
	 * Finds the last occurance of the given substring
	 *
	 * @param string needle
	 * @param boolean part If set to TRUE, it returns the string from the beginning to the last occurrence of needle.
	 * If set to FALSE, it returns the string from the last occurrence of needle to the end.
	 * @return int
	 */
	public function rchr(string! needle, boolean part = false) -> int
	{
		return mb_strrchr(this->value, needle, part, this->encoding);
	}

	/**
	 * Whether the string starts with the given substring
	 *
	 * @return bool
	 */
	public function startsWith(string str, boolean caseInsensitive = false) -> boolean
	{
		return starts_with(this->value, str, caseInsensitive);
	}

	/**
	 * Whether the string ends with the given substring
	 *
	 * @return bool
	 */
	public function endsWith(string str, boolean caseInsensitive = false) -> boolean
	{
		return ends_with(this->value, str, caseInsensitive);
	}

	/**
	 * Grabs a chunk of the string length characters in length starting at position
	 *
	 * @param int pos Position to start
	 * @param int length [Optional] Character length of the chunk. Default 1.
	 */
	public function chunk(int position, int length = 1) -> string
	{
		return mb_substr(this->value, position, length, this->encoding);
	}

	/**
	 * Returns the character at position (starting from 0)
	 *
	 * @param int pos
	 * @return string
	 */
	public function at(int position) -> string
	{
		return mb_substr(this->value, position, 1, this->encoding);
	}

	/**
	 * Returns the first length number of characters
	 *
	 * @param int length Number of characters to return. Default 1
	 * @return string
	 */
	public function first(int length = 1) -> string
	{
		return mb_substr(this->value, 0, length, this->encoding);
	}

	/**
	 * Returns the last length number of characters
	 *
	 * @param int length Number of characters to return. Default 1
	 * @return string
	 */
	public function last(int! length = 1) -> string
	{
		return mb_substr(this->value, -abs(length), null, this->encoding);
	}

	/**
	 * Splits the string into an array with each chunk being length in length.
	 *
	 * Unlike str_split(), this implementation will split by characters when dealing with a multi-byte string.
	 *
	 * @param int length Length of the array chunks. Default 1
	 *
	 * @return array
	 */
	public function toArray(int! chunkSize = 1) -> array
	{
        var fullString, encoding, character;
		array chars = [];
		int length, i = 0;

		let fullString = this->value;
		let encoding = this->encoding;
        let length = (int)mb_strlen(fullString, encoding);

    	while i < length {
			let character = mb_substr(fullString, i, chunkSize, encoding);
			let chars[] = character;
			let i += chunkSize;
		}

		return chars;
	}

	/**
	 * Split a multibyte string using regular expression pattern and returns the result as an array.
	 *
	 * @param string pattern Regex pattern
	 * @param int limit [Optional] If specified, string will be split in limit elements as maximum.
	 *
	 * @return array
	 */
	public function split(string! pattern, int limit = -1) -> array
	{
		return mb_split(pattern, this->value, limit);
	}

	/**
	 * Returns the character at position p (alias of at())
	 *
	 * @param int offset
	 * @return string
	 */
	public function offsetGet(int offset) {
		return this->at(offset);
	}

	/**
	 * Whether there is a character at the given offset
	 *
	 * @param int offset
	 * @return bool
	 */
	public function offsetExists(int offset) -> boolean
	{
		return offset <= this->length();
	}

	/**
	 * Throws an exception. Strings are immutable
	 *
	 * @throws \RuntimeException()
	 */
	public function offsetSet(int offset, var newval) -> void
	{
		throw new RuntimeException("Cannot set character using ArrayAccess");
	}

	/**
	 * Throws an exception. Strings are immutable
	 *
	 * @throws \RuntimeException()
	 */
	public function offsetUnset(int offset) -> void
	{
		throw new RuntimeException("Cannot unset character using ArrayAccess");
	}

	/**
	 * Prepends a string to the string
	 *
	 * @param string string
	 * @return \Xpl\StringBuffer
	 */
	public function prepend(string str) -> <StringBuffer>
	{
		let this->value = str . this->value;
		return this;
	}

	/**
	 * Appends a string to the string
	 *
	 * @param string string
	 * @return \Xpl\StringBuffer
	 */
	public function append(string str) -> <StringBuffer>
	{
		let this->value .= str;
		return this;
	}

	/**
	 * Wraps the string between the two given
	 *
	 * @param string before String to prepend
	 * @param string after String to append
	 * @return \Xpl\StringBuffer
	 */
	public function wrap(string before, string after) -> <StringBuffer>
	{
		let this->value = before . this->value . after;
		return this;
	}

	/**
	 * Strips whitespace (or characters) from the beginning and end of the string
	 *
	 * @param string charlist [Optional]
	 * @return \Xpl\StringBuffer
	 */
	public function trim(var charlist = null) -> <StringBuffer>
	{
		let this->value = (typeof charlist == "string") ? trim(this->value, charlist) : trim(this->value);
		return this;
	}

	/**
	 * Strips whitespace (or characters) from the beginning of the string
	 *
	 * @param string charlist [Optional]
	 * @return \Xpl\StringBuffer
	 */
	public function ltrim(var charlist = null) -> <StringBuffer>
	{
		let this->value = (typeof charlist == "string") ? ltrim(this->value, charlist) : ltrim(this->value);
		return this;
	}

	/**
	 * Strips whitespace (or characters) from the end of the string
	 *
	 * @param string charlist [Optional]
	 * @return \Xpl\StringBuffer
	 */
	public function rtrim(var charlist = null) -> <StringBuffer>
	{
		let this->value = (typeof charlist == "string") ? rtrim(this->value, charlist) : rtrim(this->value);
		return this;
	}

	/**
	 * Get part of the string
	 *
	 * @param int start Start position
	 * @param int length [Optional] Length of the substring
	 * @return \Xpl\StringBuffer
	 */
	public function sub(int start, var length = null) -> <StringBuffer>
	{
		let this->value = mb_substr(this->value, start, length, this->encoding);
		return this;
	}

	/**
	 * @return \Xpl\StringBuffer
	 */
	public function str(string needle, boolean before_needle = false) -> <StringBuffer>
	{
		let this->value = mb_strstr(this->value, needle, before_needle, this->encoding);
		return this;
	}

	/**
	 * @return \Xpl\StringBuffer
	 */
	public function replace(var search, var replace) -> <StringBuffer>
	{
		let this->value = str_replace(search, replace, this->value);
		return this;
	}

	/**
	 * @return \Xpl\StringBuffer
	 */
	public function ireplace(var search, var replace) -> <StringBuffer>
	{
		let this->value = str_ireplace(search, replace, this->value);
		return this;
	}

	/**
	 * @return \Xpl\StringBuffer
	 */
	public function pad(int length, string str = " ", int type = 1) -> <StringBuffer>
	{
		let this->value = str_pad(this->value, length, str, type);
		return this;
	}

	/**
	 * @return \Xpl\StringBuffer
	 */
	public function sanitize(int type = 0, int options = 0) -> <StringBuffer>
	{
        if type === 0 {
            let type = FILTER_SANITIZE_STRING;
        }

		let this->value = this->filter(type, options);

        return this;
	}

	/**
	 * @return \Xpl\StringBuffer
	 */
	public function entities(var flags = null, string charset = "UTF-8", boolean double_encode = false) -> <StringBuffer>
	{
		if typeof flags == "null" {
			let flags = self::htmlEntFlags;
		}

		let this->value = htmlentities(this->value, flags, charset, double_encode);

		return this;
	}

	/**
	 * @return \Xpl\StringBuffer
	 */
	public function entityDecode(var flags = null, string charset = "UTF-8") -> <StringBuffer>
	{
		if typeof flags == "null" {
			let flags = self::htmlEntFlags;
		}

		let this->value = html_entity_decode(this->value, flags, charset);

		return this;
	}

	/**
	 * @return \Xpl\StringBuffer
	 */
	public function specialChars(var flags = null, string charset = "UTF-8", boolean double_encode = false) -> <StringBuffer>
	{
		if typeof flags == "null" {
			let flags = self::htmlEntFlags;
		}

		let this->value = htmlspecialchars(this->value, flags, charset, double_encode);

		return this;
	}

	/**
	 * @return \Xpl\StringBuffer
	 */
	public function specialCharsDecode(var flags = null) -> <StringBuffer>
	{
		if typeof flags == "null" {
			let flags = self::htmlEntFlags;
		}

		let this->value = htmlspecialchars_decode(this->value, flags);

		return this;
	}

	/**
	 * Converts the string to another encoding
	 *
	 * @param string to_encoding The type of encoding that the string is being converted to
	 * @return \Xpl\StringBuffer
	 */
	public function convertEncoding(string to_encoding) -> <StringBuffer>
	{
		let this->value = mb_convert_encoding(this->value, to_encoding, this->encoding);
		let this->encoding = mb_detect_encoding(this->value);
		return this;
	}

	/**
	 * Converts the string to the given case
	 *
	 * @param int mode One of CASE_LOWER, CASE_UPPER, or CASE_TITLE
	 * @return \Xpl\StringBuffer
	 */
	public function convertCase(int mode) -> <StringBuffer>
	{
		let this->value = mb_convert_case(this->value, mode, this->encoding);
		return this;
	}

	/**
	 * Uppercases the string
	 *
	 * @return \Xpl\StringBuffer
	 */
	public function upper() -> <StringBuffer>
	{
		let this->value = mb_strtoupper(this->value, this->encoding);
		return this;
	}

	/**
	 * Lowercases the string
	 *
	 * @return \Xpl\StringBuffer
	 */
	public function lower() -> <StringBuffer>
	{
		let this->value = mb_strtolower(this->value, this->encoding);
		return this;
	}

	/**
	 * Applies ucwords() to the string
	 *
	 * @return \Xpl\StringBuffer
	 */
	public function ucwords() -> <StringBuffer>
	{
		let this->value = ucwords(this->value);
		return this;
	}

	/**
	 * Converts the first character to uppercase
	 *
	 * @return \Xpl\StringBuffer
	 */
	public function ucfirst() -> <StringBuffer>
	{
		var encoding;
		let encoding = this->encoding;

		let this->value = mb_strtoupper(this->first(), encoding) . mb_substr(this->value, 1, null, encoding);

		return this;
	}

	/**
	 * Converts the first character to lowercase
	 *
	 * @return \Xpl\StringBuffer
	 */
	public function lcfirst() -> <StringBuffer>
	{
		var encoding;
		let encoding = this->encoding;

		let this->value = mb_strtolower(this->first(), encoding) . mb_substr(this->value, 1, null, encoding);

		return this;
	}

	/**
	 * Applies md5() hash to the string
	 *
	 * @param bool raw_output [Optional]
	 * @return \Xpl\StringBuffer
	 */
	public function md5(boolean raw_output = false) -> <StringBuffer>
	{
		let this->value = md5(this->value, raw_output);
		return this;
	}

	/**
	 * Applies sha1() hash to the string
	 *
	 * @param bool raw_output [Optional]
	 * @return \Xpl\StringBuffer
	 */
	public function sha1(boolean raw_output = false) -> <StringBuffer>
	{
		let this->value = sha1(this->value, raw_output);
		return this;
	}

	/**
	 * Applies a given hash algorithm to the string
	 *
	 * @param string algo Hash algorithm
	 * @param bool raw_output [Optional]
	 * @return \Xpl\StringBuffer
	 */
	public function hash(string! algo, boolean raw_output = false) -> <StringBuffer>
	{
		let this->value = hash(algo, this->value, raw_output);
		return this;
	}

	/**
	 * Applies a given HMAC hash to the string
	 *
	 * @param string algo Hash algorithm
	 * @param string key HMAC key
	 * @param bool raw_output [Optional]
	 * @return \Xpl\StringBuffer
	 */
	public function hashHmac(string! algo, string key, boolean raw_output = false) -> <StringBuffer>
	{
		let this->value = hash_hmac(algo, this->value, key, raw_output);
		return this;
	}

	/**
	 * @return bool
	 */
	public function isAlnum() -> boolean
	{
		return ctype_alnum(this->value);
	}

	/**
	 * @return bool
	 */
	public function isAlpha() -> boolean
	{
		return ctype_alpha(this->value);
	}

	/**
	 * @return bool
	 */
	public function isUpper() -> boolean
	{
		return ctype_upper(this->value);
	}

	/**
	 * @return bool
	 */
	public function isLower() -> boolean
	{
		return ctype_lower(this->value);
	}

	/**
	 * @return bool
	 */
	public function isPrintable() -> boolean
	{
		return ctype_print(this->value);
	}

	/**
	 * @return bool
	 */
	public function isControl() -> boolean
	{
		return ctype_cntrl(this->value);
	}

	/**
	 * @return bool
	 */
	public function isDigit() -> boolean
	{
		return ctype_digit(this->value);
	}

	/**
	 * Whether the given string contains any of the characters in $charlist
	 *
	 * @param string charList
	 *
	 * @return boolean True if the string contains any of the characters in charList, otherwise false
	 */
	public function containsChars(string! charList) -> boolean
	{
		return strcspn(this->value, charList) !== this->length();
	}

	/**
	 * Sets the HTML entities flags
	 *
	 * @param int flags
	 */
	public static function setHtmlEntitiesFlags(int flags) -> void
	{
		let self::htmlEntFlags = flags;
	}

	/**
	 * Returns the HTML entities flags
	 *
	 * @return int
	 */
	public static function getHtmlEntitiesFlags() -> int
	{
		return self::htmlEntFlags;
	}

	/**
	 * Sets the error mode
	 *
	 * @param int mode One of "ERROR_*" class constants
	 *
	 * @throws \InvalidArgumentException if given an invalid error mode
	 */
	public static function setErrorMode(int mode) -> void
	{
		if ! in_array(mode, [self::ERROR_IGNORE, self::ERROR_THROW, self::ERROR_TRIGGER], true) {
			throw new InvalidArgumentException("Invalid error mode: " . mode . ".");
		}

		let self::errorMode = mode;
	}

	/**
	 * Triggers an error, throws an exception, or does nothing, based on the current error mode.
	 *
	 * @param string message Error message
	 *
	 * @throws \RuntimeException if mode is ERROR_THROW
	 *
	 * @return null
	 */
	public static function error(string message = "An error occurred") -> null
	{
		switch self::errorMode {
			case self::ERROR_IGNORE:
				break;
			case self::ERROR_TRIGGER:
				trigger_error(message, E_USER_WARNING);
				break;
			case self::ERROR_THROW:
			default:
				throw new RuntimeException(message);
		}

		return null;
	}

}
