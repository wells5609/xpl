
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Xpl_Arrayable) {

	ZEPHIR_REGISTER_INTERFACE(Xpl, Arrayable, xpl, arrayable, xpl_arrayable_method_entry);

	return SUCCESS;

}

/**
 * Returns the object data as a native PHP array.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Xpl_Arrayable, toArray);

