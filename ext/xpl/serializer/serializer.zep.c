
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Xpl_Serializer_Serializer) {

	ZEPHIR_REGISTER_INTERFACE(Xpl\\Serializer, Serializer, xpl, serializer_serializer, xpl_serializer_serializer_method_entry);

	return SUCCESS;

}

/**
 * Checks whether the serializer is available.
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Xpl_Serializer_Serializer, isAvailable);

/**
 * Serializes the given data.
 *
 * @param mixed data
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Xpl_Serializer_Serializer, serialize);

/**
 * Unserializes a value from a serialized string.
 *
 * @param string serializedData
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Xpl_Serializer_Serializer, unserialize);

