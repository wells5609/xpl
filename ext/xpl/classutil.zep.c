
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Xpl_ClassUtil) {

	ZEPHIR_REGISTER_CLASS(Xpl, ClassUtil, xpl, classutil, xpl_classutil_method_entry, 0);

	zend_declare_property_null(xpl_classutil_ce, SL("classCache"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_class_constant_string(xpl_classutil_ce, SL("TYPE_CLASS"), "class" TSRMLS_CC);

	zend_declare_class_constant_string(xpl_classutil_ce, SL("TYPE_INTERFACE"), "interface" TSRMLS_CC);

	zend_declare_class_constant_string(xpl_classutil_ce, SL("TYPE_TRAIT"), "trait" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Xpl_ClassUtil, createInstance) {

	zend_class_entry *_1$$3, *_3$$4, *_6$$5, *_10$$6;
	int ZEPHIR_LAST_CALL_STATUS, num = 0;
	zval *args = NULL;
	zval *classname_param = NULL, *args_param = NULL, *_0$$3 = NULL, *_2$$4 = NULL, *_4$$4, *_5$$5 = NULL, *_7$$5, *_8$$5, *_9$$6 = NULL, *_11$$6, *_12$$6, *_13$$6, *_14$$6;
	zval *classname = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &classname_param, &args_param);

	zephir_get_strval(classname, classname_param);
	if (!args_param) {
		ZEPHIR_INIT_VAR(args);
		array_init(args);
	} else {
		zephir_get_arrval(args, args_param);
	}


	num = zephir_fast_count_int(args TSRMLS_CC);
	if (num == 0) {
		zephir_fetch_safe_class(_0$$3, classname);
			_1$$3 = zend_fetch_class(Z_STRVAL_P(_0$$3), Z_STRLEN_P(_0$$3), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(return_value, _1$$3);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		RETURN_MM();
	}
	if (num == 1) {
		zephir_fetch_safe_class(_2$$4, classname);
			_3$$4 = zend_fetch_class(Z_STRVAL_P(_2$$4), Z_STRLEN_P(_2$$4), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(return_value, _3$$4);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			zephir_array_fetch_long(&_4$$4, args, 0, PH_NOISY | PH_READONLY, "xpl/classutil.zep", 22 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, _4$$4);
			zephir_check_call_status();
		}
		RETURN_MM();
	}
	if (num == 2) {
		zephir_fetch_safe_class(_5$$5, classname);
			_6$$5 = zend_fetch_class(Z_STRVAL_P(_5$$5), Z_STRLEN_P(_5$$5), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(return_value, _6$$5);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			zephir_array_fetch_long(&_7$$5, args, 0, PH_NOISY | PH_READONLY, "xpl/classutil.zep", 25 TSRMLS_CC);
			zephir_array_fetch_long(&_8$$5, args, 1, PH_NOISY | PH_READONLY, "xpl/classutil.zep", 25 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, _7$$5, _8$$5);
			zephir_check_call_status();
		}
		RETURN_MM();
	}
	if (num == 3) {
		zephir_fetch_safe_class(_9$$6, classname);
			_10$$6 = zend_fetch_class(Z_STRVAL_P(_9$$6), Z_STRLEN_P(_9$$6), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(return_value, _10$$6);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			zephir_array_fetch_long(&_11$$6, args, 0, PH_NOISY | PH_READONLY, "xpl/classutil.zep", 28 TSRMLS_CC);
			zephir_array_fetch_long(&_12$$6, args, 1, PH_NOISY | PH_READONLY, "xpl/classutil.zep", 28 TSRMLS_CC);
			zephir_array_fetch_long(&_13$$6, args, 2, PH_NOISY | PH_READONLY, "xpl/classutil.zep", 28 TSRMLS_CC);
			zephir_array_fetch_long(&_14$$6, args, 3, PH_NOISY | PH_READONLY, "xpl/classutil.zep", 28 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, _11$$6, _12$$6, _13$$6, _14$$6);
			zephir_check_call_status();
		}
		RETURN_MM();
	}
	ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(return_value, classname, args TSRMLS_CC);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Xpl_ClassUtil, newInstance) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *args = NULL;
	zval *classname, *args_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &classname, &args_param);

	if (!args_param) {
		ZEPHIR_INIT_VAR(args);
		array_init(args);
	} else {
	args = args_param;
	}


	if (ZEPHIR_IS_EMPTY(args)) {
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(return_value, classname TSRMLS_CC);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(return_value, classname, args TSRMLS_CC);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Xpl_ClassUtil, classBasename) {

	zval *classname;

	zephir_fetch_params(0, 1, 0, &classname);



	zephir_get_class_ns(return_value, classname, 0 TSRMLS_CC);
	return;

}

PHP_METHOD(Xpl_ClassUtil, classNamespace) {

	zval *classname;

	zephir_fetch_params(0, 1, 0, &classname);



	zephir_get_ns_class(return_value, classname, 0 TSRMLS_CC);
	return;

}

PHP_METHOD(Xpl_ClassUtil, realclass) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *classname, *reflection = NULL, *_0, *_2, *_3, *_1$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &classname);



	if (Z_TYPE_P(classname) == IS_OBJECT) {
		zephir_get_class(return_value, classname, 0 TSRMLS_CC);
		RETURN_MM();
	}
	_0 = zephir_fetch_static_property_ce(xpl_classutil_ce, SL("classCache") TSRMLS_CC);
	if (!(zephir_array_isset(_0, classname))) {
		ZEPHIR_INIT_VAR(reflection);
		object_init_ex(reflection, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, reflection, "__construct", NULL, 63, classname);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1$$4, reflection, "getname", NULL, 64);
		zephir_check_call_status();
		zephir_update_static_property_array_multi_ce(xpl_classutil_ce, SL("classCache"), &_1$$4 TSRMLS_CC, SL("z"), 1, classname);
	}
	_2 = zephir_fetch_static_property_ce(xpl_classutil_ce, SL("classCache") TSRMLS_CC);
	zephir_array_fetch(&_3, _2, classname, PH_NOISY | PH_READONLY, "xpl/classutil.zep", 66 TSRMLS_CC);
	RETURN_CTOR(_3);

}

PHP_METHOD(Xpl_ClassUtil, classType) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *obj, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &obj);



	if (zephir_interface_exists(obj, 1  TSRMLS_CC)) {
		RETURN_MM_STRING("interface", 1);
	}
	ZEPHIR_CALL_FUNCTION(&_0, "trait_exists", NULL, 65, obj);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		RETURN_MM_STRING("trait", 1);
	}
	if (zephir_class_exists(obj, 1 TSRMLS_CC)) {
		RETURN_MM_STRING("class", 1);
	}
	RETURN_MM_NULL();

}

void zephir_init_static_properties_Xpl_ClassUtil(TSRMLS_D) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_static_property_ce(xpl_classutil_ce, SL("classCache"), &_0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

