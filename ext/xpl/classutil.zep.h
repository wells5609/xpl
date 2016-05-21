
extern zend_class_entry *xpl_classutil_ce;

ZEPHIR_INIT_CLASS(Xpl_ClassUtil);

PHP_METHOD(Xpl_ClassUtil, createInstance);
PHP_METHOD(Xpl_ClassUtil, newInstance);
PHP_METHOD(Xpl_ClassUtil, classBasename);
PHP_METHOD(Xpl_ClassUtil, classNamespace);
PHP_METHOD(Xpl_ClassUtil, realclass);
PHP_METHOD(Xpl_ClassUtil, classType);
void zephir_init_static_properties_Xpl_ClassUtil(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_classutil_createinstance, 0, 0, 1)
	ZEND_ARG_INFO(0, classname)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_classutil_newinstance, 0, 0, 1)
	ZEND_ARG_INFO(0, classname)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_classutil_classbasename, 0, 0, 1)
	ZEND_ARG_INFO(0, classname)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_classutil_classnamespace, 0, 0, 1)
	ZEND_ARG_INFO(0, classname)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_classutil_realclass, 0, 0, 1)
	ZEND_ARG_INFO(0, classname)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_classutil_classtype, 0, 0, 1)
	ZEND_ARG_INFO(0, obj)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_classutil_method_entry) {
	PHP_ME(Xpl_ClassUtil, createInstance, arginfo_xpl_classutil_createinstance, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_ClassUtil, newInstance, arginfo_xpl_classutil_newinstance, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_ClassUtil, classBasename, arginfo_xpl_classutil_classbasename, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_ClassUtil, classNamespace, arginfo_xpl_classutil_classnamespace, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_ClassUtil, realclass, arginfo_xpl_classutil_realclass, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_ClassUtil, classType, arginfo_xpl_classutil_classtype, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
