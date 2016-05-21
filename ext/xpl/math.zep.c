
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/math.h"


ZEPHIR_INIT_CLASS(Xpl_Math) {

	ZEPHIR_REGISTER_CLASS(Xpl, Math, xpl, math, xpl_math_method_entry, 0);

	/**
	 * BCMath scale.
	 *
	 * @var int
	 */
	zend_declare_class_constant_long(xpl_math_ce, SL("SCALE"), 20 TSRMLS_CC);

	return SUCCESS;

}

/**
 * Adds two numbers using bcadd()
 *
 * @param string left
 * @param string right
 * @return string
 */
PHP_METHOD(Xpl_Math, add) {

	zval *_0 = NULL, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *left, *right, _2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &left, &right);



	zephir_get_strval(_0, left);
	zephir_get_strval(_1, right);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 20);
	ZEPHIR_RETURN_CALL_FUNCTION("bcadd", NULL, 8, _0, _1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Subtracts two numbers using bcsub()
 *
 * @param string left
 * @param string right
 * @return string
 */
PHP_METHOD(Xpl_Math, subtract) {

	zval *_0 = NULL, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *left, *right, _2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &left, &right);



	zephir_get_strval(_0, left);
	zephir_get_strval(_1, right);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 20);
	ZEPHIR_RETURN_CALL_FUNCTION("bcsub", NULL, 9, _0, _1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Xpl_Math, sub) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *left, *right, _0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &left, &right);



	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 20);
	ZEPHIR_RETURN_CALL_FUNCTION("bcsub", NULL, 9, left, right, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Multiplies two numbers using bcmul()
 *
 * @param string left
 * @param string right
 * @return string
 */
PHP_METHOD(Xpl_Math, multiply) {

	zval *_0 = NULL, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *left, *right, _2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &left, &right);



	zephir_get_strval(_0, left);
	zephir_get_strval(_1, right);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 20);
	ZEPHIR_RETURN_CALL_FUNCTION("bcmul", NULL, 10, _0, _1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Xpl_Math, mul) {

	zval *_0 = NULL, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *left, *right, _2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &left, &right);



	zephir_get_strval(_0, left);
	zephir_get_strval(_1, right);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 20);
	ZEPHIR_RETURN_CALL_FUNCTION("bcmul", NULL, 10, _0, _1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Divides two numbers using bcdiv()
 *
 * @param string left
 * @param string right
 * @return string
 */
PHP_METHOD(Xpl_Math, divide) {

	zval *_0 = NULL, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *left, *right, _2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &left, &right);



	zephir_get_strval(_0, left);
	zephir_get_strval(_1, right);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 20);
	ZEPHIR_RETURN_CALL_FUNCTION("bcdiv", NULL, 11, _0, _1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Xpl_Math, div) {

	zval *_0 = NULL, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *left, *right, _2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &left, &right);



	zephir_get_strval(_0, left);
	zephir_get_strval(_1, right);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 20);
	ZEPHIR_RETURN_CALL_FUNCTION("bcdiv", NULL, 11, _0, _1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Raises a number to a power using bcpow()
 *
 * @param string left
 * @param string right
 * @return string
 */
PHP_METHOD(Xpl_Math, pow) {

	zval *_0 = NULL, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *left, *right, _2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &left, &right);



	zephir_get_strval(_0, left);
	zephir_get_strval(_1, right);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 20);
	ZEPHIR_RETURN_CALL_FUNCTION("bcpow", NULL, 12, _0, _1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the square root of a number using bcsqrt()
 *
 * @param string operand
 * @return string
 */
PHP_METHOD(Xpl_Math, sqrt) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *operand, _1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &operand);



	zephir_get_strval(_0, operand);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 20);
	ZEPHIR_RETURN_CALL_FUNCTION("bcsqrt", NULL, 13, _0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Filters out non-numbers from an array.
 *
 * @param array numbers
 * @return array
 */
PHP_METHOD(Xpl_Math, filterNumeric) {

	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *numbers_param = NULL, *num = NULL, **_2, *_3$$5 = NULL;
	zval *numbers = NULL, *filtered;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &numbers_param);

	numbers = numbers_param;


	ZEPHIR_INIT_VAR(filtered);
	array_init(filtered);
	zephir_is_iterable(numbers, &_1, &_0, 0, 0, "xpl/math.zep", 122);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(num, _2);
		if (Z_TYPE_P(num) == IS_OBJECT) {
			if (zephir_instance_of_ev(num, xpl_number_ce TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(&_3$$5, num, "asstring", NULL, 0);
				zephir_check_call_status();
				zephir_array_append(&filtered, _3$$5, PH_SEPARATE, "xpl/math.zep", 113);
			}
		} else {
			if (zephir_is_numeric(num)) {
				zephir_array_append(&filtered, num, PH_SEPARATE, "xpl/math.zep", 117);
			}
		}
	}
	RETURN_CTOR(filtered);

}

