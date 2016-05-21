
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
#include "kernel/array.h"
#include "ext/date/php_date.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Xpl_Cache_Driver_ApcuDriver) {

	ZEPHIR_REGISTER_CLASS_EX(Xpl\\Cache\\Driver, ApcuDriver, xpl, cache_driver_apcudriver, xpl_cache_driver_abstractdriver_ce, xpl_cache_driver_apcudriver_method_entry, 0);

	return SUCCESS;

}

/**
 * Checks whether the driver is available for use.
 *
 * @return boolean
 */
PHP_METHOD(Xpl_Cache_Driver_ApcuDriver, isAvailable) {

	zend_bool _6$$4;
	zval _0, *_1 = NULL, _2$$3, *_3$$3 = NULL, *_5$$4 = NULL, _7$$4, *_8$$4 = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "apcu", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 16, &_0);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_SINIT_VAR(_2$$3);
		ZVAL_STRING(&_2$$3, "apc.enabled", 0);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "ini_get", &_4, 27, &_2$$3);
		zephir_check_call_status();
		if (zephir_is_true(_3$$3)) {
			ZEPHIR_CALL_FUNCTION(&_5$$4, "php_sapi_name", NULL, 28);
			zephir_check_call_status();
			_6$$4 = !ZEPHIR_IS_STRING_IDENTICAL(_5$$4, "cli");
			if (!(_6$$4)) {
				ZEPHIR_SINIT_VAR(_7$$4);
				ZVAL_STRING(&_7$$4, "apc.enable_cli", 0);
				ZEPHIR_CALL_FUNCTION(&_8$$4, "ini_get", &_4, 27, &_7$$4);
				zephir_check_call_status();
				_6$$4 = zephir_is_true(_8$$4);
			}
			if (_6$$4) {
				RETURN_MM_BOOL(1);
			}
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Whether the given item exists in the cache.
 *
 * @param string key Item key.
 *
 * @return boolean True if a cached value exists, otherwise false.
 */
PHP_METHOD(Xpl_Cache_Driver_ApcuDriver, exists) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_RETURN_CALL_FUNCTION("apcu_exists", NULL, 20, key);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a value from the cache.
 *
 * @param string key Item key.
 *
 * @return mixed Cached value, if it exists, otherwise null.
 */
PHP_METHOD(Xpl_Cache_Driver_ApcuDriver, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_RETURN_CALL_FUNCTION("apcu_fetch", NULL, 18, key);
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
PHP_METHOD(Xpl_Cache_Driver_ApcuDriver, save) {

	int ttl, ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, *ttl_param = NULL, _0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &key_param, &value, &ttl_param);

	zephir_get_strval(key, key_param);
	ttl = zephir_get_intval(ttl_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, ttl);
	ZEPHIR_CALL_FUNCTION(NULL, "apcu_store", NULL, 19, key, value, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Removes an item from the cache.
 *
 * @param string key Item key
 */
PHP_METHOD(Xpl_Cache_Driver_ApcuDriver, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_CALL_FUNCTION(NULL, "apcu_delete", NULL, 21, key);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Clears all items from the cache.
 */
PHP_METHOD(Xpl_Cache_Driver_ApcuDriver, clear) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(NULL, "apcu_clear_cache", NULL, 22);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a new Item on hit.
 *
 * @param string key
 * @param mixed value
 *
 * @return \Xpl\Cache\Item
 */
PHP_METHOD(Xpl_Cache_Driver_ApcuDriver, hit) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, *item = NULL, *cacheInfo = NULL, *ttl = NULL, *mtime = NULL, *_0, *_1$$5, *_2$$5, *_3$$5;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	ZEPHIR_INIT_VAR(item);
	object_init_ex(item, xpl_cache_item_ce);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_BOOL(_0, 1);
	ZEPHIR_CALL_METHOD(NULL, item, "__construct", NULL, 1, key, _0, value);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&cacheInfo, "apcu_key_info", NULL, 23, key);
	zephir_check_call_status();
	if (Z_TYPE_P(cacheInfo) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(ttl);
		if (zephir_array_isset_string_fetch(&ttl, cacheInfo, SS("ttl"), 0 TSRMLS_CC)) {
			ZEPHIR_OBS_VAR(mtime);
			if (zephir_array_isset_string_fetch(&mtime, cacheInfo, SS("mtime"), 0 TSRMLS_CC)) {
				ZEPHIR_INIT_VAR(_1$$5);
				object_init_ex(_1$$5, php_date_get_date_ce());
				ZEPHIR_INIT_VAR(_2$$5);
				zephir_add_function(_2$$5, mtime, ttl);
				ZEPHIR_INIT_VAR(_3$$5);
				ZEPHIR_CONCAT_SV(_3$$5, "@", _2$$5);
				ZEPHIR_CALL_METHOD(NULL, _1$$5, "__construct", NULL, 0, _3$$5);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, item, "expiresat", NULL, 35, _1$$5);
				zephir_check_call_status();
			}
		}
	}
	RETURN_CCTOR(item);

}

