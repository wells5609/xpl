<?php

namespace Xpl\Serializer;


interface Serializer
{

    /**
     * Checks whether the serializer is available.
     *
     * @return boolean 
     */
    public function isAvailable();

    /**
     * Serializes the given data.
     *
     * @param mixed $data 
     * @return string 
     */
    public function serialize($data);

    /**
     * Unserializes a value from a serialized string.
     *
     * @param string $serializedData 
     * @return mixed 
     */
    public function unserialize($serializedData);

}
