
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/object.h"


/**
 * Basic implementation of a Map.
 */
ZEPHIR_INIT_CLASS(Xpl_Collection_Map) {

	ZEPHIR_REGISTER_CLASS_EX(Xpl\\Collection, Map, xpl, collection_map, xpl_collection_abstractbasecollection_ce, xpl_collection_map_method_entry, 0);

	zend_class_implements(xpl_collection_map_ce TSRMLS_CC, 1, xpl_collection_mapinterface_ce);
	zend_class_implements(xpl_collection_map_ce TSRMLS_CC, 1, zephir_get_internal_ce(SS("jsonserializable") TSRMLS_CC));
	return SUCCESS;

}

/**
 * Constructor.
 *
 * @param mixed data [Optional]
 */
PHP_METHOD(Xpl_Collection_Map, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data);

	if (!data) {
		data = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(data) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addall", NULL, 0, data);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Import data into the object.
 *
 * @param mixed
 */
PHP_METHOD(Xpl_Collection_Map, addAll) {

	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_5 = NULL;
	zval *data, *key = NULL, *value = NULL, *_0 = NULL, **_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_CALL_CE_STATIC(&_0, xpl_type_ce, "toarray", &_1, 66, data);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_3, &_2, 0, 0, "xpl/collection/map.zep", 36);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(key, _3, _2);
		ZEPHIR_GET_HVALUE(value, _4);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_5, 0, key, value);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns an item by key.
 *
 * @param mixed
 * @return mixed
 */
PHP_METHOD(Xpl_Collection_Map, get) {

	zval *key, *value = NULL, *_0;

	zephir_fetch_params(0, 1, 0, &key);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, _0, key, 1 TSRMLS_CC)) {
		RETURN_CTORW(value);
	}
	RETURN_NULL();

}

/**
 * Sets an item by key.
 *
 * @param mixed
 * @param mixed
 */
PHP_METHOD(Xpl_Collection_Map, set) {

	zval *key, *value;

	zephir_fetch_params(0, 2, 0, &key, &value);



	zephir_update_property_array(this_ptr, SL("items"), key, value TSRMLS_CC);

}

/**
 * Whether the item given by key exists.
 *
 * @param mixed
 * @return boolean
 */
PHP_METHOD(Xpl_Collection_Map, has) {

	zval *key, *_0;

	zephir_fetch_params(0, 1, 0, &key);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	RETURN_BOOL(zephir_array_isset(_0, key));

}

/**
 * Removes an item by key.
 *
 * @param mixed
 */
PHP_METHOD(Xpl_Collection_Map, remove) {

	zval *key, *_0;

	zephir_fetch_params(0, 1, 0, &key);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	zephir_array_unset(&_0, key, PH_SEPARATE);

}

/**
 * Returns an item's key in the structure.
 *
 * @param mixed value
 * @return string|boolean
 */
PHP_METHOD(Xpl_Collection_Map, indexOf) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("array_search", NULL, 67, value, _0, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns an array of keys.
 *
 * @return array
 */
PHP_METHOD(Xpl_Collection_Map, keys) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	zephir_array_keys(return_value, _0 TSRMLS_CC);
	return;

}

/**
 * Returns an array of values.
 *
 * @return array
 */
