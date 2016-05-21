namespace Xpl\Serializer;

class Json implements Serializer
{

    /**
     * Checks whether the serializer is available.
     *
     * @return boolean
     */
    public function isAvailable() -> boolean
    {
        return function_exists("json_encode");
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
        return json_encode(data);
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
        return json_decode(serializedData);
    }

}
