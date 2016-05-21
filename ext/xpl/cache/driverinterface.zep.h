
extern zend_class_entry *xpl_cache_driverinterface_ce;

ZEPHIR_INIT_CLASS(Xpl_Cache_DriverInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_driverinterface_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_driverinterface_fetch, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_driverinterface_put, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, cacheItem, Xpl\\Cache\\Item, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_driverinterface_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_cache_driverinterface_method_entry) {
	PHP_ABSTRACT_ME(Xpl_Cache_DriverInterface, exists, arginfo_xpl_cache_driverinterface_exists)
	PHP_ABSTRACT_ME(Xpl_Cache_DriverInterface, fetch, arginfo_xpl_cache_driverinterface_fetch)
	PHP_ABSTRACT_ME(Xpl_Cache_DriverInterface, put, arginfo_xpl_cache_driverinterface_put)
	PHP_ABSTRACT_ME(Xpl_Cache_DriverInterface, delete, arginfo_xpl_cache_driverinterface_delete)
	PHP_ABSTRACT_ME(Xpl_Cache_DriverInterface, clear, NULL)
	PHP_FE_END
};
