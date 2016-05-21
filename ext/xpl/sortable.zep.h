
extern zend_class_entry *xpl_sortable_ce;

ZEPHIR_INIT_CLASS(Xpl_Sortable);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_sortable_usort, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_sortable_uasort, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_sortable_uksort, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_sortable_method_entry) {
	PHP_ABSTRACT_ME(Xpl_Sortable, asort, NULL)
	PHP_ABSTRACT_ME(Xpl_Sortable, ksort, NULL)
	PHP_ABSTRACT_ME(Xpl_Sortable, natsort, NULL)
	PHP_ABSTRACT_ME(Xpl_Sortable, natcasesort, NULL)
	PHP_ABSTRACT_ME(Xpl_Sortable, usort, arginfo_xpl_sortable_usort)
	PHP_ABSTRACT_ME(Xpl_Sortable, uasort, arginfo_xpl_sortable_uasort)
	PHP_ABSTRACT_ME(Xpl_Sortable, uksort, arginfo_xpl_sortable_uksort)
	PHP_FE_END
};
