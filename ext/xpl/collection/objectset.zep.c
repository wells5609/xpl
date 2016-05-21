
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/hash.h"


/**
 * Implementation of an object set using SplObjectStorage.
 */
ZEPHIR_INIT_CLASS(Xpl_Collection_ObjectSet) {

	ZEPHIR_REGISTER_CLASS_EX(Xpl\\Collection, ObjectSet, xpl, collection_objectset, zephir_get_internal_ce(SS("splobjectstorage") TSRMLS_CC), xpl_collection_objectset_method_entry, 0);

	zend_class_implements(xpl_collection_objectset_ce TSRMLS_CC, 1, xpl_collection_setinterface_ce);
	return SUCCESS;

}

/**
 * Add a value to the set if it does not exist.
 *
 * @param mixed value
 */
PHP_METHOD(Xpl_Collection_ObjectSet, add) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "attach", NULL, 0, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Removes a value from the set.
 *
 * @param mixed value
 */
PHP_METHOD(Xpl_Collection_ObjectSet, remove) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "detach", NULL, 0, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Xpl_Collection_ObjectSet, isEmpty) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "count", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG_IDENTICAL(_0, 0));

}

PHP_METHOD(Xpl_Collection_ObjectSet, toArray) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("iterator_to_array", NULL, 14, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Xpl_Collection_ObjectSet, addAll) {

	HashTable *_3$$4;
	HashPosition _2$$4;
	zephir_fcall_cache_entry *_1 = NULL, *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data, *value$$4 = NULL, *_0$$4 = NULL, **_4$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	if (zephir_instance_of_ev(data, zephir_get_internal_ce(SS("splobjectstorage") TSRMLS_CC) TSRMLS_CC)) {
		ZEPHIR_CALL_PARENT(NULL, xpl_collection_objectset_ce, this_ptr, "addall", NULL, 0, data);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_CE_STATIC(&_0$$4, xpl_type_ce, "iterate", &_1, 15, data);
		zephir_check_call_status();
		zephir_is_iterable(_0$$4, &_3$$4, &_2$$4, 0, 0, "xpl/collection/objectset.zep", 51);
		for (
		  ; zephir_hash_get_current_data_ex(_3$$4, (void**) &_4$$4, &_2$$4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3$$4, &_2$$4)
		) {
			ZEPHIR_GET_HVALUE(value$$4, _4$$4);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", &_5, 0, value$$4);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

