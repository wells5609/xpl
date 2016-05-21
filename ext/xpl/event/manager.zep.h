
extern zend_class_entry *xpl_event_manager_ce;

ZEPHIR_INIT_CLASS(Xpl_Event_Manager);

PHP_METHOD(Xpl_Event_Manager, __construct);
PHP_METHOD(Xpl_Event_Manager, on);
PHP_METHOD(Xpl_Event_Manager, off);
PHP_METHOD(Xpl_Event_Manager, one);
PHP_METHOD(Xpl_Event_Manager, trigger);
PHP_METHOD(Xpl_Event_Manager, triggerArray);
PHP_METHOD(Xpl_Event_Manager, filter);
PHP_METHOD(Xpl_Event_Manager, filterArray);
PHP_METHOD(Xpl_Event_Manager, did);
PHP_METHOD(Xpl_Event_Manager, event);
PHP_METHOD(Xpl_Event_Manager, result);
PHP_METHOD(Xpl_Event_Manager, setSortOrder);
PHP_METHOD(Xpl_Event_Manager, isLowToHigh);
PHP_METHOD(Xpl_Event_Manager, isHighToLow);
PHP_METHOD(Xpl_Event_Manager, prepare);
PHP_METHOD(Xpl_Event_Manager, execute);
PHP_METHOD(Xpl_Event_Manager, sortListenersAsc);
PHP_METHOD(Xpl_Event_Manager, sortListenersDesc);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_event_manager_on, 0, 0, 2)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_INFO(0, call)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_event_manager_off, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_event_manager_one, 0, 0, 2)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_INFO(0, call)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_event_manager_trigger, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_event_manager_triggerarray, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_event_manager_filter, 0, 0, 2)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_event_manager_filterarray, 0, 0, 2)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_event_manager_did, 0, 0, 1)
	ZEND_ARG_INFO(0, eventId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_event_manager_event, 0, 0, 1)
	ZEND_ARG_INFO(0, eventId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_event_manager_result, 0, 0, 1)
	ZEND_ARG_INFO(0, eventId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_event_manager_setsortorder, 0, 0, 1)
	ZEND_ARG_INFO(0, order)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_event_manager_prepare, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_event_manager_execute, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, event, Xpl\\Event\\Event, 0)
	ZEND_ARG_ARRAY_INFO(0, listeners, 0)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_event_manager_sortlistenersasc, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, a, Xpl\\Event\\Listener, 0)
	ZEND_ARG_OBJ_INFO(0, b, Xpl\\Event\\Listener, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_event_manager_sortlistenersdesc, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, a, Xpl\\Event\\Listener, 0)
	ZEND_ARG_OBJ_INFO(0, b, Xpl\\Event\\Listener, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_event_manager_method_entry) {
	PHP_ME(Xpl_Event_Manager, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Xpl_Event_Manager, on, arginfo_xpl_event_manager_on, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Event_Manager, off, arginfo_xpl_event_manager_off, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Event_Manager, one, arginfo_xpl_event_manager_one, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Event_Manager, trigger, arginfo_xpl_event_manager_trigger, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Event_Manager, triggerArray, arginfo_xpl_event_manager_triggerarray, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Event_Manager, filter, arginfo_xpl_event_manager_filter, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Event_Manager, filterArray, arginfo_xpl_event_manager_filterarray, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Event_Manager, did, arginfo_xpl_event_manager_did, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Event_Manager, event, arginfo_xpl_event_manager_event, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Event_Manager, result, arginfo_xpl_event_manager_result, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Event_Manager, setSortOrder, arginfo_xpl_event_manager_setsortorder, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Event_Manager, isLowToHigh, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Event_Manager, isHighToLow, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Event_Manager, prepare, arginfo_xpl_event_manager_prepare, ZEND_ACC_PROTECTED)
	PHP_ME(Xpl_Event_Manager, execute, arginfo_xpl_event_manager_execute, ZEND_ACC_PROTECTED)
	PHP_ME(Xpl_Event_Manager, sortListenersAsc, arginfo_xpl_event_manager_sortlistenersasc, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Event_Manager, sortListenersDesc, arginfo_xpl_event_manager_sortlistenersdesc, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
