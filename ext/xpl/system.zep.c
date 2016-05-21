
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
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/time.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


/**
 * System/server utilities.
 */
ZEPHIR_INIT_CLASS(Xpl_System) {

	ZEPHIR_REGISTER_CLASS(Xpl, System, xpl, system, xpl_system_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Xpl_System, sapi) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("php_sapi_name", NULL, 28);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Xpl_System, os) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "s", 0);
	ZEPHIR_RETURN_CALL_FUNCTION("php_uname", NULL, 182, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Xpl_System, version) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *extension = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &extension);

	if (!extension) {
		extension = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_RETURN_CALL_FUNCTION("phpversion", NULL, 183, extension);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Xpl_System, isCli) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "php_sapi_name", NULL, 28);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(_0, "cli"));

}

PHP_METHOD(Xpl_System, isWin) {

	zval _0;


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "/", 0);
	RETURN_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "\\"));

}

PHP_METHOD(Xpl_System, memoryUsage) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *megabytes_param = NULL, *_0$$3 = NULL;
	zend_bool megabytes;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &megabytes_param);

	if (!megabytes_param) {
		megabytes = 1;
	} else {
		megabytes = zephir_get_boolval(megabytes_param);
	}


	if (megabytes == 1) {
		ZEPHIR_CALL_FUNCTION(&_0$$3, "memory_get_usage", &_1, 184);
		zephir_check_call_status();
		RETURN_MM_DOUBLE(zephir_safe_div_double_long(zephir_safe_div_zval_long(_0$$3, 1024 TSRMLS_CC), (double) (1024) TSRMLS_CC));
	}
	ZEPHIR_RETURN_CALL_FUNCTION("memory_get_usage", &_1, 184);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Xpl_System, memoryPeakUsage) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *megabytes_param = NULL, *_0$$3 = NULL;
	zend_bool megabytes;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &megabytes_param);

	if (!megabytes_param) {
		megabytes = 1;
	} else {
		megabytes = zephir_get_boolval(megabytes_param);
	}


	if (megabytes == 1) {
		ZEPHIR_CALL_FUNCTION(&_0$$3, "memory_get_peak_usage", &_1, 185);
		zephir_check_call_status();
		RETURN_MM_DOUBLE(zephir_safe_div_double_long(zephir_safe_div_zval_long(_0$$3, 1024 TSRMLS_CC), (double) (1024) TSRMLS_CC));
	}
	ZEPHIR_RETURN_CALL_FUNCTION("memory_get_peak_usage", &_1, 185);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Xpl_System, timer) {

	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *milliseconds_param = NULL, *_SERVER, _0, *_1 = NULL, *startTime = NULL, *_2$$4 = NULL, *_4$$6, *_5$$6, *_6$$5;
	zend_bool milliseconds;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_fetch_params(1, 0, 1, &milliseconds_param);

	if (!milliseconds_param) {
		milliseconds = 1;
	} else {
		milliseconds = zephir_get_boolval(milliseconds_param);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "xdebug", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 16, &_0);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		if (milliseconds == 1) {
			ZEPHIR_CALL_FUNCTION(&_2$$4, "xdebug_time_index", &_3, 186);
			zephir_check_call_status();
			RETURN_MM_LONG((zephir_get_numberval(_2$$4) * 1000));
		}
		ZEPHIR_RETURN_CALL_FUNCTION("xdebug_time_index", &_3, 186);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(startTime);
	if (zephir_array_isset_string_fetch(&startTime, _SERVER, SS("REQUEST_TIME_FLOAT"), 0 TSRMLS_CC)) {
		if (milliseconds == 1) {
			ZEPHIR_INIT_VAR(_4$$6);
			zephir_microtime(_4$$6, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
			ZEPHIR_INIT_VAR(_5$$6);
			zephir_sub_function(_5$$6, _4$$6, startTime);
			RETURN_MM_LONG((zephir_get_numberval(_5$$6) * 1000));
		}
		ZEPHIR_INIT_VAR(_6$$5);
		zephir_microtime(_6$$5, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		zephir_sub_function(return_value, _6$$5, startTime);
		RETURN_MM();
	}
	RETURN_MM_NULL();

}

PHP_METHOD(Xpl_System, apc) {

	zend_bool _6$$4;
	zval _0, *_1 = NULL, _2$$3, *_3$$3 = NULL, *_5$$4 = NULL, _7$$4, *_8$$4 = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "apc", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 16, &_0);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_SINIT_VAR(_2$$3);
		ZVAL_STRING(&_2$$3, "apc.enabled", 0);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "ini_get", &_4, 27, &_2$$3);
		zephir_check_call_status();
		if (zephir_is_true(_3$$3)) {
			ZEPHIR_CALL_SELF(&_5$$4, "iscli", NULL, 0);
			zephir_check_call_status();
			_6$$4 = !zephir_is_true(_5$$4);
			if (!(_6$$4)) {
				ZEPHIR_SINIT_VAR(_7$$4);
				ZVAL_STRING(&_7$$4, "apc.enable_cli", 0);
				ZEPHIR_CALL_FUNCTION(&_8$$4, "ini_get", &_4, 27, &_7$$4);
				zephir_check_call_status();
				_6$$4 = zephir_is_true(_8$$4);
			}
			if (_6$$4) {
				RETURN_MM_BOOL(1);
			}
		}
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Xpl_System, apcu) {

	zend_bool _6$$4;
	zval _0, *_1 = NULL, _2$$3, *_3$$3 = NULL, *_5$$4 = NULL, _7$$4, *_8$$4 = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "apcu", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 16, &_0);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_SINIT_VAR(_2$$3);
		ZVAL_STRING(&_2$$3, "apc.enabled", 0);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "ini_get", &_4, 27, &_2$$3);
		zephir_check_call_status();
		if (zephir_is_true(_3$$3)) {
			ZEPHIR_CALL_SELF(&_5$$4, "iscli", NULL, 0);
			zephir_check_call_status();
			_6$$4 = !zephir_is_true(_5$$4);
			if (!(_6$$4)) {
				ZEPHIR_SINIT_VAR(_7$$4);
				ZVAL_STRING(&_7$$4, "apc.enable_cli", 0);
				ZEPHIR_CALL_FUNCTION(&_8$$4, "ini_get", &_4, 27, &_7$$4);
				zephir_check_call_status();
				_6$$4 = zephir_is_true(_8$$4);
			}
			if (_6$$4) {
				RETURN_MM_BOOL(1);
			}
		}
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Xpl_System, xdebug) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "xdebug", 0);
	ZEPHIR_RETURN_CALL_FUNCTION("extension_loaded", NULL, 16, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Xpl_System, mbstring) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "mbstring", 0);
	ZEPHIR_RETURN_CALL_FUNCTION("extension_loaded", NULL, 16, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Xpl_System, normalizePath) {

	zval *path_param = NULL, *_0, _1, _2, _3;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	if (unlikely(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(path, path_param);
	} else {
		ZEPHIR_INIT_VAR(path);
		ZVAL_EMPTY_STRING(path);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "\\", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "/", 0);
	zephir_fast_str_replace(&_0, &_1, &_2, path TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "/\\", 0);
	zephir_fast_trim(return_value, _0, &_3, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	RETURN_MM();

}

PHP_METHOD(Xpl_System, tempDir) {

	zval *_0, *_1 = NULL, _2;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CALL_FUNCTION(&_1, "sys_get_temp_dir", NULL, 187);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "/\\", 0);
	zephir_fast_trim(_0, _1, &_2, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_CONCAT_VS(return_value, _0, "/");
	RETURN_MM();

}