/**
 * Sums the arguments.
 *
 * @param number left
 * @param ...
 * @return string
 */
PHP_METHOD(Xpl_Math, sum) {

	HashTable *_2;
	HashPosition _1;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *left, *args = NULL, *sum = NULL, *val = NULL, *_0 = NULL, **_3, *_4$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &left);



	ZEPHIR_CALL_FUNCTION(&args, "func_get_args", NULL, 98);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(sum);
	ZVAL_LONG(sum, 0);
	ZEPHIR_CALL_SELF(&_0, "filternumeric", NULL, 0, args);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "xpl/math.zep", 143);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(val, _3);
		ZEPHIR_CALL_SELF(&_4$$3, "add", &_5, 0, sum, val);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(sum, _4$$3);
	}
	RETURN_CCTOR(sum);

}

/**
 * Sums an array of values.
 *
 * @param array values
 * @return string
 */
PHP_METHOD(Xpl_Math, arraySum) {

	HashTable *_2;
	HashPosition _1;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *values_param = NULL, *sum = NULL, *val = NULL, *_0 = NULL, **_3, *_4$$3 = NULL;
	zval *values = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &values_param);

	values = values_param;


	ZEPHIR_INIT_VAR(sum);
	ZVAL_LONG(sum, 0);
	ZEPHIR_CALL_SELF(&_0, "filternumeric", NULL, 0, values);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "xpl/math.zep", 161);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(val, _3);
		ZEPHIR_CALL_SELF(&_4$$3, "add", &_5, 0, sum, val);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(sum, _4$$3);
	}
	RETURN_CCTOR(sum);

}

/**
 * Returns the number of numeric values in the array
 *
 * @param array arg
 * @return int
 */
PHP_METHOD(Xpl_Math, count) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *values_param = NULL, *_0 = NULL;
	zval *values = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &values_param);

	values = values_param;


	ZEPHIR_CALL_SELF(&_0, "filternumeric", NULL, 0, values);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_fast_count_int(_0 TSRMLS_CC));

}

/**
 * Calculate mean (simple arithmetic average).
 *
 * @param array $values
 * @return string Mean
 */
PHP_METHOD(Xpl_Math, mean) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *values_param = NULL, *sum = NULL, *numericValues = NULL, *val = NULL, **_2, *_5, *_3$$3 = NULL;
	zval *values = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &values_param);

	values = values_param;


	ZEPHIR_INIT_VAR(sum);
	ZVAL_LONG(sum, 0);
	ZEPHIR_CALL_SELF(&numericValues, "filternumeric", NULL, 0, values);
	zephir_check_call_status();
	zephir_is_iterable(numericValues, &_1, &_0, 0, 0, "xpl/math.zep", 192);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(val, _2);
		ZEPHIR_CALL_SELF(&_3$$3, "add", &_4, 0, sum, val);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(sum, _3$$3);
	}
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, zephir_fast_count_int(numericValues TSRMLS_CC));
	ZEPHIR_RETURN_CALL_SELF("div", NULL, 0, sum, _5);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Calculate median.
 *
 * @param array $values
 * @return string Median value
 */
