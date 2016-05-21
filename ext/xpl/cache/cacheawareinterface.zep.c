
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Xpl_Cache_CacheAwareInterface) {

	ZEPHIR_REGISTER_INTERFACE(Xpl\\Cache, CacheAwareInterface, xpl, cache_cacheawareinterface, xpl_cache_cacheawareinterface_method_entry);

	return SUCCESS;

}

/**
 * Sets the Cache.
 *
 * @param \Xpl\Cache\Cache cache
 */
ZEPHIR_DOC_METHOD(Xpl_Cache_CacheAwareInterface, setCache);

/**
 * Returns the Cache.
 *
 * @return \Xpl\Cache\Cache
 */
ZEPHIR_DOC_METHOD(Xpl_Cache_CacheAwareInterface, getCache);

