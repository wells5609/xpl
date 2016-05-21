
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Xpl_Http_MiddlewareInterface) {

	ZEPHIR_REGISTER_INTERFACE(Xpl\\Http, MiddlewareInterface, xpl, http_middlewareinterface, xpl_http_middlewareinterface_method_entry);

	return SUCCESS;

}

/**
 * Invoke the middleware logic.
 *
 * @param \Psr\Http\Message\RequestInterface request
 * @param \Psr\Http\Message\ResponseInterface response
 * @param callable|\Xpl\Http\MiddlewareInterface|null nextMiddleware
 *
 * @return \Psr\Http\Message\ResponseInterface
 */
ZEPHIR_DOC_METHOD(Xpl_Http_MiddlewareInterface, __invoke);