PHP_METHOD(Xpl_Math, median) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *vals_param = NULL, *count = NULL, *values = NULL, *halfCount = NULL, _0 = zval_used_for_init, *_1 = NULL, *_2 = NULL, *mid1 = NULL, *mid2 = NULL, _4, _5, *midRnd = NULL, _10, *_3$$3, *_6$$5 = NULL, *_7$$5, *_8$$5, *_9$$5, *_11$$6;
	zval *vals = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &vals_param);

	vals = vals_param;


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "strval", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "array_map", NULL, 44, &_0, vals);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&values, "array_values", NULL, 68, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 1);
	ZEPHIR_MAKE_REF(values);
	ZEPHIR_CALL_FUNCTION(NULL, "sort", NULL, 113, values, _2);
	ZEPHIR_UNREF(values);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(count);
	ZVAL_LONG(count, zephir_fast_count_int(values TSRMLS_CC));
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_DOUBLE(&_0, zephir_safe_div_zval_long(count, 2 TSRMLS_CC));
	ZEPHIR_INIT_VAR(halfCount);
	ZVAL_LONG(halfCount, zephir_get_intval(&_0));
	if (zephir_array_isset(values, halfCount)) {
		zephir_array_fetch(&_3$$3, values, halfCount, PH_NOISY | PH_READONLY, "xpl/math.zep", 213 TSRMLS_CC);
		RETURN_CTOR(_3$$3);
	}
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_DOUBLE(&_4, zephir_safe_div_long_long(((zephir_get_numberval(count) - 1)), 2 TSRMLS_CC));
	ZEPHIR_INIT_VAR(mid1);
	ZVAL_LONG(mid1, zephir_get_intval(&_4));
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_DOUBLE(&_5, zephir_safe_div_long_long(((zephir_get_numberval(count) + 1)), 2 TSRMLS_CC));
	ZEPHIR_INIT_VAR(mid2);
	ZVAL_LONG(mid2, zephir_get_intval(&_5));
	if (zephir_array_isset(values, mid1)) {
		if (zephir_array_isset(values, mid2)) {
			zephir_array_fetch(&_7$$5, values, mid1, PH_NOISY | PH_READONLY, "xpl/math.zep", 223 TSRMLS_CC);
			zephir_array_fetch(&_8$$5, values, mid2, PH_NOISY | PH_READONLY, "xpl/math.zep", 223 TSRMLS_CC);
			ZEPHIR_CALL_SELF(&_6$$5, "add", NULL, 0, _7$$5, _8$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_9$$5);
			ZVAL_LONG(_9$$5, 2);
			ZEPHIR_RETURN_CALL_SELF("div", NULL, 0, _6$$5, _9$$5);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	ZEPHIR_INIT_NVAR(_2);
	ZEPHIR_SINIT_VAR(_10);
	ZVAL_LONG(&_10, 0);
	zephir_round(_2, halfCount, &_10, NULL TSRMLS_CC);
	ZEPHIR_INIT_VAR(midRnd);
	ZVAL_LONG(midRnd, zephir_get_intval(_2));
	if (zephir_array_isset(values, midRnd)) {
		zephir_array_fetch(&_11$$6, values, midRnd, PH_NOISY | PH_READONLY, "xpl/math.zep", 232 TSRMLS_CC);
		RETURN_CTOR(_11$$6);
	}
	RETURN_MM_NULL();

}

/**
 * Calculate the sum of products.
 *
 * @param array x_values
 * @param array y_values
 * @return string Sum of products.
 */
PHP_METHOD(Xpl_Math, sumxy) {

	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL;
	zval *x_values_param = NULL, *y_values_param = NULL, *sum = NULL, *index = NULL, *xVal = NULL, *yVal = NULL, **_2, *_3$$4 = NULL, *_5$$4 = NULL;
	zval *x_values = NULL, *y_values = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &x_values_param, &y_values_param);

	x_values = x_values_param;
	y_values = y_values_param;


	ZEPHIR_INIT_VAR(sum);
	ZVAL_LONG(sum, 0);
	zephir_is_iterable(x_values, &_1, &_0, 0, 0, "xpl/math.zep", 258);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(index, _1, _0);
		ZEPHIR_GET_HVALUE(xVal, _2);
		ZEPHIR_OBS_NVAR(yVal);
		if (zephir_array_isset_fetch(&yVal, y_values, index, 0 TSRMLS_CC)) {
			ZEPHIR_CALL_SELF(&_5$$4, "mul", &_6, 0, xVal, yVal);
			zephir_check_call_status();
			ZEPHIR_CALL_SELF(&_3$$4, "add", &_4, 0, sum, _5$$4);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(sum, _3$$4);
		}
	}
	RETURN_CCTOR(sum);

}

