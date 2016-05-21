
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Tagging interface for read-only objects.
 */
ZEPHIR_INIT_CLASS(Xpl_ReadOnlyInterface) {

	ZEPHIR_REGISTER_INTERFACE(Xpl, ReadOnlyInterface, xpl, readonlyinterface, NULL);

	return SUCCESS;

}

