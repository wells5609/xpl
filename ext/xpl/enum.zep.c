
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"


/**
 * Base class for an enum
 */
ZEPHIR_INIT_CLASS(Xpl_Enum) {

	ZEPHIR_REGISTER_CLASS(Xpl, Enum, xpl, enum, xpl_enum_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * This enum value.
	 *
	 * @var mixed
	 */
	zend_declare_property_null(xpl_enum_ce, SL("value"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Set the value or pass a constant name.
 *
 * If a '_default' constant is set, null is also accepted.
 *
 * @param mixed value [Optional]
 *
 * @throws \RuntimeException if given null and no default exists, or if the value is invalid.
 */
PHP_METHOD(Xpl_Enum, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &value);

	if (!value) {
		value = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "filtervalidatevalue", NULL, 0, value);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("value"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the enum value.
 *
 * @return mixed
 */
PHP_METHOD(Xpl_Enum, getValue) {

	

	RETURN_MEMBER(this_ptr, "value");

}

/**
 * Evaluates the enum to a value.
 *
 * @param ... [Optional]
 * @return mixed
 */
PHP_METHOD(Xpl_Enum, evaluate) {

	zval *_1$$3;
	zval *value = NULL, *_0, *_2$$3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(value, _0);
	if ((zephir_method_exists(this_ptr, value TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_INIT_VAR(_1$$3);
		zephir_create_array(_1$$3, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_1$$3, this_ptr);
		zephir_array_fast_append(_1$$3, value);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "func_get_args", NULL, 98);
		zephir_check_call_status();
		ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, _1$$3, _2$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(value);

}

/**
 * Returns the name of the current enum value.
 *
 * @return string
 */
PHP_METHOD(Xpl_Enum, getConstantName) {

	zval *_0 = NULL, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getvalue", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getconstants", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("array_search", NULL, 67, _0, _1, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the default enum value, if it exists.
 *
 * @return mixed
 */
PHP_METHOD(Xpl_Enum, getDefaultValue) {

	zval *constants = NULL, *defaultValue = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&constants, this_ptr, "getconstants", NULL, 0);
	zephir_check_call_status();
	if (zephir_array_isset_string_fetch(&defaultValue, constants, SS("_default"), 1 TSRMLS_CC)) {
		RETURN_CTOR(defaultValue);
	}
	RETURN_MM_NULL();

}

/**
 * Checks whether the enum value is the default value.
 *
 * @return boolean
 */
PHP_METHOD(Xpl_Enum, isDefault) {

	zval *_0, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getdefaultvalue", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(_0, _1));

}

/**
 * Allows read-only access to the "value" property, "constant" name, and "default" value.
 *
 * @param string var One of "value", "constant" or "default".
 * @return mixed
 *
 * @throws \OverflowException if var is not "value", "constant" or "default".
 */
PHP_METHOD(Xpl_Enum, __get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, *_0, *_1$$6;
	zval *property = NULL, *_2$$6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property_param);

	zephir_get_strval(property, property_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, property);
	do {
		if (ZEPHIR_IS_STRING(_0, "value")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getvalue", NULL, 0);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(_0, "constant")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getconstantname", NULL, 0);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(_0, "default")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getdefaultvalue", NULL, 0);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(_1$$6);
		object_init_ex(_1$$6, spl_ce_OverflowException);
		ZEPHIR_INIT_VAR(_2$$6);
		ZEPHIR_CONCAT_SV(_2$$6, "Invalid property: ", property);
		ZEPHIR_CALL_METHOD(NULL, _1$$6, "__construct", NULL, 99, _2$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$6, "xpl/enum.zep", 118 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the value as a string.
 *
 * @return string
 */
PHP_METHOD(Xpl_Enum, __toString) {

	zval *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("value"), PH_NOISY_CC);
	zephir_get_strval(_1, _0);
	RETURN_CTOR(_1);

}

/**
 * Returns the constants for a given class or the current class.
 *
 * @param string classname [Optional]
 * @return array
 */
PHP_METHOD(Xpl_Enum, getConstants) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *classname = NULL, *reflection = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &classname);

	if (!classname) {
		ZEPHIR_CPY_WRT(classname, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(classname);
	}


	if (Z_TYPE_P(classname) == IS_NULL) {
		ZEPHIR_INIT_NVAR(classname);
		zephir_get_called_class(classname TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(reflection);
	object_init_ex(reflection, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, reflection, "__construct", NULL, 63, classname);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(reflection, "getconstants", NULL, 100);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Validates a value against the class constants.
 *
 * If value is a valid constant name, returns the corresponding value.
 *
 * If value is null and a default is set, returns the default value.
 *
 * @param mixed value
 *
 * @return mixed
 *
 * @throws \RuntimeException if value is null and no default exists, or if given an invalid value.
 */
PHP_METHOD(Xpl_Enum, filterValidateValue) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value = NULL, *reflection = NULL, *constants = NULL, *_0, *_2 = NULL, *_1$$6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &value);

	if (!value) {
		ZEPHIR_CPY_WRT(value, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(value);
	}


	ZEPHIR_INIT_VAR(reflection);
	object_init_ex(reflection, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
	ZEPHIR_INIT_VAR(_0);
	zephir_get_class(_0, this_ptr, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, reflection, "__construct", NULL, 63, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&constants, reflection, "getconstants", NULL, 100);
	zephir_check_call_status();
	if (Z_TYPE_P(value) == IS_NULL) {
		ZEPHIR_OBS_NVAR(value);
		if (zephir_array_isset_string_fetch(&value, constants, SS("_default"), 0 TSRMLS_CC)) {
			RETVAL_ZVAL(value, 1, 0);
			RETURN_MM();
		}
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Missing value: no default exists", "xpl/enum.zep", 177);
		return;
	}
	if (Z_TYPE_P(value) == IS_STRING) {
		if (zephir_array_isset(constants, value)) {
			zephir_array_fetch(&_1$$6, constants, value, PH_NOISY | PH_READONLY, "xpl/enum.zep", 183 TSRMLS_CC);
			ZEPHIR_CPY_WRT(value, _1$$6);
		}
		if ((zephir_method_exists(this_ptr, value TSRMLS_CC)  == SUCCESS)) {
			ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, value, NULL, 0);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	ZEPHIR_CALL_FUNCTION(&_2, "in_array", NULL, 2, value, constants, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	if (!(zephir_is_true(_2))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Invalid enum value", "xpl/enum.zep", 193);
		return;
	}
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();

}

