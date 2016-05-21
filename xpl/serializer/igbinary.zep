namespace Xpl\Serializer;

class Igbinary implements Serializer
{

    /**
     * Checks whether the serializer is available.
     *
     * @return boolean
     */
    public function isAvailable() -> boolean
    {
        return function_exists("igbinary_serialize");
    }

    /**
     * Serializes the given data.
     *
     * @param mixed data
     *
     * @return string
     */
    public function serialize(var data) -> string
    {
        return igbinary_serialize(data);
    }

    /**
     * Unserializes a value from a serialized string.
     *
     * @param string serializedData
     *
     * @return mixed
     */
    public function unserialize(string! serializedData) -> var | null
    {
        return igbinary_unserialize(serializedData);
    }

}
