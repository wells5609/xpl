
extern zend_class_entry *xpl_macroable_ce;

ZEPHIR_INIT_CLASS(Xpl_Macroable);

PHP_METHOD(Xpl_Macroable, getMacros);
PHP_METHOD(Xpl_Macroable, addMacro);
PHP_METHOD(Xpl_Macroable, hasMacro);
PHP_METHOD(Xpl_Macroable, getMacro);
PHP_METHOD(Xpl_Macroable, doMacro);
PHP_METHOD(Xpl_Macroable, isCallable);
PHP_METHOD(Xpl_Macroable, __call);
PHP_METHOD(Xpl_Macroable, __invoke);
PHP_METHOD(Xpl_Macroable, __toString);
static zend_object_value zephir_init_properties_Xpl_Macroable(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_macroable_addmacro, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_macroable_hasmacro, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_macroable_getmacro, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_macroable_domacro, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_macroable_iscallable, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_macroable___call, 0, 0, 2)
	ZEND_ARG_INFO(0, func)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_macroable_method_entry) {
	PHP_ME(Xpl_Macroable, getMacros, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Macroable, addMacro, arginfo_xpl_macroable_addmacro, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Macroable, hasMacro, arginfo_xpl_macroable_hasmacro, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Macroable, getMacro, arginfo_xpl_macroable_getmacro, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Macroable, doMacro, arginfo_xpl_macroable_domacro, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Macroable, isCallable, arginfo_xpl_macroable_iscallable, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Macroable, __call, arginfo_xpl_macroable___call, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Macroable, __invoke, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Macroable, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
