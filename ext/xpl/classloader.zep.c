
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
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/require.h"
#include "kernel/hash.h"
#include "kernel/file.h"
#include "kernel/variables.h"


ZEPHIR_INIT_CLASS(Xpl_ClassLoader) {

	ZEPHIR_REGISTER_CLASS(Xpl, ClassLoader, xpl, classloader, xpl_classloader_method_entry, 0);

	/**
	 * PSR-4 prefixes lengths.
	 *
	 * @var array
	 */
	zend_declare_property_null(xpl_classloader_ce, SL("prefixLengthsPsr4"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * PSR-4 prefixes and paths.
	 *
	 * @var array
	 */
	zend_declare_property_null(xpl_classloader_ce, SL("prefixDirsPsr4"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * PSR-4 fallback paths.
	 *
	 * @var array
	 */
	zend_declare_property_null(xpl_classloader_ce, SL("fallbackDirsPsr4"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * PSR-0 prefixes and paths.
	 *
	 * @var array
	 */
	zend_declare_property_null(xpl_classloader_ce, SL("prefixesPsr0"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * PSR-0 fallback paths.
	 *
	 * @var array
	 */
	zend_declare_property_null(xpl_classloader_ce, SL("fallbackDirsPsr0"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Map of classes to file paths.
	 *
	 * @var array
	 */
	zend_declare_property_null(xpl_classloader_ce, SL("classMap"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Whether to search in the PHP include path.
	 *
	 * @var boolean
	 */
	zend_declare_property_bool(xpl_classloader_ce, SL("useIncludePath"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Path to a Composer vendor directory.
	 *
	 * @var string
	 */
	zend_declare_property_null(xpl_classloader_ce, SL("composerPath"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Unique hashes of imported loaders.
	 *
	 * @var string[]
	 */
	zend_declare_property_null(xpl_classloader_ce, SL("importHashes"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * Instances of ClassLoaders loaded through loadComposer().
	 *
	 * @var array
	 */
	zend_declare_property_null(xpl_classloader_ce, SL("composerInstances"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	xpl_classloader_ce->create_object = zephir_init_properties_Xpl_ClassLoader;

	zend_class_implements(xpl_classloader_ce TSRMLS_CC, 1, zend_ce_serializable);
	return SUCCESS;

}

/**
 * Returns a ClassLoader for the given Composer installation.
 *
 * @param string vendorPath
 * @param boolean prepend [Optional] Default = true
 *
 * @return \Xpl\ClassLoader
 */
PHP_METHOD(Xpl_ClassLoader, composer) {

	HashTable *_8, *_12, *_18$$10;
	HashPosition _7, _11, _17$$10;
	zephir_fcall_cache_entry *_10 = NULL, *_14 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool prepend;
	zval *vendorPath_param = NULL, *prepend_param = NULL, *composerPath = NULL, *instances = NULL, *loader = NULL, *ns = NULL, *path = NULL, *namespaces = NULL, *psr4 = NULL, *classMap = NULL, *filesPath = NULL, *files = NULL, *_0, _1, *_2, *_3, *_4 = NULL, *_5, *_6, **_9, **_13, *_15, *_16$$10 = NULL, **_19$$10;
	zval *vendorPath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &vendorPath_param, &prepend_param);

	if (unlikely(Z_TYPE_P(vendorPath_param) != IS_STRING && Z_TYPE_P(vendorPath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'vendorPath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(vendorPath_param) == IS_STRING)) {
		zephir_get_strval(vendorPath, vendorPath_param);
	} else {
		ZEPHIR_INIT_VAR(vendorPath);
		ZVAL_EMPTY_STRING(vendorPath);
	}
	if (!prepend_param) {
		prepend = 1;
	} else {
		prepend = zephir_get_boolval(prepend_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "/\\", 0);
	zephir_fast_trim(_0, vendorPath, &_1, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VS(_2, _0, "/composer");
	ZEPHIR_CALL_FUNCTION(&composerPath, "realpath", NULL, 47, _2);
	zephir_check_call_status();
	if (!(zephir_is_true(composerPath))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Composer directory does not exist", "xpl/classloader.zep", 147);
		return;
	}
	zephir_concat_self_str(&composerPath, SL("/") TSRMLS_CC);
	ZEPHIR_OBS_VAR(instances);
	zephir_read_static_property_ce(&instances, xpl_classloader_ce, SL("composerInstances") TSRMLS_CC);
	if (Z_TYPE_P(instances) != IS_NULL) {
		ZEPHIR_OBS_VAR(loader);
		if (zephir_array_isset_fetch(&loader, instances, composerPath, 0 TSRMLS_CC)) {
			RETURN_CCTOR(loader);
		}
	} else {
		ZEPHIR_INIT_NVAR(instances);
		array_init(instances);
	}
	ZEPHIR_INIT_NVAR(loader);
	object_init_ex(loader, xpl_classloader_ce);
	if (zephir_has_constructor(loader TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, loader, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VS(_3, composerPath, "autoload_namespaces.php");
	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_4);
	if (zephir_require_zval_ret(&_4, _3 TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CPY_WRT(namespaces, _4);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_VS(_5, composerPath, "autoload_psr4.php");
	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_4);
	if (zephir_require_zval_ret(&_4, _5 TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CPY_WRT(psr4, _4);
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_CONCAT_VS(_6, composerPath, "autoload_classmap.php");
	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_4);
	if (zephir_require_zval_ret(&_4, _6 TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CPY_WRT(classMap, _4);
	ZEPHIR_INIT_VAR(filesPath);
	ZEPHIR_CONCAT_VS(filesPath, composerPath, "autoload_files.php");
	zephir_is_iterable(namespaces, &_8, &_7, 0, 0, "xpl/classloader.zep", 171);
	for (
	  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
	  ; zephir_hash_move_forward_ex(_8, &_7)
	) {
		ZEPHIR_GET_HMKEY(ns, _8, _7);
		ZEPHIR_GET_HVALUE(path, _9);
		ZEPHIR_CALL_METHOD(NULL, loader, "set", &_10, 48, ns, path);
		zephir_check_call_status();
	}
	zephir_is_iterable(psr4, &_12, &_11, 0, 0, "xpl/classloader.zep", 175);
	for (
	  ; zephir_hash_get_current_data_ex(_12, (void**) &_13, &_11) == SUCCESS
	  ; zephir_hash_move_forward_ex(_12, &_11)
	) {
		ZEPHIR_GET_HMKEY(ns, _12, _11);
		ZEPHIR_GET_HVALUE(path, _13);
		ZEPHIR_CALL_METHOD(NULL, loader, "setpsr4", &_14, 49, ns, path);
		zephir_check_call_status();
	}
	if (zephir_fast_count_int(classMap TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, loader, "addclassmap", NULL, 50, classMap);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_15);
	if (prepend) {
		ZVAL_BOOL(_15, 1);
	} else {
		ZVAL_BOOL(_15, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, loader, "register", NULL, 51, _15);
	zephir_check_call_status();
	if ((zephir_file_exists(filesPath TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_16$$10);
		if (zephir_require_zval_ret(&_16$$10, filesPath TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
		ZEPHIR_CPY_WRT(files, _16$$10);
		zephir_is_iterable(files, &_18$$10, &_17$$10, 0, 0, "xpl/classloader.zep", 186);
		for (
		  ; zephir_hash_get_current_data_ex(_18$$10, (void**) &_19$$10, &_17$$10) == SUCCESS
		  ; zephir_hash_move_forward_ex(_18$$10, &_17$$10)
		) {
			ZEPHIR_GET_HVALUE(path, _19$$10);
			if (zephir_require_zval(path TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
		}
	}
	ZEPHIR_CALL_METHOD(NULL, loader, "setcomposerpath", NULL, 52, composerPath);
	zephir_check_call_status();
	zephir_array_update_zval(&instances, composerPath, &loader, PH_COPY | PH_SEPARATE);
	zephir_update_static_property_ce(xpl_classloader_ce, SL("composerInstances"), &instances TSRMLS_CC);
	RETURN_CCTOR(loader);

}

PHP_METHOD(Xpl_ClassLoader, getPrefixes) {

	zval *_0, _1;
	int ZEPHIR_LAST_CALL_STATUS;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("prefixesPsr0"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "array_merge", 0);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_1, _0);
	zephir_check_call_status();
	return;

}

PHP_METHOD(Xpl_ClassLoader, getPrefixesPsr4) {

	

	RETURN_MEMBER(this_ptr, "prefixDirsPsr4");

}

PHP_METHOD(Xpl_ClassLoader, getFallbackDirs) {

	

	RETURN_MEMBER(this_ptr, "fallbackDirsPsr0");

}

PHP_METHOD(Xpl_ClassLoader, getFallbackDirsPsr4) {

	

	RETURN_MEMBER(this_ptr, "fallbackDirsPsr4");

}

PHP_METHOD(Xpl_ClassLoader, getClassMap) {

	

	RETURN_MEMBER(this_ptr, "classMap");

}

/**
 * @param array $classMap Class to filename map
 */
PHP_METHOD(Xpl_ClassLoader, addClassMap) {

	zval *classMap_param = NULL, *_0, *_1$$3, *_2$$3;
	zval *classMap = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &classMap_param);

	classMap = classMap_param;


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("classMap"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_1$$3);
		_2$$3 = zephir_fetch_nproperty_this(this_ptr, SL("classMap"), PH_NOISY_CC);
		zephir_fast_array_merge(_1$$3, &(_2$$3), &(classMap) TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("classMap"), _1$$3 TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("classMap"), classMap TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Registers a set of PSR-0 directories for a given prefix, either
 * appending or prepending to the ones previously set for this prefix.
 *
 * @param string       $prefix  The prefix
 * @param array|string $paths   The PSR-0 root directories
 * @param bool         $prepend Whether to prepend the directories
 */
PHP_METHOD(Xpl_ClassLoader, add) {

	zend_bool prepend;
	zval *prefix, *paths = NULL, *prepend_param = NULL, *firstChar = NULL, *prefixPaths = NULL, _4, _5, *_6, *_7, *_0$$5, *_1$$5, *_2$$6, *_3$$6, *_8$$9, *_9$$10;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &prefix, &paths, &prepend_param);

	ZEPHIR_SEPARATE_PARAM(paths);
	if (!prepend_param) {
		prepend = 0;
	} else {
		prepend = zephir_get_boolval(prepend_param);
	}


	if (Z_TYPE_P(paths) == IS_STRING) {
		ZEPHIR_INIT_NVAR(paths);
		zephir_create_array(paths, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(paths, paths);
	}
	if (Z_TYPE_P(prefix) != IS_STRING) {
		if (prepend) {
			ZEPHIR_INIT_VAR(_0$$5);
			_1$$5 = zephir_fetch_nproperty_this(this_ptr, SL("fallbackDirsPsr0"), PH_NOISY_CC);
			zephir_fast_array_merge(_0$$5, &(paths), &(_1$$5) TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("fallbackDirsPsr0"), _0$$5 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(_2$$6);
			_3$$6 = zephir_fetch_nproperty_this(this_ptr, SL("fallbackDirsPsr0"), PH_NOISY_CC);
			zephir_fast_array_merge(_2$$6, &(_3$$6), &(paths) TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("fallbackDirsPsr0"), _2$$6 TSRMLS_CC);
		}
		RETURN_MM_NULL();
	}
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 0);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, 1);
	ZEPHIR_INIT_VAR(firstChar);
	zephir_substr(firstChar, prefix, 0 , 1 , 0);
	ZEPHIR_OBS_VAR(prefixPaths);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("prefixesPsr0"), PH_NOISY_CC);
	zephir_array_fetch(&_7, _6, firstChar, PH_READONLY, "xpl/classloader.zep", 262 TSRMLS_CC);
	if (!(zephir_array_isset_fetch(&prefixPaths, _7, prefix, 0 TSRMLS_CC))) {
		ZEPHIR_CPY_WRT(prefixPaths, paths);
	} else {
		if (prepend) {
			ZEPHIR_INIT_VAR(_8$$9);
			zephir_fast_array_merge(_8$$9, &(paths), &(prefixPaths) TSRMLS_CC);
			ZEPHIR_CPY_WRT(prefixPaths, _8$$9);
		} else {
			ZEPHIR_INIT_VAR(_9$$10);
			zephir_fast_array_merge(_9$$10, &(prefixPaths), &(paths) TSRMLS_CC);
			ZEPHIR_CPY_WRT(prefixPaths, _9$$10);
		}
	}
	zephir_update_property_array_multi(this_ptr, SL("prefixesPsr0"), &prefixPaths TSRMLS_CC, SL("zz"), 2, firstChar, prefix);
	ZEPHIR_MM_RESTORE();

}

/**
 * Registers a set of PSR-4 directories for a given namespace, either
 * appending or prepending to the ones previously set for this namespace.
 *
 * @param string       $prefix  The prefix/namespace, with trailing "\\"
 * @param array|string $paths   The PSR-0 base directories
 * @param bool         $prepend Whether to prepend the directories
 * @throws \InvalidArgumentException
 */
PHP_METHOD(Xpl_ClassLoader, addPsr4) {

	zend_bool prepend;
	zval *prefix, *paths = NULL, *prepend_param = NULL, *firstChar = NULL, *prefixDirs = NULL, *_4, *_0$$5, *_1$$5, *_2$$6, *_3$$6, _5$$7, _6$$7, *_7$$7, *_8$$10, *_9$$11;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &prefix, &paths, &prepend_param);

	ZEPHIR_SEPARATE_PARAM(paths);
	if (!prepend_param) {
		prepend = 0;
	} else {
		prepend = zephir_get_boolval(prepend_param);
	}


	if (Z_TYPE_P(paths) == IS_STRING) {
		ZEPHIR_INIT_NVAR(paths);
		zephir_create_array(paths, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(paths, paths);
	}
	if (Z_TYPE_P(prefix) != IS_STRING) {
		if (prepend) {
			ZEPHIR_INIT_VAR(_0$$5);
			_1$$5 = zephir_fetch_nproperty_this(this_ptr, SL("fallbackDirsPsr4"), PH_NOISY_CC);
			zephir_fast_array_merge(_0$$5, &(paths), &(_1$$5) TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("fallbackDirsPsr4"), _0$$5 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(_2$$6);
			_3$$6 = zephir_fetch_nproperty_this(this_ptr, SL("fallbackDirsPsr4"), PH_NOISY_CC);
			zephir_fast_array_merge(_2$$6, &(_3$$6), &(paths) TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("fallbackDirsPsr4"), _2$$6 TSRMLS_CC);
		}
		RETURN_MM_NULL();
	}
	ZEPHIR_OBS_VAR(prefixDirs);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("prefixDirsPsr4"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&prefixDirs, _4, prefix, 0 TSRMLS_CC))) {
		ZEPHIR_SINIT_VAR(_5$$7);
		ZVAL_LONG(&_5$$7, 0);
		ZEPHIR_SINIT_VAR(_6$$7);
		ZVAL_LONG(&_6$$7, 1);
		ZEPHIR_INIT_VAR(firstChar);
		zephir_substr(firstChar, prefix, 0 , 1 , 0);
		if (!(zephir_end_with_str(prefix, SL("\\")))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "A non-empty PSR-4 prefix must end with a namespace separator.", "xpl/classloader.zep", 310);
			return;
		}
		ZEPHIR_INIT_VAR(_7$$7);
		ZVAL_LONG(_7$$7, zephir_fast_strlen_ev(prefix));
		zephir_update_property_array_multi(this_ptr, SL("prefixLengthsPsr4"), &_7$$7 TSRMLS_CC, SL("zz"), 2, firstChar, prefix);
		zephir_update_property_array(this_ptr, SL("prefixDirsPsr4"), prefix, paths TSRMLS_CC);
	} else {
		if (prepend) {
			ZEPHIR_INIT_VAR(_8$$10);
			zephir_fast_array_merge(_8$$10, &(paths), &(prefixDirs) TSRMLS_CC);
			zephir_update_property_array(this_ptr, SL("prefixDirsPsr4"), prefix, _8$$10 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(_9$$11);
			zephir_fast_array_merge(_9$$11, &(prefixDirs), &(paths) TSRMLS_CC);
			zephir_update_property_array(this_ptr, SL("prefixDirsPsr4"), prefix, _9$$11 TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Registers a set of PSR-0 directories for a given prefix,
 * replacing any others previously set for this prefix.
 *
 * @param string       $prefix The prefix
 * @param array|string $paths  The PSR-0 base directories
 */
PHP_METHOD(Xpl_ClassLoader, set) {

	zval *prefix, *paths = NULL, _0$$4, _1$$4, *_2$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &prefix, &paths);

	ZEPHIR_SEPARATE_PARAM(paths);


	if (Z_TYPE_P(paths) == IS_STRING) {
		ZEPHIR_INIT_NVAR(paths);
		zephir_create_array(paths, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(paths, paths);
	}
	if (Z_TYPE_P(prefix) == IS_STRING) {
		ZEPHIR_SINIT_VAR(_0$$4);
		ZVAL_LONG(&_0$$4, 0);
		ZEPHIR_SINIT_VAR(_1$$4);
		ZVAL_LONG(&_1$$4, 1);
		ZEPHIR_INIT_VAR(_2$$4);
		zephir_substr(_2$$4, prefix, 0 , 1 , 0);
		zephir_update_property_array_multi(this_ptr, SL("prefixesPsr0"), &paths TSRMLS_CC, SL("zz"), 2, _2$$4, prefix);
	} else {
		zephir_update_property_this(this_ptr, SL("fallbackDirsPsr0"), paths TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Registers a set of PSR-4 directories for a given namespace,
 * replacing any others previously set for this namespace.
 *
 * @param string       $prefix The prefix/namespace, with trailing "\\"
 * @param array|string $paths  The PSR-4 base directories
 *
 * @throws \InvalidArgumentException
 */
PHP_METHOD(Xpl_ClassLoader, setPsr4) {

	zval *prefix, *paths = NULL, *_0$$4, _1$$4, _2$$4, *_3$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &prefix, &paths);

	ZEPHIR_SEPARATE_PARAM(paths);


	if (Z_TYPE_P(paths) == IS_STRING) {
		ZEPHIR_INIT_NVAR(paths);
		zephir_create_array(paths, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(paths, paths);
	}
	if (Z_TYPE_P(prefix) == IS_STRING) {
		if (!(zephir_end_with_str(prefix, SL("\\")))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "A non-empty PSR-4 prefix must end with a namespace separator.", "xpl/classloader.zep", 366);
			return;
		}
		ZEPHIR_INIT_VAR(_0$$4);
		ZVAL_LONG(_0$$4, zephir_fast_strlen_ev(prefix));
		ZEPHIR_SINIT_VAR(_1$$4);
		ZVAL_LONG(&_1$$4, 0);
		ZEPHIR_SINIT_VAR(_2$$4);
		ZVAL_LONG(&_2$$4, 1);
		ZEPHIR_INIT_VAR(_3$$4);
		zephir_substr(_3$$4, prefix, 0 , 1 , 0);
		zephir_update_property_array_multi(this_ptr, SL("prefixLengthsPsr4"), &_0$$4 TSRMLS_CC, SL("zz"), 2, _3$$4, prefix);
		zephir_update_property_array(this_ptr, SL("prefixDirsPsr4"), prefix, paths TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("fallbackDirsPsr4"), paths TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Turns on searching the include path for class files.
 *
 * @param bool $useIncludePath
 */
PHP_METHOD(Xpl_ClassLoader, setUseIncludePath) {

	zval *useIncludePath_param = NULL;
	zend_bool useIncludePath;

	zephir_fetch_params(0, 1, 0, &useIncludePath_param);

	useIncludePath = zephir_get_boolval(useIncludePath_param);


	if (useIncludePath) {
		zephir_update_property_this(this_ptr, SL("useIncludePath"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("useIncludePath"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}

}

/**
 * Can be used to check if the autoloader uses the include path to check
 * for classes.
 *
 * @return bool
 */
PHP_METHOD(Xpl_ClassLoader, getUseIncludePath) {

	

	RETURN_MEMBER(this_ptr, "useIncludePath");

}

/**
 * Registers this instance as an autoloader.
 *
 * @param bool $prepend Whether to prepend the autoloader or not
 */
PHP_METHOD(Xpl_ClassLoader, register) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *prepend_param = NULL, *_1, _2;
	zend_bool prepend;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prepend_param);

	if (!prepend_param) {
		prepend = 0;
	} else {
		prepend = zephir_get_boolval(prepend_param);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, this_ptr);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "loadClass", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_BOOL(&_2, (prepend ? 1 : 0));
	ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", NULL, 53, _0, ZEPHIR_GLOBAL(global_true), &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Unregisters this instance as an autoloader.
 */
PHP_METHOD(Xpl_ClassLoader, unregister) {

	zval *_1;
	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, this_ptr);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "loadClass", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_unregister", NULL, 54, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Loads the given class or interface.
 *
 * @param  string    $class The name of the class
 * @return bool|null True if loaded, null otherwise
 */
PHP_METHOD(Xpl_ClassLoader, loadClass) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, *file = NULL;
	zval *className = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);

	if (unlikely(Z_TYPE_P(className_param) != IS_STRING && Z_TYPE_P(className_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'className' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(className_param) == IS_STRING)) {
		zephir_get_strval(className, className_param);
	} else {
		ZEPHIR_INIT_VAR(className);
		ZVAL_EMPTY_STRING(className);
	}


	ZEPHIR_CALL_METHOD(&file, this_ptr, "findfile", NULL, 0, className);
	zephir_check_call_status();
	if (Z_TYPE_P(file) == IS_STRING) {
		if (zephir_require_zval(file TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Finds the path to the file where the class is defined.
 *
 * @param string $class The name of the class
 *
 * @return string|false The path if found, false otherwise
 */
PHP_METHOD(Xpl_ClassLoader, findFile) {

	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *className_param = NULL, *file = NULL, *_0, _1, *_2, *_3, _5$$5, *_6$$5 = NULL, *_7$$6;
	zval *className = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);

	if (unlikely(Z_TYPE_P(className_param) != IS_STRING && Z_TYPE_P(className_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'className' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(className_param) == IS_STRING)) {
		zephir_get_strval(className, className_param);
	} else {
		ZEPHIR_INIT_VAR(className);
		ZVAL_EMPTY_STRING(className);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "\\", 0);
	zephir_fast_trim(_0, className, &_1, ZEPHIR_TRIM_LEFT TSRMLS_CC);
	zephir_get_strval(className, _0);
	ZEPHIR_OBS_VAR(file);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("classMap"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&file, _2, className, 0 TSRMLS_CC)) {
		RETURN_CCTOR(file);
	}
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, ".php", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&file, this_ptr, "findfilewithextension", &_4, 0, className, _3);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	if (Z_TYPE_P(file) == IS_STRING) {
		zephir_update_property_array(this_ptr, SL("classMap"), className, file TSRMLS_CC);
	} else {
		ZEPHIR_SINIT_VAR(_5$$5);
		ZVAL_STRING(&_5$$5, "HHVM_VERSION", 0);
		ZEPHIR_CALL_FUNCTION(&_6$$5, "defined", NULL, 55, &_5$$5);
		zephir_check_call_status();
		if (zephir_is_true(_6$$5)) {
			ZEPHIR_INIT_VAR(_7$$6);
			ZVAL_STRING(_7$$6, ".hh", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&file, this_ptr, "findfilewithextension", &_4, 0, className, _7$$6);
			zephir_check_temp_parameter(_7$$6);
			zephir_check_call_status();
			if (Z_TYPE_P(file) == IS_STRING) {
				zephir_update_property_array(this_ptr, SL("classMap"), className, file TSRMLS_CC);
				RETURN_CCTOR(file);
			}
		}
		ZEPHIR_INIT_NVAR(file);
		ZVAL_BOOL(file, 0);
		zephir_update_property_array(this_ptr, SL("classMap"), className, file TSRMLS_CC);
	}
	RETURN_CCTOR(file);

}

PHP_METHOD(Xpl_ClassLoader, findFileWithExtension) {

	HashTable *_16, *_39, *_6$$3, *_11$$5, *_32$$12, *_35$$14;
	HashPosition _15, _38, _5$$3, _10$$5, _31$$12, _34$$14;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *className_param = NULL, *ext_param = NULL, *logicalPathPsr4 = NULL, *firstChar = NULL, *prefixLengthsPsr4 = NULL, *prefix = NULL, *length = NULL, *dir = NULL, *file = NULL, *prefixesPsr0 = NULL, *logicalPathPsr0 = NULL, *nsPos = NULL, *dirs = NULL, _0 = zval_used_for_init, _1 = zval_used_for_init, *_2 = NULL, *_4, *_14, **_17, _18, *_30, *_37, **_40, *_41, **_7$$3, *_8$$5, *_9$$5, **_12$$5, *_13$$6 = NULL, _19$$10, _20$$10, *_21$$10, _22$$10, *_23$$10, _24$$10, _25$$10, *_26$$10 = NULL, _27$$11, _28$$11, *_29$$11 = NULL, **_33$$12, **_36$$14;
	zval *className = NULL, *ext = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &className_param, &ext_param);

	if (unlikely(Z_TYPE_P(className_param) != IS_STRING && Z_TYPE_P(className_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'className' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(className_param) == IS_STRING)) {
		zephir_get_strval(className, className_param);
	} else {
		ZEPHIR_INIT_VAR(className);
		ZVAL_EMPTY_STRING(className);
	}
	zephir_get_strval(ext, ext_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "\\", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "/", 0);
	ZEPHIR_CALL_FUNCTION(&_2, "strtr", &_3, 56, className, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(logicalPathPsr4);
	ZEPHIR_CONCAT_VV(logicalPathPsr4, _2, ext);
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_INIT_VAR(firstChar);
	zephir_substr(firstChar, className, 0 , 1 , 0);
	ZEPHIR_OBS_VAR(prefixLengthsPsr4);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("prefixLengthsPsr4"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&prefixLengthsPsr4, _4, firstChar, 0 TSRMLS_CC)) {
		zephir_is_iterable(prefixLengthsPsr4, &_6$$3, &_5$$3, 0, 0, "xpl/classloader.zep", 505);
		for (
		  ; zephir_hash_get_current_data_ex(_6$$3, (void**) &_7$$3, &_5$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_6$$3, &_5$$3)
		) {
			ZEPHIR_GET_HMKEY(prefix, _6$$3, _5$$3);
			ZEPHIR_GET_HVALUE(length, _7$$3);
			if (zephir_start_with(className, prefix, ZEPHIR_GLOBAL(global_false))) {
				_8$$5 = zephir_fetch_nproperty_this(this_ptr, SL("prefixDirsPsr4"), PH_NOISY_CC);
				zephir_array_fetch(&_9$$5, _8$$5, prefix, PH_NOISY | PH_READONLY, "xpl/classloader.zep", 495 TSRMLS_CC);
				zephir_is_iterable(_9$$5, &_11$$5, &_10$$5, 0, 0, "xpl/classloader.zep", 503);
				for (
				  ; zephir_hash_get_current_data_ex(_11$$5, (void**) &_12$$5, &_10$$5) == SUCCESS
				  ; zephir_hash_move_forward_ex(_11$$5, &_10$$5)
				) {
					ZEPHIR_GET_HVALUE(dir, _12$$5);
					ZEPHIR_INIT_NVAR(_13$$6);
					zephir_substr(_13$$6, logicalPathPsr4, zephir_get_intval(length), 0, ZEPHIR_SUBSTR_NO_LENGTH);
					ZEPHIR_INIT_NVAR(file);
					ZEPHIR_CONCAT_VSV(file, dir, "/", _13$$6);
					if ((zephir_file_exists(file TSRMLS_CC) == SUCCESS)) {
						RETURN_CCTOR(file);
					}
				}
			}
		}
	}
	_14 = zephir_fetch_nproperty_this(this_ptr, SL("fallbackDirsPsr4"), PH_NOISY_CC);
	zephir_is_iterable(_14, &_16, &_15, 0, 0, "xpl/classloader.zep", 517);
	for (
	  ; zephir_hash_get_current_data_ex(_16, (void**) &_17, &_15) == SUCCESS
	  ; zephir_hash_move_forward_ex(_16, &_15)
	) {
		ZEPHIR_GET_HVALUE(dir, _17);
		ZEPHIR_INIT_NVAR(file);
		ZEPHIR_CONCAT_VSV(file, dir, "/", logicalPathPsr4);
		if ((zephir_file_exists(file TSRMLS_CC) == SUCCESS)) {
			RETURN_CCTOR(file);
		}
	}
	ZEPHIR_SINIT_VAR(_18);
	ZVAL_STRING(&_18, "\\", 0);
	ZEPHIR_CALL_FUNCTION(&nsPos, "strrpos", NULL, 57, className, &_18);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(logicalPathPsr0);
	if (zephir_is_true(nsPos)) {
		ZEPHIR_SINIT_VAR(_19$$10);
		ZVAL_LONG(&_19$$10, 0);
		ZEPHIR_SINIT_VAR(_20$$10);
		ZVAL_LONG(&_20$$10, (zephir_get_numberval(nsPos) + 1));
		ZEPHIR_INIT_VAR(_21$$10);
		zephir_substr(_21$$10, logicalPathPsr4, 0 , zephir_get_intval(&_20$$10), 0);
		ZEPHIR_SINIT_VAR(_22$$10);
		ZVAL_LONG(&_22$$10, (zephir_get_numberval(nsPos) + 1));
		ZEPHIR_INIT_VAR(_23$$10);
		zephir_substr(_23$$10, logicalPathPsr4, zephir_get_intval(&_22$$10), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_SINIT_VAR(_24$$10);
		ZVAL_STRING(&_24$$10, "_", 0);
		ZEPHIR_SINIT_VAR(_25$$10);
		ZVAL_STRING(&_25$$10, "/", 0);
		ZEPHIR_CALL_FUNCTION(&_26$$10, "strtr", &_3, 56, _23$$10, &_24$$10, &_25$$10);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(logicalPathPsr0, _21$$10, _26$$10);
	} else {
		ZEPHIR_SINIT_VAR(_27$$11);
		ZVAL_STRING(&_27$$11, "_", 0);
		ZEPHIR_SINIT_VAR(_28$$11);
		ZVAL_STRING(&_28$$11, "/", 0);
		ZEPHIR_CALL_FUNCTION(&_29$$11, "strtr", &_3, 56, className, &_27$$11, &_28$$11);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VV(logicalPathPsr0, _29$$11, ext);
	}
	ZEPHIR_OBS_VAR(prefixesPsr0);
	_30 = zephir_fetch_nproperty_this(this_ptr, SL("prefixesPsr0"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&prefixesPsr0, _30, firstChar, 0 TSRMLS_CC)) {
		zephir_is_iterable(prefixesPsr0, &_32$$12, &_31$$12, 0, 0, "xpl/classloader.zep", 546);
		for (
		  ; zephir_hash_get_current_data_ex(_32$$12, (void**) &_33$$12, &_31$$12) == SUCCESS
		  ; zephir_hash_move_forward_ex(_32$$12, &_31$$12)
		) {
			ZEPHIR_GET_HMKEY(prefix, _32$$12, _31$$12);
			ZEPHIR_GET_HVALUE(dirs, _33$$12);
			if (zephir_start_with(className, prefix, NULL)) {
				zephir_is_iterable(dirs, &_35$$14, &_34$$14, 0, 0, "xpl/classloader.zep", 544);
				for (
				  ; zephir_hash_get_current_data_ex(_35$$14, (void**) &_36$$14, &_34$$14) == SUCCESS
				  ; zephir_hash_move_forward_ex(_35$$14, &_34$$14)
				) {
					ZEPHIR_GET_HVALUE(dir, _36$$14);
					ZEPHIR_INIT_NVAR(file);
					ZEPHIR_CONCAT_VSV(file, dir, "/", logicalPathPsr0);
					if ((zephir_file_exists(file TSRMLS_CC) == SUCCESS)) {
						RETURN_CCTOR(file);
					}
				}
			}
		}
	}
	_37 = zephir_fetch_nproperty_this(this_ptr, SL("fallbackDirsPsr0"), PH_NOISY_CC);
	zephir_is_iterable(_37, &_39, &_38, 0, 0, "xpl/classloader.zep", 559);
	for (
	  ; zephir_hash_get_current_data_ex(_39, (void**) &_40, &_38) == SUCCESS
	  ; zephir_hash_move_forward_ex(_39, &_38)
	) {
		ZEPHIR_GET_HVALUE(dir, _40);
		ZEPHIR_INIT_NVAR(file);
		ZEPHIR_CONCAT_VSV(file, dir, "/", logicalPathPsr0);
		if ((zephir_file_exists(file TSRMLS_CC) == SUCCESS)) {
			RETURN_CCTOR(file);
		}
	}
	_41 = zephir_fetch_nproperty_this(this_ptr, SL("useIncludePath"), PH_NOISY_CC);
	if (ZEPHIR_IS_TRUE_IDENTICAL(_41)) {
		ZEPHIR_CALL_FUNCTION(&file, "stream_resolve_include_path", NULL, 58, logicalPathPsr0);
		zephir_check_call_status();
		if (zephir_is_true(file)) {
			RETURN_CCTOR(file);
		}
	}
	RETURN_MM_NULL();

}

/**
 * Sets the loader's Composer path.
 *
 * @param string path Path to 'vendor' directory
 */
PHP_METHOD(Xpl_ClassLoader, setComposerPath) {

	zval *path_param = NULL;
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


	zephir_update_property_this(this_ptr, SL("composerPath"), path TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the loader's Composer path, if any.
 *
 * @return string|null
 */
PHP_METHOD(Xpl_ClassLoader, getComposerPath) {

	

	RETURN_MEMBER(this_ptr, "composerPath");

}

/**
 * Exports the ClassLoader properties to a file.
 *
 * @param string filePath
 *
 * @throws \InvalidArgumentException if file path exists and is not writable.
 *
 * @return boolean
 */
PHP_METHOD(Xpl_ClassLoader, export) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *filePath_param = NULL, *content = NULL, *thisHash = NULL, *importHash = NULL, *realpath = NULL, *_4 = NULL, *_5, *_0$$3 = NULL, *_3$$3, *_1$$4;
	zval *filePath = NULL, *_2$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filePath_param);

	if (unlikely(Z_TYPE_P(filePath_param) != IS_STRING && Z_TYPE_P(filePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(filePath_param) == IS_STRING)) {
		zephir_get_strval(filePath, filePath_param);
	} else {
		ZEPHIR_INIT_VAR(filePath);
		ZVAL_EMPTY_STRING(filePath);
	}


	ZEPHIR_CALL_METHOD(&thisHash, this_ptr, "gethash", NULL, 0);
	zephir_check_call_status();
	if ((zephir_file_exists(filePath TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_FUNCTION(&_0$$3, "is_writable", NULL, 59, filePath);
		zephir_check_call_status();
		if (unlikely(!zephir_is_true(_0$$3))) {
			ZEPHIR_INIT_VAR(_1$$4);
			object_init_ex(_1$$4, spl_ce_InvalidArgumentException);
			ZEPHIR_INIT_VAR(_2$$4);
			ZEPHIR_CONCAT_SV(_2$$4, "Unwritable export file: ", filePath);
			ZEPHIR_CALL_METHOD(NULL, _1$$4, "__construct", NULL, 5, _2$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_1$$4, "xpl/classloader.zep", 609 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_FUNCTION(&realpath, "realpath", NULL, 47, filePath);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(importHash);
		_3$$3 = zephir_fetch_static_property_ce(xpl_classloader_ce, SL("importHashes") TSRMLS_CC);
		if (zephir_array_isset_fetch(&importHash, _3$$3, realpath, 0 TSRMLS_CC)) {
			if (ZEPHIR_IS_IDENTICAL(importHash, thisHash)) {
				RETURN_MM_BOOL(0);
			}
		}
	}
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_INIT_NVAR(_4);
	zephir_var_export_ex(_4, &this_ptr TSRMLS_CC);
	ZEPHIR_INIT_VAR(content);
	ZEPHIR_CONCAT_SVS(content, "<?php \nreturn ", _4, ";");
	ZEPHIR_INIT_VAR(_5);
	zephir_file_put_contents(_5, filePath, content TSRMLS_CC);
	RETURN_MM_BOOL(zephir_get_boolval(_5));

}

/**
 * Imports the ClassLoader's properties from an array.
 *
 * @param array properties
 */
PHP_METHOD(Xpl_ClassLoader, import) {

	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *properties_param = NULL, *key = NULL, *value = NULL, *composerPath = NULL, **_2;
	zval *properties = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &properties_param);

	properties = properties_param;


	zephir_is_iterable(properties, &_1, &_0, 0, 0, "xpl/classloader.zep", 640);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		zephir_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(composerPath);
	if (zephir_array_isset_string_fetch(&composerPath, properties, SS("composerPath"), 0 TSRMLS_CC)) {
		if (Z_TYPE_P(composerPath) == IS_STRING) {
			zephir_update_static_property_array_multi_ce(xpl_classloader_ce, SL("composerInstances"), &this_ptr TSRMLS_CC, SL("z"), 1, composerPath);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "register", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Creates a ClassLoader from a file created via export().
 *
 * @param string filePath
 *
 * @return \Xpl\ClassLoader
 */
PHP_METHOD(Xpl_ClassLoader, fromExportFile) {

	zend_bool _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *filePath_param = NULL, *realpath = NULL, *loader = NULL, *_2 = NULL, *_8, *_0$$3, *_4$$4, *_5$$4 = NULL, _6$$4, *_7$$4 = NULL;
	zval *filePath = NULL, *_1$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filePath_param);

	if (unlikely(Z_TYPE_P(filePath_param) != IS_STRING && Z_TYPE_P(filePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(filePath_param) == IS_STRING)) {
		zephir_get_strval(filePath, filePath_param);
	} else {
		ZEPHIR_INIT_VAR(filePath);
		ZVAL_EMPTY_STRING(filePath);
	}


	ZEPHIR_CALL_FUNCTION(&realpath, "realpath", NULL, 47, filePath);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(realpath)) {
		ZEPHIR_INIT_VAR(_0$$3);
		object_init_ex(_0$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(_1$$3);
		ZEPHIR_CONCAT_SV(_1$$3, "Invalid compiled classloader file: ", filePath);
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 5, _1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$3, "xpl/classloader.zep", 662 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_2);
	if (zephir_require_zval_ret(&_2, realpath TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CPY_WRT(loader, _2);
	_3 = Z_TYPE_P(loader) != IS_OBJECT;
	if (!(_3)) {
		_3 = !((zephir_instance_of_ev(loader, xpl_classloader_ce TSRMLS_CC)));
	}
	if (_3) {
		ZEPHIR_INIT_VAR(_4$$4);
		object_init_ex(_4$$4, spl_ce_UnexpectedValueException);
		ZEPHIR_INIT_VAR(_5$$4);
		if (Z_TYPE_P(loader) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(_5$$4);
			zephir_get_class(_5$$4, loader, 0 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(_5$$4);
			zephir_gettype(_5$$4, loader TSRMLS_CC);
		}
		ZEPHIR_SINIT_VAR(_6$$4);
		ZVAL_STRING(&_6$$4, "Expected instance of ClassLoader, given: '%s'.", 0);
		ZEPHIR_CALL_FUNCTION(&_7$$4, "sprintf", NULL, 41, &_6$$4, _5$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _4$$4, "__construct", NULL, 60, _7$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4$$4, "xpl/classloader.zep", 671 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_CALL_FUNCTION(&_2, "serialize", NULL, 3, loader);
	zephir_check_call_status();
	zephir_md5(_8, _2);
	zephir_update_static_property_array_multi_ce(xpl_classloader_ce, SL("importHashes"), &_8 TSRMLS_CC, SL("z"), 1, realpath);
	RETURN_CCTOR(loader);

}

PHP_METHOD(Xpl_ClassLoader, __set_state) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *loader = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	data = data_param;


	ZEPHIR_INIT_VAR(loader);
	object_init_ex(loader, xpl_classloader_ce);
	if (zephir_has_constructor(loader TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, loader, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, loader, "import", NULL, 61, data);
	zephir_check_call_status();
	RETURN_CCTOR(loader);

}

PHP_METHOD(Xpl_ClassLoader, serialize) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "get_object_vars", NULL, 62, this_ptr);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 3, _0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Xpl_ClassLoader, unserialize) {

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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "import", NULL, 0, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Xpl_ClassLoader, getHash) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "serialize", NULL, 3, this_ptr);
	zephir_check_call_status();
	zephir_md5(return_value, _0);
	RETURN_MM();

}

static zend_object_value zephir_init_properties_Xpl_ClassLoader(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_2, *_4, *_6, *_8, *_10, *_1$$3, *_3$$4, *_5$$5, *_7$$6, *_9$$7, *_11$$8;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("classMap"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("classMap"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("fallbackDirsPsr0"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(this_ptr, SL("fallbackDirsPsr0"), _3$$4 TSRMLS_CC);
		}
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("prefixesPsr0"), PH_NOISY_CC);
		if (Z_TYPE_P(_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(_5$$5);
			array_init(_5$$5);
			zephir_update_property_this(this_ptr, SL("prefixesPsr0"), _5$$5 TSRMLS_CC);
		}
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("fallbackDirsPsr4"), PH_NOISY_CC);
		if (Z_TYPE_P(_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(_7$$6);
			array_init(_7$$6);
			zephir_update_property_this(this_ptr, SL("fallbackDirsPsr4"), _7$$6 TSRMLS_CC);
		}
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("prefixDirsPsr4"), PH_NOISY_CC);
		if (Z_TYPE_P(_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(_9$$7);
			array_init(_9$$7);
			zephir_update_property_this(this_ptr, SL("prefixDirsPsr4"), _9$$7 TSRMLS_CC);
		}
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("prefixLengthsPsr4"), PH_NOISY_CC);
		if (Z_TYPE_P(_10) == IS_NULL) {
			ZEPHIR_INIT_VAR(_11$$8);
			array_init(_11$$8);
			zephir_update_property_this(this_ptr, SL("prefixLengthsPsr4"), _11$$8 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

void zephir_init_static_properties_Xpl_ClassLoader(TSRMLS_D) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_static_property_ce(xpl_classloader_ce, SL("composerInstances"), &_0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_static_property_ce(xpl_classloader_ce, SL("importHashes"), &_1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

