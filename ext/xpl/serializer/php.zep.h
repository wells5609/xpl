
extern zend_class_entry *xpl_serializer_php_ce;

ZEPHIR_INIT_CLASS(Xpl_Serializer_Php);

PHP_METHOD(Xpl_Serializer_Php, isAvailable);
PHP_METHOD(Xpl_Serializer_Php, serialize);
PHP_METHOD(Xpl_Serializer_Php, unserialize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_serializer_php_serialize, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_serializer_php_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, serializedData)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_serializer_php_method_entry) {
	PHP_ME(Xpl_Serializer_Php, isAvailable, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Serializer_Php, serialize, arginfo_xpl_serializer_php_serialize, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Serializer_Php, unserialize, arginfo_xpl_serializer_php_unserialize, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
