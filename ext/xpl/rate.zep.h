
extern zend_class_entry *xpl_rate_ce;

ZEPHIR_INIT_CLASS(Xpl_Rate);

PHP_METHOD(Xpl_Rate, __construct);
PHP_METHOD(Xpl_Rate, format);
PHP_METHOD(Xpl_Rate, parsePercent);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_rate___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, number)
	ZEND_ARG_INFO(0, precision)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_rate_format, 0, 0, 0)
	ZEND_ARG_INFO(0, decimals)
	ZEND_ARG_INFO(0, appendPctSign)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_rate_parsepercent, 0, 0, 1)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_rate_method_entry) {
	PHP_ME(Xpl_Rate, __construct, arginfo_xpl_rate___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Xpl_Rate, format, arginfo_xpl_rate_format, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Rate, parsePercent, arginfo_xpl_rate_parsepercent, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
