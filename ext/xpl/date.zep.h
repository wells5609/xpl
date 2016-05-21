
extern zend_class_entry *xpl_date_ce;

ZEPHIR_INIT_CLASS(Xpl_Date);

PHP_METHOD(Xpl_Date, isValid);
PHP_METHOD(Xpl_Date, time);
PHP_METHOD(Xpl_Date, make);
PHP_METHOD(Xpl_Date, timezone);
PHP_METHOD(Xpl_Date, format);
PHP_METHOD(Xpl_Date, formatHuman);
PHP_METHOD(Xpl_Date, formatSql);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_date_isvalid, 0, 0, 1)
	ZEND_ARG_INFO(0, dateTime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_date_time, 0, 0, 0)
	ZEND_ARG_INFO(0, time)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_date_make, 0, 0, 0)
	ZEND_ARG_INFO(0, time)
	ZEND_ARG_INFO(0, timezone)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_date_timezone, 0, 0, 0)
	ZEND_ARG_INFO(0, timezone)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_date_format, 0, 0, 2)
	ZEND_ARG_INFO(0, dateTime)
	ZEND_ARG_INFO(0, format)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_date_formathuman, 0, 0, 1)
	ZEND_ARG_INFO(0, dateTime)
	ZEND_ARG_INFO(0, format)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_date_formatsql, 0, 0, 1)
	ZEND_ARG_INFO(0, dateTime)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_date_method_entry) {
	PHP_ME(Xpl_Date, isValid, arginfo_xpl_date_isvalid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Date, time, arginfo_xpl_date_time, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Date, make, arginfo_xpl_date_make, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Date, timezone, arginfo_xpl_date_timezone, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Date, format, arginfo_xpl_date_format, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Date, formatHuman, arginfo_xpl_date_formathuman, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Date, formatSql, arginfo_xpl_date_formatsql, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