/**
 * Compute the sum of squares.
 *
 * @param array values An array of values.
 * @param null|scalar|array values2 If NULL, squares each array value.
 * If scalar, squares the difference between each array value and
 *   the scalar value (good for explained/regression SS).
 * If given an array, squares the difference between betweeen each array value
 *   and the value in values2 with matching key (good for residual SS).
 * @return string Sum of all da squares.
 */
PHP_METHOD(Xpl_Math, sos) {

	HashTable *_3;
	HashPosition _2;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_13 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *values_param = NULL, *values2 = NULL, *sum = NULL, *index = NULL, *value = NULL, *val2 = NULL, **_4, *_0$$4, *_1$$4 = NULL, *_5$$6 = NULL, *_7$$6 = NULL, *_9$$6 = NULL, *_10$$8 = NULL, *_11$$8 = NULL, *_12$$8 = NULL, *_14$$8 = NULL;
	zval *values = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &values_param, &values2);

	values = values_param;
	if (!values2) {
		ZEPHIR_CPY_WRT(values2, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(values2);
	}


	if (Z_TYPE_P(values2) != IS_NULL) {
		if (Z_TYPE_P(values2) != IS_ARRAY) {
			ZEPHIR_INIT_VAR(_0$$4);
			zephir_array_keys(_0$$4, values TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_1$$4, "strval", NULL, 76, values2);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&values2, "array_fill_keys", NULL, 114, _0$$4, _1$$4);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_VAR(sum);
	ZVAL_LONG(sum, 0);
	zephir_is_iterable(values, &_3, &_2, 0, 0, "xpl/math.zep", 298);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(index, _3, _2);
		ZEPHIR_GET_HVALUE(value, _4);
		if (Z_TYPE_P(values2) == IS_NULL) {
			ZEPHIR_INIT_NVAR(_9$$6);
			ZVAL_LONG(_9$$6, 2);
			ZEPHIR_CALL_SELF(&_7$$6, "pow", &_8, 0, value, _9$$6);
			zephir_check_call_status();
			ZEPHIR_CALL_SELF(&_5$$6, "add", &_6, 0, sum, _7$$6);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(sum, _5$$6);
		} else {
			ZEPHIR_OBS_NVAR(val2);
			if (zephir_array_isset_fetch(&val2, values2, index, 0 TSRMLS_CC)) {
				ZEPHIR_CALL_SELF(&_12$$8, "sub", &_13, 0, value, val2);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_14$$8);
				ZVAL_LONG(_14$$8, 2);
				ZEPHIR_CALL_SELF(&_11$$8, "pow", &_8, 0, _12$$8, _14$$8);
				zephir_check_call_status();
				ZEPHIR_CALL_SELF(&_10$$8, "add", &_6, 0, sum, _11$$8);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(sum, _10$$8);
			}
		}
	}
	RETURN_CCTOR(sum);

}

/**
 * Calculate variance.
 *
 * @param array values
 * @param boolean is_sample Default false.
 * @return string Variance of the values.
 */
