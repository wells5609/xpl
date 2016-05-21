
extern zend_class_entry *xpl_config_ce;

ZEPHIR_INIT_CLASS(Xpl_Config);

PHP_METHOD(Xpl_Config, import);
PHP_METHOD(Xpl_Config, toArray);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_config_import, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_config_method_entry) {
	PHP_ME(Xpl_Config, import, arginfo_xpl_config_import, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Config, toArray, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
