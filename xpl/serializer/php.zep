namespace Xpl\Serializer;

class Php implements Serializer
{

    /**
     * Checks whether the serializer is available.
     *
     * @return boolean
     */
    public function isAvailable() -> boolean
    {
        return true; // serialize() is always available
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
        return serialize(data);
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
        return unserialize(serializedData);
    }

}
