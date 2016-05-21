
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Contract for a Set data structure
 *
 * In a set, the order of items is insignificant, and duplicate items are not permitted.
 *
 * @link http://en.wikipedia.org/wiki/Set_(abstract_data_type)
 */
ZEPHIR_INIT_CLASS(Xpl_Collection_SetInterface) {

	ZEPHIR_REGISTER_INTERFACE(Xpl\\Collection, SetInterface, xpl, collection_setinterface, xpl_collection_setinterface_method_entry);

	zend_class_implements(xpl_collection_setinterface_ce TSRMLS_CC, 1, xpl_collection_ce);
	zend_class_implements(xpl_collection_setinterface_ce TSRMLS_CC, 1, zend_ce_iterator);
	return SUCCESS;

}

/**
 * Add a value to the set.
 *
 * If the item already exists, a \RuntimeException must be thrown.
 *
 * @param mixed value
 * @throws \RuntimeException if the value already exists in the set
 */
ZEPHIR_DOC_METHOD(Xpl_Collection_SetInterface, add);

/**
 * Removes a value from the set.
 *
 * If the item does not exist, a \OutOfBoundsException must be thrown.
 *
 * @param mixed value
 *
 * @throws \OutOfBoundsException if the value does not exist in the set
 */
ZEPHIR_DOC_METHOD(Xpl_Collection_SetInterface, remove);

