
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Xpl_Collection_StackInterface) {

	ZEPHIR_REGISTER_INTERFACE(Xpl\\Collection, StackInterface, xpl, collection_stackinterface, xpl_collection_stackinterface_method_entry);

	zend_class_implements(xpl_collection_stackinterface_ce TSRMLS_CC, 1, xpl_collection_listinterface_ce);
	return SUCCESS;

}

/**
 * Pushes an item onto the stack.
 *
 * @param mixed
 */
ZEPHIR_DOC_METHOD(Xpl_Collection_StackInterface, push);

/**
 * Pops an item off the stack.
 *
 * If the stack is empty, a \UnderflowException must be thrown.
 *
 * @return mixed
 * @throws \UnderflowException if the list is empty (contains no items)
 */
ZEPHIR_DOC_METHOD(Xpl_Collection_StackInterface, pop);

