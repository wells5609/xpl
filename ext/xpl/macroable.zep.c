
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
#include "Zend/zend_closures.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Xpl_Macroable) {

	ZEPHIR_REGISTER_CLASS(Xpl, Macroable, xpl, macroable, xpl_macroable_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(xpl_macroable_ce, SL("macros"), ZEND_ACC_PRIVATE TSRMLS_CC);

	xpl_macroable_ce->create_object = zephir_init_properties_Xpl_Macroable;
	return SUCCESS;

}

/**
 */
PHP_METHOD(Xpl_Macroable, getMacros) {


	RETURN_MEMBER(this_ptr, "macros");

}

/**
 * Adds a named macro to the object
 *
 * @param string name Macro name
 * @param callable callback Macro callback function
 * @return void
 */
PHP_METHOD(Xpl_Macroable, addMacro) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *callback = NULL, *_0 = NULL, *_1;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &callback);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	ZEPHIR_SEPARATE_PARAM(callback);


	if (zephir_instance_of_ev(callback, zend_ce_closure TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_1);
		zephir_get_class(_1, this_ptr, 0 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_0, callback, "bindto", NULL, 0, this_ptr, _1);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(callback, _0);
	} else if (!(zephir_is_callable(callback TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Macro callback must be callable", "xpl/macroable.zep", 28);
		return;
	}
	zephir_update_property_array(this_ptr, SL("macros"), name, callback TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Whether a macro given by name exists
 *
 * @param string name Macro name
 * @return boolean
 */
PHP_METHOD(Xpl_Macroable, hasMacro) {

	zval *name_param = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("macros"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, name));

}

/**
 * Returns a raw macro callback
 *
 * @param string name Macro name
 * @return mixed|null
 */
PHP_METHOD(Xpl_Macroable, getMacro) {

	zval *name_param = NULL, *_0, *_1, *_2;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("macros"), PH_NOISY_CC);
	if (zephir_array_isset(_1, name)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("macros"), PH_NOISY_CC);
		zephir_array_fetch(&_0, _2, name, PH_NOISY, "xpl/macroable.zep", 53 TSRMLS_CC);
	} else {
		ZVAL_NULL(_0);
	}
	RETURN_CCTOR(_0);

}

/**
 * Executes a macro using the given arguments
 *
 * @param string name Macro name
 * @param array args [Optional] Arguments to pass to the macro callback
 */
PHP_METHOD(Xpl_Macroable, doMacro) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *args = NULL;
	zval *name_param = NULL, *args_param = NULL, *_0, *_1, *_3, *_4;
	zval *name = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &args_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	if (!args_param) {
		ZEPHIR_INIT_VAR(args);
		array_init(args);
	} else {
	args = args_param;

	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("macros"), PH_NOISY_CC);
	if (!(zephir_array_isset(_0, name))) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SVS(_2, "Unknown macro '", name, "'");
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 21, _2);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "xpl/macroable.zep", 65 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("macros"), PH_NOISY_CC);
	zephir_array_fetch(&_4, _3, name, PH_NOISY | PH_READONLY, "xpl/macroable.zep", 68 TSRMLS_CC);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, _4, args);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Whether the object has a method or macro given by name
 *
 * @param string name Method/macro name
 */
PHP_METHOD(Xpl_Macroable, isCallable) {

	zend_bool _0;
	zval *name_param = NULL, *_1;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = (zephir_method_exists(this_ptr, name TSRMLS_CC)  == SUCCESS);
	if (!(_0)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("macros"), PH_NOISY_CC);
		_0 = zephir_array_isset(_1, name);
	}
	RETURN_MM_BOOL(_0);

}

/**
 * Allows macros to be called like object methods
 *
 * @throws \BadMethodCallException if a macro with method name does not exist
 */
PHP_METHOD(Xpl_Macroable, __call) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *args = NULL;
	zval *func_param = NULL, *args_param = NULL, *_0, *_1, *_2, *_3;
	zval *func = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &func_param, &args_param);

	zephir_get_strval(func, func_param);
	zephir_get_arrval(args, args_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("macros"), PH_NOISY_CC);
	if (zephir_array_isset(_0, func)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("macros"), PH_NOISY_CC);
		zephir_array_fetch(&_2, _1, func, PH_NOISY | PH_READONLY, "xpl/macroable.zep", 89 TSRMLS_CC);
		ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, _2, args);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_3);
	object_init_ex(_3, spl_ce_BadMethodCallException);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SVS(_4, "Invalid method: '", func, "'");
	ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, 31, _4);
	zephir_check_call_status();
	zephir_throw_exception_debug(_3, "xpl/macroable.zep", 92 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Allows the object to be invokable using an "__invoke" macro
 *
 * @throws BadMethodCallException if a "__invoke" macro does not exist
 */
PHP_METHOD(Xpl_Macroable, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2, *_3 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("macros"), PH_NOISY_CC);
	if (zephir_array_isset_string(_0, SS("__invoke"))) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("macros"), PH_NOISY_CC);
		zephir_array_fetch_string(&_2, _1, SL("__invoke"), PH_NOISY | PH_READONLY, "xpl/macroable.zep", 103 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_3, "func_get_args", NULL, 22);
		zephir_check_call_status();
		ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, _2, _3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_BadMethodCallException, "Invalid method: '__invoke'.", "xpl/macroable.zep", 106);
	return;

}

/**
 * Allows the object to be cast to a string using a "__toString" macro
 *
 * Returns an empty string if a "__toString" macro does not exist
 *
 * @return string
 */
PHP_METHOD(Xpl_Macroable, __toString) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2, *_3 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("macros"), PH_NOISY_CC);
	if (zephir_array_isset_string(_0, SS("__toString"))) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("macros"), PH_NOISY_CC);
		zephir_array_fetch_string(&_2, _1, SL("__toString"), PH_NOISY | PH_READONLY, "xpl/macroable.zep", 119 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_3, "func_get_args", NULL, 22);
		zephir_check_call_status();
		ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, _2, _3);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_STRING("", 1);

}

static zend_object_value zephir_init_properties_Xpl_Macroable(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("macros"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1);
			array_init(_1);
			zephir_update_property_this(this_ptr, SL("macros"), _1 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

