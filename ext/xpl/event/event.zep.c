
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(Xpl_Event_Event) {

	ZEPHIR_REGISTER_CLASS(Xpl\\Event, Event, xpl, event_event, xpl_event_event_method_entry, 0);

	/**
	 * Unique identifier for the event.
	 *
	 * @var string
	 */
	zend_declare_property_null(xpl_event_event_ce, SL("id"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Event value.
	 *
	 * @var mixed
	 */
	zend_declare_property_null(xpl_event_event_ce, SL("value"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * Whether the default behavior should be prevented.
	 *
	 * @var boolean
	 */
	zend_declare_property_bool(xpl_event_event_ce, SL("defaultPrevented"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Whether propagation should be stopped.
	 *
	 * @var boolean
	 */
	zend_declare_property_bool(xpl_event_event_ce, SL("propagationStopped"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * Constructor takes one string parameter, the event ID.
 *
 * @param string id Event identifier.
 */
PHP_METHOD(Xpl_Event_Event, __construct) {

	zval *id_param = NULL;
	zval *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	zephir_get_strval(id, id_param);


	zephir_update_property_this(this_ptr, SL("id"), id TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the event ID.
 *
 * @return string
 */
PHP_METHOD(Xpl_Event_Event, getID) {

	

	RETURN_MEMBER(this_ptr, "id");

}

/**
 * Prevents execution of the event"s default behavior.
 *
 * @return \Xpl\Event\Event
 */
PHP_METHOD(Xpl_Event_Event, preventDefault) {

	

	if (1) {
		zephir_update_property_this(this_ptr, SL("defaultPrevented"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("defaultPrevented"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THISW();

}

/**
 * Stops propagation of the event.
 *
 * @return \Xpl\Event\Event
 */
PHP_METHOD(Xpl_Event_Event, stopPropagation) {

	

	if (1) {
		zephir_update_property_this(this_ptr, SL("propagationStopped"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("propagationStopped"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THISW();

}

/**
 * Returns true if preventDefault() has been called on the event.
 *
 * @return boolean
 */
PHP_METHOD(Xpl_Event_Event, isDefaultPrevented) {

	

	RETURN_MEMBER(this_ptr, "defaultPrevented");

}

/**
 * Returns true if stopPropagation() has been called on the event.
 *
 * @return boolean
 */
PHP_METHOD(Xpl_Event_Event, isPropagationStopped) {

	

	RETURN_MEMBER(this_ptr, "propagationStopped");

}

/**
 * Magic get to allow access to non-public properties.
 *
 * @param string var Propety name.
 * @return mixed Property value or null.
 */
PHP_METHOD(Xpl_Event_Event, __get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, _0, _1, *_2, *_3 = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "preventDefault", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "stopPropagation", 0);
	if (ZEPHIR_IS_IDENTICAL(&_0, key)) {
		RETURN_MM_MEMBER(this_ptr, "defaultPrevented");
	} else if (ZEPHIR_IS_IDENTICAL(&_1, key)) {
		RETURN_MM_MEMBER(this_ptr, "propagationStopped");
	}
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CALL_FUNCTION(&_3, "property_exists", NULL, 101, this_ptr, key);
	zephir_check_call_status();
	if (zephir_is_true(_3)) {
		zephir_read_property_zval(&_2, this_ptr, key, PH_NOISY_CC);
	} else {
		ZVAL_NULL(_2);
	}
	RETURN_CCTOR(_2);

}

PHP_METHOD(Xpl_Event_Event, __isset) {

	zend_bool _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, _0, _2;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "preventDefault", 0);
	_1 = ZEPHIR_IS_IDENTICAL(&_0, key);
	if (!(_1)) {
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_STRING(&_2, "stopPropagation", 0);
		_1 = ZEPHIR_IS_IDENTICAL(&_2, key);
	}
	if (_1) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_RETURN_CALL_FUNCTION("property_exists", NULL, 101, this_ptr, key);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Xpl_Event_Event, __set) {

	zend_bool _1, _4;
	zval *key_param = NULL, *value, _0, _2, _3, _5;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(key, key_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "defaultPrevented", 0);
	_1 = ZEPHIR_IS_IDENTICAL(&_0, key);
	if (!(_1)) {
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_STRING(&_2, "preventDefault", 0);
		_1 = ZEPHIR_IS_IDENTICAL(&_2, key);
	}
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "propagationStopped", 0);
	_4 = ZEPHIR_IS_IDENTICAL(&_3, key);
	if (!(_4)) {
		ZEPHIR_SINIT_VAR(_5);
		ZVAL_STRING(&_5, "stopPropagation", 0);
		_4 = ZEPHIR_IS_IDENTICAL(&_5, key);
	}
	if (_1) {
		if (zephir_get_boolval(value)) {
			zephir_update_property_this(this_ptr, SL("defaultPrevented"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(this_ptr, SL("defaultPrevented"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
	} else if (_4) {
		if (zephir_get_boolval(value)) {
			zephir_update_property_this(this_ptr, SL("propagationStopped"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(this_ptr, SL("propagationStopped"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
	} else {
		zephir_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Xpl_Event_Event, __unset) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *key, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 4, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "defaultPrevented", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "preventDefault", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "propagationStopped", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "stopPropagation", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_CALL_FUNCTION(&_2, "in_array", NULL, 2, key, _0, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Cannot unset private properties.", "xpl/event/event.zep", 138);
		return;
	}
	zephir_update_property_zval_zval(this_ptr, key, ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

