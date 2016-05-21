
extern zend_class_entry *xpl_system_ce;

ZEPHIR_INIT_CLASS(Xpl_System);

PHP_METHOD(Xpl_System, sapi);
PHP_METHOD(Xpl_System, os);
PHP_METHOD(Xpl_System, version);
PHP_METHOD(Xpl_System, isCli);
PHP_METHOD(Xpl_System, isWin);
PHP_METHOD(Xpl_System, memoryUsage);
PHP_METHOD(Xpl_System, memoryPeakUsage);
PHP_METHOD(Xpl_System, timer);
PHP_METHOD(Xpl_System, apc);
PHP_METHOD(Xpl_System, apcu);
PHP_METHOD(Xpl_System, xdebug);
PHP_METHOD(Xpl_System, mbstring);
PHP_METHOD(Xpl_System, normalizePath);
PHP_METHOD(Xpl_System, tempDir);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_system_version, 0, 0, 0)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_system_memoryusage, 0, 0, 0)
	ZEND_ARG_INFO(0, megabytes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_system_memorypeakusage, 0, 0, 0)
	ZEND_ARG_INFO(0, megabytes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_system_timer, 0, 0, 0)
	ZEND_ARG_INFO(0, milliseconds)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_system_normalizepath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_system_method_entry) {
	PHP_ME(Xpl_System, sapi, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_System, os, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_System, version, arginfo_xpl_system_version, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_System, isCli, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_System, isWin, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_System, memoryUsage, arginfo_xpl_system_memoryusage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_System, memoryPeakUsage, arginfo_xpl_system_memorypeakusage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_System, timer, arginfo_xpl_system_timer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_System, apc, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_System, apcu, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_System, xdebug, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_System, mbstring, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_System, normalizePath, arginfo_xpl_system_normalizepath, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_System, tempDir, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
