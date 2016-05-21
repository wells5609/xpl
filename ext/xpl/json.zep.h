
extern zend_class_entry *xpl_json_ce;

ZEPHIR_INIT_CLASS(Xpl_Json);

PHP_METHOD(Xpl_Json, encode);
PHP_METHOD(Xpl_Json, decode);
PHP_METHOD(Xpl_Json, decodeFile);
PHP_METHOD(Xpl_Json, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_json_encode, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_json_decode, 0, 0, 1)
	ZEND_ARG_INFO(0, json)
	ZEND_ARG_INFO(0, assoc)
	ZEND_ARG_INFO(0, depth)
	ZEND_ARG_INFO(0, flags)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_json_decodefile, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, assoc)
	ZEND_ARG_INFO(0, depth)
	ZEND_ARG_INFO(0, flags)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_json_validate, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_json_method_entry) {
	PHP_ME(Xpl_Json, encode, arginfo_xpl_json_encode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Json, decode, arginfo_xpl_json_decode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Json, decodeFile, arginfo_xpl_json_decodefile, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Json, validate, arginfo_xpl_json_validate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
