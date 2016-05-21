namespace Xpl;

use ReflectionClass;

class ClassUtil
{
    const TYPE_CLASS = "class";
    const TYPE_INTERFACE = "interface";
    const TYPE_TRAIT = "trait";

    private static classCache = [];

    public static function createInstance(string classname, array args = null) -> object
    {
        int num;
        let num = count(args);

        if num === 0 {
            return new {classname}();
        }
        if num === 1 {
            return new {classname}(args[0]);
        }
        if num === 2 {
            return new {classname}(args[0], args[1]);
        }
        if num === 3 {
            return new {classname}(args[0], args[1], args[2], args[3]);
        }

        return create_instance_params(classname, args);
    }

    public static function newInstance(var classname, array! args = []) -> object
    {
        if empty args {
            return create_instance(classname);
        }

        return create_instance_params(classname, args);
    }

    public static function classBasename(var classname) -> string
    {
        return get_class_ns(classname);
    }

    public static function classNamespace(var classname) -> string
    {
        return get_ns_class(classname);
    }

    public static function realclass(var classname) -> string
    {
        var reflection;

        if typeof classname == "object" {
            return get_class(classname);
        }

        if ! isset self::classCache[classname] {
            let reflection = new ReflectionClass(classname);
            let self::classCache[classname] = reflection->getName();
        }

        return self::classCache[classname];
    }

    public static function classType(var obj) -> string | null
    {
        if interface_exists(obj) {
            return self::TYPE_INTERFACE;
        }

        if trait_exists(obj) {
            return self::TYPE_TRAIT;
        }

        if class_exists(obj) {
            return self::TYPE_CLASS;
        }

        return null;
    }

}
