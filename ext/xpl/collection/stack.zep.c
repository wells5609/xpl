
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
#include "ext/spl/spl_dllist.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/hash.h"


/**
 * Stack is an extended \SplStack that implements StackInterface.
 */
ZEPHIR_INIT_CLASS(Xpl_Collection_Stack) {

	ZEPHIR_REGISTER_CLASS_EX(Xpl\\Collection, Stack, xpl, collection_stack, spl_ce_SplStack, xpl_collection_stack_method_entry, 0);

	zend_class_implements(xpl_collection_stack_ce TSRMLS_CC, 1, xpl_collection_stackinterface_ce);
	return SUCCESS;

}

/**
 * Constructor.
 *
 * @param mixed data [Optional]
 */
PHP_METHOD(Xpl_Collection_Stack, __construct) {

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
 * Removes an item by index.
 *
 * @param int index
 */
PHP_METHOD(Xpl_Collection_Stack, remove) {

	zval *index_param = NULL;
	int index;

	zephir_fetch_params(0, 1, 0, &index_param);

	index = zephir_get_intval(index_param);


	zephir_array_unset_long(&this_ptr, index, PH_SEPARATE);

}

/**
 * Checks whether the object contains a given value.
 *
 * @param mixed value
 * @return boolean
 */
PHP_METHOD(Xpl_Collection_Stack, contains) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	ZEPHIR_CALL_FUNCTION(&_0, "iterator_to_array", NULL, 14, this_ptr);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("in_array", NULL, 2, value, _0, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the object data as an array.
 *
 * @return array
 */
PHP_METHOD(Xpl_Collection_Stack, toArray) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("iterator_to_array", NULL, 14, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds data to the collection.
 *
 * @param mixed data
 */
PHP_METHOD(Xpl_Collection_Stack, addAll) {

	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_5 = NULL;
	zval *data, *value = NULL, *_0 = NULL, **_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_CALL_CE_STATIC(&_0, xpl_type_ce, "iterate", &_1, 15, data);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_3, &_2, 0, 0, "xpl/collection/stack.zep", 65);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(value, _4);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "push", &_5, 0, value);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Implements \IteratorAggregate
 *
 * @return \Iterator
 */
PHP_METHOD(Xpl_Collection_Stack, getIterator) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, zephir_get_internal_ce(SS("arrayiterator") TSRMLS_CC));
	ZEPHIR_CALL_FUNCTION(&_0, "iterator_to_array", NULL, 14, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 77, _0);
	zephir_check_call_status();
	RETURN_MM();

}

