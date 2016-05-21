
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Xpl_Collection_ScalarSet) {

	ZEPHIR_REGISTER_CLASS_EX(Xpl\\Collection, ScalarSet, xpl, collection_scalarset, zephir_get_internal_ce(SS("splobjectstorage") TSRMLS_CC), xpl_collection_scalarset_method_entry, 0);

	zend_class_implements(xpl_collection_scalarset_ce TSRMLS_CC, 1, xpl_collection_setinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Xpl_Collection_ScalarSet, add) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	ZEPHIR_CALL_SELF(&_0, "cast", NULL, 0, value);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, xpl_collection_scalarset_ce, this_ptr, "attach", NULL, 0, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Xpl_Collection_ScalarSet, remove) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value, *inf = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &value, &inf);

	if (!inf) {
		inf = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_SELF(&_0, "cast", NULL, 0, value);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, xpl_collection_scalarset_ce, this_ptr, "detach", NULL, 0, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Xpl_Collection_ScalarSet, attach) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value, *inf = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &value, &inf);

	if (!inf) {
		inf = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", NULL, 0, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Xpl_Collection_ScalarSet, detach) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value, *inf = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &value, &inf);

	if (!inf) {
		inf = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "remove", NULL, 0, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Xpl_Collection_ScalarSet, contains) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	ZEPHIR_CALL_SELF(&_0, "cast", NULL, 0, value);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_PARENT(xpl_collection_scalarset_ce, this_ptr, "contains", NULL, 0, _0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Xpl_Collection_ScalarSet, getHash) {

	zval *_1 = NULL;
	zval *obj, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &obj);



	ZEPHIR_OBS_VAR(_0);
	zephir_read_property(&_0, obj, SL("scalar"), PH_NOISY_CC);
	zephir_get_strval(_1, _0);
	RETURN_CTOR(_1);

}

PHP_METHOD(Xpl_Collection_ScalarSet, isEmpty) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "count", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG_IDENTICAL(_0, 0));

}

PHP_METHOD(Xpl_Collection_ScalarSet, toArray) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("iterator_to_array", NULL, 14, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Xpl_Collection_ScalarSet, addAll) {

	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_5 = NULL;
	zval *data, *value = NULL, *_0 = NULL, **_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_CALL_CE_STATIC(&_0, xpl_type_ce, "iterate", &_1, 15, data);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_3, &_2, 0, 0, "xpl/collection/scalarset.zep", 56);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(value, _4);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", &_5, 0, value);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Xpl_Collection_ScalarSet, cast) {

	zval *_1$$3;
	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *value, *_3, *_4, *_5, *_2$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	_0 = Z_TYPE_P(value) == IS_NULL;
	if (!(_0)) {
		_0 = zephir_is_scalar(value);
	}
	if (likely(_0)) {
		ZEPHIR_INIT_VAR(_1$$3);
		zephir_create_array(_1$$3, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&_1$$3, SL("scalar"), &value, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(_2$$3, _1$$3);
		zephir_convert_to_object(_2$$3);
		RETURN_CCTOR(_2$$3);
	}
	ZEPHIR_INIT_VAR(_3);
	object_init_ex(_3, spl_ce_InvalidArgumentException);
	ZEPHIR_INIT_VAR(_4);
	zephir_gettype(_4, value TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_SV(_5, "Expecting null or scalar, given: ", _4);
	ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, 5, _5);
	zephir_check_call_status();
	zephir_throw_exception_debug(_3, "xpl/collection/scalarset.zep", 64 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

