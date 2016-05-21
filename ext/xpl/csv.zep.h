
extern zend_class_entry *xpl_csv_ce;

ZEPHIR_INIT_CLASS(Xpl_Csv);

PHP_METHOD(Xpl_Csv, encode);
PHP_METHOD(Xpl_Csv, decode);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_csv_encode, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_ARRAY_INFO(0, headers, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_csv_decode, 0, 0, 1)
	ZEND_ARG_INFO(0, csv)
	ZEND_ARG_INFO(0, assoc)
	ZEND_ARG_INFO(0, headers)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_csv_method_entry) {
	PHP_ME(Xpl_Csv, encode, arginfo_xpl_csv_encode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Csv, decode, arginfo_xpl_csv_decode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
