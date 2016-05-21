
extern zend_class_entry *xpl_cache_driver_abstractdriver_ce;

ZEPHIR_INIT_CLASS(Xpl_Cache_Driver_AbstractDriver);

PHP_METHOD(Xpl_Cache_Driver_AbstractDriver, put);
PHP_METHOD(Xpl_Cache_Driver_AbstractDriver, fetch);
PHP_METHOD(Xpl_Cache_Driver_AbstractDriver, get);
PHP_METHOD(Xpl_Cache_Driver_AbstractDriver, save);
PHP_METHOD(Xpl_Cache_Driver_AbstractDriver, hit);
PHP_METHOD(Xpl_Cache_Driver_AbstractDriver, miss);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_driver_abstractdriver_put, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, cacheItem, Xpl\\Cache\\Item, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_driver_abstractdriver_fetch, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_driver_abstractdriver_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_driver_abstractdriver_save, 0, 0, 3)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_driver_abstractdriver_hit, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_driver_abstractdriver_miss, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_cache_driver_abstractdriver_method_entry) {
	PHP_ME(Xpl_Cache_Driver_AbstractDriver, put, arginfo_xpl_cache_driver_abstractdriver_put, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_Driver_AbstractDriver, fetch, arginfo_xpl_cache_driver_abstractdriver_fetch, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_Driver_AbstractDriver, get, arginfo_xpl_cache_driver_abstractdriver_get, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Xpl_Cache_Driver_AbstractDriver, save, arginfo_xpl_cache_driver_abstractdriver_save, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Xpl_Cache_Driver_AbstractDriver, hit, arginfo_xpl_cache_driver_abstractdriver_hit, ZEND_ACC_PROTECTED)
	PHP_ME(Xpl_Cache_Driver_AbstractDriver, miss, arginfo_xpl_cache_driver_abstractdriver_miss, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
