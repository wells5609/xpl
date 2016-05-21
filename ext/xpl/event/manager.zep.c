
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"
#include "kernel/hash.h"


/**
 * Event manager/container/emitter.
 *
 * Class for binding and triggering events.
 */
ZEPHIR_INIT_CLASS(Xpl_Event_Manager) {

	ZEPHIR_REGISTER_CLASS(Xpl\\Event, Manager, xpl, event_manager, xpl_event_manager_method_entry, 0);

	/**
	 * Sort order to use for listener priorities.
	 *
	 * One of the SORT_* class constants. Default is low-to-high.
	 *
	 * @var integer
	 */
	zend_declare_property_null(xpl_event_manager_ce, SL("sortOrder"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * The sort function to use.
	 *
	 * @var string
	 */
	zend_declare_property_null(xpl_event_manager_ce, SL("sortFunction"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Associative array of events and their listeners.
	 *
	 * Event name/IDs are used as keys.
	 *
	 * @var array
	 */
	zend_declare_property_null(xpl_event_manager_ce, SL("listeners"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Completed event objects and their results.
	 *
	 * @var array
	 */
	zend_declare_property_null(xpl_event_manager_ce, SL("completed"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Sort and execute listeners from low-to-high priority.
	 *
	 * e.g. 1 before 2, 2 before 3, etc.
	 *
	 * @var integer
	 */
	zend_declare_class_constant_long(xpl_event_manager_ce, SL("SORT_LOW_HIGH"), 0 TSRMLS_CC);

	/**
	 * Sort and execute listeners from high-to-low priority.
	 *
	 * e.g. 3 before 2, 2 before 1, etc.
	 *
	 * @var integer
	 */
	zend_declare_class_constant_long(xpl_event_manager_ce, SL("SORT_HIGH_LOW"), 1 TSRMLS_CC);

	return SUCCESS;

}

/**
 * Constructor. Sets the default sort order (low to high).
 *
 * @return void
 */
PHP_METHOD(Xpl_Event_Manager, __construct) {

	zval *_0, *_1, *_2;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("listeners"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("completed"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setsortorder", NULL, 0, _2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds an event listener.
 *
 * @param string event Event ID.
 * @param callable call Callable to execute on event trigger.
 * @param integer priority [Optional] Priority to give to the listener. Default = 10
 * @return \Xpl\Event\Manager
 */
PHP_METHOD(Xpl_Event_Manager, on) {

	int priority, ZEPHIR_LAST_CALL_STATUS;
	zval *event, *call, *priority_param = NULL, *listeners = NULL, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &event, &call, &priority_param);

	if (!priority_param) {
		priority = 10;
	} else {
		priority = zephir_get_intval(priority_param);
	}


	ZEPHIR_OBS_VAR(listeners);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("listeners"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&listeners, _0, event, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(listeners);
		array_init(listeners);
	}
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, xpl_event_listener_ce);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, priority);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 102, event, call, _2);
	zephir_check_call_status();
	zephir_array_append(&listeners, _1, PH_SEPARATE, "xpl/event/manager.zep", 92);
	zephir_update_property_array(this_ptr, SL("listeners"), event, listeners TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Unregisters one or all listeners for an event.
 *
 * @param string|\Xpl\Event\Event event Event ID or object.
 * @param callable callback [Optional] Callback to remove. If no callback is given,
 * then all of the event's listeners are removed.
 * @return \Xpl\Event\Manager
 *
 * @throws \InvalidArgumentException if event is not a string or Event instance.
 */
PHP_METHOD(Xpl_Event_Manager, off) {

	HashTable *_6$$8;
	HashPosition _5$$8;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *event, *callback = NULL, *id = NULL, *listeners = NULL, *_4, *_0$$4, *_1$$5, *_2$$5, *_3$$5, *i$$8 = NULL, *listener$$8 = NULL, **_7$$8, *_8$$9 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &event, &callback);

	if (!callback) {
		callback = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(event) == IS_STRING) {
		ZEPHIR_CPY_WRT(id, event);
	} else if (zephir_instance_of_ev(event, xpl_event_event_ce TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(_0$$4);
		zephir_read_property(&_0$$4, event, SL("id"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(id, _0$$4);
	} else {
		ZEPHIR_INIT_VAR(_1$$5);
		object_init_ex(_1$$5, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(_2$$5);
		zephir_gettype(_2$$5, event TSRMLS_CC);
		ZEPHIR_INIT_VAR(_3$$5);
		ZEPHIR_CONCAT_SV(_3$$5, "Event must be string or instance of Event, given: ", _2$$5);
		ZEPHIR_CALL_METHOD(NULL, _1$$5, "__construct", NULL, 5, _3$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$5, "xpl/event/manager.zep", 118 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(listeners);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("listeners"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&listeners, _4, id, 0 TSRMLS_CC)) {
		if (Z_TYPE_P(callback) == IS_NULL) {
			zephir_array_unset(&listeners, id, PH_SEPARATE);
		} else {
			zephir_is_iterable(listeners, &_6$$8, &_5$$8, 1, 0, "xpl/event/manager.zep", 137);
			for (
			  ; zephir_hash_get_current_data_ex(_6$$8, (void**) &_7$$8, &_5$$8) == SUCCESS
			  ; zephir_hash_move_forward_ex(_6$$8, &_5$$8)
			) {
				ZEPHIR_GET_HMKEY(i$$8, _6$$8, _5$$8);
				ZEPHIR_GET_HVALUE(listener$$8, _7$$8);
				ZEPHIR_OBS_NVAR(_8$$9);
				zephir_read_property(&_8$$9, listener$$8, SL("callback"), PH_NOISY_CC);
				if (ZEPHIR_IS_EQUAL(callback, _8$$9)) {
					zephir_array_unset(&listeners, i$$8, PH_SEPARATE);
				}
			}
			zend_hash_destroy(_6$$8);
			FREE_HASHTABLE(_6$$8);
		}
		zephir_update_property_array(this_ptr, SL("listeners"), id, listeners TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Adds an event listener which will be the only one called for the event.
 *
 * @param string event Event ID.
 * @param callable call Callable to execute on event trigger.
 * @return \Xpl\Event\Manager
 */
PHP_METHOD(Xpl_Event_Manager, one) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *event, *call, *_0, *_2, *_3, *_1$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &event, &call);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("listeners"), PH_NOISY_CC);
	if (!(zephir_array_isset(_0, event))) {
		ZEPHIR_INIT_VAR(_1$$3);
		array_init(_1$$3);
		zephir_update_property_array(this_ptr, SL("listeners"), event, _1$$3 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_2);
	object_init_ex(_2, xpl_event_listener_ce);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 102, event, call, _3);
	zephir_check_call_status();
	zephir_update_property_array_multi(this_ptr, SL("listeners"), &_2 TSRMLS_CC, SL("zs"), 3, event, SL("one"));
	RETURN_THIS();

}

/**
 * Triggers an event.
 *
 * @param \Xpl\Event\Event|string event Event object or ID.
 * @param ... Arguments to pass to callback.
 * @return array Items returned from event listeners.
 */
PHP_METHOD(Xpl_Event_Manager, trigger) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *event, *prepared = NULL, *eventObj = NULL, *listeners = NULL, *args = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &event);



	ZEPHIR_CALL_METHOD(&prepared, this_ptr, "prepare", NULL, 0, event);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(prepared)) {
		array_init(return_value);
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(eventObj);
	zephir_array_fetch_long(&eventObj, prepared, 0, PH_NOISY, "xpl/event/manager.zep", 181 TSRMLS_CC);
	ZEPHIR_OBS_VAR(listeners);
	zephir_array_fetch_long(&listeners, prepared, 1, PH_NOISY, "xpl/event/manager.zep", 182 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&args, "func_get_args", NULL, 98);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(args);
	ZEPHIR_CALL_FUNCTION(NULL, "array_shift", NULL, 103, args);
	ZEPHIR_UNREF(args);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, eventObj, listeners, args);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Triggers an event with an array of arguments.
 *
 * @param \Xpl\Event\Event|string event Event object or ID.
 * @param array args Args to pass to listeners.
 * @return array Items returned from event Listeners.
 */
PHP_METHOD(Xpl_Event_Manager, triggerArray) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *args = NULL;
	zval *event, *args_param = NULL, *prepared = NULL, *eventObj = NULL, *listeners = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &event, &args_param);

	if (!args_param) {
		ZEPHIR_INIT_VAR(args);
		array_init(args);
	} else {
		zephir_get_arrval(args, args_param);
	}


	ZEPHIR_CALL_METHOD(&prepared, this_ptr, "prepare", NULL, 0, event);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(prepared)) {
		array_init(return_value);
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(eventObj);
	zephir_array_fetch_long(&eventObj, prepared, 0, PH_NOISY, "xpl/event/manager.zep", 213 TSRMLS_CC);
	ZEPHIR_OBS_VAR(listeners);
	zephir_array_fetch_long(&listeners, prepared, 1, PH_NOISY, "xpl/event/manager.zep", 214 TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, eventObj, listeners, args);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Triggers a "filter" event, which returns the final event value.
 *
 * @param string|\Xpl\Event\Event event
 * @param mixed value
 * @param ... Arguments
 * @return mixed
 */
PHP_METHOD(Xpl_Event_Manager, filter) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *event, *value, *args = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &event, &value);



	ZEPHIR_CALL_FUNCTION(&args, "func_get_args", NULL, 98);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(args);
	ZEPHIR_CALL_FUNCTION(NULL, "array_shift", NULL, 103, args);
	ZEPHIR_UNREF(args);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "filterarray", NULL, 0, event, args);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Triggers a "filter" event, which returns the final event value.
 *
 * @param string|\Xpl\Event\Event event
 * @param array args
 * @return mixed
 */
PHP_METHOD(Xpl_Event_Manager, filterArray) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *args = NULL;
	zval *event, *args_param = NULL, *prepared = NULL, *eventObj = NULL, *listeners = NULL, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &event, &args_param);

	zephir_get_arrval(args, args_param);


	ZEPHIR_CALL_METHOD(&prepared, this_ptr, "prepare", NULL, 0, event);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(prepared)) {
		ZEPHIR_MAKE_REF(args);
		ZEPHIR_RETURN_CALL_FUNCTION("reset", NULL, 70, args);
		ZEPHIR_UNREF(args);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(eventObj);
	zephir_array_fetch_long(&eventObj, prepared, 0, PH_NOISY, "xpl/event/manager.zep", 259 TSRMLS_CC);
	ZEPHIR_OBS_VAR(listeners);
	zephir_array_fetch_long(&listeners, prepared, 1, PH_NOISY, "xpl/event/manager.zep", 260 TSRMLS_CC);
	ZEPHIR_MAKE_REF(args);
	ZEPHIR_CALL_FUNCTION(&_0, "array_shift", NULL, 103, args);
	ZEPHIR_UNREF(args);
	zephir_check_call_status();
	zephir_update_property_zval(eventObj, SL("value"), _0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "execute", NULL, 0, eventObj, listeners, args);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property(&_1, eventObj, SL("value"), PH_NOISY_CC);
	RETURN_CCTOR(_1);

}

/**
 * Returns whether an event has been completed.
 *
 * @param string eventId Event ID.
 * @return boolean True if event has completed, otherwise false.
 */
PHP_METHOD(Xpl_Event_Manager, did) {

	zval *eventId_param = NULL, *_0;
	zval *eventId = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventId_param);

	zephir_get_strval(eventId, eventId_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("completed"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, eventId));

}

/**
 * Returns a completed Event object.
 *
 * @param string eventId The event's ID.
 * @return \Xpl\Event\Event The completed Event object.
 */
PHP_METHOD(Xpl_Event_Manager, event) {

	zval *eventId_param = NULL, *_0, *_1, *_2, *_3;
	zval *eventId = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventId_param);

	zephir_get_strval(eventId, eventId_param);


	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("completed"), PH_NOISY_CC);
	if (zephir_array_isset(_1, eventId)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("completed"), PH_NOISY_CC);
		zephir_array_fetch(&_3, _2, eventId, PH_NOISY | PH_READONLY, "xpl/event/manager.zep", 288 TSRMLS_CC);
		zephir_array_fetch_string(&_0, _3, SL("event"), PH_NOISY, "xpl/event/manager.zep", 288 TSRMLS_CC);
	} else {
		ZVAL_NULL(_0);
	}
	RETURN_CCTOR(_0);

}

/**
 * Returns the array that was returned from a completed event trigger.
 *
 * This allows you to access previously returned values (obviously).
 *
 * @param string eventId The event's ID
 * @return array Values returned from the event's listeners, else null.
 */
PHP_METHOD(Xpl_Event_Manager, result) {

	zval *eventId_param = NULL, *_0, *_1, *_2, *_3;
	zval *eventId = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventId_param);

	zephir_get_strval(eventId, eventId_param);


	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("completed"), PH_NOISY_CC);
	if (zephir_array_isset(_1, eventId)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("completed"), PH_NOISY_CC);
		zephir_array_fetch(&_3, _2, eventId, PH_NOISY | PH_READONLY, "xpl/event/manager.zep", 301 TSRMLS_CC);
		zephir_array_fetch_string(&_0, _3, SL("result"), PH_NOISY, "xpl/event/manager.zep", 301 TSRMLS_CC);
	} else {
		ZVAL_NULL(_0);
	}
	RETURN_CCTOR(_0);

}

