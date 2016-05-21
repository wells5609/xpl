
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Xpl_Config) {

	ZEPHIR_REGISTER_CLASS_EX(Xpl, Config, xpl, config, xpl_std_arrayobject_ce, xpl_config_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Xpl_Config, import) {

	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *util_util_typecast;
	zval *data, *key = NULL, *value = NULL, *_0 = NULL, **_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	util_util_typecast = zend_fetch_class(SL("\\Util\\Typecast"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_0, util_util_typecast, "toarray", NULL, data);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "xpl/config.zep", 19);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		if (Z_TYPE_P(value) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(value);
			object_init_ex(value, xpl_config_ce);
			ZEPHIR_CALL_METHOD(NULL, value, "__construct", &_4, value);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_5, key, value);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Xpl_Config, toArray) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;
	zend_class_entry *util_util_typecast;

	ZEPHIR_MM_GROW();

	util_util_typecast = zend_fetch_class(SL("\\Util\\Typecast"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getarraycopy", NULL);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_CE_STATIC(util_util_typecast, "toarrays", NULL, _0);
	zephir_check_call_status();
	RETURN_MM();

}

