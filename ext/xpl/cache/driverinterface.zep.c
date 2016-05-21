
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Xpl_Cache_DriverInterface) {

	ZEPHIR_REGISTER_INTERFACE(Xpl\\Cache, DriverInterface, xpl, cache_driverinterface, xpl_cache_driverinterface_method_entry);

	return SUCCESS;

}

/**
 * Whether the given item exists in the cache.
 *
 * @param string key Item key.
 *
 * @return boolean True if a cached value exists, otherwise false.
 */
ZEPHIR_DOC_METHOD(Xpl_Cache_DriverInterface, exists);

/**
 * Fetches an Item from the cache backend.
 *
 * @param string key
 *
 * @return \Xpl\Cache\Item
 */
ZEPHIR_DOC_METHOD(Xpl_Cache_DriverInterface, fetch);

/**
 * Saves the given Item to the cache backend.
 *
 * @param \Xpl\Cache\Item
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Xpl_Cache_DriverInterface, put);

/**
 * Removes an item from the cache.
 *
 * @param string key Item key
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Xpl_Cache_DriverInterface, delete);

/**
 * Clears all items from the cache.
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Xpl_Cache_DriverInterface, clear);

