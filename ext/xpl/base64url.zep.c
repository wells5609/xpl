
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Xpl_Base64Url) {

	ZEPHIR_REGISTER_CLASS(Xpl, Base64Url, xpl, base64url, xpl_base64url_method_entry, 0);

	return SUCCESS;

}

/**
 * Base64 encode a string, safe for URLs.
 *
 * @param string $str Data to encode.
 *
 * @return string URL-safe base64-encoded string.
 */
PHP_METHOD(Xpl_Base64Url, encode) {

	zval *_0, *_2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *_1 = NULL, *_3 = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_strval(data, data_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "+", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "/", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "=", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "-", 1);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "_", 1);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_CALL_FUNCTION(&_3, "base64_encode", NULL, 24, data);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	zephir_fast_str_replace(&_1, _0, _2, _3 TSRMLS_CC);
	RETURN_CCTOR(_1);

}

/**
 * Decodes a URL-safe base64-encoded string.
 *
 * @param string data
 *
 * @return string Decoded string.
 */
PHP_METHOD(Xpl_Base64Url, decode) {

	zval *_0, *_2;
	int ZEPHIR_LAST_CALL_STATUS, mod4 = 0;
	zval *data_param = NULL, *replaced = NULL, *_1 = NULL, _3$$3, _4$$3, *_5$$3;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_strval(data, data_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 8, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "-", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "_", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, " ", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "\x09", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "\x0a", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "\x0b", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "\x0c", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "\x0d", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "+", 1);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "/", 1);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_INIT_VAR(replaced);
	zephir_fast_str_replace(&replaced, _0, _2, data TSRMLS_CC);
	mod4 = (long) (zephir_safe_mod_long_long(zephir_fast_strlen_ev(replaced), 4 TSRMLS_CC));
	if (mod4) {
		ZEPHIR_SINIT_VAR(_3$$3);
		ZVAL_STRING(&_3$$3, "====", 0);
		ZEPHIR_SINIT_VAR(_4$$3);
		ZVAL_LONG(&_4$$3, mod4);
		ZEPHIR_INIT_VAR(_5$$3);
		zephir_substr(_5$$3, &_3$$3, zephir_get_intval(&_4$$3), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		zephir_concat_self(&replaced, _5$$3 TSRMLS_CC);
	}
	ZEPHIR_RETURN_CALL_FUNCTION("base64_decode", NULL, 25, replaced);
	zephir_check_call_status();
	RETURN_MM();

}

