
extern zend_class_entry *xpl_collection_objectset_ce;

ZEPHIR_INIT_CLASS(Xpl_Collection_ObjectSet);

PHP_METHOD(Xpl_Collection_ObjectSet, add);
PHP_METHOD(Xpl_Collection_ObjectSet, remove);
PHP_METHOD(Xpl_Collection_ObjectSet, isEmpty);
PHP_METHOD(Xpl_Collection_ObjectSet, toArray);
PHP_METHOD(Xpl_Collection_ObjectSet, addAll);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_objectset_add, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_objectset_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_objectset_addall, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_collection_objectset_method_entry) {
	PHP_ME(Xpl_Collection_ObjectSet, add, arginfo_xpl_collection_objectset_add, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_ObjectSet, remove, arginfo_xpl_collection_objectset_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_ObjectSet, isEmpty, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_ObjectSet, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_ObjectSet, addAll, arginfo_xpl_collection_objectset_addall, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
