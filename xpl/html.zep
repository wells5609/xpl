namespace Xpl;

use InvalidArgumentException;

class Html
{

	/**
	 * Whether to use HTML5
	 * @var boolean
	 */
	public static html5 = true;

	/**
	 * Self-closing tags.
	 * @var array
	 */
	protected static selfClosingTags;

	/**
	 * Create an HTML element string.
	 *
	 * @param string $tag Element tag.
	 * @param mixed $attributes [Optional] Element attribute array or string.
	 * @param string $content [Optional] Element content to place between opening and closing tags.
	 * @return string HTML element string.
	 */
	public static function make(string tag, var attributes = null, string content = "") -> string
    {
        string html;

        if ! ctype_alnum(tag) {
            let tag = preg_replace("/[^a-zA-Z0-9]/", "", tag);
        }

		if unlikely empty tag {
			throw new InvalidArgumentException("Invalid HTML tag");
		}

		let html = "<" . tag;

		if typeof attributes != "null" {
			let html .= self::attributeString(attributes);
		}

		if self::isSelfClosingTag(tag) {
            let html .= self::html5 ? ">" : " />\n";
		} else {
            let html .= ">" . content . "</" . tag . ">\n";
		}

		return html;
	}

	/**
	 * Creates an attribute string for an element
	 *
	 * @param string|array $attributes Attribute string or array
	 * @return string Attribute string
	 */
	public static function attributeString(var attributes) -> string
    {
        string str = "";
		var name, value;

		for name, value in self::parseAttributes(attributes) {

			if typeof value == "array" {
				let value = implode(" ", value);
			}

			let str .= " " . name . "=\"" . htmlentities(value, ENT_NOQUOTES|ENT_HTML5, "UTF-8", false) . "\"";
		}

		return str;
	}

    /**
     * Parses a string of attributes to an array
     *
     * @param string|array str Attribute string/array
     * @return array
     */
    public static function parseAttributes(var str) -> array
    {
        var arr, attr, parts, name, vals;
		array attributes = [];

    	if typeof str != "string" {
    		return str;
    	}

    	let str = trim(str);

        // check for double-quotes and a space
    	if ! memstr(str, "\" ") {
    		// only 1 attribute
    		let arr = [str];
    	} else {
    		// split at double quote followed by whitespace
    		let arr = explode("\" ", str);
    	}

    	for attr in arr {

    		// strip quotes
    		let attr = str_replace("\"", "", attr);

            // check for empty values
    		if ! memstr(attr, "=") {
    			// have attribute like "autofocus" or "selected"
    			let attributes[attr] = attr;

    		} else {

                // split name and value(s)
    			let parts = explode("=", attr, 2);
                let name = parts[0],
                    vals = parts[1];

                // whitespace = multiple attribute values
    			if memstr(vals, " ") {
    				let vals = explode(" ", vals);
    			}

                let attributes[name] = vals;
    		}
    	}

    	return attributes;
    }

	/**
	 * Applies htmlentities() to an attribute string using ENT_NOQUOTES to protect against XSS
	 *
	 * @param string $str Attribute value string
	 * @return string Escaped attribute value
	 */
	public static function escapeAttribute(string str) -> string
    {
		return htmlentities(str, ENT_NOQUOTES | ENT_HTML5, "UTF-8", false);
	}

	/**
	 * Whether the given tag is self-closing.
	 *
	 * @param string $tag Element tag.
	 * @return boolean
	 */
	public static function isSelfClosingTag(string tag) -> boolean
    {
        if typeof self::selfClosingTags == "null" {
            let self::selfClosingTags = [
        		"hr": 1,
        		"br": 1,
        		"input": 1,
        		"meta": 1,
        		"base": 1,
        		"basefont": 1,
        		"col": 1,
        		"frame": 1,
        		"link": 1,
        		"param": 1
        	];
        }

		return isset self::selfClosingTags[tag];
	}

}
