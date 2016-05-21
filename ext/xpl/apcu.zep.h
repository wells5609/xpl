
extern zend_class_entry *xpl_apcu_ce;

ZEPHIR_INIT_CLASS(Xpl_Apcu);

PHP_METHOD(Xpl_Apcu, loaded);
PHP_METHOD(Xpl_Apcu, enabled);
PHP_METHOD(Xpl_Apcu, setPrefix);
PHP_METHOD(Xpl_Apcu, getPrefix);
PHP_METHOD(Xpl_Apcu, get);
PHP_METHOD(Xpl_Apcu, set);
PHP_METHOD(Xpl_Apcu, exists);
PHP_METHOD(Xpl_Apcu, delete);
PHP_METHOD(Xpl_Apcu, clear);
PHP_METHOD(Xpl_Apcu, expiry);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_apcu_setprefix, 0, 0, 1)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_apcu_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_apcu_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_apcu_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_apcu_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_apcu_expiry, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_apcu_method_entry) {
	PHP_ME(Xpl_Apcu, loaded, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Apcu, enabled, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Apcu, setPrefix, arginfo_xpl_apcu_setprefix, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Apcu, getPrefix, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Apcu, get, arginfo_xpl_apcu_get, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Apcu, set, arginfo_xpl_apcu_set, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Apcu, exists, arginfo_xpl_apcu_exists, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Apcu, delete, arginfo_xpl_apcu_delete, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Apcu, clear, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Apcu, expiry, arginfo_xpl_apcu_expiry, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
