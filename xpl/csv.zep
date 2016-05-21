namespace Xpl;

use InvalidArgumentException;

class Csv
{

    public static delimiter = ",";
    public static enclosure = "\"";
    public static escape_char = "\\";

    public static function encode(array! data, array headers = null) -> string
    {
        var handle, row, delimiter, enclosure, escape, contents;

        let handle = fopen("php://temp", "w+b");

        let delimiter = self::delimiter,
            enclosure = self::enclosure,
            escape = self::escape_char;

        for row in data {
            fputcsv(handle, Type::toArray(row), delimiter, enclosure, escape);
        }

        rewind(handle);
        let contents = stream_get_contents(handle);
        fclose(handle);

        return contents;
    }

    /**
     * Returns an array or object of items from a CSV string.
     *
     * The string is written to a temporary stream so that fgetcsv() can be used.
     * This has the nice (side) effect of avoiding str_getcsv(), which is less
     * forgiving in its treatment of escape characters and delimeters.
     *
     * @param string $csv CSV string.
     * @param boolean $assoc [Optional] Return as associative arrays instead of objects. Default false.
     * @param mixed $headers [Optional] Array of headers, or boolean true if the first CSV row contains headers.
     * Headers will be used as the keys for the values in each row. Defaults to boolean true.
     * @return object|array|null
     */
    public static function decode(var csv, boolean assoc = false, var headers = true) -> object | array | null
    {
        var handle, numHeaders, line;
        boolean hasHeaders = false;
        array data = [];

        if typeof csv == "string" {

            if empty csv {
                return null;
            }

        	// Open a temporary read/write stream using 2 MB of memory
        	let handle = fopen("php://temp/maxmemory=2097152", "w+b");

        	// Write the string to the temporary stream and rewind
        	fwrite(handle, csv);
        	rewind(handle);

        } else {

            if typeof csv != "resource" {
                throw new InvalidArgumentException("Expecting CSV string or resource, given: " . gettype(csv));
            }

            let handle = csv;
        }

        if typeof headers == "array" {
            let hasHeaders = count(headers) > 0;
        } else {
            if typeof headers != "boolean" {
                throw new InvalidArgumentException("Expecting headers to be array or bool, given: " . gettype(headers));
            }
            let hasHeaders = headers;
            let headers = fgetcsv(handle);
        }

    	if hasHeaders === true {
            let numHeaders = count(headers);
        }

    	while ! feof(handle) {

            let line = fgetcsv(handle);

    		if hasHeaders === true {
    			// Pad row with empty strings in case end column(s) are blank
    			let line = array_combine(headers, array_pad(line, numHeaders, ""));
    		}

            if assoc === true {
                let data[] = line;
            } else {
                let data[] = (object)line;
            }
        }

    	fclose(handle);

    	return assoc ? data : (object)data;
    }

}
