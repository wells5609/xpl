
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Contract for a list-based collection.
 *
 * In a list, the order of data items is significant, and duplicate data items are permitted.
 *
 * Stack and Queue are types of lists.
 *
 * @link http://en.wikipedia.org/wiki/List_(abstract_data_type)
 */
ZEPHIR_INIT_CLASS(Xpl_Collection_ListInterface) {

	ZEPHIR_REGISTER_INTERFACE(Xpl\\Collection, ListInterface, xpl, collection_listinterface, xpl_collection_listinterface_method_entry);

	zend_class_implements(xpl_collection_listinterface_ce TSRMLS_CC, 1, xpl_collection_ce);
	zend_class_implements(xpl_collection_listinterface_ce TSRMLS_CC, 1, zend_ce_iterator);
	return SUCCESS;

}

/**
 * Add a value to the list by index.
 *
 * @param int index
 * @param mixed value
 */
ZEPHIR_DOC_METHOD(Xpl_Collection_ListInterface, add);

/**
 * Removes a value from the list by index.
 *
 * @param int index
 */
ZEPHIR_DOC_METHOD(Xpl_Collection_ListInterface, remove);

