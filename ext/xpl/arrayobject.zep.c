
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "ext/spl/spl_array.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/object.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Xpl_ArrayObject) {

	ZEPHIR_REGISTER_CLASS_EX(Xpl, ArrayObject, xpl, arrayobject, spl_ce_ArrayObject, xpl_arrayobject_method_entry, 0);

	zend_class_implements(xpl_arrayobject_ce TSRMLS_CC, 1, xpl_dictionaryinterface_ce);
	return SUCCESS;

}

/**
 * Constructor
 *
 * @param array|object input
 * @param string iterator_class Iterator classname. Default "ArrayIterator"
 */
PHP_METHOD(Xpl_ArrayObject, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *iterator_class = NULL;
	zval *input = NULL, *iterator_class_param = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &input, &iterator_class_param);

	if (!input) {
		ZEPHIR_INIT_VAR(input);
		array_init(input);
	}
	if (!iterator_class_param) {
		ZEPHIR_INIT_VAR(iterator_class);
		ZVAL_STRING(iterator_class, "ArrayIterator", 1);
	} else {
	if (unlikely(Z_TYPE_P(iterator_class_param) != IS_STRING && Z_TYPE_P(iterator_class_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'iterator_class' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(iterator_class_param) == IS_STRING)) {
		zephir_get_strval(iterator_class, iterator_class_param);
	} else {
		ZEPHIR_INIT_VAR(iterator_class);
		ZVAL_EMPTY_STRING(iterator_class);
	}
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 2);
	ZEPHIR_CALL_PARENT(NULL, xpl_arrayobject_ce, this_ptr, "__construct", NULL, 0, input, _0, iterator_class);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Flags cannot be changed from \ArrayObject::ARRAY_AS_PROPS
 *
 * @throws \Xpl\ImmutableException
 */
PHP_METHOD(Xpl_ArrayObject, setFlags) {

	zval *flags;

	zephir_fetch_params(0, 1, 0, &flags);



	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(xpl_immutableexception_ce, "Flags are immutable", "xpl/arrayobject.zep", 26);
	return;

}

/**
 * Import data into the object
 *
 * @param mixed
 */
PHP_METHOD(Xpl_ArrayObject, import) {

	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zval *data, *key = NULL, *value = NULL, *_0 = NULL, **_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	_1 = zend_fetch_class(SL("Util\\Typecast"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_0, _1, "toarray", NULL, 0, data);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_3, &_2, 0, 0, "xpl/arrayobject.zep", 40);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(key, _3, _2);
		ZEPHIR_GET_HVALUE(value, _4);
		zephir_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the structure as a native PHP array
 *
 * @return array
 */
PHP_METHOD(Xpl_ArrayObject, toArray) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getarraycopy", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Whether the structure is empty
 *
 * @return boolean
 */
PHP_METHOD(Xpl_ArrayObject, isEmpty) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "count", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(_0, 0));

}

/**
 * Whether the structure contains the given value
 *
 * @param mixed value
 * @return boolean
 */
PHP_METHOD(Xpl_ArrayObject, contains) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getarraycopy", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("in_array", NULL, 1, value, _0, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns an item's key in the structure
 *
 * @param mixed value
 * @return string|boolean
 */
PHP_METHOD(Xpl_ArrayObject, indexOf) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getarraycopy", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("array_search", NULL, 5, value, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns an item by key
 *
 * @param string
 * @return mixed
 */
PHP_METHOD(Xpl_ArrayObject, get) {

	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_INIT_VAR(_0);
	if (zephir_isset_property_zval(this_ptr, key TSRMLS_CC)) {
		zephir_read_property_zval(&_0, this_ptr, key, PH_NOISY_CC);
	} else {
		ZVAL_NULL(_0);
	}
	RETURN_CCTOR(_0);

}

/**
 * Sets an item by key
 *
 * @param string
 */
PHP_METHOD(Xpl_ArrayObject, set) {

	zval *key_param = NULL, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(key, key_param);


	zephir_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Whether the item given by key exists
 *
 * @param string
 * @return boolean
 */
PHP_METHOD(Xpl_ArrayObject, has) {

	zval *key_param = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	RETURN_MM_BOOL(zephir_isset_property_zval(this_ptr, key TSRMLS_CC));

}

/**
 * Removes an item by key
 *
 * @param string
 */
PHP_METHOD(Xpl_ArrayObject, remove) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "offsetunset", NULL, 0, key);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns an array of keys
 *
 * @return array
 */
