
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Contract for a collection.
 */
ZEPHIR_INIT_CLASS(Xpl_Collection) {

	ZEPHIR_REGISTER_INTERFACE(Xpl, Collection, xpl, collection, xpl_collection_method_entry);

	zend_class_implements(xpl_collection_ce TSRMLS_CC, 1, xpl_arrayable_ce);
	zend_class_implements(xpl_collection_ce TSRMLS_CC, 1, spl_ce_Countable);
	zend_class_implements(xpl_collection_ce TSRMLS_CC, 1, zend_ce_serializable);
	return SUCCESS;

}

/**
 * Checks whether the collection is empty (i.e. has 0 elements).
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Xpl_Collection, isEmpty);

/**
 * Checks whether the collection contains the given value.
 *
 * @param mixed value
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Xpl_Collection, contains);

/**
 * Adds all the elements of data into the collection.
 *
 * @param mixed data
 */
ZEPHIR_DOC_METHOD(Xpl_Collection, addAll);

