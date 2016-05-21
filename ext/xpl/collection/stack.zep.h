
extern zend_class_entry *xpl_collection_stack_ce;

ZEPHIR_INIT_CLASS(Xpl_Collection_Stack);

PHP_METHOD(Xpl_Collection_Stack, __construct);
PHP_METHOD(Xpl_Collection_Stack, remove);
PHP_METHOD(Xpl_Collection_Stack, contains);
PHP_METHOD(Xpl_Collection_Stack, toArray);
PHP_METHOD(Xpl_Collection_Stack, addAll);
PHP_METHOD(Xpl_Collection_Stack, getIterator);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_stack___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_stack_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_stack_contains, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_stack_addall, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_collection_stack_method_entry) {
	PHP_ME(Xpl_Collection_Stack, __construct, arginfo_xpl_collection_stack___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Xpl_Collection_Stack, remove, arginfo_xpl_collection_stack_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Stack, contains, arginfo_xpl_collection_stack_contains, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Stack, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Stack, addAll, arginfo_xpl_collection_stack_addall, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Stack, getIterator, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
