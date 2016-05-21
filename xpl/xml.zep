namespace Xpl;

use XMLWriter;

class Xml
{

	/**
	 * Returns an XML document as a string.
	 *
	 * @param array $data Document data.
	 * @param string $root_tag Root document element. Default "XML"
	 * @param string $version XML version. Default "1.0"
	 * @param string $encoding XML encoding. Default "UTF-8"
	 * @return string XML document as string
	 */
	public static function encode(
		const array! data,
		const string! root_tag = "XML",
		const string! version = "1.0",
		const string! encoding = "UTF-8"
	) -> string
	{
        var writer;
        let writer = new XMLWriter();

        writer->openMemory();

		writer->startDocument(version, encoding);
		writer->startElement(root_tag);

		self::writeElement(writer, data);

        writer->endElement();
		writer->endDocument();

		return writer->outputMemory(true);
	}

    /**
     * Decodes an XML string into an object or array.
     *
     * @param string $xml A well-formed XML string.
     * @param boolean $assoc [Optional] Decode to an associative array. Default false.
     *
     * @return object|array|null XML data decoded to object(s) or array(s).
     */
    public static function decode(string! xml, boolean assoc = false) -> object | array | null
    {
		var xmlErrors, simpleXml;

        if empty xml || ! starts_with(xml, "<?xml ") {
            return null;
        }

    	let xmlErrors = libxml_use_internal_errors(true);
		let simpleXml = simplexml_load_string(xml);
		libxml_use_internal_errors(xmlErrors);

		if simpleXml instanceof \SimpleXMLElement {
			return json_decode(json_encode(simpleXml), assoc);
		}

		return null;
    }

	/**
	 * Checks whether the given value is a valid XML string.
	 *
	 * @param string $arg Value to check if XML.
	 *
	 * @return boolean TRUE if value is a valid XML string, otherwise false.
	 */
	public static function validate(string! str) -> boolean
	{
        var xmlErrors, val;

        if empty str || ! starts_with(str, "<?xml ") {
            return false;
        }

		let xmlErrors = libxml_use_internal_errors(true);
		let val = (simplexml_load_string(str) instanceof \SimpleXMLElement) && false === libxml_get_last_error();
		libxml_use_internal_errors(xmlErrors);

		return val;
	}

	/**
	 * Writes an element.
	 *
	 * @param \XMLWriter $writer An XMLWriter instance.
	 * @param array $data Data to write to the document.
	 * @return void
	 */
	public static function writeElement(<XMLWriter> writer, array! data) -> void
	{
		var key, value, tag, attributes;

		for key, value in data {

			let key = Str::alnum(key);

			if is_numeric(key) {
				let key = "Item_" . key;
			}

			if typeof value == "object" {
				let value = Type::toArray(value);
			}

			if typeof value == "array" {

				if fetch tag, value["@tag"] {
					let key = (string)tag;
					unset value["@tag"];
				}

				writer->startElement(key);

				if fetch attributes, value["@attributes"] {
					if typeof attributes == "array" {
						var k, v;
						for k, v in array_unique(attributes) {
							writer->writeAttribute(k, v);
						}
						unset value["@attributes"];
					}
				}

				self::writeElement(writer, value);

				writer->endElement();

			} else {

				if typeof value == "null" || is_scalar(value) {

					if typeof value == "string" {
						let value = htmlentities(html_entity_decode(value), ENT_XML1|ENT_DISALLOWED);
					}

					writer->writeElement(key, value);
				}
			}
		}
	}

}
