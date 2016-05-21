
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(xpl_1__closure) {

	ZEPHIR_REGISTER_CLASS(xpl, 1__closure, xpl, 1__closure, xpl_1__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(xpl_1__closure, __invoke) {

	zval *request, *response, *next;

	zephir_fetch_params(0, 3, 0, &request, &response, &next);



	RETVAL_ZVAL(response, 1, 0);
	return;

}

