
extern zend_class_entry *xpl_collection_setinterface_ce;

ZEPHIR_INIT_CLASS(Xpl_Collection_SetInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_setinterface_add, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_setinterface_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_collection_setinterface_method_entry) {
	PHP_ABSTRACT_ME(Xpl_Collection_SetInterface, add, arginfo_xpl_collection_setinterface_add)
	PHP_ABSTRACT_ME(Xpl_Collection_SetInterface, remove, arginfo_xpl_collection_setinterface_remove)
	PHP_FE_END
};
