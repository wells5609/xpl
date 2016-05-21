
extern zend_class_entry *xpl_event_event_ce;

ZEPHIR_INIT_CLASS(Xpl_Event_Event);

PHP_METHOD(Xpl_Event_Event, __construct);
PHP_METHOD(Xpl_Event_Event, getID);
PHP_METHOD(Xpl_Event_Event, preventDefault);
PHP_METHOD(Xpl_Event_Event, stopPropagation);
PHP_METHOD(Xpl_Event_Event, isDefaultPrevented);
PHP_METHOD(Xpl_Event_Event, isPropagationStopped);
PHP_METHOD(Xpl_Event_Event, __get);
PHP_METHOD(Xpl_Event_Event, __isset);
PHP_METHOD(Xpl_Event_Event, __set);
PHP_METHOD(Xpl_Event_Event, __unset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_event_event___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_event_event___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_event_event___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_event_event___set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_event_event___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_event_event_method_entry) {
	PHP_ME(Xpl_Event_Event, __construct, arginfo_xpl_event_event___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Xpl_Event_Event, getID, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Event_Event, preventDefault, NULL, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Event_Event, stopPropagation, NULL, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Event_Event, isDefaultPrevented, NULL, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Event_Event, isPropagationStopped, NULL, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Event_Event, __get, arginfo_xpl_event_event___get, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Event_Event, __isset, arginfo_xpl_event_event___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Event_Event, __set, arginfo_xpl_event_event___set, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Event_Event, __unset, arginfo_xpl_event_event___unset, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
