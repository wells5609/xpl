
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Contract for a map data structure.
 *
 * Each item in a map is identified by a unique key.
 *
 * @method get(key);
 * @method set(key, value);
 * @method has(key);
 * @method remove(key);
 */
ZEPHIR_INIT_CLASS(Xpl_Collection_MapInterface) {

	ZEPHIR_REGISTER_INTERFACE(Xpl\\Collection, MapInterface, xpl, collection_mapinterface, xpl_collection_mapinterface_method_entry);

	zend_class_implements(xpl_collection_mapinterface_ce TSRMLS_CC, 1, xpl_collection_ce);
	zend_class_implements(xpl_collection_mapinterface_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	zend_class_implements(xpl_collection_mapinterface_ce TSRMLS_CC, 1, zend_ce_aggregate);
	return SUCCESS;

}

/**
 * Returns an array of keys
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Xpl_Collection_MapInterface, keys);

/**
 * Returns an array of values
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Xpl_Collection_MapInterface, values);

/**
 * Returns an item's key in the structure
 *
 * @param mixed value
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Xpl_Collection_MapInterface, indexOf);

