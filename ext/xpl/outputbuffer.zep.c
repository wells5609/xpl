
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Xpl_OutputBuffer) {

	ZEPHIR_REGISTER_CLASS(Xpl, OutputBuffer, xpl, outputbuffer, xpl_outputbuffer_method_entry, 0);

	zend_declare_property_null(xpl_outputbuffer_ce, SL("root"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_bool(xpl_outputbuffer_ce, SL("valid"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(xpl_outputbuffer_ce, SL("level"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(xpl_outputbuffer_ce, SL("callback"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Xpl_OutputBuffer, start) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *outputCallback = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &outputCallback);

	if (!outputCallback) {
		outputCallback = ZEPHIR_GLOBAL(global_null);
	}


	object_init_ex(return_value, xpl_outputbuffer_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 120, outputCallback);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Xpl_OutputBuffer, finish) {

	zval *_0, *_1$$3;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_static_property_ce(xpl_outputbuffer_ce, SL("root") TSRMLS_CC);
	if (Z_TYPE_P(_0) != IS_NULL) {
		_1$$3 = zephir_fetch_static_property_ce(xpl_outputbuffer_ce, SL("root") TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "endflush", NULL, 0);
		zephir_check_call_status();
		zephir_update_static_property_ce(xpl_outputbuffer_ce, SL("root"), &ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Xpl_OutputBuffer, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *outputCallback = NULL, *_0 = NULL, *_1$$3 = NULL, *_2$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &outputCallback);

	if (!outputCallback) {
		outputCallback = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(this_ptr, SL("callback"), outputCallback TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_0, "ob_start", NULL, 121, outputCallback);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_CALL_FUNCTION(&_1$$3, "ob_get_level", NULL, 122);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("level"), _1$$3 TSRMLS_CC);
		if (1) {
			zephir_update_property_this(this_ptr, SL("valid"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(this_ptr, SL("valid"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
		_2$$3 = zephir_fetch_static_property_ce(xpl_outputbuffer_ce, SL("root") TSRMLS_CC);
		if (Z_TYPE_P(_2$$3) == IS_NULL) {
			zephir_update_static_property_ce(xpl_outputbuffer_ce, SL("root"), &this_ptr TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Xpl_OutputBuffer, getContents) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "valid", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_contents", NULL, 123);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_NULL();

}

PHP_METHOD(Xpl_OutputBuffer, getClean) {

	zend_bool _1;
	zval *_0 = NULL, *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "valid", NULL, 0);
	zephir_check_call_status();
	_1 = zephir_is_true(_0);
	if (_1) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "active", NULL, 0);
		zephir_check_call_status();
		_1 = zephir_is_true(_2);
	}
	if (_1) {
		if (0) {
			zephir_update_property_this(this_ptr, SL("valid"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(this_ptr, SL("valid"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", NULL, 124);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_NULL();

}

PHP_METHOD(Xpl_OutputBuffer, getFullClean) {

	zval *_0 = NULL, *content = NULL, *level = NULL, *_1, *_2 = NULL, *_4$$4 = NULL, *_6$$4 = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "valid", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(content);
	ZVAL_STRING(content, "", 1);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("level"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(level, _1);
	while (1) {
		ZEPHIR_CALL_FUNCTION(&_2, "ob_get_level", &_3, 122);
		zephir_check_call_status();
		if (!(ZEPHIR_GE(_2, level))) {
			break;
		}
		ZEPHIR_CALL_FUNCTION(&_4$$4, "ob_get_clean", &_5, 124);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_6$$4);
		ZEPHIR_CONCAT_VV(_6$$4, _4$$4, content);
		ZEPHIR_CPY_WRT(content, _6$$4);
	}
	if (0) {
		zephir_update_property_this(this_ptr, SL("valid"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("valid"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_CCTOR(content);

}

PHP_METHOD(Xpl_OutputBuffer, clean) {

	zend_bool _1;
	zval *_0 = NULL, *_2 = NULL, *_3$$3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "valid", NULL, 0);
	zephir_check_call_status();
	_1 = zephir_is_true(_0);
	if (_1) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "active", NULL, 0);
		zephir_check_call_status();
		_1 = zephir_is_true(_2);
	}
	if (_1) {
		ZEPHIR_CALL_FUNCTION(&_3$$3, "ob_end_clean", NULL, 125);
		zephir_check_call_status();
		if (zephir_is_true(_3$$3)) {
			if (0) {
				zephir_update_property_this(this_ptr, SL("valid"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
			} else {
				zephir_update_property_this(this_ptr, SL("valid"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
			}
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Xpl_OutputBuffer, fullClean) {

	zval *level = NULL, *_0 = NULL, *_1$$3, *_2$$3 = NULL, *_4$$4 = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "valid", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("level"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(level, _1$$3);
		while (1) {
			ZEPHIR_CALL_FUNCTION(&_2$$3, "ob_get_level", &_3, 122);
			zephir_check_call_status();
			if (!(ZEPHIR_GE(_2$$3, level))) {
				break;
			}
			ZEPHIR_CALL_FUNCTION(&_4$$4, "ob_end_clean", &_5, 125);
			zephir_check_call_status();
			if (!(zephir_is_true(_4$$4))) {
				break;
			}
		}
		if (0) {
			zephir_update_property_this(this_ptr, SL("valid"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(this_ptr, SL("valid"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Xpl_OutputBuffer, flush) {

	zval *level = NULL, *_0 = NULL, *_1$$3, *_2$$3 = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "valid", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("level"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(level, _1$$3);
		while (1) {
			ZEPHIR_CALL_FUNCTION(&_2$$3, "ob_get_level", &_3, 122);
			zephir_check_call_status();
			if (!(ZEPHIR_GE(_2$$3, level))) {
				break;
			}
			ZEPHIR_CALL_FUNCTION(NULL, "ob_flush", &_4, 126);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Xpl_OutputBuffer, endFlush) {

	zval *level = NULL, *_0 = NULL, *_1$$3, *_2$$3 = NULL, *_4$$4 = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "valid", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("level"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(level, _1$$3);
		while (1) {
			ZEPHIR_CALL_FUNCTION(&_2$$3, "ob_get_level", &_3, 122);
			zephir_check_call_status();
			if (!(ZEPHIR_GE(_2$$3, level))) {
				break;
			}
			ZEPHIR_CALL_FUNCTION(&_4$$4, "ob_end_flush", &_5, 127);
			zephir_check_call_status();
			if (!(zephir_is_true(_4$$4))) {
				RETURN_MM_BOOL(0);
			}
		}
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Xpl_OutputBuffer, valid) {

	zval *_0, *_1$$3 = NULL, *_2$$3;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("valid"), PH_NOISY_CC);
	if (ZEPHIR_IS_TRUE_IDENTICAL(_0)) {
		ZEPHIR_CALL_FUNCTION(&_1$$3, "ob_get_level", NULL, 122);
		zephir_check_call_status();
		_2$$3 = zephir_fetch_nproperty_this(this_ptr, SL("level"), PH_NOISY_CC);
		if (ZEPHIR_LT(_1$$3, _2$$3)) {
			if (0) {
				zephir_update_property_this(this_ptr, SL("valid"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
			} else {
				zephir_update_property_this(this_ptr, SL("valid"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
			}
		}
	}
	RETURN_MM_MEMBER(this_ptr, "valid");

}

PHP_METHOD(Xpl_OutputBuffer, active) {

	zval *_0 = NULL, *_1;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "ob_get_level", NULL, 122);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("level"), PH_NOISY_CC);
	RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(_0, _1));

}

PHP_METHOD(Xpl_OutputBuffer, getLevel) {

	

	RETURN_MEMBER(this_ptr, "level");

}

PHP_METHOD(Xpl_OutputBuffer, getOutputCallback) {

	

	RETURN_MEMBER(this_ptr, "callback");

}

