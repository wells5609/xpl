
extern zend_class_entry *xpl_configurableinterface_ce;

ZEPHIR_INIT_CLASS(Xpl_ConfigurableInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_configurableinterface_setconfig, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, config, Xpl\\Collection\\Config, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_configurableinterface_method_entry) {
	PHP_ABSTRACT_ME(Xpl_ConfigurableInterface, setConfig, arginfo_xpl_configurableinterface_setconfig)
	PHP_ABSTRACT_ME(Xpl_ConfigurableInterface, getConfig, NULL)
	PHP_FE_END
};
