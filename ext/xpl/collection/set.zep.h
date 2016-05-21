
extern zend_class_entry *xpl_collection_set_ce;

ZEPHIR_INIT_CLASS(Xpl_Collection_Set);

PHP_METHOD(Xpl_Collection_Set, current);
PHP_METHOD(Xpl_Collection_Set, key);
PHP_METHOD(Xpl_Collection_Set, next);
PHP_METHOD(Xpl_Collection_Set, rewind);
PHP_METHOD(Xpl_Collection_Set, valid);
PHP_METHOD(Xpl_Collection_Set, add);
PHP_METHOD(Xpl_Collection_Set, remove);
PHP_METHOD(Xpl_Collection_Set, append);
PHP_METHOD(Xpl_Collection_Set, prepend);
PHP_METHOD(Xpl_Collection_Set, addAll);
PHP_METHOD(Xpl_Collection_Set, asort);
PHP_METHOD(Xpl_Collection_Set, ksort);
PHP_METHOD(Xpl_Collection_Set, natsort);
PHP_METHOD(Xpl_Collection_Set, natcasesort);
PHP_METHOD(Xpl_Collection_Set, usort);
PHP_METHOD(Xpl_Collection_Set, uasort);
PHP_METHOD(Xpl_Collection_Set, uksort);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_set_add, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_set_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_set_append, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_set_prepend, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_set_addall, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_set_usort, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_set_uasort, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_set_uksort, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_collection_set_method_entry) {
	PHP_ME(Xpl_Collection_Set, current, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Set, key, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Set, next, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Set, rewind, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Set, valid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Set, add, arginfo_xpl_collection_set_add, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Set, remove, arginfo_xpl_collection_set_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Set, append, arginfo_xpl_collection_set_append, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Set, prepend, arginfo_xpl_collection_set_prepend, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Set, addAll, arginfo_xpl_collection_set_addall, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Set, asort, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Set, ksort, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Set, natsort, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Set, natcasesort, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Set, usort, arginfo_xpl_collection_set_usort, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Set, uasort, arginfo_xpl_collection_set_uasort, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_Set, uksort, arginfo_xpl_collection_set_uksort, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
