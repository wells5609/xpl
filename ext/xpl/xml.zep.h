
extern zend_class_entry *xpl_xml_ce;

ZEPHIR_INIT_CLASS(Xpl_Xml);

PHP_METHOD(Xpl_Xml, encode);
PHP_METHOD(Xpl_Xml, decode);
PHP_METHOD(Xpl_Xml, validate);
PHP_METHOD(Xpl_Xml, writeElement);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_xml_encode, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, root_tag)
	ZEND_ARG_INFO(0, version)
	ZEND_ARG_INFO(0, encoding)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_xml_decode, 0, 0, 1)
	ZEND_ARG_INFO(0, xml)
	ZEND_ARG_INFO(0, assoc)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_xml_validate, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_xml_writeelement, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, writer, XMLWriter, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_xml_method_entry) {
	PHP_ME(Xpl_Xml, encode, arginfo_xpl_xml_encode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Xml, decode, arginfo_xpl_xml_decode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Xml, validate, arginfo_xpl_xml_validate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Xml, writeElement, arginfo_xpl_xml_writeelement, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
