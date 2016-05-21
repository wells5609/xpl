
extern zend_class_entry *xpl_cache_driver_xcachedriver_ce;

ZEPHIR_INIT_CLASS(Xpl_Cache_Driver_XCacheDriver);

PHP_METHOD(Xpl_Cache_Driver_XCacheDriver, isAvailable);
PHP_METHOD(Xpl_Cache_Driver_XCacheDriver, exists);
PHP_METHOD(Xpl_Cache_Driver_XCacheDriver, get);
PHP_METHOD(Xpl_Cache_Driver_XCacheDriver, save);
PHP_METHOD(Xpl_Cache_Driver_XCacheDriver, delete);
PHP_METHOD(Xpl_Cache_Driver_XCacheDriver, clear);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_driver_xcachedriver_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_driver_xcachedriver_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_driver_xcachedriver_save, 0, 0, 3)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_driver_xcachedriver_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_cache_driver_xcachedriver_method_entry) {
	PHP_ME(Xpl_Cache_Driver_XCacheDriver, isAvailable, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Cache_Driver_XCacheDriver, exists, arginfo_xpl_cache_driver_xcachedriver_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_Driver_XCacheDriver, get, arginfo_xpl_cache_driver_xcachedriver_get, ZEND_ACC_PROTECTED)
	PHP_ME(Xpl_Cache_Driver_XCacheDriver, save, arginfo_xpl_cache_driver_xcachedriver_save, ZEND_ACC_PROTECTED)
	PHP_ME(Xpl_Cache_Driver_XCacheDriver, delete, arginfo_xpl_cache_driver_xcachedriver_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_Driver_XCacheDriver, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
