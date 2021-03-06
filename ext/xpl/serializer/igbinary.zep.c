
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Xpl_Serializer_Igbinary) {

	ZEPHIR_REGISTER_CLASS(Xpl\\Serializer, Igbinary, xpl, serializer_igbinary, xpl_serializer_igbinary_method_entry, 0);

	zend_class_implements(xpl_serializer_igbinary_ce TSRMLS_CC, 1, xpl_serializer_serializer_ce);
	return SUCCESS;

}

/**
 * Checks whether the serializer is available.
 *
 * @return boolean
 */
PHP_METHOD(Xpl_Serializer_Igbinary, isAvailable) {

	

	RETURN_BOOL((zephir_function_exists_ex(SS("igbinary_serialize") TSRMLS_CC) == SUCCESS));

}

/**
 * Serializes the given data.
 *
 * @param mixed data
 *
 * @return string
 */
PHP_METHOD(Xpl_Serializer_Igbinary, serialize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_RETURN_CALL_FUNCTION("igbinary_serialize", NULL, 131, data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Unserializes a value from a serialized string.
 *
 * @param string serializedData
 *
 * @return mixed
 */
PHP_METHOD(Xpl_Serializer_Igbinary, unserialize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *serializedData_param = NULL;
	zval *serializedData = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serializedData_param);

	if (unlikely(Z_TYPE_P(serializedData_param) != IS_STRING && Z_TYPE_P(serializedData_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'serializedData' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(serializedData_param) == IS_STRING)) {
		zephir_get_strval(serializedData, serializedData_param);
	} else {
		ZEPHIR_INIT_VAR(serializedData);
		ZVAL_EMPTY_STRING(serializedData);
	}


	ZEPHIR_RETURN_CALL_FUNCTION("igbinary_unserialize", NULL, 132, serializedData);
	zephir_check_call_status();
	RETURN_MM();

}

