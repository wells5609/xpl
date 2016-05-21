
extern zend_class_entry *xpl_event_listener_ce;

ZEPHIR_INIT_CLASS(Xpl_Event_Listener);

PHP_METHOD(Xpl_Event_Listener, __construct);
PHP_METHOD(Xpl_Event_Listener, __invoke);
PHP_METHOD(Xpl_Event_Listener, __get);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_event_listener___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, event_id)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_event_listener___invoke, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_event_listener___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_event_listener_method_entry) {
	PHP_ME(Xpl_Event_Listener, __construct, arginfo_xpl_event_listener___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Xpl_Event_Listener, __invoke, arginfo_xpl_event_listener___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Event_Listener, __get, arginfo_xpl_event_listener___get, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
