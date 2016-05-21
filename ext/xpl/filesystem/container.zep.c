
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
#include "ext/spl/spl_iterators.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/file.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Xpl_Filesystem_Container) {

	ZEPHIR_REGISTER_CLASS(Xpl\\Filesystem, Container, xpl, filesystem_container, xpl_filesystem_container_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(xpl_filesystem_container_ce, SL("rootPath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(xpl_filesystem_container_ce, SL("paths"), ZEND_ACC_PROTECTED TSRMLS_CC);

	xpl_filesystem_container_ce->create_object = zephir_init_properties_Xpl_Filesystem_Container;

	zend_class_implements(xpl_filesystem_container_ce TSRMLS_CC, 1, spl_ce_Countable);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Xpl_Filesystem_Container, getRootPath) {

	

	RETURN_MEMBER(this_ptr, "rootPath");

}

PHP_METHOD(Xpl_Filesystem_Container, __construct) {

	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *rootPath_param = NULL, *realpath = NULL, *_1 = NULL, *_2;
	zval *rootPath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &rootPath_param);

	zephir_get_strval(rootPath, rootPath_param);


	ZEPHIR_CALL_FUNCTION(&realpath, "realpath", NULL, 47, rootPath);
	zephir_check_call_status();
	_0 = ZEPHIR_IS_FALSE_IDENTICAL(realpath);
	if (!(_0)) {
		ZEPHIR_CALL_FUNCTION(&_1, "is_dir", NULL, 106, realpath);
		zephir_check_call_status();
		_0 = !zephir_is_true(_1);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid base directory path", "xpl/filesystem/container.zep", 26);
		return;
	}
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VS(_2, realpath, "/");
	zephir_update_property_this(this_ptr, SL("rootPath"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Xpl_Filesystem_Container, setPaths) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *paths_param = NULL, *path = NULL, **_2;
	zval *paths = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &paths_param);

	zephir_get_arrval(paths, paths_param);


	zephir_is_iterable(paths, &_1, &_0, 0, 0, "xpl/filesystem/container.zep", 40);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(path, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addpath", &_3, 0, path);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

PHP_METHOD(Xpl_Filesystem_Container, getPaths) {

	

	RETURN_MEMBER(this_ptr, "paths");

}

PHP_METHOD(Xpl_Filesystem_Container, addPath) {

	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *realpath = NULL, *_1 = NULL, *_4, *_2$$3;
	zval *path = NULL, *_3$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(path, path_param);


	ZEPHIR_CALL_FUNCTION(&realpath, "realpath", NULL, 47, path);
	zephir_check_call_status();
	_0 = ZEPHIR_IS_FALSE_IDENTICAL(realpath);
	if (!(_0)) {
		ZEPHIR_CALL_FUNCTION(&_1, "is_dir", NULL, 106, realpath);
		zephir_check_call_status();
		_0 = !zephir_is_true(_1);
	}
	if (_0) {
		ZEPHIR_INIT_VAR(_2$$3);
		object_init_ex(_2$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_CONCAT_SV(_3$$3, "Invalid directory path: ", path);
		ZEPHIR_CALL_METHOD(NULL, _2$$3, "__construct", NULL, 5, _3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$3, "xpl/filesystem/container.zep", 54 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_VS(_4, realpath, "/");
	zephir_update_property_array_append(this_ptr, SL("paths"), _4 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Xpl_Filesystem_Container, hasPath) {

	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *realpath = NULL, *_1 = NULL, *_2, *_3;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(path, path_param);


	ZEPHIR_CALL_FUNCTION(&realpath, "realpath", NULL, 47, path);
	zephir_check_call_status();
	_0 = ZEPHIR_IS_FALSE_IDENTICAL(realpath);
	if (!(_0)) {
		ZEPHIR_CALL_FUNCTION(&_1, "is_dir", NULL, 106, realpath);
		zephir_check_call_status();
		_0 = !zephir_is_true(_1);
	}
	if (_0) {
		RETURN_MM_BOOL(0);
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("rootPath"), PH_NOISY_CC);
	if (ZEPHIR_IS_IDENTICAL(realpath, _2)) {
		RETURN_MM_BOOL(1);
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("paths"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("in_array", NULL, 2, realpath, _3, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Xpl_Filesystem_Container, getRelativePath) {

	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *realpath = NULL, *_1, *_2, _3;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(path, path_param);


	ZEPHIR_CALL_FUNCTION(&realpath, "realpath", NULL, 47, path);
	zephir_check_call_status();
	_0 = ZEPHIR_IS_FALSE_IDENTICAL(realpath);
	if (!(_0)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("rootPath"), PH_NOISY_CC);
		_0 = !(zephir_start_with(realpath, _1, NULL));
	}
	if (_0) {
		RETURN_MM_NULL();
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("rootPath"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, zephir_fast_strlen_ev(_2));
	zephir_substr(return_value, realpath, zephir_get_intval(&_3), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	RETURN_MM();

}

PHP_METHOD(Xpl_Filesystem_Container, find) {

	HashTable *_6;
	HashPosition _5;
	zval *filename_param = NULL, *path = NULL, *_0, _1, *_2, *_3, *_4, **_7, *_8$$4 = NULL;
	zval *filename = NULL, *file = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filename_param);

	zephir_get_strval(filename, filename_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "/\\", 0);
	zephir_fast_trim(_0, filename, &_1, ZEPHIR_TRIM_LEFT TSRMLS_CC);
	zephir_get_strval(filename, _0);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("rootPath"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VV(_3, _2, filename);
	zephir_get_strval(file, _3);
	if ((zephir_file_exists(file TSRMLS_CC) == SUCCESS)) {
		RETURN_CTOR(file);
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("paths"), PH_NOISY_CC);
	zephir_is_iterable(_4, &_6, &_5, 0, 0, "xpl/filesystem/container.zep", 109);
	for (
	  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zephir_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HVALUE(path, _7);
		ZEPHIR_INIT_LNVAR(_8$$4);
		ZEPHIR_CONCAT_VV(_8$$4, path, filename);
		zephir_get_strval(file, _8$$4);
		if ((zephir_file_exists(file TSRMLS_CC) == SUCCESS)) {
			RETURN_CTOR(file);
		}
	}
	RETURN_MM_NULL();

}

PHP_METHOD(Xpl_Filesystem_Container, search) {

	HashTable *_6;
	HashPosition _5;
	zval *files;
	zval *filename_param = NULL, *path = NULL, *_0, _1, *_2, *_3, *_4, **_7, *_9 = NULL, *_8$$4 = NULL;
	zval *filename = NULL, *file = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filename_param);

	zephir_get_strval(filename, filename_param);


	ZEPHIR_INIT_VAR(files);
	array_init(files);
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "/\\", 0);
	zephir_fast_trim(_0, filename, &_1, ZEPHIR_TRIM_LEFT TSRMLS_CC);
	zephir_get_strval(filename, _0);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("rootPath"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VV(_3, _2, filename);
	zephir_get_strval(file, _3);
	if ((zephir_file_exists(file TSRMLS_CC) == SUCCESS)) {
		zephir_array_append(&files, file, PH_SEPARATE, "xpl/filesystem/container.zep", 122);
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("paths"), PH_NOISY_CC);
	zephir_is_iterable(_4, &_6, &_5, 0, 0, "xpl/filesystem/container.zep", 132);
	for (
	  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zephir_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HVALUE(path, _7);
		ZEPHIR_INIT_LNVAR(_8$$4);
		ZEPHIR_CONCAT_VV(_8$$4, path, filename);
		zephir_get_strval(file, _8$$4);
		if ((zephir_file_exists(file TSRMLS_CC) == SUCCESS)) {
			zephir_array_append(&files, file, PH_SEPARATE, "xpl/filesystem/container.zep", 128);
		}
	}
	ZEPHIR_INIT_VAR(_9);
	if (ZEPHIR_IS_EMPTY(files)) {
		ZVAL_NULL(_9);
	} else {
		ZEPHIR_CPY_WRT(_9, files);
	}
	RETURN_CCTOR(_9);

}

PHP_METHOD(Xpl_Filesystem_Container, count) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("paths"), PH_NOISY_CC);
	RETURN_LONG((zephir_fast_count_int(_0 TSRMLS_CC) + 1));

}

static zend_object_value zephir_init_properties_Xpl_Filesystem_Container(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("paths"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("paths"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

