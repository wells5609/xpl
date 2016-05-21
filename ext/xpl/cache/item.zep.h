
extern zend_class_entry *xpl_cache_item_ce;

ZEPHIR_INIT_CLASS(Xpl_Cache_Item);

PHP_METHOD(Xpl_Cache_Item, __construct);
PHP_METHOD(Xpl_Cache_Item, getKey);
PHP_METHOD(Xpl_Cache_Item, get);
PHP_METHOD(Xpl_Cache_Item, isHit);
PHP_METHOD(Xpl_Cache_Item, set);
PHP_METHOD(Xpl_Cache_Item, expiresAt);
PHP_METHOD(Xpl_Cache_Item, expiresAfter);
PHP_METHOD(Xpl_Cache_Item, getExpiration);
PHP_METHOD(Xpl_Cache_Item, getTtl);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_item___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, hit)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, expiry)
	ZEND_ARG_INFO(0, defaultTtl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_item_set, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_item_expiresat, 0, 0, 1)
	ZEND_ARG_INFO(0, expiration)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_item_expiresafter, 0, 0, 1)
	ZEND_ARG_INFO(0, time)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_cache_item_method_entry) {
	PHP_ME(Xpl_Cache_Item, __construct, arginfo_xpl_cache_item___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Xpl_Cache_Item, getKey, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_Item, get, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_Item, isHit, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_Item, set, arginfo_xpl_cache_item_set, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_Item, expiresAt, arginfo_xpl_cache_item_expiresat, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_Item, expiresAfter, arginfo_xpl_cache_item_expiresafter, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_Item, getExpiration, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Cache_Item, getTtl, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
