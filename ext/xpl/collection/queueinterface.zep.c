
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Xpl_Collection_QueueInterface) {

	ZEPHIR_REGISTER_INTERFACE(Xpl\\Collection, QueueInterface, xpl, collection_queueinterface, xpl_collection_queueinterface_method_entry);

	zend_class_implements(xpl_collection_queueinterface_ce TSRMLS_CC, 1, xpl_collection_listinterface_ce);
	return SUCCESS;

}

/**
 * Enqueues an item onto the list.
 *
 * @param mixed value
 */
ZEPHIR_DOC_METHOD(Xpl_Collection_QueueInterface, enqueue);

/**
 * Dequeues an item off the list.
 *
 * If the list is empty, a \UnderflowException must be thrown.
 *
 * @return mixed
 *
 * @throws \UnderflowException if the list is empty (contains no items)
 */
ZEPHIR_DOC_METHOD(Xpl_Collection_QueueInterface, dequeue);

