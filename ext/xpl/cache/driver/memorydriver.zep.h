
extern zend_class_entry *xpl_cache_driver_memorydriver_ce;

ZEPHIR_INIT_CLASS(Xpl_Cache_Driver_MemoryDriver);

PHP_METHOD(Xpl_Cache_Driver_MemoryDriver, exists);
PHP_METHOD(Xpl_Cache_Driver_MemoryDriver, get);
PHP_METHOD(Xpl_Cache_Driver_MemoryDriver, save);
PHP_METHOD(Xpl_Cache_Driver_MemoryDriver, delete);
PHP_METHOD(Xpl_Cache_Driver_MemoryDriver, clear);
static zend_object_value zephir_init_properties_Xpl_Cache_Driver_MemoryDriver(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_driver_memorydriver_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_driver_memorydriver_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_driver_memorydriver_save, 0, 0, 3)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_driver_memorydriver_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_cache_driver_memorydriver_method_entry) {
	PHP_ME(Xpl_Cache_Driver_MemoryDriver, exists, arginfo_xpl_cache_driver_memorydriver_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_Driver_MemoryDriver, get, arginfo_xpl_cache_driver_memorydriver_get, ZEND_ACC_PROTECTED)
	PHP_ME(Xpl_Cache_Driver_MemoryDriver, save, arginfo_xpl_cache_driver_memorydriver_save, ZEND_ACC_PROTECTED)
	PHP_ME(Xpl_Cache_Driver_MemoryDriver, delete, arginfo_xpl_cache_driver_memorydriver_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_Driver_MemoryDriver, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
