
extern zend_class_entry *xpl_http_middlewareinterface_ce;

ZEPHIR_INIT_CLASS(Xpl_Http_MiddlewareInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_http_middlewareinterface___invoke, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, Psr\\Http\\Message\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, Psr\\Http\\Message\\ResponseInterface, 0)
	ZEND_ARG_INFO(0, nextMiddleware)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_http_middlewareinterface_method_entry) {
	PHP_ABSTRACT_ME(Xpl_Http_MiddlewareInterface, __invoke, arginfo_xpl_http_middlewareinterface___invoke)
	PHP_FE_END
};
