
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
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Xpl_Collection_Config) {

	ZEPHIR_REGISTER_CLASS(Xpl\\Collection, Config, xpl, collection_config, xpl_collection_config_method_entry, 0);

	zend_class_implements(xpl_collection_config_ce TSRMLS_CC, 1, xpl_collection_mapinterface_ce);
	return SUCCESS;

}

/**
 * Constructor.
 *
 * @param array|\Traversable data [Optional]
 * @return void
 */
PHP_METHOD(Xpl_Collection_Config, __construct) {

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
 * Checks whether the collection is empty (i.e. has 0 elements).
 *
 * @return boolean
 */
PHP_METHOD(Xpl_Collection_Config, isEmpty) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "get_object_vars", NULL, 62, this_ptr);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_fast_count_int(_0 TSRMLS_CC) == 0);

}

/**
 * Returns the number of properties.
 *
 * @return int
 */
PHP_METHOD(Xpl_Collection_Config, count) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "get_object_vars", NULL, 62, this_ptr);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_fast_count_int(_0 TSRMLS_CC));

}

/**
 * Returns the object data as an array.
 *
 * @return array
 */
PHP_METHOD(Xpl_Collection_Config, toArray) {

	zend_bool _4$$3;
	HashTable *_2;
	HashPosition _1;
	zval *rtn = NULL, *key = NULL, *value = NULL, *_0 = NULL, **_3, *_5$$4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(rtn);
	array_init(rtn);
	ZEPHIR_CALL_FUNCTION(&_0, "get_object_vars", NULL, 62, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "xpl/collection/config.zep", 62);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		_4$$3 = Z_TYPE_P(value) == IS_OBJECT;
		if (_4$$3) {
			_4$$3 = (zephir_method_exists_ex(value, SS("toarray") TSRMLS_CC) == SUCCESS);
		}
		if (_4$$3) {
			ZEPHIR_CALL_METHOD(&_5$$4, value, "toarray", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_zval(&rtn, key, &_5$$4, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_zval(&rtn, key, &value, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(rtn);

}

/**
 * Adds multiple entries to the Config.
 *
 * @param array|\Traversable data
 *
 * @return \Xpl\Collection\Config
 */
PHP_METHOD(Xpl_Collection_Config, addAll) {

	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_6 = NULL, *_8 = NULL;
	zval *data, *key = NULL, *value = NULL, *_0 = NULL, **_4, *_5$$3 = NULL, *_7$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_CALL_CE_STATIC(&_0, xpl_type_ce, "toarray", &_1, 66, data);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_3, &_2, 0, 0, "xpl/collection/config.zep", 87);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(key, _3, _2);
		ZEPHIR_GET_HVALUE(value, _4);
		ZEPHIR_CALL_FUNCTION(&_5$$3, "strval", &_6, 76, key);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(key, _5$$3);
		if (Z_TYPE_P(value) == IS_ARRAY) {
			ZEPHIR_CALL_METHOD(&_7$$4, this_ptr, "newstatic", &_8, 0, value);
			zephir_check_call_status();
			zephir_update_property_zval_zval(this_ptr, key, _7$$4 TSRMLS_CC);
		} else {
			zephir_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
		}
	}
	RETURN_THIS();

}

/**
 * Returns an array of keys
 *
 * @return array
 */
PHP_METHOD(Xpl_Collection_Config, keys) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "get_object_vars", NULL, 62, this_ptr);
	zephir_check_call_status();
	zephir_array_keys(return_value, _0 TSRMLS_CC);
	RETURN_MM();

}

/**
 * Returns an array of values
 *
 * @return array
 */
