
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"


/**
 * Abstract implementation of Collection.
 */
ZEPHIR_INIT_CLASS(Xpl_Collection_AbstractBaseCollection) {

	ZEPHIR_REGISTER_CLASS(Xpl\\Collection, AbstractBaseCollection, xpl, collection_abstractbasecollection, xpl_collection_abstractbasecollection_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var array
	 */
	zend_declare_property_null(xpl_collection_abstractbasecollection_ce, SL("items"), ZEND_ACC_PROTECTED TSRMLS_CC);

	xpl_collection_abstractbasecollection_ce->create_object = zephir_init_properties_Xpl_Collection_AbstractBaseCollection;

	zend_class_implements(xpl_collection_abstractbasecollection_ce TSRMLS_CC, 1, xpl_collection_ce);
	return SUCCESS;

}

/**
 * Returns the structure as a native PHP array.
 *
 * @return array
 */
PHP_METHOD(Xpl_Collection_AbstractBaseCollection, toArray) {

	

	RETURN_MEMBER(this_ptr, "items");

}

/**
 * Whether the structure is empty.
 *
 * @return boolean
 */
PHP_METHOD(Xpl_Collection_AbstractBaseCollection, isEmpty) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	RETURN_BOOL(ZEPHIR_IS_EMPTY(_0));

}

/**
 * Whether the structure contains the given value.
 *
 * @param mixed value
 * @return boolean
 */
PHP_METHOD(Xpl_Collection_AbstractBaseCollection, contains) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("in_array", NULL, 2, value, _0, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the number of items in the structure
 *
 * @return int
 */
PHP_METHOD(Xpl_Collection_AbstractBaseCollection, count) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	RETURN_LONG(zephir_fast_count_int(_0 TSRMLS_CC));

}

/**
 * Serializes the object data
 *
 * @return string
 */
PHP_METHOD(Xpl_Collection_AbstractBaseCollection, serialize) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 3, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Constructs the object from a serialized string
 *
 * @param string serialized
 */
PHP_METHOD(Xpl_Collection_AbstractBaseCollection, unserialize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *serialized_param = NULL, *_0 = NULL;
	zval *serialized = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serialized_param);

	zephir_get_strval(serialized, serialized_param);


	ZEPHIR_CALL_FUNCTION(&_0, "unserialize", NULL, 4, serialized);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addall", NULL, 0, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

static zend_object_value zephir_init_properties_Xpl_Collection_AbstractBaseCollection(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("items"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

