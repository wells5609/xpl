
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/math.h"


ZEPHIR_INIT_CLASS(Xpl_Number) {

	ZEPHIR_REGISTER_CLASS(Xpl, Number, xpl, number, xpl_number_method_entry, 0);

	/**
	 * @var number
	 */
	zend_declare_property_null(xpl_number_ce, SL("value"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var integer
	 */
	zend_declare_property_null(xpl_number_ce, SL("precision"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var int
	 */
	zend_declare_class_constant_long(xpl_number_ce, SL("PRECISION"), 128 TSRMLS_CC);

	return SUCCESS;

}

/**
 * Constructor.
 *
 * @param number number
 *
 * @throws InvalidArgumentException if argument is not numeric or instance of Number.
 */
PHP_METHOD(Xpl_Number, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *number, *precision = NULL, *_0$$4 = NULL, *_1$$5, *_2$$5, *_3$$5, *_4$$7, _5$$7, *_6$$7, *_7$$8, *_8$$8, *_9$$8, *_10$$9, *_11$$10;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &number, &precision);

	if (!precision) {
		precision = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(number) == IS_OBJECT) {
		if (zephir_instance_of_ev(number, xpl_number_ce TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(&_0$$4, number, "asstring", NULL, 0);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("value"), _0$$4 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(_1$$5);
			object_init_ex(_1$$5, spl_ce_InvalidArgumentException);
			ZEPHIR_INIT_VAR(_2$$5);
			zephir_get_class(_2$$5, number, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_3$$5);
			ZEPHIR_CONCAT_SV(_3$$5, "Object must be instance of Number, given: ", _2$$5);
			ZEPHIR_CALL_METHOD(NULL, _1$$5, "__construct", NULL, 5, _3$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_1$$5, "xpl/number.zep", 36 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		if (zephir_is_numeric(number)) {
			ZEPHIR_INIT_VAR(_4$$7);
			ZEPHIR_SINIT_VAR(_5$$7);
			ZVAL_LONG(&_5$$7, 0);
			zephir_fast_trim(_4$$7, number, &_5$$7, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
			ZEPHIR_INIT_VAR(_6$$7);
			ZEPHIR_CONCAT_VS(_6$$7, _4$$7, "0");
			zephir_update_property_this(this_ptr, SL("value"), _6$$7 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(_7$$8);
			object_init_ex(_7$$8, spl_ce_InvalidArgumentException);
			ZEPHIR_INIT_VAR(_8$$8);
			zephir_gettype(_8$$8, number TSRMLS_CC);
			ZEPHIR_INIT_VAR(_9$$8);
			ZEPHIR_CONCAT_SV(_9$$8, "Argument must be numeric, given: ", _8$$8);
			ZEPHIR_CALL_METHOD(NULL, _7$$8, "__construct", NULL, 5, _9$$8);
			zephir_check_call_status();
			zephir_throw_exception_debug(_7$$8, "xpl/number.zep", 42 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (Z_TYPE_P(precision) == IS_NULL) {
		ZEPHIR_INIT_ZVAL_NREF(_10$$9);
		ZVAL_LONG(_10$$9, 128);
		zephir_update_property_this(this_ptr, SL("precision"), _10$$9 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_11$$10);
		ZVAL_LONG(_11$$10, zephir_get_intval(precision));
		zephir_update_property_this(this_ptr, SL("precision"), _11$$10 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the number of digits to use after the decimal.
 *
 * @return int
 */
PHP_METHOD(Xpl_Number, getPrecision) {

	

	RETURN_MEMBER(this_ptr, "precision");

}

/**
 * Sets the number of digits to the right of the decimal.
 *
 * @param int digits
 */
PHP_METHOD(Xpl_Number, setPrecision) {

	zval *digits_param = NULL, *_0;
	int digits;

	zephir_fetch_params(0, 1, 0, &digits_param);

	if (unlikely(Z_TYPE_P(digits_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'digits' must be a int") TSRMLS_CC);
		RETURN_NULL();
	}
	digits = Z_LVAL_P(digits_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, digits);
	zephir_update_property_this(this_ptr, SL("precision"), _0 TSRMLS_CC);

}

/**
 * Returns the number as a floating point number.
 *
 * @return float
 */
PHP_METHOD(Xpl_Number, asFloat) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("value"), PH_NOISY_CC);
	RETURN_MM_DOUBLE(zephir_get_doubleval(_0));

}

/**
 * Returns the number as a double.
 *
 * @return double
 */
PHP_METHOD(Xpl_Number, asDouble) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("value"), PH_NOISY_CC);
	RETURN_MM_DOUBLE(zephir_get_doubleval(_0));

}

/**
 * Returns the number as an integer
 *
 * @return int
 */
PHP_METHOD(Xpl_Number, asInt) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("value"), PH_NOISY_CC);
	RETURN_MM_LONG(zephir_get_intval(_0));

}

/**
 * Returns the number as an integer
 *
 * @return int
 */
PHP_METHOD(Xpl_Number, asInteger) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("value"), PH_NOISY_CC);
	RETURN_MM_LONG(zephir_get_intval(_0));

}

/**
 * Returns the number as a string.
 *
 * @return string
 */
PHP_METHOD(Xpl_Number, asString) {

	

	RETURN_MEMBER(this_ptr, "value");

}

/**
 * Returns the number as a string.
 *
 * @return string
 */
PHP_METHOD(Xpl_Number, __toString) {

	

	RETURN_MEMBER(this_ptr, "value");

}

/**
 * Returns the number as a string or integer.
 *
 * @return string|int
 */
PHP_METHOD(Xpl_Number, safe) {

	zval *_0, *_1 = NULL, *_2;
	int ZEPHIR_LAST_CALL_STATUS, integerValue = 0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("value"), PH_NOISY_CC);
	integerValue = zephir_get_intval(_0);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, integerValue);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "cmp", NULL, 0, _2);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG_IDENTICAL(_1, 0)) {
		RETURN_MM_LONG(integerValue);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "display", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the number with the least amount of formatting suitable for display.
 *
 * @return string
 */
PHP_METHOD(Xpl_Number, display) {

	

	RETURN_MEMBER(this_ptr, "value");

}

/**
 * Applies the number_format() function to the number.
 *
 * @param int decimals
 * @return string
 */
PHP_METHOD(Xpl_Number, format) {

	zval *decimals_param = NULL, *_0, _1;
	int decimals, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &decimals_param);

	decimals = zephir_get_intval(decimals_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, decimals);
	ZEPHIR_RETURN_CALL_FUNCTION("number_format", NULL, 6, _0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Compares a given number to this number.
 *
 * @param mixed number
 * @return int
 */
PHP_METHOD(Xpl_Number, cmp) {

	zval *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *number, *_0, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &number);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	zephir_get_strval(_1, number);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("precision"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("bccomp", NULL, 7, _0, _1, _2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Checks whether the given number is equal to this one.
 *
 * Unlike a "===" comparison in PHP, the argument type does not need to match.
 * Only the value of the numbers must be equal for this method to return true.
 *
 * @param mixed number
 * @return boolean
 */
PHP_METHOD(Xpl_Number, equals) {

	zval *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *number, *_0, *_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &number);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	zephir_get_strval(_1, number);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("precision"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_3, "bccomp", NULL, 7, _0, _1, _2);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG_IDENTICAL(_3, 0));

}

/**
 * Adds a number to this one and returns a new instance.
 *
 * @param mixed number
 *
 * @return \Xpl\Number
 */
PHP_METHOD(Xpl_Number, add) {

	zval *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *number, *_0, *_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &number);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	zephir_get_strval(_1, number);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("precision"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_3, "bcadd", NULL, 8, _0, _1, _2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newinstance", NULL, 0, _3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Subtracts a number from this one and returns a new instance.
 *
 * @param mixed number
 *
 * @return \Xpl\Number
 */
PHP_METHOD(Xpl_Number, sub) {

	zval *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *number, *_0, *_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &number);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	zephir_get_strval(_1, number);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("precision"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_3, "bcsub", NULL, 9, _0, _1, _2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newinstance", NULL, 0, _3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Multiplies a number by this one and returns a new instance.
 *
 * @param mixed number
 *
 * @return \Xpl\Number
 */
PHP_METHOD(Xpl_Number, mul) {

	zval *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *number, *_0, *_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &number);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	zephir_get_strval(_1, number);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("precision"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_3, "bcmul", NULL, 10, _0, _1, _2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newinstance", NULL, 0, _3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Divides by the given number and returns a new instance.
 *
 * @param mixed number
 *
 * @return \Xpl\Number
 */
PHP_METHOD(Xpl_Number, div) {

	zval *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *number, *_0, *_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &number);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	zephir_get_strval(_1, number);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("precision"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_3, "bcdiv", NULL, 11, _0, _1, _2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newinstance", NULL, 0, _3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Raises the number to a given exponent and returns a new instance.
 *
 * @param mixed exponent
 *
 * @return \Xpl\Number
 */
PHP_METHOD(Xpl_Number, pow) {

	zval *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *exponent, *_0, *_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &exponent);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	zephir_get_strval(_1, exponent);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("precision"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_3, "bcpow", NULL, 12, _0, _1, _2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newinstance", NULL, 0, _3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Computes the square root of the number and returns a new instance.
 *
 * @return \Xpl\Number
 */
PHP_METHOD(Xpl_Number, sqrt) {

	zval *_0, *_1, *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("precision"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_2, "bcsqrt", NULL, 13, _0, _1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newinstance", NULL, 0, _2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Creates a new instance of the late-bound class from the given value.
 *
 * @param mixed number
 * @param int precision [Optional]
 *
 * @return \Xpl\Number
 */
PHP_METHOD(Xpl_Number, create) {

	zend_class_entry *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *number, *precision = NULL, *calledClass = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &number, &precision);

	if (!precision) {
		precision = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(calledClass);
	zephir_get_called_class(calledClass TSRMLS_CC);
	zephir_fetch_safe_class(_0, calledClass);
		_1 = zend_fetch_class(Z_STRVAL_P(_0), Z_STRLEN_P(_0), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(return_value, _1);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, number, precision);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * Casts a numeric value to an int or float.
 *
 * @param string|int|float number
 * @return int|float
 */
PHP_METHOD(Xpl_Number, cast) {

	double floated = 0, floored = 0;
	zval *number;

	zephir_fetch_params(0, 1, 0, &number);



	floated = zephir_get_doubleval(number);
	floored = zephir_floor(number TSRMLS_CC);
	if (floated == floored) {
		RETURN_LONG(zephir_get_intval(number));
	}
	RETURN_DOUBLE(floated);

}

/**
 * Checks whether the given number is a non-integer.
 *
 * @param mixed
 * @return boolean
 */
PHP_METHOD(Xpl_Number, isMixedNumber) {

	double floated = 0, floored = 0;
	zval *number;

	zephir_fetch_params(0, 1, 0, &number);



	floated = zephir_get_doubleval(number);
	floored = zephir_floor(number TSRMLS_CC);
	RETURN_BOOL(floated != floored);

}

/**
 * Returns a new instance of the current class.
 */
PHP_METHOD(Xpl_Number, newInstance) {

	zend_class_entry *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *number_param = NULL, *thisClass = NULL, *_0 = NULL, *_2;
	zval *number = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &number_param);

	zephir_get_strval(number, number_param);


	ZEPHIR_INIT_VAR(thisClass);
	zephir_get_class(thisClass, this_ptr, 0 TSRMLS_CC);
	zephir_fetch_safe_class(_0, thisClass);
		_1 = zend_fetch_class(Z_STRVAL_P(_0), Z_STRLEN_P(_0), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(return_value, _1);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("precision"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, number, _2);
		zephir_check_call_status();
	}
	RETURN_MM();

}

