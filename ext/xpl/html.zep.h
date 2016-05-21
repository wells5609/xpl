
extern zend_class_entry *xpl_html_ce;

ZEPHIR_INIT_CLASS(Xpl_Html);

PHP_METHOD(Xpl_Html, make);
PHP_METHOD(Xpl_Html, attributeString);
PHP_METHOD(Xpl_Html, parseAttributes);
PHP_METHOD(Xpl_Html, escapeAttribute);
PHP_METHOD(Xpl_Html, isSelfClosingTag);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_html_make, 0, 0, 1)
	ZEND_ARG_INFO(0, tag)
	ZEND_ARG_INFO(0, attributes)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_html_attributestring, 0, 0, 1)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_html_parseattributes, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_html_escapeattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_html_isselfclosingtag, 0, 0, 1)
	ZEND_ARG_INFO(0, tag)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_html_method_entry) {
	PHP_ME(Xpl_Html, make, arginfo_xpl_html_make, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Html, attributeString, arginfo_xpl_html_attributestring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Html, parseAttributes, arginfo_xpl_html_parseattributes, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Html, escapeAttribute, arginfo_xpl_html_escapeattribute, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Html, isSelfClosingTag, arginfo_xpl_html_isselfclosingtag, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
