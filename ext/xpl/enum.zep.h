
extern zend_class_entry *xpl_enum_ce;

ZEPHIR_INIT_CLASS(Xpl_Enum);

PHP_METHOD(Xpl_Enum, __construct);
PHP_METHOD(Xpl_Enum, getValue);
PHP_METHOD(Xpl_Enum, evaluate);
PHP_METHOD(Xpl_Enum, getConstantName);
PHP_METHOD(Xpl_Enum, getDefaultValue);
PHP_METHOD(Xpl_Enum, isDefault);
PHP_METHOD(Xpl_Enum, __get);
PHP_METHOD(Xpl_Enum, __toString);
PHP_METHOD(Xpl_Enum, getConstants);
PHP_METHOD(Xpl_Enum, filterValidateValue);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_enum___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_enum___get, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_enum_getconstants, 0, 0, 0)
	ZEND_ARG_INFO(0, classname)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_enum_filtervalidatevalue, 0, 0, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_enum_method_entry) {
	PHP_ME(Xpl_Enum, __construct, arginfo_xpl_enum___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Xpl_Enum, getValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Enum, evaluate, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Enum, getConstantName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Enum, getDefaultValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Enum, isDefault, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Enum, __get, arginfo_xpl_enum___get, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Enum, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Enum, getConstants, arginfo_xpl_enum_getconstants, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Enum, filterValidateValue, arginfo_xpl_enum_filtervalidatevalue, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
