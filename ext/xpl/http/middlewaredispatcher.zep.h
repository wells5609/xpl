
extern zend_class_entry *xpl_http_middlewaredispatcher_ce;

ZEPHIR_INIT_CLASS(Xpl_Http_MiddlewareDispatcher);

PHP_METHOD(Xpl_Http_MiddlewareDispatcher, __construct);
PHP_METHOD(Xpl_Http_MiddlewareDispatcher, __invoke);
PHP_METHOD(Xpl_Http_MiddlewareDispatcher, getFinalMiddleware);
PHP_METHOD(Xpl_Http_MiddlewareDispatcher, setFinalMiddleware);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_http_middlewaredispatcher___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, queue, Xpl\\Http\\MiddlewareQueue, 0)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, finalMiddleware)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_http_middlewaredispatcher___invoke, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, Psr\\Http\\Message\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, Psr\\Http\\Message\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_http_middlewaredispatcher_setfinalmiddleware, 0, 0, 1)
	ZEND_ARG_INFO(0, middleware)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_http_middlewaredispatcher_method_entry) {
	PHP_ME(Xpl_Http_MiddlewareDispatcher, __construct, arginfo_xpl_http_middlewaredispatcher___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Xpl_Http_MiddlewareDispatcher, __invoke, arginfo_xpl_http_middlewaredispatcher___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Http_MiddlewareDispatcher, getFinalMiddleware, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Http_MiddlewareDispatcher, setFinalMiddleware, arginfo_xpl_http_middlewaredispatcher_setfinalmiddleware, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
