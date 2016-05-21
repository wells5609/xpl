
extern zend_class_entry *xpl_listinterface_ce;

ZEPHIR_INIT_CLASS(Xpl_ListInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_listinterface_push, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_listinterface_method_entry) {
	PHP_ABSTRACT_ME(Xpl_ListInterface, push, arginfo_xpl_listinterface_push)
	PHP_ABSTRACT_ME(Xpl_ListInterface, pop, NULL)
	PHP_FE_END
};
