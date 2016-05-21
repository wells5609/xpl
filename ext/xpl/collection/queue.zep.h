
extern zend_class_entry *xpl_collection_queue_ce;

ZEPHIR_INIT_CLASS(Xpl_Collection_Queue);

PHP_METHOD(Xpl_Collection_Queue, __construct);
PHP_METHOD(Xpl_Collection_Queue, remove);
PHP_METHOD(Xpl_Collection_Queue, contains);
PHP_METHOD(Xpl_Collection_Queue, toArray);
PHP_METHOD(Xpl_Collection_Queue, addAll);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_queue___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_queue_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_queue_contains, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_queue_addall, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_collection_queue_method_entry) {
	PHP_ME(Xpl_Collection_Queue, __construct, arginfo_xpl_collection_queue___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Xpl_Collection_Queue, remove, arginfo_xpl_collection_queue_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Queue, contains, arginfo_xpl_collection_queue_contains, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Queue, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Queue, addAll, arginfo_xpl_collection_queue_addall, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
