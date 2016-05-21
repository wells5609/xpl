
extern zend_class_entry *xpl_cache_cacheawareinterface_ce;

ZEPHIR_INIT_CLASS(Xpl_Cache_CacheAwareInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_cache_cacheawareinterface_setcache, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, cache, Xpl\\Cache\\Cache, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_cache_cacheawareinterface_method_entry) {
	PHP_ABSTRACT_ME(Xpl_Cache_CacheAwareInterface, setCache, arginfo_xpl_cache_cacheawareinterface_setcache)
	PHP_ABSTRACT_ME(Xpl_Cache_CacheAwareInterface, getCache, NULL)
	PHP_FE_END
};
