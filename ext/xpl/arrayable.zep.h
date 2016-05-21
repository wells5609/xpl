
extern zend_class_entry *xpl_arrayable_ce;

ZEPHIR_INIT_CLASS(Xpl_Arrayable);

ZEPHIR_INIT_FUNCS(xpl_arrayable_method_entry) {
	PHP_ABSTRACT_ME(Xpl_Arrayable, toArray, NULL)
	PHP_FE_END
};
