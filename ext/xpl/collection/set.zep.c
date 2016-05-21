
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/hash.h"


/**
 * In a set, the order of items is insignificant, and duplicate items are not permitted.
 *
 * @link http://en.wikipedia.org/wiki/Set_(abstractitems_type)
 */
ZEPHIR_INIT_CLASS(Xpl_Collection_Set) {

	ZEPHIR_REGISTER_CLASS_EX(Xpl\\Collection, Set, xpl, collection_set, xpl_collection_abstractbasecollection_ce, xpl_collection_set_method_entry, 0);

	zend_declare_property_long(xpl_collection_set_ce, SL("iteratorPosition"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_class_implements(xpl_collection_set_ce TSRMLS_CC, 1, xpl_collection_setinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Xpl_Collection_Set, current) {

	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property_this(&_2, this_ptr, SL("iteratorPosition"), PH_NOISY_CC);
	zephir_array_fetch(&_1, _0, _2, PH_NOISY | PH_READONLY, "xpl/collection/set.zep", 19 TSRMLS_CC);
	RETURN_CTOR(_1);

}

PHP_METHOD(Xpl_Collection_Set, key) {

	

	RETURN_MEMBER(this_ptr, "iteratorPosition");

}

PHP_METHOD(Xpl_Collection_Set, next) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 1);
	ZEPHIR_ADD_ASSIGN(_0, _1)
	zephir_update_property_this(this_ptr, SL("iteratorPosition"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Xpl_Collection_Set, rewind) {

	zval *_0;


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(this_ptr, SL("iteratorPosition"), _0 TSRMLS_CC);

}

PHP_METHOD(Xpl_Collection_Set, valid) {

	zval *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("iteratorPosition"), PH_NOISY_CC);
	RETURN_BOOL(zephir_array_isset(_0, _1));

}

/**
 * Adds a value to the set
 *
 * @param mixed value
 * @throws \RuntimeException if the value already exists
 */
PHP_METHOD(Xpl_Collection_Set, add) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "in_array", NULL, 2, value, _0, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Value already exists in set", "xpl/collection/set.zep", 51);
		return;
	}
	zephir_update_property_array_append(this_ptr, SL("items"), value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Removes a value from the set
 *
 * @param mixed value
 * @throws \OutOfBoundsException if the value does not exist in the set
 */
PHP_METHOD(Xpl_Collection_Set, remove) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value, *index = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&index, "array_search", NULL, 67, value, _0, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(index)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_OutOfBoundsException, "Value does not exist in set", "xpl/collection/set.zep", 69);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	zephir_array_unset(&_1, index, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds a value to the end of the set
 *
 * @param mixed value
 * @throws \RuntimeException if the value already exists
 */
PHP_METHOD(Xpl_Collection_Set, append) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value, *_0, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "in_array", NULL, 2, value, _0, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Value already exists in set", "xpl/collection/set.zep", 84);
		return;
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_MAKE_REF(value);
	ZEPHIR_CALL_FUNCTION(NULL, "array_push", NULL, 79, value, _2);
	ZEPHIR_UNREF(value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds a value to the beginning of the set
 *
 * @param mixed value
 * @throws \RuntimeException if the value already exists
 */
PHP_METHOD(Xpl_Collection_Set, prepend) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value, *_0, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "in_array", NULL, 2, value, _0, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Value already exists in set", "xpl/collection/set.zep", 99);
		return;
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_MAKE_REF(value);
	ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 80, value, _2);
	ZEPHIR_UNREF(value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Imports items into the set
 *
 * @param mixed data
 */
PHP_METHOD(Xpl_Collection_Set, addAll) {

	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_7 = NULL;
	zval *data, *value = NULL, *_0 = NULL, **_4, *_5$$3, *_6$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_CALL_CE_STATIC(&_0, xpl_type_ce, "toarray", &_1, 66, data);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_3, &_2, 0, 0, "xpl/collection/set.zep", 119);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(value, _4);
		_5$$3 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_6$$3, "in_array", &_7, 2, value, _5$$3, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		if (!(zephir_is_true(_6$$3))) {
			zephir_update_property_array_append(this_ptr, SL("items"), value TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sort items and retain keys.
 *
 * @return boolean TRUE on success, or FALSE on failure.
 */
PHP_METHOD(Xpl_Collection_Set, asort) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_MAKE_REF(_0);
	ZEPHIR_RETURN_CALL_FUNCTION("asort", NULL, 81, _0);
	ZEPHIR_UNREF(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sort items by key.
 *
 * @return boolean TRUE on success, or FALSE on failure.
 */
PHP_METHOD(Xpl_Collection_Set, ksort) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_MAKE_REF(_0);
	ZEPHIR_RETURN_CALL_FUNCTION("ksort", NULL, 82, _0);
	ZEPHIR_UNREF(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sort items using natural order algo.
 *
 * @return boolean TRUE on success, or FALSE on failure.
 */
PHP_METHOD(Xpl_Collection_Set, natsort) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_MAKE_REF(_0);
	ZEPHIR_RETURN_CALL_FUNCTION("natsort", NULL, 83, _0);
	ZEPHIR_UNREF(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sort items using case-insensitive natural order algo.
 *
 * @return boolean TRUE on success, or FALSE on failure.
 */
PHP_METHOD(Xpl_Collection_Set, natcasesort) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_MAKE_REF(_0);
	ZEPHIR_RETURN_CALL_FUNCTION("natcasesort", NULL, 84, _0);
	ZEPHIR_UNREF(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sort items using a given callback function.
 *
 * @return boolean TRUE on success, or FALSE on failure.
 */
PHP_METHOD(Xpl_Collection_Set, usort) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *callback, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_MAKE_REF(_0);
	ZEPHIR_RETURN_CALL_FUNCTION("usort", NULL, 85, _0, callback);
	ZEPHIR_UNREF(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sort items using a given callback function.
 *
 * @return boolean TRUE on success, or FALSE on failure.
 */
PHP_METHOD(Xpl_Collection_Set, uasort) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *callback, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_MAKE_REF(_0);
	ZEPHIR_RETURN_CALL_FUNCTION("uasort", NULL, 86, _0, callback);
	ZEPHIR_UNREF(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sort items by key using a given callback function.
 *
 * @return boolean TRUE on success, or FALSE on failure.
 */
PHP_METHOD(Xpl_Collection_Set, uksort) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *callback, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	ZEPHIR_MAKE_REF(_0);
	ZEPHIR_RETURN_CALL_FUNCTION("uksort", NULL, 87, _0, callback);
	ZEPHIR_UNREF(_0);
	zephir_check_call_status();
	RETURN_MM();

}