/**
 * Sets the listener priority sort order.
 *
 * Tip: you can also use PHP's SORT_ASC and SORT_DESC
 *
 * @param int order One of self::LOW_TO_HIGH or self::HIGH_TO_LOW
 * @return \Xpl\Event\Manager
 *
 * @throws \DomainException if order is not one of the class constants.
 */
PHP_METHOD(Xpl_Event_Manager, setSortOrder) {

	zend_bool _0;
	zval *order_param = NULL, *_1, *_2 = NULL, *_3;
	int order;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &order_param);

	order = zephir_get_intval(order_param);


	_0 = order != 0;
	if (_0) {
		_0 = order != 1;
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_DomainException, "Invalid sort order.", "xpl/event/manager.zep", 317);
		return;
	}
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, order);
	zephir_update_property_this(this_ptr, SL("sortOrder"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("sortOrder"), PH_NOISY_CC);
	if (ZEPHIR_IS_LONG_IDENTICAL(_1, 0)) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "Asc", 1);
	} else {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "Desc", 1);
	}
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SV(_3, "sortListeners", _2);
	zephir_update_property_this(this_ptr, SL("sortFunction"), _3 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns true if sort order is low to high.
 *
 * @return boolean True if sort order is low-to-high, otherwise false.
 */
PHP_METHOD(Xpl_Event_Manager, isLowToHigh) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("sortOrder"), PH_NOISY_CC);
	RETURN_BOOL(ZEPHIR_IS_LONG_IDENTICAL(_0, 0));

}