PHP_METHOD(Xpl_Collection_Config, values) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "get_object_vars", NULL, 62, this_ptr);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("array_values", NULL, 68, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns an item's key in the structure
 *
 * @param mixed value
 * @return mixed
 */
PHP_METHOD(Xpl_Collection_Config, indexOf) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	ZEPHIR_CALL_FUNCTION(&_0, "get_object_vars", NULL, 62, this_ptr);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("array_search", NULL, 67, value, _0, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Whether the structure contains the given value.
 *
 * @param mixed value
 * @return boolean
 */
PHP_METHOD(Xpl_Collection_Config, contains) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	ZEPHIR_CALL_FUNCTION(&_0, "get_object_vars", NULL, 62, this_ptr);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("in_array", NULL, 2, value, _0, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns an iterator for the object.
 *
 * @return \ArrayIterator
 */
PHP_METHOD(Xpl_Collection_Config, getIterator) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, zephir_get_internal_ce(SS("arrayiterator") TSRMLS_CC));
	ZEPHIR_CALL_FUNCTION(&_0, "get_object_vars", NULL, 62, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 77, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a property value using array access.
 *
 * @param string index
 *
 * @return mixed
 */
PHP_METHOD(Xpl_Collection_Config, offsetGet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index = NULL, *value = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);

	ZEPHIR_SEPARATE_PARAM(index);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 76, index);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(index, _0);
	ZEPHIR_OBS_VAR(value);
	if (zephir_fetch_property_zval(&value, this_ptr, index, PH_SILENT_CC)) {
		RETURN_CTOR(value);
	}
	RETURN_MM_NULL();

}

/**
 * Sets a property value.
 *
 * @param string index
 * @param mixed value
 */
PHP_METHOD(Xpl_Collection_Config, offsetSet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index = NULL, *value, *_0 = NULL, *_1$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &index, &value);

	ZEPHIR_SEPARATE_PARAM(index);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 76, index);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(index, _0);
	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "newstatic", NULL, 0, value);
		zephir_check_call_status();
		zephir_update_property_zval_zval(this_ptr, index, _1$$3 TSRMLS_CC);
	} else {
		zephir_update_property_zval_zval(this_ptr, index, value TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks if a property exists.
 *
 * @param string index
 *
 * @return boolean
 */
PHP_METHOD(Xpl_Collection_Config, offsetExists) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index = NULL, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);

	ZEPHIR_SEPARATE_PARAM(index);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 76, index);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(index, _0);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_zval(&_1, this_ptr, index, PH_NOISY_CC);
	RETURN_MM_BOOL(Z_TYPE_P(_1) != IS_NULL);

}

/**
 * Sets a property to null.
 *
 * @param string index
 */
PHP_METHOD(Xpl_Collection_Config, offsetUnset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index = NULL, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);

	ZEPHIR_SEPARATE_PARAM(index);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 76, index);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(index, _0);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_zval(&_1, this_ptr, index, PH_NOISY_CC);
	if (Z_TYPE_P(_1) != IS_NULL) {
		zephir_update_property_zval_zval(this_ptr, index, ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Get an item using "dot" notation.
 *
 * @param  string  key
 * @param  mixed   defaultValue
 *
 * @return mixed
 */
PHP_METHOD(Xpl_Collection_Config, get) {

	zend_bool _7$$4;
	HashTable *_5;
	HashPosition _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, *defaultValue = NULL, *_0 = NULL, *_1, *currentItem = NULL, *segment = NULL, *_3, **_6, *_2$$3, *_8$$4 = NULL, *_9$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key, &defaultValue);

	ZEPHIR_SEPARATE_PARAM(key);
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 76, key);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(key, _0);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_zval(&_1, this_ptr, key, PH_NOISY_CC);
	if (Z_TYPE_P(_1) != IS_NULL) {
		ZEPHIR_OBS_VAR(_2$$3);
		zephir_read_property_zval(&_2$$3, this_ptr, key, PH_NOISY_CC);
		RETURN_CCTOR(_2$$3);
	}
	ZEPHIR_CPY_WRT(currentItem, this_ptr);
	ZEPHIR_INIT_VAR(_3);
	zephir_fast_explode_str(_3, SL("."), key, LONG_MAX TSRMLS_CC);
	zephir_is_iterable(_3, &_5, &_4, 0, 0, "xpl/collection/config.zep", 236);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(segment, _6);
		_7$$4 = Z_TYPE_P(currentItem) != IS_OBJECT;
		if (!(_7$$4)) {
			ZEPHIR_OBS_NVAR(_8$$4);
			zephir_read_property_zval(&_8$$4, currentItem, segment, PH_NOISY_CC);
			_7$$4 = Z_TYPE_P(_8$$4) == IS_NULL;
		}
		if (_7$$4) {
			RETVAL_ZVAL(defaultValue, 1, 0);
			RETURN_MM();
		}
		ZEPHIR_OBS_NVAR(_9$$4);
		zephir_read_property_zval(&_9$$4, currentItem, segment, PH_NOISY_CC);
		ZEPHIR_CPY_WRT(currentItem, _9$$4);
	}
	RETURN_CCTOR(currentItem);

}

