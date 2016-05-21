
extern zend_class_entry *xpl_cache_itempool_ce;

ZEPHIR_INIT_CLASS(Xpl_Cache_ItemPool);

PHP_METHOD(Xpl_Cache_ItemPool, __construct);
PHP_METHOD(Xpl_Cache_ItemPool, getDriver);
PHP_METHOD(Xpl_Cache_ItemPool, getItem);
PHP_METHOD(Xpl_Cache_ItemPool, getItems);
PHP_METHOD(Xpl_Cache_ItemPool, hasItem);
PHP_METHOD(Xpl_Cache_ItemPool, clear);
PHP_METHOD(Xpl_Cache_ItemPool, deleteItem);
PHP_METHOD(Xpl_Cache_ItemPool, deleteItems);
PHP_METHOD(Xpl_Cache_ItemPool, save);
PHP_METHOD(Xpl_Cache_ItemPool, saveDeferred);
PHP_METHOD(Xpl_Cache_ItemPool, commit);
PHP_METHOD(Xpl_Cache_ItemPool, reset);
PHP_METHOD(Xpl_Cache_ItemPool, isValidKey);
PHP_METHOD(Xpl_Cache_ItemPool, isItemExpired);
static zend_object_value zephir_init_properties_Xpl_Cache_ItemPool(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_itempool___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, driver, Xpl\\Cache\\DriverInterface, 0)
	ZEND_ARG_INFO(0, prefix)
	ZEND_ARG_INFO(0, defaultTtl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_itempool_getitem, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_itempool_getitems, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, keys, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_itempool_hasitem, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_itempool_deleteitem, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_itempool_deleteitems, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_itempool_save, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, item, Psr\\Cache\\CacheItemInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_itempool_savedeferred, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, item, Psr\\Cache\\CacheItemInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_itempool_isvalidkey, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_itempool_isitemexpired, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, cacheItem, Xpl\\Cache\\Item, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_cache_itempool_method_entry) {
	PHP_ME(Xpl_Cache_ItemPool, __construct, arginfo_xpl_cache_itempool___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Xpl_Cache_ItemPool, getDriver, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_ItemPool, getItem, arginfo_xpl_cache_itempool_getitem, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_ItemPool, getItems, arginfo_xpl_cache_itempool_getitems, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_ItemPool, hasItem, arginfo_xpl_cache_itempool_hasitem, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_ItemPool, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_ItemPool, deleteItem, arginfo_xpl_cache_itempool_deleteitem, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_ItemPool, deleteItems, arginfo_xpl_cache_itempool_deleteitems, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_ItemPool, save, arginfo_xpl_cache_itempool_save, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_ItemPool, saveDeferred, arginfo_xpl_cache_itempool_savedeferred, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_ItemPool, commit, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_ItemPool, reset, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_ItemPool, isValidKey, arginfo_xpl_cache_itempool_isvalidkey, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_ItemPool, isItemExpired, arginfo_xpl_cache_itempool_isitemexpired, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