/**
 * Returns true if sort order is high to low.
 *
 * @return boolean True if sort order is high-to-low, otherwise false.
 */
PHP_METHOD(Xpl_Event_Manager, isHighToLow) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("sortOrder"), PH_NOISY_CC);
	RETURN_BOOL(ZEPHIR_IS_LONG_IDENTICAL(_0, 1));

}

/**
 * Prepares event for execution by lazy-loading listener objects.
 *
 * @param string|\Xpl\Event\Event event The event ID or object to trigger.
 * @return boolean|array False if no listeners, otherwise indexed array of the
 * Event object (at index 0) and an array of listeners (at index 1).
 *
 * @throws \InvalidArgumentException if event is not a string or Event object.
 */
PHP_METHOD(Xpl_Event_Manager, prepare) {

	zval *_4$$7;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *event, *eventObj = NULL, *eventId = NULL, *listeners = NULL, *onceListener = NULL, *_3, *_0$$5, *_1$$5, *_2$$5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &event);



	if (Z_TYPE_P(event) == IS_STRING) {
		ZEPHIR_CPY_WRT(eventId, event);
		ZEPHIR_INIT_VAR(eventObj);
		object_init_ex(eventObj, xpl_event_event_ce);
		ZEPHIR_CALL_METHOD(NULL, eventObj, "__construct", NULL, 104, event);
		zephir_check_call_status();
	} else if (zephir_instance_of_ev(event, xpl_event_event_ce TSRMLS_CC)) {
		ZEPHIR_CPY_WRT(eventObj, event);
		ZEPHIR_CALL_METHOD(&eventId, event, "getid", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_0$$5);
		object_init_ex(_0$$5, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(_1$$5);
		zephir_gettype(_1$$5, event TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2$$5);
		ZEPHIR_CONCAT_SV(_2$$5, "Event must be string or instance of Event, given: ", _1$$5);
		ZEPHIR_CALL_METHOD(NULL, _0$$5, "__construct", NULL, 5, _2$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$5, "xpl/event/manager.zep", 367 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("listeners"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&listeners, _3, eventId, 1 TSRMLS_CC))) {
		RETURN_MM_BOOL(0);
	}
	if (zephir_array_isset_string_fetch(&onceListener, listeners, SS("one"), 1 TSRMLS_CC)) {
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(return_value, eventObj);
		ZEPHIR_INIT_VAR(_4$$7);
		zephir_create_array(_4$$7, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_4$$7, onceListener);
		zephir_array_fast_append(return_value, _4$$7);
		RETURN_MM();
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, eventObj);
	zephir_array_fast_append(return_value, listeners);
	RETURN_MM();

}

