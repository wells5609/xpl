
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
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/file.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Xpl_Json) {

	ZEPHIR_REGISTER_CLASS(Xpl, Json, xpl, json, xpl_json_method_entry, 0);

	return SUCCESS;

}

/**
 * JSON-encodes data.
 *
 * @param mixed data
 * @param int options [Optional]
 * @return string
 */
PHP_METHOD(Xpl_Json, encode) {

	int options;
	zval *data, *options_param = NULL, _0;

	zephir_fetch_params(0, 1, 1, &data, &options_param);

	if (!options_param) {
		options = 0;
	} else {
		options = zephir_get_intval(options_param);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, options);
	zephir_json_encode(return_value, &(return_value), data, zephir_get_intval(&_0)  TSRMLS_CC);
	return;

}

/**
 * Decodes a JSON-encoded string into an object or array
 *
 * @param string $json A well-formed JSON string.
 * @param boolean $assoc [Optional] Whether to decode to an associative array. Default false.
 * @param int $depth [Optional] Depth to decode to. Default 512
 * @param int $flags [Optional] Bitwise flags for use in json_decode(). Default is 0
 * @return object|array|null JSON data decoded to object(s) or array(s).
 */
PHP_METHOD(Xpl_Json, decode) {

	int depth, flags;
	zend_bool assoc;
	zval *json_param = NULL, *assoc_param = NULL, *depth_param = NULL, *flags_param = NULL, _0, _1, _2;
	zval *json = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &json_param, &assoc_param, &depth_param, &flags_param);

	if (unlikely(Z_TYPE_P(json_param) != IS_STRING && Z_TYPE_P(json_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'json' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(json_param) == IS_STRING)) {
		zephir_get_strval(json, json_param);
	} else {
		ZEPHIR_INIT_VAR(json);
		ZVAL_EMPTY_STRING(json);
	}
	if (!assoc_param) {
		assoc = 0;
	} else {
		assoc = zephir_get_boolval(assoc_param);
	}
	if (!depth_param) {
		depth = 512;
	} else {
		depth = zephir_get_intval(depth_param);
	}
	if (!flags_param) {
		flags = 0;
	} else {
		flags = zephir_get_intval(flags_param);
	}


	if (ZEPHIR_IS_EMPTY(json)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_BOOL(&_0, (assoc ? 1 : 0));
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, depth);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, flags);
	zephir_json_decode(return_value, &(return_value), json, zephir_get_intval(&_0)  TSRMLS_CC);
	RETURN_MM();

}

/**
 * Reads and decodes a JSON-encoded file into an object or array
 *
 * @param string $file A readable JSON file.
 * @param boolean $assoc [Optional] Whether to decode to an associative array. Default false.
 * @param int $depth [Optional] Depth to decode to. Default 512
 * @param int $flags [Optional] Bitwise flags for use in json_decode(). Default is 0
 * @return object|array|null JSON data decoded to object(s) or array(s).
 */
PHP_METHOD(Xpl_Json, decodeFile) {

	int depth, flags, ZEPHIR_LAST_CALL_STATUS;
	zend_bool assoc;
	zval *file_param = NULL, *assoc_param = NULL, *depth_param = NULL, *flags_param = NULL, *json = NULL, *_2, *_3, *_4, *_0$$3;
	zval *file = NULL, *_1$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &file_param, &assoc_param, &depth_param, &flags_param);

	if (unlikely(Z_TYPE_P(file_param) != IS_STRING && Z_TYPE_P(file_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'file' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(file_param) == IS_STRING)) {
		zephir_get_strval(file, file_param);
	} else {
		ZEPHIR_INIT_VAR(file);
		ZVAL_EMPTY_STRING(file);
	}
	if (!assoc_param) {
		assoc = 0;
	} else {
		assoc = zephir_get_boolval(assoc_param);
	}
	if (!depth_param) {
		depth = 512;
	} else {
		depth = zephir_get_intval(depth_param);
	}
	if (!flags_param) {
		flags = 0;
	} else {
		flags = zephir_get_intval(flags_param);
	}


	if (!((zephir_file_exists(file TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_INIT_VAR(_0$$3);
		object_init_ex(_0$$3, spl_ce_RuntimeException);
		ZEPHIR_INIT_VAR(_1$$3);
		ZEPHIR_CONCAT_SV(_1$$3, "Unreadable file: ", file);
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 111, _1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$3, "xpl/json.zep", 62 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(json);
	zephir_file_get_contents(json, file TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	if (assoc) {
		ZVAL_BOOL(_2, 1);
	} else {
		ZVAL_BOOL(_2, 0);
	}
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, depth);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, flags);
	ZEPHIR_RETURN_CALL_SELF("decode", NULL, 0, json, _2, _3, _4);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns whether the given variable is a valid JSON string.
 *
 * @param string
 * @return boolean
 */
PHP_METHOD(Xpl_Json, validate) {

	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *_1, *_2 = NULL;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	if (ZEPHIR_IS_EMPTY(str)) {
		RETURN_MM_BOOL(0);
	}
	_0 = ZEPHIR_IS_STRING_IDENTICAL(str, "{}");
	if (!(_0)) {
		_0 = ZEPHIR_IS_STRING_IDENTICAL(str, "[]");
	}
	if (_0) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(_1);
	zephir_json_decode(_1, &(_1), str, 0  TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_2, "json_last_error", NULL, 112);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG_IDENTICAL(_2, 0));

}

