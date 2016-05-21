
extern zend_class_entry *xpl_collection_scalarset_ce;

ZEPHIR_INIT_CLASS(Xpl_Collection_ScalarSet);

PHP_METHOD(Xpl_Collection_ScalarSet, add);
PHP_METHOD(Xpl_Collection_ScalarSet, remove);
PHP_METHOD(Xpl_Collection_ScalarSet, attach);
PHP_METHOD(Xpl_Collection_ScalarSet, detach);
PHP_METHOD(Xpl_Collection_ScalarSet, contains);
PHP_METHOD(Xpl_Collection_ScalarSet, getHash);
PHP_METHOD(Xpl_Collection_ScalarSet, isEmpty);
PHP_METHOD(Xpl_Collection_ScalarSet, toArray);
PHP_METHOD(Xpl_Collection_ScalarSet, addAll);
PHP_METHOD(Xpl_Collection_ScalarSet, cast);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_scalarset_add, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_scalarset_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, inf)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_scalarset_attach, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, inf)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_scalarset_detach, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, inf)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_scalarset_contains, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_scalarset_gethash, 0, 0, 1)
	ZEND_ARG_INFO(0, obj)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_scalarset_addall, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_scalarset_cast, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_collection_scalarset_method_entry) {
	PHP_ME(Xpl_Collection_ScalarSet, add, arginfo_xpl_collection_scalarset_add, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_ScalarSet, remove, arginfo_xpl_collection_scalarset_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_ScalarSet, attach, arginfo_xpl_collection_scalarset_attach, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_ScalarSet, detach, arginfo_xpl_collection_scalarset_detach, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_ScalarSet, contains, arginfo_xpl_collection_scalarset_contains, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_ScalarSet, getHash, arginfo_xpl_collection_scalarset_gethash, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_ScalarSet, isEmpty, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_ScalarSet, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_ScalarSet, addAll, arginfo_xpl_collection_scalarset_addall, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_ScalarSet, cast, arginfo_xpl_collection_scalarset_cast, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
