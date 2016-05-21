
extern zend_class_entry *xpl_object_ce;

ZEPHIR_INIT_CLASS(Xpl_Object);

PHP_METHOD(Xpl_Object, equals);
PHP_METHOD(Xpl_Object, getObjectHash);
PHP_METHOD(Xpl_Object, valueOf);
PHP_METHOD(Xpl_Object, serialize);
PHP_METHOD(Xpl_Object, unserialize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_object_equals, 0, 0, 1)
	ZEND_ARG_INFO(0, obj)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_object_valueof, 0, 0, 1)
	ZEND_ARG_INFO(0, obj)
	ZEND_ARG_ARRAY_INFO(0, ctorArgs, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_object_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, serial)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_object_method_entry) {
	PHP_ME(Xpl_Object, equals, arginfo_xpl_object_equals, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Object, getObjectHash, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Object, valueOf, arginfo_xpl_object_valueof, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Object, serialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Object, unserialize, arginfo_xpl_object_unserialize, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
