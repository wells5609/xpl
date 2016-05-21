
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
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/math.h"
#include "kernel/string.h"


/**
 * Provides utilities to cast PHP variables to other types.
 */
ZEPHIR_INIT_CLASS(Xpl_Type) {

	ZEPHIR_REGISTER_CLASS(Xpl, Type, xpl, type, xpl_type_method_entry, 0);

	/**
	 * The locale-dependent decimal point character.
	 *
	 * @var string
	 */
	zend_declare_property_null(xpl_type_ce, SL("decimalPoint"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_class_constant_long(xpl_type_ce, SL("CAST_NUMERIC"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(xpl_type_ce, SL("FORCE_STRING"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(xpl_type_ce, SL("IGNORE_ERROR"), 5 TSRMLS_CC);

	return SUCCESS;

}

/**
 * Returns an iterator for the given argument.
 *
 * @param mixed arg
 *
 * @throws \InvalidArgumentException if not given an array or object.
 *
 * @return array|\Traversable
 */
PHP_METHOD(Xpl_Type, iterate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *argument, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &argument);



	if (Z_TYPE_P(argument) == IS_ARRAY) {
		RETVAL_ZVAL(argument, 1, 0);
		RETURN_MM();
	}
	if (zephir_zval_is_traversable(argument TSRMLS_CC)) {
		RETVAL_ZVAL(argument, 1, 0);
		RETURN_MM();
	}
	if (Z_TYPE_P(argument) == IS_OBJECT) {
		if ((zephir_method_exists_ex(argument, SS("toarray") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_RETURN_CALL_METHOD(argument, "toarray", NULL, 0);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_RETURN_CALL_FUNCTION("get_object_vars", NULL, 62, argument);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, spl_ce_InvalidArgumentException);
	ZEPHIR_INIT_VAR(_1);
	zephir_gettype(_1, argument TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SV(_2, "Cannot get iterator from type: ", _1);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 5, _2);
	zephir_check_call_status();
	zephir_throw_exception_debug(_0, "xpl/type.zep", 50 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Converts a value to an array.
 *
 * @param mixed
 *
 * @return array
 */
PHP_METHOD(Xpl_Type, toArray) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *arg;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arg);



	if (Z_TYPE_P(arg) == IS_ARRAY) {
		RETVAL_ZVAL(arg, 1, 0);
		RETURN_MM();
	}
	if (Z_TYPE_P(arg) == IS_OBJECT) {
		if ((zephir_method_exists_ex(arg, SS("toarray") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_RETURN_CALL_METHOD(arg, "toarray", NULL, 0);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (zephir_zval_is_traversable(arg TSRMLS_CC)) {
			ZEPHIR_RETURN_CALL_FUNCTION("iterator_to_array", NULL, 14, arg);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_RETURN_CALL_FUNCTION("get_object_vars", NULL, 62, arg);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_get_arrval(_0, arg);
	RETURN_CTOR(_0);

}

/**
 * Converts a value to an object
 *
 * @param mixed
 *
 * @return object
 */
PHP_METHOD(Xpl_Type, toObject) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *arg, *_0$$3 = NULL, *_1$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arg);



	if (Z_TYPE_P(arg) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_0$$3);
		if (zephir_instance_of_ev(arg, zend_standard_class_def TSRMLS_CC)) {
			ZEPHIR_CPY_WRT(_0$$3, arg);
		} else {
			ZEPHIR_CALL_SELF(&_1$$3, "toarray", NULL, 0, arg);
			zephir_check_call_status();
			zephir_convert_to_object(_1$$3);
			ZEPHIR_CPY_WRT(_0$$3, _1$$3);
		}
		RETURN_CCTOR(_0$$3);
	}
	zephir_convert_to_object(arg);
	RETVAL_ZVAL(arg, 1, 0);
	RETURN_MM();

}

/**
 * Converts a value to arrays recursively.
 *
 * Objects and arrays are converted to arrays.
 *
 * @param mixed
 *
 * @return array
 */
PHP_METHOD(Xpl_Type, toArrays) {

	zend_bool _4$$3;
	HashTable *_2;
	HashPosition _1;
	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *arg, *arr = NULL, *key = NULL, *value = NULL, *_0 = NULL, **_3, *_5$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arg);



	ZEPHIR_INIT_VAR(arr);
	array_init(arr);
	ZEPHIR_CALL_SELF(&_0, "toarray", NULL, 0, arg);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "xpl/type.zep", 122);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		_4$$3 = Z_TYPE_P(value) == IS_ARRAY;
		if (!(_4$$3)) {
			_4$$3 = Z_TYPE_P(value) == IS_OBJECT;
		}
		if (_4$$3) {
			ZEPHIR_CALL_SELF(&_5$$4, "toarrays", &_6, 0, value);
			zephir_check_call_status();
			zephir_array_update_zval(&arr, key, &_5$$4, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_zval(&arr, key, &value, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(arr);

}

/**
 * Converts a value to objects recursively.
 *
 * Objects and arrays are converted to instances of stdClass.
 *
 * @param mixed
 *
 * @return object
 */
PHP_METHOD(Xpl_Type, toObjects) {

	zend_bool _4$$3;
	HashTable *_2;
	HashPosition _1;
	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *arg, *arr = NULL, *key = NULL, *value = NULL, *_0 = NULL, **_3, *_5$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arg);



	ZEPHIR_INIT_VAR(arr);
	array_init(arr);
	ZEPHIR_CALL_SELF(&_0, "toarray", NULL, 0, arg);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "xpl/type.zep", 149);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		_4$$3 = Z_TYPE_P(value) == IS_ARRAY;
		if (!(_4$$3)) {
			_4$$3 = Z_TYPE_P(value) == IS_OBJECT;
		}
		if (_4$$3) {
			ZEPHIR_CALL_SELF(&_5$$4, "toobjects", &_6, 0, value);
			zephir_check_call_status();
			zephir_array_update_zval(&arr, key, &_5$$4, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_zval(&arr, key, &value, PH_COPY | PH_SEPARATE);
		}
	}
	zephir_convert_to_object(arr);
	RETURN_CCTOR(arr);

}

/**
 * Casts a variable to its "natural" type.
 *
 * This function will:
 *   - Convert numeric strings to integer or float
 *   - Convert boolean strings to bool
 *   - Return the given variable if neither of these two conditions match.
 *
 * @param mixed variable
 *
 * @return mixed
 */
PHP_METHOD(Xpl_Type, natcast) {

	double floated = 0, floored = 0;
	zval *variable, *_0$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &variable);



	if (Z_TYPE_P(variable) == IS_STRING) {
		if (zephir_is_numeric(variable)) {
			floated = zephir_get_doubleval(variable);
			floored = zephir_floor(variable TSRMLS_CC);
			if (floated != floored) {
				RETURN_MM_DOUBLE(floated);
			}
			RETURN_MM_LONG(zephir_get_intval(variable));
		}
		ZEPHIR_INIT_VAR(_0$$3);
		zephir_fast_strtolower(_0$$3, variable);
		do {
			if (ZEPHIR_IS_STRING(_0$$3, "n") || ZEPHIR_IS_STRING(_0$$3, "no") || ZEPHIR_IS_STRING(_0$$3, "false") || ZEPHIR_IS_STRING(_0$$3, "off")) {
				RETURN_MM_BOOL(0);
			}
			if (ZEPHIR_IS_STRING(_0$$3, "y") || ZEPHIR_IS_STRING(_0$$3, "yes") || ZEPHIR_IS_STRING(_0$$3, "true") || ZEPHIR_IS_STRING(_0$$3, "on")) {
				RETURN_MM_BOOL(1);
			}
			if (ZEPHIR_IS_STRING(_0$$3, "null")) {
				RETURN_MM_NULL();
			}
		} while(0);

	}
	RETVAL_ZVAL(variable, 1, 0);
	RETURN_MM();

}

/**
 * Converts a variable to a boolean value
 *
 * @param mixed arg
 * @return boolean
 */
PHP_METHOD(Xpl_Type, toBool) {

	zend_bool _1$$5, _2$$5, _3$$5, _4$$5, _5$$5, _6$$5;
	zval *arg = NULL, *_0$$5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arg);

	ZEPHIR_SEPARATE_PARAM(arg);


	if (Z_TYPE_P(arg) == IS_BOOL) {
		RETVAL_ZVAL(arg, 1, 0);
		RETURN_MM();
	}
	if (zephir_is_numeric(arg)) {
		RETURN_MM_BOOL(ZEPHIR_GT_LONG(arg, 0));
	}
	if (Z_TYPE_P(arg) == IS_STRING) {
		ZEPHIR_INIT_VAR(_0$$5);
		zephir_fast_strtolower(_0$$5, arg);
		ZEPHIR_CPY_WRT(arg, _0$$5);
		_1$$5 = ZEPHIR_IS_STRING_IDENTICAL(arg, "n");
		if (!(_1$$5)) {
			_1$$5 = ZEPHIR_IS_STRING_IDENTICAL(arg, "no");
		}
		_2$$5 = _1$$5;
		if (!(_2$$5)) {
			_2$$5 = ZEPHIR_IS_STRING_IDENTICAL(arg, "false");
		}
		_3$$5 = _2$$5;
		if (!(_3$$5)) {
			_3$$5 = ZEPHIR_IS_STRING_IDENTICAL(arg, "off");
		}
		if (_3$$5) {
			RETURN_MM_BOOL(0);
		}
		_4$$5 = ZEPHIR_IS_STRING_IDENTICAL(arg, "y");
		if (!(_4$$5)) {
			_4$$5 = ZEPHIR_IS_STRING_IDENTICAL(arg, "yes");
		}
		_5$$5 = _4$$5;
		if (!(_5$$5)) {
			_5$$5 = ZEPHIR_IS_STRING_IDENTICAL(arg, "true");
		}
		_6$$5 = _5$$5;
		if (!(_6$$5)) {
			_6$$5 = ZEPHIR_IS_STRING_IDENTICAL(arg, "on");
		}
		if (_6$$5) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(zephir_get_boolval(arg));

}

/**
 * Convert value to a scalar value.
 *
 * @param string Value we"d like to be scalar.
 * @param int $flags SCALAR_* flag bitwise mask.
 * @return string
 * @throws InvalidArgumentException if value can not be scalarized.
 */
PHP_METHOD(Xpl_Type, toScalar) {

	zval *_3$$4 = NULL;
	int flags, ZEPHIR_LAST_CALL_STATUS;
	zval *arg, *flags_param = NULL, *_0, *_6, *_7, *_8, *_1$$3 = NULL, *_2$$4 = NULL, *_4$$5 = NULL, *_5$$9;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &arg, &flags_param);

	if (!flags_param) {
		flags = 0;
	} else {
		flags = zephir_get_intval(flags_param);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_gettype(_0, arg TSRMLS_CC);
	do {
		if (ZEPHIR_IS_STRING(_0, "string")) {
			ZEPHIR_INIT_VAR(_1$$3);
			if ((flags & 0)) {
				ZEPHIR_CALL_SELF(&_1$$3, "tonumber", NULL, 0, arg);
				zephir_check_call_status();
			} else {
				ZEPHIR_CPY_WRT(_1$$3, arg);
			}
			RETURN_CCTOR(_1$$3);
		}
		if (ZEPHIR_IS_STRING(_0, "double") || ZEPHIR_IS_STRING(_0, "integer")) {
			ZEPHIR_INIT_VAR(_2$$4);
			if ((flags & 1)) {
				zephir_get_strval(_3$$4, arg);
				ZEPHIR_CPY_WRT(_2$$4, _3$$4);
			} else {
				ZEPHIR_CPY_WRT(_2$$4, arg);
			}
			RETURN_CCTOR(_2$$4);
		}
		if (ZEPHIR_IS_STRING(_0, "boolean")) {
			ZEPHIR_INIT_VAR(_4$$5);
			if ((flags & 1)) {
				if (zephir_is_true(arg)) {
					ZVAL_LONG(_4$$5, 1);
				} else {
					ZVAL_STRING(_4$$5, "", 1);
				}
			} else {
				if (zephir_is_true(arg)) {
					ZEPHIR_INIT_NVAR(_4$$5);
					ZVAL_LONG(_4$$5, 1);
				} else {
					ZEPHIR_INIT_NVAR(_4$$5);
					ZVAL_LONG(_4$$5, 0);
				}
			}
			RETURN_CCTOR(_4$$5);
		}
		if (ZEPHIR_IS_STRING(_0, "NULL")) {
			RETURN_MM_STRING("", 1);
		}
		if (ZEPHIR_IS_STRING(_0, "object")) {
			if (zephir_instance_of_ev(arg, zend_standard_class_def TSRMLS_CC)) {
				if ((0 == 0)) {
					ZEPHIR_OBS_VAR(_5$$9);
					zephir_read_property(&_5$$9, arg, SL("scalar"), PH_NOISY_CC);
					RETURN_CCTOR(_5$$9);
				}
			}
			if ((zephir_method_exists_ex(arg, SS("__tostring") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_RETURN_CALL_FUNCTION("strval", NULL, 76, arg);
				zephir_check_call_status();
				RETURN_MM();
			}
		}
	} while(0);

	if ((flags & 5)) {
		RETURN_MM_STRING("", 1);
	}
	ZEPHIR_INIT_VAR(_6);
	object_init_ex(_6, spl_ce_InvalidArgumentException);
	ZEPHIR_INIT_VAR(_7);
	zephir_gettype(_7, arg TSRMLS_CC);
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_CONCAT_SVS(_8, "Cannot cast value to scalar (given: '", _7, "').");
	ZEPHIR_CALL_METHOD(NULL, _6, "__construct", NULL, 5, _8);
	zephir_check_call_status();
	zephir_throw_exception_debug(_6, "xpl/type.zep", 274 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * If $value is a numeric string, it is converted to a float or integer depending
 * on whether a decimal point is present. Otherwise the original value is returned.
 *
 * @param mixed value If numeric string, converted to integer or float.
 *
 * @return mixed Value as string, integer, or float.
 */
PHP_METHOD(Xpl_Type, toNumber) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value, *_0$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	if (Z_TYPE_P(value) == IS_STRING) {
		if (zephir_is_numeric(value)) {
			ZEPHIR_CALL_SELF(&_0$$4, "getdecimalpoint", NULL, 0);
			zephir_check_call_status();
			if (zephir_memnstr(value, _0$$4, "xpl/type.zep", 291)) {
				RETURN_MM_DOUBLE(zephir_get_doubleval(value));
			}
			RETURN_MM_LONG(zephir_get_intval(value));
		}
	}
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();

}

/**
 * Checks whether a variable is a mixed number
 */
PHP_METHOD(Xpl_Type, isMixedNumber) {

	double floated = 0, floored = 0;
	zval *value;

	zephir_fetch_params(0, 1, 0, &value);



	if (zephir_is_numeric(value)) {
		floated = zephir_get_doubleval(value);
		floored = zephir_floor(value TSRMLS_CC);
		if (floated != floored) {
			RETURN_BOOL(1);
		}
	}
	RETURN_BOOL(0);

}

/**
 * Casts a numeric string to a float or integer
 */
PHP_METHOD(Xpl_Type, castNumericString) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool allowNonNumeric, _0;
	zval *value, *allowNonNumeric_param = NULL, *_2 = NULL, *_1$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &value, &allowNonNumeric_param);

	if (!allowNonNumeric_param) {
		allowNonNumeric = 1;
	} else {
		allowNonNumeric = zephir_get_boolval(allowNonNumeric_param);
	}


	_0 = Z_TYPE_P(value) == IS_STRING;
	if (_0) {
		_0 = zephir_is_numeric(value);
	}
	if (_0) {
		ZEPHIR_CALL_SELF(&_1$$3, "ismixednumber", NULL, 0, value);
		zephir_check_call_status();
		if (zephir_is_true(_1$$3)) {
			RETURN_MM_DOUBLE(zephir_get_doubleval(value));
		}
		RETURN_MM_LONG(zephir_get_intval(value));
	}
	ZEPHIR_INIT_VAR(_2);
	if (allowNonNumeric) {
		ZEPHIR_CPY_WRT(_2, value);
	} else {
		ZVAL_NULL(_2);
	}
	RETURN_CCTOR(_2);

}

/**
 * Checks whether an object was created by casting a scalar value.
 *
 * Objects created from scalars will be an instance of \stdClass with
 * a property named "scalar" set to the value.
 *
 * @param object value
 *
 * @return boolean
 */
PHP_METHOD(Xpl_Type, isScalarObject) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value, *scalarValue = NULL, _0$$3, *_1$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	if (Z_TYPE_P(value) == IS_OBJECT) {
		ZEPHIR_SINIT_VAR(_0$$3);
		ZVAL_STRING(&_0$$3, "scalar", 0);
		ZEPHIR_CALL_FUNCTION(&_1$$3, "property_exists", NULL, 101, value, &_0$$3);
		zephir_check_call_status();
		if (zephir_is_true(_1$$3)) {
			ZEPHIR_OBS_VAR(scalarValue);
			zephir_read_property(&scalarValue, value, SL("scalar"), PH_NOISY_CC);
			if (Z_TYPE_P(scalarValue) == IS_NULL) {
				RETURN_MM_BOOL(1);
			}
			if (zephir_is_scalar(scalarValue)) {
				RETURN_MM_BOOL(1);
			}
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Converts an object to a scalar value.
 *
 * @param object value
 * @return scalar|null
 */
PHP_METHOD(Xpl_Type, objectToScalar) {

	zval *_3$$4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *value, _0, *_1 = NULL, *_2$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);

	if (unlikely(Z_TYPE_P(value) != IS_OBJECT)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'value' must be a object") TSRMLS_CC);
		RETURN_MM_NULL();
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "scalar", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "property_exists", NULL, 101, value, &_0);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_OBS_VAR(_2$$3);
		zephir_read_property(&_2$$3, value, SL("scalar"), PH_NOISY_CC);
		RETURN_CCTOR(_2$$3);
	}
	if ((zephir_method_exists_ex(value, SS("__tostring") TSRMLS_CC) == SUCCESS)) {
		zephir_get_strval(_3$$4, value);
		RETURN_CTOR(_3$$4);
	}
	RETURN_MM_NULL();

}

PHP_METHOD(Xpl_Type, canStringCast) {

	zval *variable, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &variable);



	ZEPHIR_INIT_VAR(_0);
	zephir_gettype(_0, variable TSRMLS_CC);
	do {
		if (ZEPHIR_IS_STRING(_0, "string") || ZEPHIR_IS_STRING(_0, "integer") || ZEPHIR_IS_STRING(_0, "double") || ZEPHIR_IS_STRING(_0, "null")) {
			RETURN_MM_BOOL(1);
		}
		if (ZEPHIR_IS_STRING(_0, "object")) {
			RETURN_MM_BOOL((zephir_method_exists_ex(variable, SS("__tostring") TSRMLS_CC) == SUCCESS));
		}
	} while(0);

	RETURN_MM_BOOL(0);

}

/**
 * Returns the decimal point for the current locale
 *
 * @return string
 */
PHP_METHOD(Xpl_Type, getDecimalPoint) {

	zval *decimal = NULL, *loc$$3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(decimal);
	zephir_read_static_property_ce(&decimal, xpl_type_ce, SL("decimalPoint") TSRMLS_CC);
	if (Z_TYPE_P(decimal) == IS_NULL) {
		ZEPHIR_CALL_FUNCTION(&loc$$3, "localeconv", NULL, 188);
		zephir_check_call_status();
		if (zephir_array_isset_string(loc$$3, SS("decimal_point"))) {
			ZEPHIR_OBS_NVAR(decimal);
			zephir_array_fetch_string(&decimal, loc$$3, SL("decimal_point"), PH_NOISY, "xpl/type.zep", 420 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(decimal);
			ZVAL_STRING(decimal, ".", 1);
		}
		zephir_update_static_property_ce(xpl_type_ce, SL("decimalPoint"), &decimal TSRMLS_CC);
	}
	RETURN_CCTOR(decimal);

}

