
extern zend_class_entry *xpl_cache_driver_apcdriver_ce;

ZEPHIR_INIT_CLASS(Xpl_Cache_Driver_ApcDriver);

PHP_METHOD(Xpl_Cache_Driver_ApcDriver, isAvailable);
PHP_METHOD(Xpl_Cache_Driver_ApcDriver, exists);
PHP_METHOD(Xpl_Cache_Driver_ApcDriver, get);
PHP_METHOD(Xpl_Cache_Driver_ApcDriver, save);
PHP_METHOD(Xpl_Cache_Driver_ApcDriver, delete);
PHP_METHOD(Xpl_Cache_Driver_ApcDriver, clear);
PHP_METHOD(Xpl_Cache_Driver_ApcDriver, hit);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_driver_apcdriver_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_driver_apcdriver_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_driver_apcdriver_save, 0, 0, 3)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_driver_apcdriver_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_driver_apcdriver_hit, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_cache_driver_apcdriver_method_entry) {
	PHP_ME(Xpl_Cache_Driver_ApcDriver, isAvailable, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Cache_Driver_ApcDriver, exists, arginfo_xpl_cache_driver_apcdriver_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_Driver_ApcDriver, get, arginfo_xpl_cache_driver_apcdriver_get, ZEND_ACC_PROTECTED)
	PHP_ME(Xpl_Cache_Driver_ApcDriver, save, arginfo_xpl_cache_driver_apcdriver_save, ZEND_ACC_PROTECTED)
	PHP_ME(Xpl_Cache_Driver_ApcDriver, delete, arginfo_xpl_cache_driver_apcdriver_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_Driver_ApcDriver, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_Driver_ApcDriver, hit, arginfo_xpl_cache_driver_apcdriver_hit, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
