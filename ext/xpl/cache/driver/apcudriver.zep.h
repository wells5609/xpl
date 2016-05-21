
extern zend_class_entry *xpl_cache_driver_apcudriver_ce;

ZEPHIR_INIT_CLASS(Xpl_Cache_Driver_ApcuDriver);

PHP_METHOD(Xpl_Cache_Driver_ApcuDriver, isAvailable);
PHP_METHOD(Xpl_Cache_Driver_ApcuDriver, exists);
PHP_METHOD(Xpl_Cache_Driver_ApcuDriver, get);
PHP_METHOD(Xpl_Cache_Driver_ApcuDriver, save);
PHP_METHOD(Xpl_Cache_Driver_ApcuDriver, delete);
PHP_METHOD(Xpl_Cache_Driver_ApcuDriver, clear);
PHP_METHOD(Xpl_Cache_Driver_ApcuDriver, hit);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_driver_apcudriver_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_driver_apcudriver_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_driver_apcudriver_save, 0, 0, 3)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_driver_apcudriver_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_driver_apcudriver_hit, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_cache_driver_apcudriver_method_entry) {
	PHP_ME(Xpl_Cache_Driver_ApcuDriver, isAvailable, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Cache_Driver_ApcuDriver, exists, arginfo_xpl_cache_driver_apcudriver_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_Driver_ApcuDriver, get, arginfo_xpl_cache_driver_apcudriver_get, ZEND_ACC_PROTECTED)
	PHP_ME(Xpl_Cache_Driver_ApcuDriver, save, arginfo_xpl_cache_driver_apcudriver_save, ZEND_ACC_PROTECTED)
	PHP_ME(Xpl_Cache_Driver_ApcuDriver, delete, arginfo_xpl_cache_driver_apcudriver_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_Driver_ApcuDriver, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_Driver_ApcuDriver, hit, arginfo_xpl_cache_driver_apcudriver_hit, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
