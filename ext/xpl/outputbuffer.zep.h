
extern zend_class_entry *xpl_outputbuffer_ce;

ZEPHIR_INIT_CLASS(Xpl_OutputBuffer);

PHP_METHOD(Xpl_OutputBuffer, start);
PHP_METHOD(Xpl_OutputBuffer, finish);
PHP_METHOD(Xpl_OutputBuffer, __construct);
PHP_METHOD(Xpl_OutputBuffer, getContents);
PHP_METHOD(Xpl_OutputBuffer, getClean);
PHP_METHOD(Xpl_OutputBuffer, getFullClean);
PHP_METHOD(Xpl_OutputBuffer, clean);
PHP_METHOD(Xpl_OutputBuffer, fullClean);
PHP_METHOD(Xpl_OutputBuffer, flush);
PHP_METHOD(Xpl_OutputBuffer, endFlush);
PHP_METHOD(Xpl_OutputBuffer, valid);
PHP_METHOD(Xpl_OutputBuffer, active);
PHP_METHOD(Xpl_OutputBuffer, getLevel);
PHP_METHOD(Xpl_OutputBuffer, getOutputCallback);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_outputbuffer_start, 0, 0, 0)
	ZEND_ARG_INFO(0, outputCallback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_outputbuffer___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, outputCallback)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_outputbuffer_method_entry) {
	PHP_ME(Xpl_OutputBuffer, start, arginfo_xpl_outputbuffer_start, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_OutputBuffer, finish, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_OutputBuffer, __construct, arginfo_xpl_outputbuffer___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Xpl_OutputBuffer, getContents, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_OutputBuffer, getClean, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_OutputBuffer, getFullClean, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_OutputBuffer, clean, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_OutputBuffer, fullClean, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_OutputBuffer, flush, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_OutputBuffer, endFlush, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_OutputBuffer, valid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_OutputBuffer, active, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_OutputBuffer, getLevel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_OutputBuffer, getOutputCallback, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
