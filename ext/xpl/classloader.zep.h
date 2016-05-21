
extern zend_class_entry *xpl_classloader_ce;

ZEPHIR_INIT_CLASS(Xpl_ClassLoader);

PHP_METHOD(Xpl_ClassLoader, composer);
PHP_METHOD(Xpl_ClassLoader, getPrefixes);
PHP_METHOD(Xpl_ClassLoader, getPrefixesPsr4);
PHP_METHOD(Xpl_ClassLoader, getFallbackDirs);
PHP_METHOD(Xpl_ClassLoader, getFallbackDirsPsr4);
PHP_METHOD(Xpl_ClassLoader, getClassMap);
PHP_METHOD(Xpl_ClassLoader, addClassMap);
PHP_METHOD(Xpl_ClassLoader, add);
PHP_METHOD(Xpl_ClassLoader, addPsr4);
PHP_METHOD(Xpl_ClassLoader, set);
PHP_METHOD(Xpl_ClassLoader, setPsr4);
PHP_METHOD(Xpl_ClassLoader, setUseIncludePath);
PHP_METHOD(Xpl_ClassLoader, getUseIncludePath);
PHP_METHOD(Xpl_ClassLoader, register);
PHP_METHOD(Xpl_ClassLoader, unregister);
PHP_METHOD(Xpl_ClassLoader, loadClass);
PHP_METHOD(Xpl_ClassLoader, findFile);
PHP_METHOD(Xpl_ClassLoader, findFileWithExtension);
PHP_METHOD(Xpl_ClassLoader, setComposerPath);
PHP_METHOD(Xpl_ClassLoader, getComposerPath);
PHP_METHOD(Xpl_ClassLoader, export);
PHP_METHOD(Xpl_ClassLoader, import);
PHP_METHOD(Xpl_ClassLoader, fromExportFile);
PHP_METHOD(Xpl_ClassLoader, __set_state);
PHP_METHOD(Xpl_ClassLoader, serialize);
PHP_METHOD(Xpl_ClassLoader, unserialize);
PHP_METHOD(Xpl_ClassLoader, getHash);
static zend_object_value zephir_init_properties_Xpl_ClassLoader(zend_class_entry *class_type TSRMLS_DC);
void zephir_init_static_properties_Xpl_ClassLoader(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_classloader_composer, 0, 0, 1)
	ZEND_ARG_INFO(0, vendorPath)
	ZEND_ARG_INFO(0, prepend)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_classloader_addclassmap, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, classMap, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_classloader_add, 0, 0, 2)
	ZEND_ARG_INFO(0, prefix)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_INFO(0, prepend)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_classloader_addpsr4, 0, 0, 2)
	ZEND_ARG_INFO(0, prefix)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_INFO(0, prepend)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_classloader_set, 0, 0, 2)
	ZEND_ARG_INFO(0, prefix)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_classloader_setpsr4, 0, 0, 2)
	ZEND_ARG_INFO(0, prefix)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_classloader_setuseincludepath, 0, 0, 1)
	ZEND_ARG_INFO(0, useIncludePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_classloader_register, 0, 0, 0)
	ZEND_ARG_INFO(0, prepend)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_classloader_loadclass, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_classloader_findfile, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_classloader_findfilewithextension, 0, 0, 2)
	ZEND_ARG_INFO(0, className)
	ZEND_ARG_INFO(0, ext)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_classloader_setcomposerpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_classloader_export, 0, 0, 1)
	ZEND_ARG_INFO(0, filePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_classloader_import, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, properties, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_classloader_fromexportfile, 0, 0, 1)
	ZEND_ARG_INFO(0, filePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_classloader___set_state, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_classloader_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, serial)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_classloader_method_entry) {
	PHP_ME(Xpl_ClassLoader, composer, arginfo_xpl_classloader_composer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_ClassLoader, getPrefixes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ClassLoader, getPrefixesPsr4, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ClassLoader, getFallbackDirs, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ClassLoader, getFallbackDirsPsr4, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ClassLoader, getClassMap, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ClassLoader, addClassMap, arginfo_xpl_classloader_addclassmap, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ClassLoader, add, arginfo_xpl_classloader_add, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ClassLoader, addPsr4, arginfo_xpl_classloader_addpsr4, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ClassLoader, set, arginfo_xpl_classloader_set, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ClassLoader, setPsr4, arginfo_xpl_classloader_setpsr4, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ClassLoader, setUseIncludePath, arginfo_xpl_classloader_setuseincludepath, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ClassLoader, getUseIncludePath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ClassLoader, register, arginfo_xpl_classloader_register, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ClassLoader, unregister, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ClassLoader, loadClass, arginfo_xpl_classloader_loadclass, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ClassLoader, findFile, arginfo_xpl_classloader_findfile, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ClassLoader, findFileWithExtension, arginfo_xpl_classloader_findfilewithextension, ZEND_ACC_PROTECTED)
	PHP_ME(Xpl_ClassLoader, setComposerPath, arginfo_xpl_classloader_setcomposerpath, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ClassLoader, getComposerPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ClassLoader, export, arginfo_xpl_classloader_export, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ClassLoader, import, arginfo_xpl_classloader_import, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ClassLoader, fromExportFile, arginfo_xpl_classloader_fromexportfile, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_ClassLoader, __set_state, arginfo_xpl_classloader___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_ClassLoader, serialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ClassLoader, unserialize, arginfo_xpl_classloader_unserialize, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_ClassLoader, getHash, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