PHP_METHOD(Xpl_Collection_Map, values) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("array_values", NULL, 68, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Applies a callback function to each item in the object.
 *
 * @param callable callback
 * @param mixed userdata [Optional]
 * @return \Xpl\Collection\MapInterface
 */
PHP_METHOD(Xpl_Collection_Map, walk) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *callback, *userdata = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &callback, &userdata);

	if (!userdata) {
		userdata = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_MAKE_REF(_0);
	ZEPHIR_CALL_FUNCTION(NULL, "array_walk", NULL, 72, _0, callback, userdata);
	ZEPHIR_UNREF(_0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Applies a callback function to each item and returns a new MapInterface containing the items.
 *
 * @param callable callback
 * @return \Xpl\Collection\MapInterface
 */
PHP_METHOD(Xpl_Collection_Map, map) {

	zend_class_entry *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *callback, *calledClass = NULL, *newObject = NULL, *_0 = NULL, *_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	ZEPHIR_INIT_VAR(calledClass);
	zephir_get_called_class(calledClass TSRMLS_CC);
	ZEPHIR_INIT_VAR(newObject);
	zephir_fetch_safe_class(_0, calledClass);
		_1 = zend_fetch_class(Z_STRVAL_P(_0), Z_STRLEN_P(_0), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(newObject, _1);
	if (zephir_has_constructor(newObject TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, newObject, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_3, "array_map", NULL, 44, callback, _2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, newObject, "addall", NULL, 0, _3);
	zephir_check_call_status();
	RETURN_CCTOR(newObject);

}

/**
 * Filters the elements using a callback function and returns a new MapInterface.
 *
 * @param callable callback
 * @return \Xpl\Collection\MapInterface
 */
PHP_METHOD(Xpl_Collection_Map, filter) {

	zend_class_entry *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *callback, *calledClass = NULL, *newObject = NULL, *_0 = NULL, *_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	ZEPHIR_INIT_VAR(calledClass);
	zephir_get_called_class(calledClass TSRMLS_CC);
	ZEPHIR_INIT_VAR(newObject);
	zephir_fetch_safe_class(_0, calledClass);
		_1 = zend_fetch_class(Z_STRVAL_P(_0), Z_STRLEN_P(_0), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(newObject, _1);
	if (zephir_has_constructor(newObject TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, newObject, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_3, "array_filter", NULL, 74, _2, callback);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, newObject, "addall", NULL, 0, _3);
	zephir_check_call_status();
	RETURN_CCTOR(newObject);

}

/**
 * Merges the given items into the object.
 *
 * @param mixed data
 * @return \Xpl\Collection\MapInterface
 */
PHP_METHOD(Xpl_Collection_Map, merge) {

	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *data, *key = NULL, *value = NULL, *objectData = NULL, *_0 = NULL, **_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_OBS_VAR(objectData);
	zephir_read_property_this(&objectData, this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CALL_CE_STATIC(&_0, xpl_type_ce, "toarray", &_1, 66, data);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_3, &_2, 0, 0, "xpl/collection/map.zep", 183);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(key, _3, _2);
		ZEPHIR_GET_HVALUE(value, _4);
		zephir_array_update_zval(&objectData, key, &value, PH_COPY | PH_SEPARATE);
	}
	zephir_update_property_this(this_ptr, SL("items"), objectData TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Replaces items in the collection with those given.
 *
 * @param mixed data
 * @return \Xpl\Collection\MapInterface
 */
PHP_METHOD(Xpl_Collection_Map, replace) {

	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *data, *key = NULL, *value = NULL, *objectData = NULL, *_0 = NULL, **_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_OBS_VAR(objectData);
	zephir_read_property_this(&objectData, this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CALL_CE_STATIC(&_0, xpl_type_ce, "toarray", &_1, 66, data);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_3, &_2, 0, 0, "xpl/collection/map.zep", 206);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(key, _3, _2);
		ZEPHIR_GET_HVALUE(value, _4);
		if (zephir_array_isset(objectData, key)) {
			zephir_array_update_zval(&objectData, key, &value, PH_COPY | PH_SEPARATE);
		}
	}
	zephir_update_property_this(this_ptr, SL("items"), objectData TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns an iterator for the object.
 *
 * @return \ArrayIterator
 */
PHP_METHOD(Xpl_Collection_Map, getIterator) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, zephir_get_internal_ce(SS("arrayiterator") TSRMLS_CC));
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 77, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Implements \ArrayAccess
 */
PHP_METHOD(Xpl_Collection_Map, offsetGet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, index);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Implements \ArrayAccess
 */
PHP_METHOD(Xpl_Collection_Map, offsetSet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index, *newval;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &index, &newval);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, index, newval);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Implements \ArrayAccess
 */
PHP_METHOD(Xpl_Collection_Map, offsetExists) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, index);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Implements \ArrayAccess
 */
PHP_METHOD(Xpl_Collection_Map, offsetUnset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "remove", NULL, 0, index);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the structure as a native PHP array.
 *
 * Implements \JsonSerializable
 *
 * @return array
 */
PHP_METHOD(Xpl_Collection_Map, jsonSerialize) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

