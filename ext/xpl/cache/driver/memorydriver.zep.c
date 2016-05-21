
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Xpl_Cache_Driver_MemoryDriver) {

	ZEPHIR_REGISTER_CLASS_EX(Xpl\\Cache\\Driver, MemoryDriver, xpl, cache_driver_memorydriver, xpl_cache_driver_abstractdriver_ce, xpl_cache_driver_memorydriver_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(xpl_cache_driver_memorydriver_ce, SL("storage"), ZEND_ACC_PROTECTED TSRMLS_CC);

	xpl_cache_driver_memorydriver_ce->create_object = zephir_init_properties_Xpl_Cache_Driver_MemoryDriver;
	return SUCCESS;

}

/**
 * Whether the given item exists in the cache.
 *
 * @param string key Item key.
 * @return boolean True if a cached value exists, otherwise false.
 */
PHP_METHOD(Xpl_Cache_Driver_MemoryDriver, exists) {

	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, key));

}

/**
 * Returns a value from the cache.
 *
 * @param string key Item key.
 * @return mixed Cached value, if it exists, otherwise null.
 */
PHP_METHOD(Xpl_Cache_Driver_MemoryDriver, get) {

	zval *key_param = NULL, *value = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, _0, key, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	RETURN_MM_NULL();

}

/**
 * Saves a value in the cache.
 *
 * @param string key Item key
 * @param scalar value Item value
 * @param int ttl [Optional] Cache lifetime in seconds
 */
PHP_METHOD(Xpl_Cache_Driver_MemoryDriver, save) {

	int ttl;
	zval *key_param = NULL, *value, *ttl_param = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &key_param, &value, &ttl_param);

	zephir_get_strval(key, key_param);
	ttl = zephir_get_intval(ttl_param);


	zephir_update_property_array(this_ptr, SL("storage"), key, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Removes an item from the cache.
 *
 * @param string key Item key
 */
PHP_METHOD(Xpl_Cache_Driver_MemoryDriver, delete) {

	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
	zephir_array_unset(&_0, key, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

/**
 * Clears all items from the cache.
 */
PHP_METHOD(Xpl_Cache_Driver_MemoryDriver, clear) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("storage"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

static zend_object_value zephir_init_properties_Xpl_Cache_Driver_MemoryDriver(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("storage"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

