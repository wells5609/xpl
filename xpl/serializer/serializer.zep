namespace Xpl\Serializer;

interface Serializer
{

    /**
     * Checks whether the serializer is available.
     *
     * @return boolean
     */
    public function isAvailable() -> boolean;

    /**
     * Serializes the given data.
     *
     * @param mixed data
     *
     * @return string
     */
    public function serialize(var data) -> string;

    /**
     * Unserializes a value from a serialized string.
     *
     * @param string serializedData
     *
     * @return mixed
     */
    public function unserialize(string! serializedData) -> var | null;

}
