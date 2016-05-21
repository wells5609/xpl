
extern zend_class_entry *xpl_money_ce;

ZEPHIR_INIT_CLASS(Xpl_Money);

PHP_METHOD(Xpl_Money, format);
PHP_METHOD(Xpl_Money, getNumberFormatter);
PHP_METHOD(Xpl_Money, getLocale);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_money_format, 0, 0, 0)
	ZEND_ARG_INFO(0, decimals)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_money_getnumberformatter, 0, 0, 0)
	ZEND_ARG_INFO(0, locale)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_money_method_entry) {
	PHP_ME(Xpl_Money, format, arginfo_xpl_money_format, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Money, getNumberFormatter, arginfo_xpl_money_getnumberformatter, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Money, getLocale, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
