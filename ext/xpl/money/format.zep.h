
extern zend_class_entry *xpl_money_format_ce;

ZEPHIR_INIT_CLASS(Xpl_Money_Format);

PHP_METHOD(Xpl_Money_Format, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_money_format___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, localeConv)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_money_format_method_entry) {
	PHP_ME(Xpl_Money_Format, __construct, arginfo_xpl_money_format___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
