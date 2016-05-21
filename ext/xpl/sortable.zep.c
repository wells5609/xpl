
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Contract for an object whose data can be sorted.
 */
ZEPHIR_INIT_CLASS(Xpl_Sortable) {

	ZEPHIR_REGISTER_INTERFACE(Xpl, Sortable, xpl, sortable, xpl_sortable_method_entry);

	return SUCCESS;

}

/**
 * Sort items and retain keys.
 *
 * @return boolean TRUE on success, or FALSE on failure.
 */
ZEPHIR_DOC_METHOD(Xpl_Sortable, asort);

/**
 * Sort items by key.
 *
 * @return boolean TRUE on success, or FALSE on failure.
 */
ZEPHIR_DOC_METHOD(Xpl_Sortable, ksort);

/**
 * Sort items using natural order algo.
 *
 * @return boolean TRUE on success, or FALSE on failure.
 */
ZEPHIR_DOC_METHOD(Xpl_Sortable, natsort);

/**
 * Sort items using case-insensitive natural order algo.
 *
 * @return boolean TRUE on success, or FALSE on failure.
 */
ZEPHIR_DOC_METHOD(Xpl_Sortable, natcasesort);

/**
 * Sort items using a given callback function.
 *
 * @param callable callback
 * @return boolean TRUE on success, or FALSE on failure.
 */
ZEPHIR_DOC_METHOD(Xpl_Sortable, usort);

/**
 * Sort items using a given callback function.
 *
 * @param callable callback
 * @return boolean TRUE on success, or FALSE on failure.
 */
ZEPHIR_DOC_METHOD(Xpl_Sortable, uasort);

/**
 * Sort items by key using a given callback function.
 *
 * @param callable callback
 * @return boolean TRUE on success, or FALSE on failure.
 */
ZEPHIR_DOC_METHOD(Xpl_Sortable, uksort);