/**
 * Executes the event listeners; sorts, calls, and returns result.
 *
 * @param \Xpl\Event\Event event Event object.
 * @param array listeners Array of Listener objects.
 * @param array args Callback arguments.
 * @return array Array of event callback results.
 */
PHP_METHOD(Xpl_Event_Manager, execute) {

	HashTable *_3;
	HashPosition _2;
	zephir_fcall_cache_entry *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *listeners = NULL, *args = NULL, *_0, *_8;
	zval *event, *listeners_param = NULL, *args_param = NULL, *results = NULL, *listener = NULL, *value = NULL, *_1, **_4, *_9 = NULL, *_5$$4 = NULL, *_6$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &event, &listeners_param, &args_param);

	ZEPHIR_SEPARATE_PARAM(event);
	listeners = listeners_param;
	if (!args_param) {
		ZEPHIR_INIT_VAR(args);
		array_init(args);
	} else {
	args = args_param;
	}


	ZEPHIR_INIT_VAR(results);
	array_init(results);
	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, this_ptr);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("sortFunction"), PH_NOISY_CC);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_MAKE_REF(listeners);
	ZEPHIR_CALL_FUNCTION(NULL, "usort", NULL, 85, listeners, _0);
	ZEPHIR_UNREF(listeners);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(args);
	ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 80, args, event);
	ZEPHIR_UNREF(args);
	zephir_check_call_status();
	zephir_is_iterable(listeners, &_3, &_2, 0, 0, "xpl/event/manager.zep", 427);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(listener, _4);
		ZEPHIR_CALL_ZVAL_FUNCTION(&value, listener, NULL, 0, args);
		zephir_check_call_status();
		zephir_array_append(&results, value, PH_SEPARATE, "xpl/event/manager.zep", 408);
		if (Z_TYPE_P(value) != IS_NULL) {
			ZEPHIR_OBS_NVAR(_5$$4);
			zephir_read_property(&_5$$4, event, SL("value"), PH_NOISY_CC);
			if (!ZEPHIR_IS_IDENTICAL(value, _5$$4)) {
				zephir_update_property_zval(event, SL("value"), value TSRMLS_CC);
			}
		}
		ZEPHIR_INIT_NVAR(value);
		ZVAL_NULL(value);
		ZEPHIR_CALL_METHOD(&_6$$3, event, "ispropagationstopped", &_7, 105);
		zephir_check_call_status();
		if (zephir_is_true(_6$$3)) {
			break;
		}
	}
	ZEPHIR_INIT_VAR(_8);
	zephir_create_array(_8, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&_8, SL("event"), &event, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_8, SL("result"), &results, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_9, event, "getid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("completed"), _9, _8 TSRMLS_CC);
	RETURN_CCTOR(results);

}

/**
 * Ascending listener sort callback.
 *
 * @param \Xpl\Event\Listener a
 * @param \Xpl\Event\Listener b
 * @return int Sort result
 */
PHP_METHOD(Xpl_Event_Manager, sortListenersAsc) {

	zval *a, *b, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &a, &b);



	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property(&_1, a, SL("priority"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, b, SL("priority"), PH_NOISY_CC);
	if (ZEPHIR_GE(_1, _2)) {
		ZVAL_LONG(_0, 1);
	} else {
		ZVAL_LONG(_0, -1);
	}
	RETURN_CCTOR(_0);

}

/**
 * Descending listener sort callback.
 *
 * @param \Xpl\Event\Listener a
 * @param \Xpl\Event\Listener b
 * @return int Sort result
 */
PHP_METHOD(Xpl_Event_Manager, sortListenersDesc) {

	zval *a, *b, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &a, &b);



	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property(&_1, a, SL("priority"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, b, SL("priority"), PH_NOISY_CC);
	if (ZEPHIR_LE(_1, _2)) {
		ZVAL_LONG(_0, 1);
	} else {
		ZVAL_LONG(_0, -1);
	}
	RETURN_CCTOR(_0);

}

