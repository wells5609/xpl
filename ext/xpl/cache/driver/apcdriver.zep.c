
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
#include "kernel/hash.h"
#include "ext/date/php_date.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Xpl_Cache_Driver_ApcDriver) {

	ZEPHIR_REGISTER_CLASS_EX(Xpl\\Cache\\Driver, ApcDriver, xpl, cache_driver_apcdriver, xpl_cache_driver_abstractdriver_ce, xpl_cache_driver_apcdriver_method_entry, 0);

	return SUCCESS;

}

/**
 * Checks whether the driver is available for use.
 *
 * @return boolean
 */
PHP_METHOD(Xpl_Cache_Driver_ApcDriver, isAvailable) {

	zend_bool _6$$4;
	zval _0, *_1 = NULL, _2$$3, *_3$$3 = NULL, *_5$$4 = NULL, _7$$4, *_8$$4 = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "apc", 0);
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
PHP_METHOD(Xpl_Cache_Driver_ApcDriver, exists) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_RETURN_CALL_FUNCTION("apc_exists", NULL, 29, key);
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
PHP_METHOD(Xpl_Cache_Driver_ApcDriver, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_RETURN_CALL_FUNCTION("apc_fetch", NULL, 30, key);
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
PHP_METHOD(Xpl_Cache_Driver_ApcDriver, save) {

	int ttl, ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, *ttl_param = NULL, _0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &key_param, &value, &ttl_param);

	zephir_get_strval(key, key_param);
	ttl = zephir_get_intval(ttl_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, ttl);
	ZEPHIR_CALL_FUNCTION(NULL, "apc_store", NULL, 31, key, value, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Removes an item from the cache.
 *
 * @param string key Item key
 */
PHP_METHOD(Xpl_Cache_Driver_ApcDriver, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_CALL_FUNCTION(NULL, "apc_delete", NULL, 32, key);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Clears all items from the cache.
 */
PHP_METHOD(Xpl_Cache_Driver_ApcDriver, clear) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "user", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "apc_clear_cache", NULL, 33, &_0);
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
PHP_METHOD(Xpl_Cache_Driver_ApcDriver, hit) {

	HashTable *_4;
	HashPosition _3;
	zephir_fcall_cache_entry *_10 = NULL, *_11 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, *cacheInfo = NULL, *itemInfo = NULL, *ttl = NULL, *mtime = NULL, *item = NULL, *_0, _1, *_2, **_5, *_6$$3, *_7$$6 = NULL, *_8$$6 = NULL, *_9$$6 = NULL;
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
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "user", 0);
	ZEPHIR_CALL_FUNCTION(&cacheInfo, "apc_cache_info", NULL, 34, &_1);
	zephir_check_call_status();
	zephir_array_fetch_string(&_2, cacheInfo, SL("cache_list"), PH_NOISY | PH_READONLY, "xpl/cache/driver/apcdriver.zep", 97 TSRMLS_CC);
	zephir_is_iterable(_2, &_4, &_3, 0, 0, "xpl/cache/driver/apcdriver.zep", 108);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(itemInfo, _5);
		zephir_array_fetch_string(&_6$$3, itemInfo, SL("key"), PH_NOISY | PH_READONLY, "xpl/cache/driver/apcdriver.zep", 98 TSRMLS_CC);
		if (ZEPHIR_IS_IDENTICAL(_6$$3, key)) {
			ZEPHIR_OBS_NVAR(ttl);
			if (zephir_array_isset_string_fetch(&ttl, itemInfo, SS("ttl"), 0 TSRMLS_CC)) {
				ZEPHIR_OBS_NVAR(mtime);
				if (zephir_array_isset_string_fetch(&mtime, itemInfo, SS("mtime"), 0 TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(_7$$6);
					object_init_ex(_7$$6, php_date_get_date_ce());
					ZEPHIR_INIT_LNVAR(_8$$6);
					zephir_add_function(_8$$6, mtime, ttl);
					ZEPHIR_INIT_LNVAR(_9$$6);
					ZEPHIR_CONCAT_SV(_9$$6, "@", _8$$6);
					ZEPHIR_CALL_METHOD(NULL, _7$$6, "__construct", &_10, 0, _9$$6);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, item, "expiresat", &_11, 35, _7$$6);
					zephir_check_call_status();
				}
			}
			break;
		}
	}
	RETURN_CCTOR(item);

}

