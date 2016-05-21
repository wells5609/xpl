
extern zend_class_entry *xpl_comparator_ce;

ZEPHIR_INIT_CLASS(Xpl_Comparator);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_comparator_compare, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_comparator_method_entry) {
	PHP_ABSTRACT_ME(Xpl_Comparator, compare, arginfo_xpl_comparator_compare)
	PHP_FE_END
};
