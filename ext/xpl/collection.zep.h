
extern zend_class_entry *xpl_collection_ce;

ZEPHIR_INIT_CLASS(Xpl_Collection);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_contains, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_addall, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_collection_method_entry) {
	PHP_ABSTRACT_ME(Xpl_Collection, isEmpty, NULL)
	PHP_ABSTRACT_ME(Xpl_Collection, contains, arginfo_xpl_collection_contains)
	PHP_ABSTRACT_ME(Xpl_Collection, addAll, arginfo_xpl_collection_addall)
	PHP_FE_END
};
