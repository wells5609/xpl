namespace Xpl;

class Base64Url
{

	/**
	 * Base64 encode a string, safe for URLs.
	 *
	 * @param string $str Data to encode.
	 *
	 * @return string URL-safe base64-encoded string.
	 */
	public static function encode(string data) -> string
    {
		return str_replace(["+", "/", "="], ["-", "_"], base64_encode(data));
	}

	/**
	 * Decodes a URL-safe base64-encoded string.
	 *
	 * @param string data
	 *
	 * @return string Decoded string.
	 */
	public static function decode(string data) -> string
    {
        var replaced, mod4;

        let replaced = str_replace(
            ["-", "_", " ", "\x09", "\x0a", "\x0b", "\x0c", "\x0d"],
            ["+", "/"],
            data
		);

        let mod4 = strlen(replaced) % 4;

        if mod4 {
        	let replaced .= substr("====", mod4);
		}

        return base64_decode(replaced);
	}

}
