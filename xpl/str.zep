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
	public static lastError;

    public static function ukey(var obj, var params, var extra = null) -> string | var
    {
        return unique_key(obj, params);
    }

    /**
     * Camelizes an underscored string to camelcase.
     *
     * @param string str
     * @return string
     */
    public static function camelize(string str) -> string
    {
        return camelize(str);
    }

    /**
     * Uncamelizes a camelcase string to underscored.
     *
     * @param string str
     * @return string
     */
    public static function uncamelize(string str) -> string
    {
        return uncamelize(str);
    }

    /**
     * Returns true if $haystack starts with $needle.
     *
     * @param string $haystack String to search within.
     * @param string $needle String to find.
     * @param boolean $case_insensitive Whether to check case-insensitive. Default true.
     * @return boolean
     */
    public static function startsWith(string haystack, string needle, boolean case_insensitive = true) -> boolean
	{
    	return starts_with(haystack, needle, case_insensitive);
    }

    /**
     * Returns true if $haystack ends with $needle.
     *
     * @param string $haystack String to search within.
     * @param string $needle String to find.
     * @param boolean $case_insensitive Whether to check case-insensitive. Default true.
     * @return boolean
     */
    public static function endsWith(string haystack, string needle, boolean case_insensitive = true) -> boolean
	{
    	return ends_with(haystack, needle, case_insensitive);
    }

	/**
	 * Whether the given string contains any of the characters in $charlist
	 *
	 * @param string str
	 * @param string charlist
	 * @return boolean True if str contains any of the characters in charlist, otherwise false
	 */
	public static function hasChars(string str, string charlist) -> boolean
	{
		return strcspn(str, charlist) !== strlen(str);
	}

	/**
	 * Converts a string to a PEAR-like class name. (e.g. "Http_Request2_Response")
	 *
	 * @param string
	 * @return string
	 */
	public static function pearCase(string str) -> string
	{
		var pearStr;

		let pearStr = preg_replace("/[^a-zA-Z0-9]/", " ", trim(preg_replace("/[A-Z]/", " $0", str)));
		let pearStr = preg_replace("/[_]{2,}/", "_", str_replace(" ", "_", ucwords(pearStr)));

		return pearStr;
	}

	/**
	 * Converts a string to "snake_case"
	 *
	 * @param string
	 * @return string
	 */
	public static function snakeCase(string str) -> string
	{
		return strtolower(self::pearCase(str));
	}

	/**
	 * Converts a string to "StudlyCaps"
	 *
	 * @param string
	 * @return string
	 */
	public static function studlyCase(string str) -> string
	{
		return str_replace(" ", "", ucwords(trim(preg_replace("/[^a-zA-Z0-9]/", " ", str))));
	}

	/**
	 * Converts a string to "camelCase"
	 *
	 * @param string
	 * @return string
	 */
	public static function camelCase(string str) -> string
	{
		return lcfirst(self::studlyCase(str));
	}

	/**
	 * Sanitizes a string to contain only ASCII characters
	 *
	 * @param string $str
	 * @return string
	 */
	public static function ascii(string str) -> string
	{
		return filter_var(
			preg_replace("/[\\x01-\\x08\\x0B-\\x1F]/", "", html_entity_decode(str, ENT_QUOTES, "UTF-8")),
			FILTER_SANITIZE_STRING,
			FILTER_FLAG_STRIP_HIGH | FILTER_FLAG_STRIP_BACKTICK
		);
	}

	/**
	 * Strips non-alphabetic characters from a string.
	 *
	 * @param string
	 * @return string
	 */
	public static function alpha(string str) -> string
	{
		return ctype_alpha(str) ? str : preg_replace("/[^a-zA-Z]/", "", str);
	}

	/**
	 * Strips non-alphanumeric characters from a string.
	 *
	 * @param string
	 * @return string
	 */
	public static function alnum(string str) -> string
	{
		return ctype_alnum(str) ? str : preg_replace("/[^a-zA-Z0-9]/", "", str);
	}

	/**
	 * Strips invalid unicode from a string.
	 *
	 * @param string
	 * @return string
	 */
	public static function unicode(string str) -> string
	{
		if function_exists("mb_convert_encoding") {

			var encoding;
			let encoding = mb_detect_encoding(str);

			if encoding !== "ASCII" {

				var substituteCharacter;
				let substituteCharacter = ini_set("mbstring.substitute_character", "none");

				let str = mb_convert_encoding(str, "UTF-8", "UTF-8");

				ini_set("mbstring.substitute_character", substituteCharacter);
			}
		}

		return stripcslashes(preg_replace("/\\\\u([0-9a-f]{4})/i", "", str));
	}

	/**
	 * Sanitizes a string to a "slug" format: lowercase alphanumeric string with given separator.
	 *
	 * @param string $string Dirty string.
	 * @param string $separator [Optional] Character used to replace non-alphanumeric characters. Default "-".
	 * @return string Slugified string.
	 */
	public static function slug(string str, string separator = "-") -> string
	{
		var slug;

		let slug = preg_replace("#[\"\\'\\’\\x01-\\x08\\x0B-\\x1F]#", "", self::ascii(str));
		let slug = preg_replace("#[/_|+ -]+#u", separator, preg_replace("#[^a-z0-9]#i", separator, slug));

		return strtolower(trim(slug, separator));
	}

	/**
	 * Removes single and double quotes from a string.
	 *
	 * @param string
	 * @return string
	 */
	public static function stripQuotes(string str) -> string
	{
		return preg_replace("/[\"\\'\\’]/", "", str);
	}

	/**
	 * Removes non-printing ASCII control characters from a string.
	 *
	 * @param string
	 * @return string
	 */
	public static function stripControl(string str) -> string
	{
		return preg_replace("/[\\x01-\\x08\\x0B-\\x1F]/", "", str);
	}

	/**
	 * Escapes text for SQL LIKE special characters % and _.
	 *
	 * @param string $text The text to be escaped.
	 * @return string text, safe for inclusion in LIKE query.
	 */
	public static function filterSqlLike(string str) -> string
	{
		return str_replace(["%", "_"], ["\\\\%", "\\\\_"], str);
	}

	/**
	 * Sanitizes a URL, decoding using rawurldecode() and filter_var().
	 *
	 * @param string url URL, possibly containing encoded characters
	 * @param int flags [Optional] Optional filter_var() flags
	 * @return string Sanitized URL with "%##" characters translated
	 */
	public static function filterUrl(string url, int flags = 0) -> string
	{
		return filter_var(rawurldecode(url), FILTER_SANITIZE_URL, flags);
	}

	/**
	 * Returns whether the given variable is a valid JSON string.
	 *
	 * @param string
	 * @return boolean
	 */
	public static function isJson(string str) -> boolean
	{
        return Json::validate(str);
	}

	/**
	 * Checks whether the given value is a valid XML string.
	 *
	 * @param string $arg Value to check if XML.
	 * @return boolean TRUE if value is a valid XML string, otherwise false.
	 */
	public static function isXml(string str) -> boolean
	{
        return Xml::validate(str);
	}

	/**
	 * Checks whether the given value is a valid serialized string.
	 *
	 * @param string $data Value to check if serialized
	 * @return boolean TRUE If value is a valid serialized string, otherwise false.
	 */
	public static function isSerialized(string str) -> boolean
	{
		if str === "" {
			return false;
		}

		if str === "N;" {
			return true;
		}

		// Reset last error
		let self::lastError = null;

		set_error_handler("Xpl\\Str::handleError");
		unserialize(str);
		restore_error_handler();

		if typeof self::lastError == "null" {
			// No error occurred, so string is serial
			return true;
		}

		return false;
	}

	/**
	 * Formats a string by injecting non-numeric characters into
	 * the string in the positions they appear in the template.
	 *
	 * @param string $string The string to format
	 * @param string $template String format to apply
	 * @return string Formatted string.
	 */
	public static function format(string str, string template) -> string
	{
		string result = "";
		int fpos = 0, spos = 0;
		var chr, len;

        let len = strlen(template) - 1;

		while len >= fpos {

			let chr = substr(template, fpos, 1);

			if ! ctype_alnum(chr) {
				let result .= chr;
			} else {
				let result .= substr(str, spos, 1);
				let spos++;
			}

			let fpos++;
		}

		return result;
	}

    /**
     * Returns 1st occurance of text between two strings.
     *
     * The "between" strings are not included in output.
     *
     * @param string $string The string in which to search.
     * @param string $substr_start The starting string.
     * @param string $substr_end The ending string.
     * @return string Text between $start and $end.
     */
    public static function between(string! str, string! substr_start, string! substr_end) -> string|null
    {
        var str1, substr1, str2;

    	let str1 = explode(substr_start, str);

        if !fetch substr1, str1[1] {
            return null;
        }

    	let str2 = explode(substr_end, substr1);

        return trim(str2[0]);
    }

    /**
     * Get a given number of sentences from a string.
     *
     * @param string $text The full string of sentences.
     * @param int $num Number of sentences to return. Default 1.
     * @param boolean|array $strip_abbr Whether to strip abbreviations (they break the function).
     * Pass an array to account for those abbreviations as well.
     * @return string Given number of sentences.
     */
    public static function sentences(string str, int num = 1, var strip_abbr = false) -> string|null
    {
    	var replacements, strip, replace_keys, replace_vals, matches;

        let replace_keys = [], replace_vals = [], matches = [];
    	let str = strip_tags(str);

    	if strip_abbr {

            // brackets are for uniqueness - if we just removed the
    		// dots, then "Mr" would match "Mrs" when we reconvert.
    		let replacements = [
    			"Dr.": "<Dr>",
    			"Mrs.": "<Mrs>",
    			"Mr.": "<Mr>",
    			"Ms.": "<Ms>",
    			"Co.": "<Co>",
    			"Ltd.": "<Ltd>",
    			"Inc.": "<Inc>"
    		];

    		// add extra strings to strip
    		if typeof strip_abbr == "array" {
                for strip in strip_abbr {
    				let replacements[strip] = "<" . str_replace(".", "", strip) . ">";
    			}
    		}

    		// set the key/value vars and replace with placeholders
            let replace_keys = array_keys(replacements);
            let replace_vals = array_values(replacements);

    		let str = str_replace(replace_keys, replace_vals, str);
    	}

    	// get num number of sentences delimited by ".", "!", or "?"
    	if ! preg_match("/^([^.!?]*[\\.!?]+){0," . num . "}/", str, matches) {
            return null;
        }

        // replace the placeholders with originals
        return strip_abbr ? str_replace(replace_vals, replace_keys, matches[0]) : matches[0];
    }

    /**
     * Class error handler
     *
     * @param int errorNum
     * @param string errorMsg
     */
	public static function handleError(int errorNum, string errorMsg) -> void
	{
		let self::lastError = errorNum . ": " . errorMsg;
	}

}
