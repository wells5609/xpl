namespace Xpl;

use RuntimeException;

class Json
{

    /**
     * JSON-encodes data.
     *
     * @param mixed data
     * @param int options [Optional]
     * @return string
     */
    public static function encode(var data, int options = 0) -> string
    {
        return json_encode(data, options);
    }

    /**
     * Decodes a JSON-encoded string into an object or array
     *
     * @param string $json A well-formed JSON string.
     * @param boolean $assoc [Optional] Whether to decode to an associative array. Default false.
     * @param int $depth [Optional] Depth to decode to. Default 512
     * @param int $flags [Optional] Bitwise flags for use in json_decode(). Default is 0
     * @return object|array|null JSON data decoded to object(s) or array(s).
     */
    public static function decode(
        string! json,
        boolean assoc = false,
        int depth = 512,
        int flags = 0
    ) -> object | array | null
    {
        if empty json {
            return null;
        }

        return json_decode(json, assoc, depth, flags);
    }

    /**
     * Reads and decodes a JSON-encoded file into an object or array
     *
     * @param string $file A readable JSON file.
     * @param boolean $assoc [Optional] Whether to decode to an associative array. Default false.
     * @param int $depth [Optional] Depth to decode to. Default 512
     * @param int $flags [Optional] Bitwise flags for use in json_decode(). Default is 0
     * @return object|array|null JSON data decoded to object(s) or array(s).
     */
    public static function decodeFile(
        string! file,
        boolean assoc = false,
        int depth = 512,
        int flags = 0
    ) -> object | array | null
    {
        var json;

        if ! file_exists(file) {
            throw new RuntimeException("Unreadable file: " . file);
        }

        let json = file_get_contents(file);

        return self::decode(json, assoc, depth, flags);
    }

	/**
	 * Returns whether the given variable is a valid JSON string.
	 *
	 * @param string
	 * @return boolean
	 */
	public static function validate(string str) -> boolean
	{
		if empty str {
			return false;
		}

		if str === "{}" || str === "[]" {
			return true;
		}

		json_decode(str);

		return json_last_error() === JSON_ERROR_NONE;
	}

}
