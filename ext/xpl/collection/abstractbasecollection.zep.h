
extern zend_class_entry *xpl_collection_abstractbasecollection_ce;

ZEPHIR_INIT_CLASS(Xpl_Collection_AbstractBaseCollection);

PHP_METHOD(Xpl_Collection_AbstractBaseCollection, toArray);
PHP_METHOD(Xpl_Collection_AbstractBaseCollection, isEmpty);
PHP_METHOD(Xpl_Collection_AbstractBaseCollection, contains);
PHP_METHOD(Xpl_Collection_AbstractBaseCollection, count);
PHP_METHOD(Xpl_Collection_AbstractBaseCollection, serialize);
PHP_METHOD(Xpl_Collection_AbstractBaseCollection, unserialize);
static zend_object_value zephir_init_properties_Xpl_Collection_AbstractBaseCollection(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_abstractbasecollection_contains, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_abstractbasecollection_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, serialized)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_collection_abstractbasecollection_method_entry) {
	PHP_ME(Xpl_Collection_AbstractBaseCollection, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_AbstractBaseCollection, isEmpty, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_AbstractBaseCollection, contains, arginfo_xpl_collection_abstractbasecollection_contains, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_AbstractBaseCollection, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_AbstractBaseCollection, serialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Collection_AbstractBaseCollection, unserialize, arginfo_xpl_collection_abstractbasecollection_unserialize, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
