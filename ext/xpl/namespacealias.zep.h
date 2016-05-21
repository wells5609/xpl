
extern zend_class_entry *xpl_namespacealias_ce;

ZEPHIR_INIT_CLASS(Xpl_NamespaceAlias);

PHP_METHOD(Xpl_NamespaceAlias, __construct);
PHP_METHOD(Xpl_NamespaceAlias, load);
PHP_METHOD(Xpl_NamespaceAlias, getResolved);
PHP_METHOD(Xpl_NamespaceAlias, register);
PHP_METHOD(Xpl_NamespaceAlias, unregister);
static zend_object_value zephir_init_properties_Xpl_NamespaceAlias(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_namespacealias___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, original)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_namespacealias_load, 0, 0, 1)
	ZEND_ARG_INFO(0, classname)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_namespacealias_method_entry) {
	PHP_ME(Xpl_NamespaceAlias, __construct, arginfo_xpl_namespacealias___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Xpl_NamespaceAlias, load, arginfo_xpl_namespacealias_load, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_NamespaceAlias, getResolved, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_NamespaceAlias, register, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_NamespaceAlias, unregister, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