PHP_METHOD(Xpl_ArrayObject, keys) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getarraycopy", NULL, 0);
	zephir_check_call_status();
	zephir_array_keys(return_value, _0 TSRMLS_CC);
	RETURN_MM();

}

/**
 * Returns an array of values
 *
 * @return array
 */
PHP_METHOD(Xpl_ArrayObject, values) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getarraycopy", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("array_values", NULL, 6, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the sum of all values
 *
 * @return float
 */
PHP_METHOD(Xpl_ArrayObject, sum) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getarraycopy", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("array_sum", NULL, 12, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the first value
 *
 * @return mixed
 */
PHP_METHOD(Xpl_ArrayObject, first) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *arr = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&arr, this_ptr, "getarraycopy", NULL, 0);
	zephir_check_call_status();
	Z_SET_ISREF_P(arr);
	ZEPHIR_RETURN_CALL_FUNCTION("reset", NULL, 13, arr);
	Z_UNSET_ISREF_P(arr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the last value
 *
 * @return mixed
 */
PHP_METHOD(Xpl_ArrayObject, last) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *arr = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&arr, this_ptr, "getarraycopy", NULL, 0);
	zephir_check_call_status();
	Z_SET_ISREF_P(arr);
	ZEPHIR_RETURN_CALL_FUNCTION("end", NULL, 14, arr);
	Z_UNSET_ISREF_P(arr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Implements \JsonSerializable
 *
 * @return array
 */
PHP_METHOD(Xpl_ArrayObject, jsonSerialize) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getarraycopy", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Applies a callback function to each item in the object
 *
 * @param callable callback
 * @param mixed userdata [Optional]
 */
PHP_METHOD(Xpl_ArrayObject, walk) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *callback, *userdata = NULL, *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &callback, &userdata);

	if (!userdata) {
		userdata = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&data, this_ptr, "getarraycopy", NULL, 0);
	zephir_check_call_status();
	Z_SET_ISREF_P(data);
	ZEPHIR_CALL_FUNCTION(NULL, "array_walk", NULL, 7, data, callback, userdata);
	Z_UNSET_ISREF_P(data);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "exchangearray", NULL, 0, data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Applies a callback function to each item and returns a new ArrayObject.
 *
 * @param callable callback
 * @return \Xpl\ArrayObject
 */
PHP_METHOD(Xpl_ArrayObject, map) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *callback, *_0 = NULL, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	object_init_ex(return_value, xpl_arrayobject_ce);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getarraycopy", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "array_map", NULL, 8, callback, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getiteratorclass", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 15, _1, _2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Filters the elements using a callback function and returns a new ArrayObject.
 *
 * @param callable callback
 * @return \Xpl\ArrayObject
 */
PHP_METHOD(Xpl_ArrayObject, filter) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *callback, *_0 = NULL, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	object_init_ex(return_value, xpl_arrayobject_ce);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getarraycopy", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "array_filter", NULL, 10, _0, callback);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getiteratorclass", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 15, _1, _2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Merges items into the object
 *
 * @param mixed data
 */
PHP_METHOD(Xpl_ArrayObject, merge) {

	zend_class_entry *_3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data, *_0, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getarraycopy", NULL, 0);
	zephir_check_call_status();
	_3 = zend_fetch_class(SL("Util\\Typecast"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_2, _3, "toarray", NULL, 0, data);
	zephir_check_call_status();
	zephir_fast_array_merge(_0, &(_1), &(_2) TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "exchangearray", NULL, 0, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Replaces items in the object
 *
 * @param mixed data
 */
PHP_METHOD(Xpl_ArrayObject, replace) {

	zend_class_entry *_2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data, *_0 = NULL, *_1 = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getarraycopy", NULL, 0);
	zephir_check_call_status();
	_2 = zend_fetch_class(SL("Util\\Typecast"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_1, _2, "toarray", NULL, 0, data);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_3, "array_replace", NULL, 11, _0, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "exchangearray", NULL, 0, _3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

