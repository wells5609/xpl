
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Contract for a list-based structure.
 *
 * In a list, the order of data items is significant, and duplicate data items are permitted.
 *
 * Stack and Queue are types of lists.
 *
 * @link http://en.wikipedia.org/wiki/List_(abstract_data_type)
 */
ZEPHIR_INIT_CLASS(Xpl_ListInterface) {

	ZEPHIR_REGISTER_INTERFACE(Xpl, ListInterface, xpl, listinterface, xpl_listinterface_method_entry);

	zend_class_implements(xpl_listinterface_ce TSRMLS_CC, 1, xpl_structinterface_ce);
	return SUCCESS;

}

/**
 * Pushes an item onto the list
 *
 * @param mixed
 */
ZEPHIR_DOC_METHOD(Xpl_ListInterface, push);

/**
 * Pops an item off the list
 *
 * If the list is empty, a \UnderflowException must be thrown.
 *
 * @return mixed
 * @throws \UnderflowException if the list is empty (contains no items)
 */
ZEPHIR_DOC_METHOD(Xpl_ListInterface, pop);

