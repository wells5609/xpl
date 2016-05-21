
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Xpl_Apcu) {

	ZEPHIR_REGISTER_CLASS(Xpl, Apcu, xpl, apcu, xpl_apcu_method_entry, 0);

	zend_declare_property_string(xpl_apcu_ce, SL("prefix"), "", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_class_constant_long(xpl_apcu_ce, SL("DEFAULT_TTL"), 3600 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Xpl_Apcu, loaded) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "apcu", 0);
	ZEPHIR_RETURN_CALL_FUNCTION("extension_loaded", NULL, 16, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Xpl_Apcu, enabled) {

	zval *_1 = NULL;
	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = (zephir_function_exists_ex(SS("apcu_enabled") TSRMLS_CC) == SUCCESS);
	if (_0) {
		ZEPHIR_CALL_FUNCTION(&_1, "apcu_enabled", NULL, 17);
		zephir_check_call_status();
		_0 = zephir_is_true(_1);
	}
	RETURN_MM_BOOL(_0);

}

PHP_METHOD(Xpl_Apcu, setPrefix) {

	zval *prefix_param = NULL, *_0, _1, *_2;
	zval *prefix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &prefix_param);

	if (unlikely(Z_TYPE_P(prefix_param) != IS_STRING && Z_TYPE_P(prefix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(prefix_param) == IS_STRING)) {
		zephir_get_strval(prefix, prefix_param);
	} else {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_EMPTY_STRING(prefix);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, ".", 0);
	zephir_fast_trim(_0, prefix, &_1, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VS(_2, _0, ".");
	zephir_update_static_property_ce(xpl_apcu_ce, SL("prefix"), &_2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Xpl_Apcu, getPrefix) {

	zval *_0;


	_0 = zephir_fetch_static_property_ce(xpl_apcu_ce, SL("prefix") TSRMLS_CC);
	RETURN_CTORW(_0);

}

PHP_METHOD(Xpl_Apcu, get) {

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


	ZEPHIR_OBS_VAR(_0);
	zephir_read_static_property_ce(&_0, xpl_apcu_ce, SL("prefix") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VV(_1, _0, key);
	ZEPHIR_RETURN_CALL_FUNCTION("apcu_fetch", NULL, 18, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Xpl_Apcu, set) {

	int ttl, ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, *ttl_param = NULL, *_0, *_1, _2;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key_param, &value, &ttl_param);

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
	if (!ttl_param) {
		ttl = 3600;
	} else {
		ttl = zephir_get_intval(ttl_param);
	}


	ZEPHIR_OBS_VAR(_0);
	zephir_read_static_property_ce(&_0, xpl_apcu_ce, SL("prefix") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VV(_1, _0, key);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, ttl);
	ZEPHIR_CALL_FUNCTION(NULL, "apcu_store", NULL, 19, _1, value, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Xpl_Apcu, exists) {

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


	ZEPHIR_OBS_VAR(_0);
	zephir_read_static_property_ce(&_0, xpl_apcu_ce, SL("prefix") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VV(_1, _0, key);
	ZEPHIR_RETURN_CALL_FUNCTION("apcu_exists", NULL, 20, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Xpl_Apcu, delete) {

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


	ZEPHIR_OBS_VAR(_0);
	zephir_read_static_property_ce(&_0, xpl_apcu_ce, SL("prefix") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VV(_1, _0, key);
	ZEPHIR_CALL_FUNCTION(NULL, "apcu_delete", NULL, 21, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Xpl_Apcu, clear) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(NULL, "apcu_clear_cache", NULL, 22);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Xpl_Apcu, expiry) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *info = NULL, *ttl = NULL, *mtime = NULL, *_0, *_1;
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


	ZEPHIR_OBS_VAR(_0);
	zephir_read_static_property_ce(&_0, xpl_apcu_ce, SL("prefix") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VV(_1, _0, key);
	ZEPHIR_CALL_FUNCTION(&info, "apcu_key_info", NULL, 23, _1);
	zephir_check_call_status();
	if (Z_TYPE_P(info) == IS_ARRAY) {
		if (zephir_array_isset_string_fetch(&ttl, info, SS("ttl"), 1 TSRMLS_CC)) {
			if (zephir_array_isset_string_fetch(&mtime, info, SS("mtime"), 1 TSRMLS_CC)) {
				zephir_add_function(return_value, mtime, ttl);
				RETURN_MM();
			}
		}
	}
	RETURN_MM_NULL();

}

