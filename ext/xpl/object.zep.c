
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Xpl_Object) {

	ZEPHIR_REGISTER_CLASS(Xpl, Object, xpl, object, xpl_object_method_entry, 0);

	zend_class_implements(xpl_object_ce TSRMLS_CC, 1, zend_ce_serializable);
	return SUCCESS;

}

/**
 * Indicates whether some other object is "equal to" this one.
 *
 * @param object
 * @return boolean
 */
PHP_METHOD(Xpl_Object, equals) {

	zval *obj;

	zephir_fetch_params(0, 1, 0, &obj);

	if (unlikely(Z_TYPE_P(obj) != IS_OBJECT)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'obj' must be a object") TSRMLS_CC);
		RETURN_NULL();
	}


	RETURN_BOOL(ZEPHIR_IS_IDENTICAL(obj, this_ptr));

}

/**
 * Returns a unique hash for the object.
 *
 * @return string
 */
PHP_METHOD(Xpl_Object, getObjectHash) {

	zval *_0, *_1 = NULL, *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_get_class(_0, this_ptr, 0 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "serialize", NULL, 3, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "sha1", NULL, 119, _1);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, _0, "@", _2);
	RETURN_MM();

}

/**
 * Returns a new instance of the given object.
 *
 * @param object obj
 * @param mixed arg [Optional]
 * @return object
 */
PHP_METHOD(Xpl_Object, valueOf) {

	zend_class_entry *_1$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *ctorArgs = NULL;
	zval *obj, *ctorArgs_param = NULL, *classname = NULL, *_0$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &obj, &ctorArgs_param);

	if (unlikely(Z_TYPE_P(obj) != IS_OBJECT)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'obj' must be a object") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (!ctorArgs_param) {
		ZEPHIR_INIT_VAR(ctorArgs);
		array_init(ctorArgs);
	} else {
	ctorArgs = ctorArgs_param;
	}


	ZEPHIR_INIT_VAR(classname);
	zephir_get_class(classname, obj, 0 TSRMLS_CC);
	if (zephir_fast_count_int(ctorArgs TSRMLS_CC) == 0) {
		zephir_fetch_safe_class(_0$$3, classname);
			_1$$3 = zend_fetch_class(Z_STRVAL_P(_0$$3), Z_STRLEN_P(_0$$3), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(return_value, _1$$3);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		RETURN_MM();
	}
	ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(return_value, classname, ctorArgs TSRMLS_CC);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Serializes the object.
 *
 * @return string
 */
PHP_METHOD(Xpl_Object, serialize) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "get_object_vars", NULL, 62, this_ptr);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 3, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Unserializes the object.
 *
 * @param string serial
 * @return void
 */
PHP_METHOD(Xpl_Object, unserialize) {

	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *serial_param = NULL, *key = NULL, *value = NULL, *_0 = NULL, **_3;
	zval *serial = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serial_param);

	zephir_get_strval(serial, serial_param);


	ZEPHIR_CALL_FUNCTION(&_0, "unserialize", NULL, 4, serial);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "xpl/object.zep", 68);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		zephir_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

