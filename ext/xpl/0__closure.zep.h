
extern zend_class_entry *xpl_0__closure_ce;

ZEPHIR_INIT_CLASS(xpl_0__closure);

PHP_METHOD(xpl_0__closure, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_0__closure___invoke, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, request, xpl\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, xpl\\ResponseInterface, 0)
	ZEND_ARG_INFO(0, next)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_0__closure_method_entry) {
	PHP_ME(xpl_0__closure, __invoke, arginfo_xpl_0__closure___invoke, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_FE_END
};
