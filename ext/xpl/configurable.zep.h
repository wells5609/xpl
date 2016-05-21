
extern zend_class_entry *xpl_configurable_ce;

ZEPHIR_INIT_CLASS(Xpl_Configurable);

PHP_METHOD(Xpl_Configurable, setConfig);
PHP_METHOD(Xpl_Configurable, getConfig);
PHP_METHOD(Xpl_Configurable, injectConfig);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_configurable_setconfig, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, config, Xpl\\Collection\\Config, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_configurable_method_entry) {
	PHP_ME(Xpl_Configurable, setConfig, arginfo_xpl_configurable_setconfig, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Configurable, getConfig, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Configurable, injectConfig, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
