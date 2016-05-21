
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


ZEPHIR_INIT_CLASS(Xpl_Cache_InvalidArgumentException) {

	ZEPHIR_REGISTER_CLASS_EX(Xpl\\Cache, InvalidArgumentException, xpl, cache_invalidargumentexception, xpl_cache_exception_ce, NULL, 0);

	zend_class_implements(xpl_cache_invalidargumentexception_ce TSRMLS_CC, 1, zephir_get_internal_ce(SS("psr\\cache\\invalidargumentexception") TSRMLS_CC));
	return SUCCESS;

}

