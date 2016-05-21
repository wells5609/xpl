
extern zend_class_entry *xpl_collection_map_ce;

ZEPHIR_INIT_CLASS(Xpl_Collection_Map);

PHP_METHOD(Xpl_Collection_Map, __construct);
PHP_METHOD(Xpl_Collection_Map, addAll);
PHP_METHOD(Xpl_Collection_Map, get);
PHP_METHOD(Xpl_Collection_Map, set);
PHP_METHOD(Xpl_Collection_Map, has);
PHP_METHOD(Xpl_Collection_Map, remove);
PHP_METHOD(Xpl_Collection_Map, indexOf);
PHP_METHOD(Xpl_Collection_Map, keys);
PHP_METHOD(Xpl_Collection_Map, values);
PHP_METHOD(Xpl_Collection_Map, walk);
PHP_METHOD(Xpl_Collection_Map, map);
PHP_METHOD(Xpl_Collection_Map, filter);
PHP_METHOD(Xpl_Collection_Map, merge);
PHP_METHOD(Xpl_Collection_Map, replace);
PHP_METHOD(Xpl_Collection_Map, getIterator);
PHP_METHOD(Xpl_Collection_Map, offsetGet);
PHP_METHOD(Xpl_Collection_Map, offsetSet);
PHP_METHOD(Xpl_Collection_Map, offsetExists);
PHP_METHOD(Xpl_Collection_Map, offsetUnset);
PHP_METHOD(Xpl_Collection_Map, jsonSerialize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_map___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_map_addall, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_map_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_map_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_map_has, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_map_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_map_indexof, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_map_walk, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_INFO(0, userdata)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_map_map, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_map_filter, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_map_merge, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_map_replace, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_map_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_map_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, newval)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_map_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_map_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_collection_map_method_entry) {
	PHP_ME(Xpl_Collection_Map, __construct, arginfo_xpl_collection_map___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Xpl_Collection_Map, addAll, arginfo_xpl_collection_map_addall, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Map, get, arginfo_xpl_collection_map_get, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Map, set, arginfo_xpl_collection_map_set, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Map, has, arginfo_xpl_collection_map_has, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Map, remove, arginfo_xpl_collection_map_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Map, indexOf, arginfo_xpl_collection_map_indexof, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Map, keys, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Map, values, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Map, walk, arginfo_xpl_collection_map_walk, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Map, map, arginfo_xpl_collection_map_map, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Map, filter, arginfo_xpl_collection_map_filter, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Map, merge, arginfo_xpl_collection_map_merge, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Map, replace, arginfo_xpl_collection_map_replace, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Map, getIterator, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Map, offsetGet, arginfo_xpl_collection_map_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Map, offsetSet, arginfo_xpl_collection_map_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Map, offsetExists, arginfo_xpl_collection_map_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Map, offsetUnset, arginfo_xpl_collection_map_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Map, jsonSerialize, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
