
extern zend_class_entry *xpl_arrayobject_ce;

ZEPHIR_INIT_CLASS(Xpl_ArrayObject);

PHP_METHOD(Xpl_ArrayObject, __construct);
PHP_METHOD(Xpl_ArrayObject, setFlags);
PHP_METHOD(Xpl_ArrayObject, import);
PHP_METHOD(Xpl_ArrayObject, toArray);
PHP_METHOD(Xpl_ArrayObject, isEmpty);
PHP_METHOD(Xpl_ArrayObject, contains);
PHP_METHOD(Xpl_ArrayObject, indexOf);
PHP_METHOD(Xpl_ArrayObject, get);
PHP_METHOD(Xpl_ArrayObject, set);
PHP_METHOD(Xpl_ArrayObject, has);
PHP_METHOD(Xpl_ArrayObject, remove);
PHP_METHOD(Xpl_ArrayObject, keys);
PHP_METHOD(Xpl_ArrayObject, values);
PHP_METHOD(Xpl_ArrayObject, sum);
PHP_METHOD(Xpl_ArrayObject, first);
PHP_METHOD(Xpl_ArrayObject, last);
PHP_METHOD(Xpl_ArrayObject, jsonSerialize);
PHP_METHOD(Xpl_ArrayObject, walk);
PHP_METHOD(Xpl_ArrayObject, map);
PHP_METHOD(Xpl_ArrayObject, filter);
PHP_METHOD(Xpl_ArrayObject, merge);
PHP_METHOD(Xpl_ArrayObject, replace);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_arrayobject___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, input)
	ZEND_ARG_INFO(0, iterator_class)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_arrayobject_setflags, 0, 0, 1)
	ZEND_ARG_INFO(0, flags)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_arrayobject_import, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_arrayobject_contains, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_arrayobject_indexof, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_arrayobject_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_arrayobject_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_arrayobject_has, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_arrayobject_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_arrayobject_walk, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_INFO(0, userdata)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_arrayobject_map, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_arrayobject_filter, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_arrayobject_merge, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_arrayobject_replace, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_arrayobject_method_entry) {
	PHP_ME(Xpl_ArrayObject, __construct, arginfo_xpl_arrayobject___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Xpl_ArrayObject, setFlags, arginfo_xpl_arrayobject_setflags, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ArrayObject, import, arginfo_xpl_arrayobject_import, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ArrayObject, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ArrayObject, isEmpty, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ArrayObject, contains, arginfo_xpl_arrayobject_contains, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ArrayObject, indexOf, arginfo_xpl_arrayobject_indexof, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ArrayObject, get, arginfo_xpl_arrayobject_get, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ArrayObject, set, arginfo_xpl_arrayobject_set, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ArrayObject, has, arginfo_xpl_arrayobject_has, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ArrayObject, remove, arginfo_xpl_arrayobject_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ArrayObject, keys, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ArrayObject, values, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ArrayObject, sum, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ArrayObject, first, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ArrayObject, last, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ArrayObject, jsonSerialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ArrayObject, walk, arginfo_xpl_arrayobject_walk, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ArrayObject, map, arginfo_xpl_arrayobject_map, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ArrayObject, filter, arginfo_xpl_arrayobject_filter, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ArrayObject, merge, arginfo_xpl_arrayobject_merge, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ArrayObject, replace, arginfo_xpl_arrayobject_replace, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
