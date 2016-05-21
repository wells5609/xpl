
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Xpl_Rate) {

	ZEPHIR_REGISTER_CLASS_EX(Xpl, Rate, xpl, rate, xpl_number_ce, xpl_rate_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Xpl_Rate, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *number, *precision = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &number, &precision);

	if (!precision) {
		precision = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_SELF(&_1, "parsepercent", NULL, 0, number);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, xpl_rate_ce, this_ptr, "__construct", &_0, 128, _1, precision);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Xpl_Rate, format) {

	zephir_fcall_cache_entry *_1 = NULL;
	zend_bool appendPctSign;
	zval *decimals_param = NULL, *appendPctSign_param = NULL, *formatted = NULL, *_0 = NULL, *_2, *_3, _4;
	int decimals, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &decimals_param, &appendPctSign_param);

	if (!decimals_param) {
		decimals = 2;
	} else {
		decimals = zephir_get_intval(decimals_param);
	}
	if (!appendPctSign_param) {
		appendPctSign = 1;
	} else {
		appendPctSign = zephir_get_boolval(appendPctSign_param);
	}


	_2 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 100);
	ZEPHIR_CALL_CE_STATIC(&_0, xpl_math_ce, "mul", &_1, 129, _2, _3);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, decimals);
	ZEPHIR_CALL_FUNCTION(&formatted, "number_format", NULL, 6, _0, &_4);
	zephir_check_call_status();
	if (appendPctSign == 1) {
		zephir_concat_self_str(&formatted, SL("%") TSRMLS_CC);
	}
	RETURN_CCTOR(formatted);

}

PHP_METHOD(Xpl_Rate, parsePercent) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *number, _0$$3, *_1$$3, *_3$$4, _4$$4, *_5$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &number);



	if (Z_TYPE_P(number) == IS_STRING) {
		ZEPHIR_SINIT_VAR(_0$$3);
		ZVAL_LONG(&_0$$3, -1);
		ZEPHIR_INIT_VAR(_1$$3);
		zephir_substr(_1$$3, number, -1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		if (ZEPHIR_IS_STRING_IDENTICAL(_1$$3, "%")) {
			ZEPHIR_INIT_VAR(_3$$4);
			ZEPHIR_SINIT_VAR(_4$$4);
			ZVAL_STRING(&_4$$4, "%", 0);
			zephir_fast_trim(_3$$4, number, &_4$$4, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
			ZEPHIR_INIT_VAR(_5$$4);
			ZVAL_LONG(_5$$4, 100);
			ZEPHIR_RETURN_CALL_CE_STATIC(xpl_math_ce, "div", &_2, 130, _3$$4, _5$$4);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	RETVAL_ZVAL(number, 1, 0);
	RETURN_MM();

}

