
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Xpl_Comparator) {

	ZEPHIR_REGISTER_INTERFACE(Xpl, Comparator, xpl, comparator, xpl_comparator_method_entry);

	return SUCCESS;

}

/**
 * Compares two items.
 *
 * @param mixed a
 * @param mixed b
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Xpl_Comparator, compare);

