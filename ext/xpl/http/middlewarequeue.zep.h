
extern zend_class_entry *xpl_http_middlewarequeue_ce;

ZEPHIR_INIT_CLASS(Xpl_Http_MiddlewareQueue);

PHP_METHOD(Xpl_Http_MiddlewareQueue, enqueue);
PHP_METHOD(Xpl_Http_MiddlewareQueue, offsetSet);
PHP_METHOD(Xpl_Http_MiddlewareQueue, push);
PHP_METHOD(Xpl_Http_MiddlewareQueue, attach);
PHP_METHOD(Xpl_Http_MiddlewareQueue, unshift);
PHP_METHOD(Xpl_Http_MiddlewareQueue, assertValidMiddleware);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_http_middlewarequeue_enqueue, 0, 0, 1)
	ZEND_ARG_INFO(0, middleware)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_http_middlewarequeue_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_http_middlewarequeue_push, 0, 0, 1)
	ZEND_ARG_INFO(0, middleware)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_http_middlewarequeue_attach, 0, 0, 1)
	ZEND_ARG_INFO(0, middleware)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_http_middlewarequeue_unshift, 0, 0, 1)
	ZEND_ARG_INFO(0, middleware)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_http_middlewarequeue_assertvalidmiddleware, 0, 0, 1)
	ZEND_ARG_INFO(0, middleware)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_http_middlewarequeue_method_entry) {
	PHP_ME(Xpl_Http_MiddlewareQueue, enqueue, arginfo_xpl_http_middlewarequeue_enqueue, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Http_MiddlewareQueue, offsetSet, arginfo_xpl_http_middlewarequeue_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Http_MiddlewareQueue, push, arginfo_xpl_http_middlewarequeue_push, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Http_MiddlewareQueue, attach, arginfo_xpl_http_middlewarequeue_attach, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Http_MiddlewareQueue, unshift, arginfo_xpl_http_middlewarequeue_unshift, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Http_MiddlewareQueue, assertValidMiddleware, arginfo_xpl_http_middlewarequeue_assertvalidmiddleware, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
