
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "Zend/zend_closures.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(Xpl_Http_MiddlewareQueue) {

	ZEPHIR_REGISTER_CLASS_EX(Xpl\\Http, MiddlewareQueue, xpl, http_middlewarequeue, xpl_collection_queue_ce, xpl_http_middlewarequeue_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Xpl_Http_MiddlewareQueue, enqueue) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *middleware;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &middleware);



	ZEPHIR_CALL_SELF(NULL, "assertvalidmiddleware", NULL, 0, middleware);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, xpl_http_middlewarequeue_ce, this_ptr, "enqueue", NULL, 0, middleware);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Xpl_Http_MiddlewareQueue, offsetSet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index, *value;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &index, &value);



	ZEPHIR_CALL_SELF(NULL, "assertvalidmiddleware", NULL, 0, value);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, xpl_http_middlewarequeue_ce, this_ptr, "offsetset", NULL, 0, index, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Xpl_Http_MiddlewareQueue, push) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *middleware;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &middleware);



	ZEPHIR_CALL_SELF(NULL, "assertvalidmiddleware", NULL, 0, middleware);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, xpl_http_middlewarequeue_ce, this_ptr, "push", NULL, 0, middleware);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Xpl_Http_MiddlewareQueue, attach) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *middleware;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &middleware);



	ZEPHIR_CALL_SELF(NULL, "assertvalidmiddleware", NULL, 0, middleware);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "enqueue", NULL, 0, middleware);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Xpl_Http_MiddlewareQueue, unshift) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *middleware;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &middleware);



	ZEPHIR_CALL_SELF(NULL, "assertvalidmiddleware", NULL, 0, middleware);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, xpl_http_middlewarequeue_ce, this_ptr, "unshift", NULL, 0, middleware);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Xpl_Http_MiddlewareQueue, assertValidMiddleware) {

	zend_bool _0$$3;
	zval *middleware;

	zephir_fetch_params(0, 1, 0, &middleware);



	if (Z_TYPE_P(middleware) == IS_OBJECT) {
		_0$$3 = zephir_instance_of_ev(middleware, zend_ce_closure TSRMLS_CC);
		if (!(_0$$3)) {
			_0$$3 = (zephir_method_exists_ex(middleware, SS("__invoke") TSRMLS_CC) == SUCCESS);
		}
		if (_0$$3) {
			RETURN_BOOL(1);
		}
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Middleware must be Closure or object with __invoke method", "xpl/http/middlewarequeue.zep", 47);
	return;

}

