
extern zend_class_entry *xpl_collection_listinterface_ce;

ZEPHIR_INIT_CLASS(Xpl_Collection_ListInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_listinterface_add, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_listinterface_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_collection_listinterface_method_entry) {
	PHP_ABSTRACT_ME(Xpl_Collection_ListInterface, add, arginfo_xpl_collection_listinterface_add)
	PHP_ABSTRACT_ME(Xpl_Collection_ListInterface, remove, arginfo_xpl_collection_listinterface_remove)
	PHP_FE_END
};
