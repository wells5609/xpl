
extern zend_class_entry *xpl_cache_cache_ce;

ZEPHIR_INIT_CLASS(Xpl_Cache_Cache);

PHP_METHOD(Xpl_Cache_Cache, __construct);
PHP_METHOD(Xpl_Cache_Cache, setPrefix);
PHP_METHOD(Xpl_Cache_Cache, getPrefix);
PHP_METHOD(Xpl_Cache_Cache, getDriver);
PHP_METHOD(Xpl_Cache_Cache, setDriver);
PHP_METHOD(Xpl_Cache_Cache, getConfig);
PHP_METHOD(Xpl_Cache_Cache, setConfig);
PHP_METHOD(Xpl_Cache_Cache, getPool);
PHP_METHOD(Xpl_Cache_Cache, setPool);
PHP_METHOD(Xpl_Cache_Cache, createPool);
PHP_METHOD(Xpl_Cache_Cache, getDetectedDriver);
static zend_object_value zephir_init_properties_Xpl_Cache_Cache(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_cache___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, driver, Xpl\\Cache\\DriverInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_cache_setprefix, 0, 0, 1)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_cache_setdriver, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, driver, Xpl\\Cache\\DriverInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_cache_getconfig, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_cache_setconfig, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, config, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_cache_getpool, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_cache_setpool, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, pool, Xpl\\Cache\\ItemPool, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_cache_createpool, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_cache_cache_method_entry) {
	PHP_ME(Xpl_Cache_Cache, __construct, arginfo_xpl_cache_cache___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Xpl_Cache_Cache, setPrefix, arginfo_xpl_cache_cache_setprefix, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_Cache, getPrefix, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_Cache, getDriver, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_Cache, setDriver, arginfo_xpl_cache_cache_setdriver, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_Cache, getConfig, arginfo_xpl_cache_cache_getconfig, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_Cache, setConfig, arginfo_xpl_cache_cache_setconfig, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_Cache, getPool, arginfo_xpl_cache_cache_getpool, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_Cache, setPool, arginfo_xpl_cache_cache_setpool, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_Cache, createPool, arginfo_xpl_cache_cache_createpool, ZEND_ACC_PROTECTED)
	PHP_ME(Xpl_Cache_Cache, getDetectedDriver, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
