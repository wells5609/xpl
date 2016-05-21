
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
#include "ext/spl/spl_fixedarray.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/hash.h"


/**
 * Sequence is a list of a fixed size.
 */
ZEPHIR_INIT_CLASS(Xpl_Collection_Sequence) {

	ZEPHIR_REGISTER_CLASS_EX(Xpl\\Collection, Sequence, xpl, collection_sequence, spl_ce_SplFixedArray, xpl_collection_sequence_method_entry, 0);

	zend_class_implements(xpl_collection_sequence_ce TSRMLS_CC, 1, xpl_collection_listinterface_ce);
	return SUCCESS;

}

/**
 * Constructor.
 *
 * @param mixed data [Optional]
 */
PHP_METHOD(Xpl_Collection_Sequence, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, *_0$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data);

	if (!data) {
		data = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(data) != IS_NULL) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_LONG(_0$$3, zephir_fast_count_int(data TSRMLS_CC));
		ZEPHIR_CALL_PARENT(NULL, xpl_collection_sequence_ce, this_ptr, "__construct", NULL, 0, _0$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addall", NULL, 0, data);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_PARENT(NULL, xpl_collection_sequence_ce, this_ptr, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Add a value to the list by index.
 *
 * @param int index
 * @param mixed value
 */
PHP_METHOD(Xpl_Collection_Sequence, add) {

	zval *index_param = NULL, *value, *_0;
	int index, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &index_param, &value);

	index = zephir_get_intval(index_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, index);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "offsetset", NULL, 0, _0, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Removes a value from the list by index.
 *
 * @param int index
 */
PHP_METHOD(Xpl_Collection_Sequence, remove) {

	zval *index_param = NULL, *_0;
	int index, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	index = zephir_get_intval(index_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, index);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "offsetunset", NULL, 0, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks whether the collection is empty (i.e. has 0 elements).
 *
 * @return boolean
 */
PHP_METHOD(Xpl_Collection_Sequence, isEmpty) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "count", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG_IDENTICAL(_0, 0));

}

/**
 * Checks whether the collection contains the given value.
 *
 * @param mixed value
 *
 * @return boolean
 */
PHP_METHOD(Xpl_Collection_Sequence, contains) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("in_array", NULL, 2, value, _0, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds all the elements of data into the collection.
 *
 * @param mixed data
 */
PHP_METHOD(Xpl_Collection_Sequence, addAll) {

	HashTable *_4;
	HashPosition _3;
	zephir_fcall_cache_entry *_2 = NULL, *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *values, *size = NULL, *value = NULL, *_0, *_1 = NULL, **_5, *_7$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &values);



	ZEPHIR_CALL_METHOD(&size, this_ptr, "count", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, (zephir_get_numberval(size) + zephir_fast_count_int(values TSRMLS_CC)));
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setsize", NULL, 0, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_1, xpl_type_ce, "iterate", &_2, 15, values);
	zephir_check_call_status();
	zephir_is_iterable(_1, &_4, &_3, 0, 0, "xpl/collection/sequence.zep", 86);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(value, _5);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "offsetset", &_6, 0, size, value);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_7$$3);
		ZVAL_LONG(_7$$3, 1);
		ZEPHIR_ADD_ASSIGN(size, _7$$3);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Serializes the object data
 *
 * @return string
 */
PHP_METHOD(Xpl_Collection_Sequence, serialize) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 3, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Constructs the object from a serialized string
 *
 * @param string serialized
 */
PHP_METHOD(Xpl_Collection_Sequence, unserialize) {

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