PHP_METHOD(Xpl_Math, variance) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool is_sample;
	zval *values_param = NULL, *is_sample_param = NULL, *_0$$3 = NULL, *_1$$3 = NULL, *_2$$3 = NULL, *_3$$3;
	zval *values = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &values_param, &is_sample_param);

	values = values_param;
	if (!is_sample_param) {
		is_sample = 0;
	} else {
		is_sample = zephir_get_boolval(is_sample_param);
	}


	if (is_sample) {
		ZEPHIR_CALL_SELF(&_1$$3, "mean", NULL, 0, values);
		zephir_check_call_status();
		ZEPHIR_CALL_SELF(&_0$$3, "sos", NULL, 0, values, _1$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_SELF(&_2$$3, "count", NULL, 0, values);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3$$3);
		ZVAL_LONG(_3$$3, (zephir_get_numberval(_2$$3) - 1));
		ZEPHIR_RETURN_CALL_SELF("div", NULL, 0, _0$$3, _3$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_SELF("covariance", NULL, 0, values, values);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Compute standard deviation.
 *
 * @param array a The array of data to find the standard deviation for.
 * @param bool sample [Optional] Set true if given a sample of the population (otherwise assumes data
 * is population); Defaults to false
 * @return string|bool The standard deviation or false on error.
 */
PHP_METHOD(Xpl_Math, stddev) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool sample;
	zval *values_param = NULL, *sample_param = NULL, *_0 = NULL, *_3 = NULL, *_4, _1$$3, _2$$3;
	zval *values = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &values_param, &sample_param);

	values = values_param;
	if (!sample_param) {
		sample = 0;
	} else {
		sample = zephir_get_boolval(sample_param);
	}


	ZEPHIR_CALL_SELF(&_0, "count", NULL, 0, values);
	zephir_check_call_status();
	if (unlikely(ZEPHIR_LT_LONG(_0, 2))) {
		ZEPHIR_SINIT_VAR(_1$$3);
		ZVAL_STRING(&_1$$3, "The array has too few elements", 0);
		ZEPHIR_SINIT_VAR(_2$$3);
		ZVAL_LONG(&_2$$3, 1024);
		ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 115, &_1$$3, &_2$$3);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(_4);
	if (sample) {
		ZVAL_BOOL(_4, 1);
	} else {
		ZVAL_BOOL(_4, 0);
	}
	ZEPHIR_CALL_SELF(&_3, "variance", NULL, 0, values, _4);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_SELF("sqrt", NULL, 0, _3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Calculate covariance.
 *
 * @param array x_values Dependent variable values.
 * @param array y_values Independent variable values.
 * @return string Covariance of x and y.
 */
PHP_METHOD(Xpl_Math, covariance) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *x_values_param = NULL, *y_values_param = NULL, *left = NULL, *right = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL;
	zval *x_values = NULL, *y_values = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &x_values_param, &y_values_param);

	x_values = x_values_param;
	y_values = y_values_param;


	ZEPHIR_CALL_SELF(&_0, "sumxy", NULL, 0, x_values, y_values);
	zephir_check_call_status();
	ZEPHIR_CALL_SELF(&_1, "count", NULL, 0, x_values);
	zephir_check_call_status();
	ZEPHIR_CALL_SELF(&left, "div", NULL, 0, _0, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_SELF(&_2, "mean", NULL, 0, x_values);
	zephir_check_call_status();
	ZEPHIR_CALL_SELF(&_3, "mean", NULL, 0, y_values);
	zephir_check_call_status();
	ZEPHIR_CALL_SELF(&right, "mul", NULL, 0, _2, _3);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_SELF("sub", NULL, 0, left, right);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Compute correlation.
 *
 * @param array x_values
 * @param array y_values
 * @return string Correlation
 */
PHP_METHOD(Xpl_Math, correlation) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *x_values_param = NULL, *y_values_param = NULL, *sdxy = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL;
	zval *x_values = NULL, *y_values = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &x_values_param, &y_values_param);

	x_values = x_values_param;
	y_values = y_values_param;


	ZEPHIR_INIT_VAR(_1);
	ZVAL_BOOL(_1, 1);
	ZEPHIR_CALL_SELF(&_0, "stddev", NULL, 0, x_values, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_BOOL(_1, 1);
	ZEPHIR_CALL_SELF(&_2, "stddev", NULL, 0, y_values, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_SELF(&sdxy, "mul", NULL, 0, _0, _2);
	zephir_check_call_status();
	ZEPHIR_CALL_SELF(&_3, "covariance", NULL, 0, x_values, y_values);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_SELF("div", NULL, 0, _3, sdxy);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the present value of a cashflow.
 *
 * @param int|float|string cashflow Numeric quantity of currency.
 * @param float|string rate Discount rate
 * @param int|float|string period A number representing time period in which the
 * cash flow occurs. e.g. for an annual cashflow, start a 0 and increase by 1
 * each year (e.g. [Year] 0, [Year] 1, ...)
 * @return string Present value of the cash flow.
 */
PHP_METHOD(Xpl_Math, pv) {

	int period, ZEPHIR_LAST_CALL_STATUS;
	zval *cashflow_param = NULL, *rate_param = NULL, *period_param = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL;
	zval *cashflow = NULL, *rate = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &cashflow_param, &rate_param, &period_param);

	zephir_get_strval(cashflow, cashflow_param);
	zephir_get_strval(rate, rate_param);
	if (!period_param) {
		period = 0;
	} else {
		period = zephir_get_intval(period_param);
	}


	if (period < 1) {
		RETURN_CTOR(cashflow);
	}
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 1);
	ZEPHIR_CALL_SELF(&_1, "add", NULL, 0, rate, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, period);
	ZEPHIR_CALL_SELF(&_0, "pow", NULL, 0, _1, _2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_SELF("div", NULL, 0, cashflow, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the Net Present Value of a series of cashflows.
 *
 * @param array cashflows Indexed array of cash flows.
 * @param number rate Discount rate applied.
 * @return string NPV of cashflows discounted at rate.
 */
PHP_METHOD(Xpl_Math, npv) {

	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL;
	zval *rate = NULL;
	zval *cashflows_param = NULL, *rate_param = NULL, *npv = NULL, *idx = NULL, *cf = NULL, **_2, *_3$$3 = NULL, *_5$$3 = NULL;
	zval *cashflows = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &cashflows_param, &rate_param);

	zephir_get_arrval(cashflows, cashflows_param);
	zephir_get_strval(rate, rate_param);


	ZEPHIR_INIT_VAR(npv);
	ZVAL_LONG(npv, 0);
	zephir_is_iterable(cashflows, &_1, &_0, 0, 0, "xpl/math.zep", 403);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(idx, _1, _0);
		ZEPHIR_GET_HVALUE(cf, _2);
		ZEPHIR_CALL_SELF(&_5$$3, "pv", &_6, 0, cf, rate, idx);
		zephir_check_call_status();
		ZEPHIR_CALL_SELF(&_3$$3, "add", &_4, 0, npv, _5$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(npv, _3$$3);
	}
	RETURN_CCTOR(npv);

}

/**
 * Returns the weighted average of a series of values.
 *
 * @param array values Indexed array of values.
 * @param array weights Indexed array of weights corresponding to each value.
 * @return string Weighted average of values.
 */
PHP_METHOD(Xpl_Math, weightedAvg) {

	HashTable *_4;
	HashPosition _3;
	zephir_fcall_cache_entry *_7 = NULL, *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *values_param = NULL, *weights_param = NULL, _0$$3, _1$$3, *sum = NULL, *idx = NULL, *val = NULL, *_2 = NULL, **_5, *_11 = NULL, *_6$$4 = NULL, *_8$$4 = NULL, *_10$$4;
	zval *values = NULL, *weights = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &values_param, &weights_param);

	zephir_get_arrval(values, values_param);
	zephir_get_arrval(weights, weights_param);


	if (zephir_fast_count_int(values TSRMLS_CC) != zephir_fast_count_int(weights TSRMLS_CC)) {
		ZEPHIR_SINIT_VAR(_0$$3);
		ZVAL_STRING(&_0$$3, "Must pass the same number of weights and values.", 0);
		ZEPHIR_SINIT_VAR(_1$$3);
		ZVAL_LONG(&_1$$3, 1024);
		ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 115, &_0$$3, &_1$$3);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(sum);
	ZVAL_LONG(sum, 0);
	ZEPHIR_CALL_FUNCTION(&_2, "array_values", NULL, 68, values);
	zephir_check_call_status();
	zephir_is_iterable(_2, &_4, &_3, 0, 0, "xpl/math.zep", 428);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HMKEY(idx, _4, _3);
		ZEPHIR_GET_HVALUE(val, _5);
		zephir_array_fetch(&_10$$4, weights, idx, PH_NOISY | PH_READONLY, "xpl/math.zep", 425 TSRMLS_CC);
		ZEPHIR_CALL_SELF(&_8$$4, "mul", &_9, 0, val, _10$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_SELF(&_6$$4, "add", &_7, 0, sum, _8$$4);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(sum, _6$$4);
	}
	ZEPHIR_CALL_SELF(&_11, "arraysum", NULL, 0, weights);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_SELF("div", NULL, 0, sum, _11);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the % of an amount of the total.
 *
 * e.g. for operating margin, use operating income as 1st arg, revenue as 2nd.
 * e.g. for capex as a % of sales, use capex as 1st arg, revenue as 2nd.
 *
 * @param number portion An amount, a portion of the total.
 * @param number total The total amount.
 * @return string
 */
PHP_METHOD(Xpl_Math, pct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *portion, *total;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &portion, &total);



	ZEPHIR_RETURN_CALL_SELF("div", NULL, 0, portion, total);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the % change between two values.
 *
 * @param number current The current value.
 * @param number previous The previous value.
 * @return string Percent change from previous to current.
 */
PHP_METHOD(Xpl_Math, pctChange) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *current, *previous, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &current, &previous);



	ZEPHIR_CALL_SELF(&_0, "sub", NULL, 0, current, previous);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_SELF("div", NULL, 0, _0, previous);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Convert an array of values to % change.
 *
 * @param array values Raw values ordered from oldest to newest.
 * @return array Array of the % change between values.
 */
PHP_METHOD(Xpl_Math, pctChangeArray) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *vals_param = NULL, *percents = NULL, *keys = NULL, *values = NULL, *index = NULL, *val = NULL, *prev = NULL, **_2, *_3$$5 = NULL, *_4$$6 = NULL, *_6$$6 = NULL;
	zval *vals = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &vals_param);

	zephir_get_arrval(vals, vals_param);


	ZEPHIR_INIT_VAR(percents);
	array_init(percents);
	ZEPHIR_INIT_VAR(keys);
	zephir_array_keys(keys, vals TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&values, "array_values", NULL, 68, vals);
	zephir_check_call_status();
	zephir_is_iterable(values, &_1, &_0, 0, 0, "xpl/math.zep", 486);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(index, _1, _0);
		ZEPHIR_GET_HVALUE(val, _2);
		if (!ZEPHIR_IS_LONG_IDENTICAL(index, 0)) {
			ZEPHIR_OBS_NVAR(prev);
			zephir_array_fetch_long(&prev, values, ((zephir_get_numberval(index) - 1)), PH_NOISY, "xpl/math.zep", 476 TSRMLS_CC);
			if (ZEPHIR_IS_LONG(prev, 0)) {
				ZEPHIR_INIT_NVAR(_3$$5);
				ZVAL_LONG(_3$$5, 0);
				zephir_array_update_zval(&percents, index, &_3$$5, PH_COPY | PH_SEPARATE);
			} else {
				ZEPHIR_CALL_SELF(&_6$$6, "sub", &_7, 0, val, prev);
				zephir_check_call_status();
				ZEPHIR_CALL_SELF(&_4$$6, "div", &_5, 0, _6$$6, prev);
				zephir_check_call_status();
				zephir_array_update_zval(&percents, index, &_4$$6, PH_COPY | PH_SEPARATE);
			}
		}
	}
	ZEPHIR_MAKE_REF(keys);
	ZEPHIR_CALL_FUNCTION(NULL, "array_shift", NULL, 103, keys);
	ZEPHIR_UNREF(keys);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("array_combine", NULL, 45, keys, percents);
	zephir_check_call_status();
	RETURN_MM();

}

