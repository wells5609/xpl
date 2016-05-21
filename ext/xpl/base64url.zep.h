
extern zend_class_entry *xpl_base64url_ce;

ZEPHIR_INIT_CLASS(Xpl_Base64Url);

PHP_METHOD(Xpl_Base64Url, encode);
PHP_METHOD(Xpl_Base64Url, decode);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_base64url_encode, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_base64url_decode, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_base64url_method_entry) {
	PHP_ME(Xpl_Base64Url, encode, arginfo_xpl_base64url_encode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Base64Url, decode, arginfo_xpl_base64url_decode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
