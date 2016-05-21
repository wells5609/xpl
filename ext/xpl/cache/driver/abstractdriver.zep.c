
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Xpl_Cache_Driver_AbstractDriver) {

	ZEPHIR_REGISTER_CLASS(Xpl\\Cache\\Driver, AbstractDriver, xpl, cache_driver_abstractdriver, xpl_cache_driver_abstractdriver_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_class_implements(xpl_cache_driver_abstractdriver_ce TSRMLS_CC, 1, xpl_cache_driverinterface_ce);
	return SUCCESS;

}

/**
 * Saves the given Item to the cache backend.
 *
 * @param \Xpl\Cache\Item
 *
 * @return boolean
 */
PHP_METHOD(Xpl_Cache_Driver_AbstractDriver, put) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *cacheItem, *e = NULL, *_0$$3 = NULL, *_1$$3 = NULL, *_2$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cacheItem);




	/* try_start_1: */

		ZEPHIR_CALL_METHOD(&_0$$3, cacheItem, "getkey", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&_1$$3, cacheItem, "get", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&_2$$3, cacheItem, "getttl", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "save", NULL, 0, _0$$3, _1$$3, _2$$3);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_CPY_WRT(e, EG(exception));
		if (zephir_instance_of_ev(e, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			RETURN_MM_BOOL(0);
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Fetches an Item from the cache backend.
 *
 * @param \Xpl\Cache\Item cacheItem
 *
 * @return \Xpl\Cache\Item
 */
PHP_METHOD(Xpl_Cache_Driver_AbstractDriver, fetch) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_0 = NULL, *_1$$3 = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "exists", NULL, 0, key);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "get", NULL, 0, key);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "hit", NULL, 0, key, _1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "miss", NULL, 0, key);
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
PHP_METHOD(Xpl_Cache_Driver_AbstractDriver, get) {

}

/**
 * Saves a value in the cache.
 *
 * @param string key Item key
 * @param mixed value Item value
 * @param int ttl Cache lifetime in seconds
 *
 * @return void
 */
PHP_METHOD(Xpl_Cache_Driver_AbstractDriver, save) {

}

/**
 * Returns a new Item on hit.
 *
 * @param string key
 * @param mixed value
 *
 * @return \Xpl\Cache\Item
 */
PHP_METHOD(Xpl_Cache_Driver_AbstractDriver, hit) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, *_0;
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


	object_init_ex(return_value, xpl_cache_item_ce);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_BOOL(_0, 1);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 1, key, _0, value);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Creates a new Item on miss.
 *
 * @param string key
 *
 * @return \Xpl\Cache\Item
 */
PHP_METHOD(Xpl_Cache_Driver_AbstractDriver, miss) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_0, *_1;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

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


	object_init_ex(return_value, xpl_cache_item_ce);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_BOOL(_0, 0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_NULL(_1);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 1, key, _0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

