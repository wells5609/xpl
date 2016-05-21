
extern zend_class_entry *xpl_filesystem_container_ce;

ZEPHIR_INIT_CLASS(Xpl_Filesystem_Container);

PHP_METHOD(Xpl_Filesystem_Container, getRootPath);
PHP_METHOD(Xpl_Filesystem_Container, __construct);
PHP_METHOD(Xpl_Filesystem_Container, setPaths);
PHP_METHOD(Xpl_Filesystem_Container, getPaths);
PHP_METHOD(Xpl_Filesystem_Container, addPath);
PHP_METHOD(Xpl_Filesystem_Container, hasPath);
PHP_METHOD(Xpl_Filesystem_Container, getRelativePath);
PHP_METHOD(Xpl_Filesystem_Container, find);
PHP_METHOD(Xpl_Filesystem_Container, search);
PHP_METHOD(Xpl_Filesystem_Container, count);
static zend_object_value zephir_init_properties_Xpl_Filesystem_Container(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_filesystem_container___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, rootPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_filesystem_container_setpaths, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, paths, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_filesystem_container_addpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_filesystem_container_haspath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_filesystem_container_getrelativepath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_filesystem_container_find, 0, 0, 1)
	ZEND_ARG_INFO(0, filename)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_filesystem_container_search, 0, 0, 1)
	ZEND_ARG_INFO(0, filename)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_filesystem_container_method_entry) {
	PHP_ME(Xpl_Filesystem_Container, getRootPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Filesystem_Container, __construct, arginfo_xpl_filesystem_container___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Xpl_Filesystem_Container, setPaths, arginfo_xpl_filesystem_container_setpaths, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Filesystem_Container, getPaths, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Filesystem_Container, addPath, arginfo_xpl_filesystem_container_addpath, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Filesystem_Container, hasPath, arginfo_xpl_filesystem_container_haspath, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Filesystem_Container, getRelativePath, arginfo_xpl_filesystem_container_getrelativepath, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Filesystem_Container, find, arginfo_xpl_filesystem_container_find, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Filesystem_Container, search, arginfo_xpl_filesystem_container_search, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Filesystem_Container, count, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