/**
 * Set an item using "dot" notation.
 *
 * @param  string  key
 * @param  mixed   value
 *
 * @return \Xpl\Collection\Config
 */
PHP_METHOD(Xpl_Collection_Config, set) {

	HashTable *_2$$3;
	HashPosition _1$$3;
	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, *value, *segments = NULL, *segment = NULL, *currentItem = NULL, *realKey = NULL, *_0 = NULL, **_3$$3, *_4$$4 = NULL, *_7$$4 = NULL, *_5$$5 = NULL, *_8$$6 = NULL, *_9$$9 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key, &value);

	ZEPHIR_SEPARATE_PARAM(key);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 76, key);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(key, _0);
	if (zephir_memnstr_str(key, SL("."), "xpl/collection/config.zep", 253)) {
		ZEPHIR_INIT_VAR(segments);
		zephir_fast_explode_str(segments, SL("."), key, LONG_MAX TSRMLS_CC);
		ZEPHIR_MAKE_REF(segments);
		ZEPHIR_CALL_FUNCTION(&realKey, "array_pop", NULL, 78, segments);
		ZEPHIR_UNREF(segments);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(currentItem, this_ptr);
		zephir_is_iterable(segments, &_2$$3, &_1$$3, 0, 0, "xpl/collection/config.zep", 268);
		for (
		  ; zephir_hash_get_current_data_ex(_2$$3, (void**) &_3$$3, &_1$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2$$3, &_1$$3)
		) {
			ZEPHIR_GET_HVALUE(segment, _3$$3);
			ZEPHIR_OBS_NVAR(_4$$4);
			zephir_read_property_zval(&_4$$4, currentItem, segment, PH_NOISY_CC);
			if (Z_TYPE_P(_4$$4) != IS_OBJECT) {
				ZEPHIR_CALL_METHOD(&_5$$5, this_ptr, "newstatic", &_6, 0);
				zephir_check_call_status();
				zephir_update_property_zval_zval(currentItem, segment, _5$$5 TSRMLS_CC);
			}
			ZEPHIR_OBS_NVAR(_7$$4);
			zephir_read_property_zval(&_7$$4, currentItem, segment, PH_NOISY_CC);
			ZEPHIR_CPY_WRT(currentItem, _7$$4);
		}
		if (Z_TYPE_P(value) == IS_ARRAY) {
			ZEPHIR_CALL_METHOD(&_8$$6, this_ptr, "newstatic", &_6, 0, value);
			zephir_check_call_status();
			zephir_update_property_zval_zval(currentItem, realKey, _8$$6 TSRMLS_CC);
		} else {
			zephir_update_property_zval_zval(currentItem, realKey, value TSRMLS_CC);
		}
	} else {
		if (Z_TYPE_P(value) == IS_ARRAY) {
			ZEPHIR_CALL_METHOD(&_9$$9, this_ptr, "newstatic", &_6, 0, value);
			zephir_check_call_status();
			zephir_update_property_zval_zval(this_ptr, key, _9$$9 TSRMLS_CC);
		} else {
			zephir_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
		}
	}
	RETURN_THIS();

}

/**
 * Check if an item exists using "dot" notation.
 *
 * @param  string  key
 * @return bool
 */
PHP_METHOD(Xpl_Collection_Config, has) {

	zend_bool _6$$4;
	HashTable *_4;
	HashPosition _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, *_0 = NULL, *_1, *currentItem = NULL, *segment = NULL, *_2, **_5, *_7$$4 = NULL, *_8$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);

	ZEPHIR_SEPARATE_PARAM(key);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 76, key);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(key, _0);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_zval(&_1, this_ptr, key, PH_NOISY_CC);
	if (Z_TYPE_P(_1) != IS_NULL) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CPY_WRT(currentItem, this_ptr);
	ZEPHIR_INIT_VAR(_2);
	zephir_fast_explode_str(_2, SL("."), key, LONG_MAX TSRMLS_CC);
	zephir_is_iterable(_2, &_4, &_3, 0, 0, "xpl/collection/config.zep", 313);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(segment, _5);
		_6$$4 = Z_TYPE_P(currentItem) != IS_OBJECT;
		if (!(_6$$4)) {
			ZEPHIR_OBS_NVAR(_7$$4);
			zephir_read_property_zval(&_7$$4, currentItem, segment, PH_NOISY_CC);
			_6$$4 = Z_TYPE_P(_7$$4) == IS_NULL;
		}
		if (_6$$4) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_OBS_NVAR(_8$$4);
		zephir_read_property_zval(&_8$$4, currentItem, segment, PH_NOISY_CC);
		ZEPHIR_CPY_WRT(currentItem, _8$$4);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Returns a Config object for a given component.
 *
 * @param string component
 *
 * @return \Xpl\Collection\Config
 */
