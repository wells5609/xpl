
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Xpl_Event_Listener) {

	ZEPHIR_REGISTER_CLASS(Xpl\\Event, Listener, xpl, event_listener, xpl_event_listener_method_entry, 0);

	/**
	 * Event's unique identifier.
	 *
	 * @var string
	 */
	zend_declare_property_null(xpl_event_listener_ce, SL("event_id"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Callback.
	 *
	 * @var callable
	 */
	zend_declare_property_null(xpl_event_listener_ce, SL("callback"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Priority.
	 *
	 * @var integer
	 */
	zend_declare_property_null(xpl_event_listener_ce, SL("priority"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Construct listener using event ID, callback, and priority.
 *
 * @param string eventID Unique identifier for the event.
 * @param callable callback Callback to run when listener called.
 * @param integer priority Listener execution priority.
 */
PHP_METHOD(Xpl_Event_Listener, __construct) {

	int priority;
	zval *event_id_param = NULL, *callback, *priority_param = NULL, *_0;
	zval *event_id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &event_id_param, &callback, &priority_param);

	zephir_get_strval(event_id, event_id_param);
	priority = zephir_get_intval(priority_param);


	zephir_update_property_this(this_ptr, SL("event_id"), event_id TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("callback"), callback TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, priority);
	zephir_update_property_this(this_ptr, SL("priority"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Invokes the listener's callback function.
 *
 * @param array args Array of arguments to pass to callback.
 * @return mixed Result of callback.
 */
PHP_METHOD(Xpl_Event_Listener, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS, _1;
	zval *args_param = NULL, *callback = NULL, *_0, *_2$$3, *_3$$4, *_4$$4, *_5$$5, *_6$$5, *_7$$5, *_8$$6, *_9$$6, *_10$$6, *_11$$6;
	zval *args = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &args_param);

	zephir_get_arrval(args, args_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("callback"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(callback, _0);
	do {
		_1 = zephir_fast_count_int(args TSRMLS_CC);
		if (_1 == 1) {
			zephir_array_fetch_long(&_2$$3, args, 0, PH_NOISY | PH_READONLY, "xpl/event/listener.zep", 55 TSRMLS_CC);
			ZEPHIR_RETURN_CALL_ZVAL_FUNCTION(callback, NULL, 0, _2$$3);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (_1 == 2) {
			zephir_array_fetch_long(&_3$$4, args, 0, PH_NOISY | PH_READONLY, "xpl/event/listener.zep", 57 TSRMLS_CC);
			zephir_array_fetch_long(&_4$$4, args, 1, PH_NOISY | PH_READONLY, "xpl/event/listener.zep", 57 TSRMLS_CC);
			ZEPHIR_RETURN_CALL_ZVAL_FUNCTION(callback, NULL, 0, _3$$4, _4$$4);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (_1 == 3) {
			zephir_array_fetch_long(&_5$$5, args, 0, PH_NOISY | PH_READONLY, "xpl/event/listener.zep", 59 TSRMLS_CC);
			zephir_array_fetch_long(&_6$$5, args, 1, PH_NOISY | PH_READONLY, "xpl/event/listener.zep", 59 TSRMLS_CC);
			zephir_array_fetch_long(&_7$$5, args, 2, PH_NOISY | PH_READONLY, "xpl/event/listener.zep", 59 TSRMLS_CC);
			ZEPHIR_RETURN_CALL_ZVAL_FUNCTION(callback, NULL, 0, _5$$5, _6$$5, _7$$5);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (_1 == 4) {
			zephir_array_fetch_long(&_8$$6, args, 0, PH_NOISY | PH_READONLY, "xpl/event/listener.zep", 61 TSRMLS_CC);
			zephir_array_fetch_long(&_9$$6, args, 1, PH_NOISY | PH_READONLY, "xpl/event/listener.zep", 61 TSRMLS_CC);
			zephir_array_fetch_long(&_10$$6, args, 2, PH_NOISY | PH_READONLY, "xpl/event/listener.zep", 61 TSRMLS_CC);
			zephir_array_fetch_long(&_11$$6, args, 3, PH_NOISY | PH_READONLY, "xpl/event/listener.zep", 61 TSRMLS_CC);
			ZEPHIR_RETURN_CALL_ZVAL_FUNCTION(callback, NULL, 0, _8$$6, _9$$6, _10$$6, _11$$6);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, callback, args);
		zephir_check_call_status();
		RETURN_MM();
	} while(0);

	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Xpl_Event_Listener, __get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CALL_FUNCTION(&_1, "property_exists", NULL, 101, this_ptr, key);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		zephir_read_property_zval(&_0, this_ptr, key, PH_NOISY_CC);
	} else {
		ZVAL_NULL(_0);
	}
	RETURN_CCTOR(_0);

}

