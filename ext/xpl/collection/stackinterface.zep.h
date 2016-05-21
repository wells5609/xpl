
extern zend_class_entry *xpl_collection_stackinterface_ce;

ZEPHIR_INIT_CLASS(Xpl_Collection_StackInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_stackinterface_push, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_collection_stackinterface_method_entry) {
	PHP_ABSTRACT_ME(Xpl_Collection_StackInterface, push, arginfo_xpl_collection_stackinterface_push)
	PHP_ABSTRACT_ME(Xpl_Collection_StackInterface, pop, NULL)
	PHP_FE_END
};