PHP_METHOD(Xpl_Collection_Config, getConfig) {

	zend_bool _0$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *component_param = NULL, *configObject = NULL;
	zval *component = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &component_param);

	if (unlikely(Z_TYPE_P(component_param) != IS_STRING && Z_TYPE_P(component_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'component' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(component_param) == IS_STRING)) {
		zephir_get_strval(component, component_param);
	} else {
		ZEPHIR_INIT_VAR(component);
		ZVAL_EMPTY_STRING(component);
	}


	ZEPHIR_OBS_VAR(configObject);
	if (zephir_fetch_property_zval(&configObject, this_ptr, component, PH_SILENT_CC)) {
		_0$$3 = Z_TYPE_P(configObject) != IS_OBJECT;
		if (!(_0$$3)) {
			_0$$3 = !((zephir_instance_of_ev(configObject, xpl_collection_config_ce TSRMLS_CC)));
		}
		if (_0$$3) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Item with given key is not a Config", "xpl/collection/config.zep", 329);
			return;
		}
	} else {
		ZEPHIR_CALL_METHOD(&configObject, this_ptr, "newstatic", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval_zval(this_ptr, component, configObject TSRMLS_CC);
	}
	RETURN_CCTOR(configObject);

}

PHP_METHOD(Xpl_Collection_Config, __get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "offsetget", NULL, 0, key);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Xpl_Collection_Config, __isset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "offsetexists", NULL, 0, key);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Xpl_Collection_Config, __set) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key, *value;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key, &value);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "offsetset", NULL, 0, key, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Xpl_Collection_Config, __unset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "offsetunset", NULL, 0, key);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Serializes the object.
 *
 * @return string
 */
PHP_METHOD(Xpl_Collection_Config, serialize) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "get_object_vars", NULL, 62, this_ptr);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 3, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Restores the object from a serial string.
 *
 * @param string serial
 * @return void
 */
PHP_METHOD(Xpl_Collection_Config, unserialize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *serial_param = NULL, *_0 = NULL;
	zval *serial = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serial_param);

	if (unlikely(Z_TYPE_P(serial_param) != IS_STRING && Z_TYPE_P(serial_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'serial' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(serial_param) == IS_STRING)) {
		zephir_get_strval(serial, serial_param);
	} else {
		ZEPHIR_INIT_VAR(serial);
		ZVAL_EMPTY_STRING(serial);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "unserialize", NULL, 4, serial);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addall", NULL, 0, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Restores the state of a Config object.
 */
PHP_METHOD(Xpl_Collection_Config, __set_state) {

	zend_class_entry *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *calledClass = NULL, *_0 = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	data = data_param;


	ZEPHIR_INIT_VAR(calledClass);
	zephir_get_called_class(calledClass TSRMLS_CC);
	zephir_fetch_safe_class(_0, calledClass);
		_1 = zend_fetch_class(Z_STRVAL_P(_0), Z_STRLEN_P(_0), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(return_value, _1);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, data);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * Provides Zephir compatibility for "new static()" construct.
 *
 * @param array data
 * @return \Xpl\Collection\Config
 */
PHP_METHOD(Xpl_Collection_Config, newStatic) {

	zend_class_entry *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, *calledClass = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data);

	if (!data) {
		data = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(calledClass);
	zephir_get_called_class(calledClass TSRMLS_CC);
	zephir_fetch_safe_class(_0, calledClass);
		_1 = zend_fetch_class(Z_STRVAL_P(_0), Z_STRLEN_P(_0), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(return_value, _1);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, data);
		zephir_check_call_status();
	}
	RETURN_MM();

}

