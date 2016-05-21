
extern zend_class_entry *xpl_collection_sequence_ce;

ZEPHIR_INIT_CLASS(Xpl_Collection_Sequence);

PHP_METHOD(Xpl_Collection_Sequence, __construct);
PHP_METHOD(Xpl_Collection_Sequence, add);
PHP_METHOD(Xpl_Collection_Sequence, remove);
PHP_METHOD(Xpl_Collection_Sequence, isEmpty);
PHP_METHOD(Xpl_Collection_Sequence, contains);
PHP_METHOD(Xpl_Collection_Sequence, addAll);
PHP_METHOD(Xpl_Collection_Sequence, serialize);
PHP_METHOD(Xpl_Collection_Sequence, unserialize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_sequence___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_sequence_add, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_sequence_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_sequence_contains, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_sequence_addall, 0, 0, 1)
	ZEND_ARG_INFO(0, values)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_sequence_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, serialized)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_collection_sequence_method_entry) {
	PHP_ME(Xpl_Collection_Sequence, __construct, arginfo_xpl_collection_sequence___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Xpl_Collection_Sequence, add, arginfo_xpl_collection_sequence_add, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Sequence, remove, arginfo_xpl_collection_sequence_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Sequence, isEmpty, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Sequence, contains, arginfo_xpl_collection_sequence_contains, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Sequence, addAll, arginfo_xpl_collection_sequence_addall, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Sequence, serialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Sequence, unserialize, arginfo_xpl_collection_sequence_unserialize, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
