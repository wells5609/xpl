
extern zend_class_entry *xpl_serializer_serializer_ce;

ZEPHIR_INIT_CLASS(Xpl_Serializer_Serializer);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_serializer_serializer_serialize, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_serializer_serializer_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, serializedData)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_serializer_serializer_method_entry) {
	PHP_ABSTRACT_ME(Xpl_Serializer_Serializer, isAvailable, NULL)
	PHP_ABSTRACT_ME(Xpl_Serializer_Serializer, serialize, arginfo_xpl_serializer_serializer_serialize)
	PHP_ABSTRACT_ME(Xpl_Serializer_Serializer, unserialize, arginfo_xpl_serializer_serializer_unserialize)
	PHP_FE_END
};
