namespace Xpl;

class $Object implements \Serializable
{

    /**
     * Indicates whether some other object is "equal to" this one.
     *
     * @param object
     * @return boolean
     */
    public function equals(object! obj) -> boolean
    {
        return obj === this;
    }

    /**
     * Returns a unique hash for the object.
     *
     * @return string
     */
    public function getObjectHash() -> string
    {
        return get_class(this) . "@" . sha1(serialize(this));
    }

    /**
     * Returns a new instance of the given object.
     *
     * @param object obj
     * @param mixed arg [Optional]
     * @return object
     */
    public static function valueOf(object! obj, array! ctorArgs = []) -> object
    {
        var classname;
        let classname = get_class(obj);

        if count(ctorArgs) === 0 {
            return new {classname}();
        }

        return create_instance_params(classname, ctorArgs);
    }

    /**
     * Serializes the object.
     *
     * @return string
     */
    public function serialize() -> string
    {
        return serialize(get_object_vars(this));
    }

    /**
     * Unserializes the object.
     *
     * @param string serial
     * @return void
     */
    public function unserialize(string serial) -> void
    {
        var key, value;
        for key, value in unserialize(serial) {
            let this->{key} = value;
        }
    }
    
}
