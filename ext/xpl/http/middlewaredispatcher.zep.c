
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
#include "kernel/object.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Xpl_Http_MiddlewareDispatcher) {

	ZEPHIR_REGISTER_CLASS(Xpl\\Http, MiddlewareDispatcher, xpl, http_middlewaredispatcher, xpl_http_middlewaredispatcher_method_entry, 0);

	/**
	 * @var \Xpl\Http\MiddlewareQueue
	 */
	zend_declare_property_null(xpl_http_middlewaredispatcher_ce, SL("queue"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var null|callable
	 */
	zend_declare_property_null(xpl_http_middlewaredispatcher_ce, SL("filter"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var null|callable
	 */
	zend_declare_property_null(xpl_http_middlewaredispatcher_ce, SL("finalMiddleware"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Constructor.
 *
 * @param \Xpl\Http\MiddlewareQueue queue The middleware queue.
 * @param callable filter [Optional] Filters each queue entry before calling.
 */
PHP_METHOD(Xpl_Http_MiddlewareDispatcher, __construct) {

	zval *queue, *filter = NULL, *finalMiddleware = NULL, *_0$$7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &queue, &filter, &finalMiddleware);

	if (!filter) {
		filter = ZEPHIR_GLOBAL(global_null);
	}
	if (!finalMiddleware) {
		finalMiddleware = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(this_ptr, SL("queue"), queue TSRMLS_CC);
	if (Z_TYPE_P(filter) != IS_NULL) {
		if (!(zephir_is_callable(filter TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Middleware filter must be callable", "xpl/http/middlewaredispatcher.zep", 37);
			return;
		}
		zephir_update_property_this(this_ptr, SL("filter"), filter TSRMLS_CC);
	}
	if (Z_TYPE_P(finalMiddleware) != IS_NULL) {
		if (!(zephir_is_callable(finalMiddleware TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Final middleware must be callable", "xpl/http/middlewaredispatcher.zep", 44);
			return;
		}
		zephir_update_property_this(this_ptr, SL("finalMiddleware"), finalMiddleware TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_0$$7);
		ZEPHIR_INIT_NVAR(_0$$7);
		zephir_create_closure_ex(_0$$7, NULL, xpl_0__closure_ce, SS("__invoke") TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("finalMiddleware"), _0$$7 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Calls the next entry in the queue.
 *
 * @param \Psr\Http\Message\RequestInterface request The incoming request.
 * @param \Psr\Http\Message\ResponseInterface response The outgoing response.
 *
 * @return \Psr\Http\Message\ResponseInterface
 */
PHP_METHOD(Xpl_Http_MiddlewareDispatcher, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *request, *response, *middleware = NULL, *filter = NULL, *_0, *_1 = NULL, *_3, *_2$$4, *_4$$5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &request, &response);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("queue"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "isempty", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_CALL_METHOD(&middleware, this_ptr, "getfinalmiddleware", NULL, 0);
		zephir_check_call_status();
	} else {
		_2$$4 = zephir_fetch_nproperty_this(this_ptr, SL("queue"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&middleware, _2$$4, "dequeue", NULL, 0);
		zephir_check_call_status();
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("filter"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(filter, _3);
	if (Z_TYPE_P(filter) != IS_NULL) {
		ZEPHIR_CALL_ZVAL_FUNCTION(&_4$$5, filter, NULL, 0, middleware);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(middleware, _4$$5);
	}
	ZEPHIR_RETURN_CALL_ZVAL_FUNCTION(middleware, NULL, 0, request, response, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a middleware to run when the queue is empty.
 *
 * @return callable
 */
PHP_METHOD(Xpl_Http_MiddlewareDispatcher, getFinalMiddleware) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("finalMiddleware"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) != IS_NULL) {
		RETURN_MM_MEMBER(this_ptr, "finalMiddleware");
	}
	zephir_create_closure_ex(return_value, NULL, xpl_1__closure_ce, SS("__invoke") TSRMLS_CC);
	RETURN_MM();

}

/**
 * Returns a middleware to run when the queue is empty.
 *
 * @return callable
 */
PHP_METHOD(Xpl_Http_MiddlewareDispatcher, setFinalMiddleware) {

	zval *middleware;

	zephir_fetch_params(0, 1, 0, &middleware);



	zephir_update_property_this(this_ptr, SL("finalMiddleware"), middleware TSRMLS_CC);

}

