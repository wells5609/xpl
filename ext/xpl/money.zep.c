
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


/**
 * Money represents a generic monetary unit.
 */
ZEPHIR_INIT_CLASS(Xpl_Money) {

	ZEPHIR_REGISTER_CLASS_EX(Xpl, Money, xpl, money, xpl_number_ce, xpl_money_method_entry, 0);

	return SUCCESS;

}

/**
 * Formats the number.
 *
 * @param int decimals
 * @return string
 */
PHP_METHOD(Xpl_Money, format) {

	zephir_fcall_cache_entry *_2 = NULL;
	zval *decimals_param = NULL, *locale = NULL, *formatter = NULL, *_3, *_0$$3, *_1$$3 = NULL;
	int decimals, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &decimals_param);

	if (!decimals_param) {
		decimals = 2;
	} else {
		decimals = zephir_get_intval(decimals_param);
	}


	ZEPHIR_CALL_METHOD(&locale, this_ptr, "getlocale", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(locale) == IS_STRING) {
		ZEPHIR_INIT_VAR(formatter);
		object_init_ex(formatter, zephir_get_internal_ce(SS("numberformatter") TSRMLS_CC));
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_LONG(_0$$3, 2);
		ZEPHIR_CALL_METHOD(NULL, formatter, "__construct", NULL, 0, locale, _0$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "asstring", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(formatter, "format", NULL, 0, _1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, decimals);
	ZEPHIR_RETURN_CALL_PARENT(xpl_money_ce, this_ptr, "format", &_2, 116, _3);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Xpl_Money, getNumberFormatter) {

	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *locale = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &locale);

	if (!locale) {
		ZEPHIR_CPY_WRT(locale, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(locale);
	}


	_0 = Z_TYPE_P(locale) == IS_NULL;
	if (!(_0)) {
		_0 = ZEPHIR_IS_EMPTY(locale);
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&locale, this_ptr, "getlocale", NULL, 0);
		zephir_check_call_status();
	}
	object_init_ex(return_value, zephir_get_internal_ce(SS("numberformatter") TSRMLS_CC));
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 2);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, locale, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Xpl_Money, getLocale) {

	zval _0, _1;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_RETURN_CALL_FUNCTION("setlocale", NULL, 117, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

