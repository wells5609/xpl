
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Xpl_Cache_Driver_XCacheDriver) {

	ZEPHIR_REGISTER_CLASS_EX(Xpl\\Cache\\Driver, XCacheDriver, xpl, cache_driver_xcachedriver, xpl_cache_driver_abstractdriver_ce, xpl_cache_driver_xcachedriver_method_entry, 0);

	return SUCCESS;

}

/**
 * Checks whether the driver is available for use.
 *
 * @return boolean
 */
PHP_METHOD(Xpl_Cache_Driver_XCacheDriver, isAvailable) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "xcache", 0);
	ZEPHIR_RETURN_CALL_FUNCTION("extension_loaded", NULL, 16, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Whether the given item exists in the cache.
 *
 * @param string key Item key.
 *
 * @return boolean True if a cached value exists, otherwise false.
 */
PHP_METHOD(Xpl_Cache_Driver_XCacheDriver, exists) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_RETURN_CALL_FUNCTION("xcache_isset", NULL, 36, key);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a value from the cache.
 *
 * @param string key Item key.
 * @return mixed Cached value, if it exists, otherwise null.
 */
PHP_METHOD(Xpl_Cache_Driver_XCacheDriver, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_RETURN_CALL_FUNCTION("xcache_get", NULL, 37, key);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Saves a value in the cache.
 *
 * @param string key Item key
 * @param scalar value Item value
 * @param int ttl [Optional] Cache lifetime in seconds
 */
PHP_METHOD(Xpl_Cache_Driver_XCacheDriver, save) {

	int ttl, ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, *ttl_param = NULL, _0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &key_param, &value, &ttl_param);

	zephir_get_strval(key, key_param);
	ttl = zephir_get_intval(ttl_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, ttl);
	ZEPHIR_CALL_FUNCTION(NULL, "xcache_set", NULL, 38, key, value, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Removes an item from the cache.
 *
 * @param string key Item key
 */
PHP_METHOD(Xpl_Cache_Driver_XCacheDriver, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_CALL_FUNCTION(NULL, "xcache_unset", NULL, 39, key);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Clears all items from the cache.
 */
PHP_METHOD(Xpl_Cache_Driver_XCacheDriver, clear) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 1);
	ZEPHIR_CALL_FUNCTION(NULL, "xcache_clear_cache", NULL, 40, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

