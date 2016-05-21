
extern zend_class_entry *xpl_collection_config_ce;

ZEPHIR_INIT_CLASS(Xpl_Collection_Config);

PHP_METHOD(Xpl_Collection_Config, __construct);
PHP_METHOD(Xpl_Collection_Config, isEmpty);
PHP_METHOD(Xpl_Collection_Config, count);
PHP_METHOD(Xpl_Collection_Config, toArray);
PHP_METHOD(Xpl_Collection_Config, addAll);
PHP_METHOD(Xpl_Collection_Config, keys);
PHP_METHOD(Xpl_Collection_Config, values);
PHP_METHOD(Xpl_Collection_Config, indexOf);
PHP_METHOD(Xpl_Collection_Config, contains);
PHP_METHOD(Xpl_Collection_Config, getIterator);
PHP_METHOD(Xpl_Collection_Config, offsetGet);
PHP_METHOD(Xpl_Collection_Config, offsetSet);
PHP_METHOD(Xpl_Collection_Config, offsetExists);
PHP_METHOD(Xpl_Collection_Config, offsetUnset);
PHP_METHOD(Xpl_Collection_Config, get);
PHP_METHOD(Xpl_Collection_Config, set);
PHP_METHOD(Xpl_Collection_Config, has);
PHP_METHOD(Xpl_Collection_Config, getConfig);
PHP_METHOD(Xpl_Collection_Config, __get);
PHP_METHOD(Xpl_Collection_Config, __isset);
PHP_METHOD(Xpl_Collection_Config, __set);
PHP_METHOD(Xpl_Collection_Config, __unset);
PHP_METHOD(Xpl_Collection_Config, serialize);
PHP_METHOD(Xpl_Collection_Config, unserialize);
PHP_METHOD(Xpl_Collection_Config, __set_state);
PHP_METHOD(Xpl_Collection_Config, newStatic);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_config___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_config_addall, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_config_indexof, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_config_contains, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_config_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_config_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_config_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_config_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_config_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_config_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_config_has, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_config_getconfig, 0, 0, 1)
	ZEND_ARG_INFO(0, component)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_config___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_config___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_config___set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_config___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_config_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, serial)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_config___set_state, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_config_newstatic, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_collection_config_method_entry) {
	PHP_ME(Xpl_Collection_Config, __construct, arginfo_xpl_collection_config___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Xpl_Collection_Config, isEmpty, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Config, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Config, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Config, addAll, arginfo_xpl_collection_config_addall, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Config, keys, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Config, values, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Config, indexOf, arginfo_xpl_collection_config_indexof, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Config, contains, arginfo_xpl_collection_config_contains, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Config, getIterator, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Config, offsetGet, arginfo_xpl_collection_config_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Config, offsetSet, arginfo_xpl_collection_config_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Config, offsetExists, arginfo_xpl_collection_config_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Config, offsetUnset, arginfo_xpl_collection_config_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Config, get, arginfo_xpl_collection_config_get, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Config, set, arginfo_xpl_collection_config_set, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Config, has, arginfo_xpl_collection_config_has, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Config, getConfig, arginfo_xpl_collection_config_getconfig, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Config, __get, arginfo_xpl_collection_config___get, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Config, __isset, arginfo_xpl_collection_config___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Config, __set, arginfo_xpl_collection_config___set, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Config, __unset, arginfo_xpl_collection_config___unset, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Config, serialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Config, unserialize, arginfo_xpl_collection_config_unserialize, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Config, __set_state, arginfo_xpl_collection_config___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Collection_Config, newStatic, arginfo_xpl_collection_config_newstatic, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
