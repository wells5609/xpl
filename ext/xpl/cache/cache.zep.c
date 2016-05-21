
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
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Xpl_Cache_Cache) {

	ZEPHIR_REGISTER_CLASS(Xpl\\Cache, Cache, xpl, cache_cache, xpl_cache_cache_method_entry, 0);

	/**
	 * @var \Xpl\Cache\DriverInterface
	 */
	zend_declare_property_null(xpl_cache_cache_ce, SL("driver"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var \Xpl\Cache\ItemPool[]
	 */
	zend_declare_property_null(xpl_cache_cache_ce, SL("pools"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array[]
	 */
	zend_declare_property_null(xpl_cache_cache_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_string(xpl_cache_cache_ce, SL("prefix"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	xpl_cache_cache_ce->create_object = zephir_init_properties_Xpl_Cache_Cache;
	/**
	 * @var string
	 */
	zend_declare_class_constant_string(xpl_cache_cache_ce, SL("DEFAULT_NAMESPACE"), "default" TSRMLS_CC);

	return SUCCESS;

}

/**
 * Constructor.
 *
 * @param \Xpl\Cache\DriverInterface driver [Optional]
 */
PHP_METHOD(Xpl_Cache_Cache, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *driver = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &driver);

	if (!driver) {
		ZEPHIR_CPY_WRT(driver, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(driver);
	}


	if (Z_TYPE_P(driver) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&driver, this_ptr, "getdetecteddriver", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdriver", NULL, 0, driver);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the cache item key prefix.
 *
 * @param string prefix
 *
 * @return \Xpl\Cache\Cache
 */
PHP_METHOD(Xpl_Cache_Cache, setPrefix) {

	zval *prefix_param = NULL, *_0, _1, *_2;
	zval *prefix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &prefix_param);

	if (unlikely(Z_TYPE_P(prefix_param) != IS_STRING && Z_TYPE_P(prefix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(prefix_param) == IS_STRING)) {
		zephir_get_strval(prefix, prefix_param);
	} else {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_EMPTY_STRING(prefix);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, ".", 0);
	zephir_fast_trim(_0, prefix, &_1, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VS(_2, _0, ".");
	zephir_update_property_this(this_ptr, SL("prefix"), _2 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the cache item key prefix.
 *
 * @return string
 */
PHP_METHOD(Xpl_Cache_Cache, getPrefix) {

	

	RETURN_MEMBER(this_ptr, "prefix");

}

/**
 * Returns the cache driver instance.
 *
 * @return \Xpl\Cache\DriverInterface
 */
PHP_METHOD(Xpl_Cache_Cache, getDriver) {

	

	RETURN_MEMBER(this_ptr, "driver");

}

/**
 * Sets the cache driver.
 *
 * @param \Xpl\Cache\DriverInterface driver
 *
 * @return \Xpl\Cache\Cache
 */
PHP_METHOD(Xpl_Cache_Cache, setDriver) {

	zval *driver;

	zephir_fetch_params(0, 1, 0, &driver);



	zephir_update_property_this(this_ptr, SL("driver"), driver TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the pool configuration settings for a given namespace.
 *
 * @param string namespaceName [Optional]
 *
 * @return array
 */
PHP_METHOD(Xpl_Cache_Cache, getConfig) {

	zend_bool _0;
	zval *defaults;
	zval *name_param = NULL, *_1, *_2, *_3;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_INIT_VAR(defaults);
	array_init(defaults);
	_0 = ZEPHIR_IS_EMPTY(name);
	if (!(_0)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		_0 = !(zephir_array_isset(_1, name));
	}
	if (_0) {
		RETURN_CTOR(defaults);
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch(&_3, _2, name, PH_NOISY | PH_READONLY, "xpl/cache/cache.zep", 108 TSRMLS_CC);
	zephir_fast_array_merge(return_value, &(defaults), &(_3) TSRMLS_CC);
	RETURN_MM();

}

/**
 * Sets the pool configuration settings for a given namespace.
 *
 * @param string namespaceName
 * @param array config
 *
 * @return \Xpl\Cache\Cache
 */
PHP_METHOD(Xpl_Cache_Cache, setConfig) {

	zval *config = NULL;
	zval *name_param = NULL, *config_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &config_param);

	zephir_get_strval(name, name_param);
	config = config_param;


	zephir_update_property_array(this_ptr, SL("config"), name, config TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the ItemPool for a given namespace.
 *
 * If no pool exists, one will be created.
 *
 * @param string namespaceName [Optional]
 *
 * @return \Xpl\Cache\ItemPool
 */
PHP_METHOD(Xpl_Cache_Cache, getPool) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *pool = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_OBS_VAR(pool);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pools"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&pool, _0, name, 0 TSRMLS_CC))) {
		ZEPHIR_CALL_METHOD(&pool, this_ptr, "createpool", NULL, 0, name);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("pools"), name, pool TSRMLS_CC);
	}
	RETURN_CCTOR(pool);

}

/**
 * Sets the ItemPool for a given namespace.
 *
 * @param \Xpl\Cache\ItemPool
 * @param string namespaceName [Optional]
 */
PHP_METHOD(Xpl_Cache_Cache, setPool) {

	zval *name = NULL;
	zval *pool, *name_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &pool, &name_param);

	zephir_get_strval(name, name_param);


	zephir_update_property_array(this_ptr, SL("pools"), name, pool TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Creates an ItemPool for the given namespace.
 *
 * @param string namespaceName
 *
 * @return \Xpl\Cache\ItemPool
 */
PHP_METHOD(Xpl_Cache_Cache, createPool) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *config = NULL, *driver = NULL, *driverClass = NULL, *prefix = NULL, *cachePrefix = NULL, *defaultTtl = NULL, *_0, *_5, *_1$$5, _2$$5, *_3$$5;
	zval *name = NULL, *_4$$7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	ZEPHIR_CALL_METHOD(&config, this_ptr, "getconfig", NULL, 0, name);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(driverClass);
	if (zephir_array_isset_string_fetch(&driverClass, config, SS("driver"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(driver);
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(driver, driverClass TSRMLS_CC);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&driver, this_ptr, "getdriver", NULL, 0);
		zephir_check_call_status();
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("prefix"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(prefix, _0);
	ZEPHIR_OBS_VAR(cachePrefix);
	if (zephir_array_isset_string_fetch(&cachePrefix, config, SS("prefix"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_1$$5);
		ZEPHIR_SINIT_VAR(_2$$5);
		ZVAL_STRING(&_2$$5, ".", 0);
		zephir_fast_trim(_1$$5, cachePrefix, &_2$$5, ZEPHIR_TRIM_BOTH TSRMLS_CC);
		ZEPHIR_INIT_VAR(_3$$5);
		ZEPHIR_CONCAT_VS(_3$$5, _1$$5, ".");
		zephir_concat_self(&prefix, _3$$5 TSRMLS_CC);
	} else {
		if (!ZEPHIR_IS_STRING_IDENTICAL(name, "default")) {
			ZEPHIR_INIT_VAR(_4$$7);
			ZEPHIR_CONCAT_VS(_4$$7, name, ".");
			zephir_concat_self(&prefix, _4$$7 TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_VAR(defaultTtl);
	if (!(zephir_array_isset_string_fetch(&defaultTtl, config, SS("default_ttl"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(defaultTtl);
		ZVAL_LONG(defaultTtl, 0);
	}
	object_init_ex(return_value, xpl_cache_itempool_ce);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, zephir_get_intval(defaultTtl));
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 26, driver, prefix, _5);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Detects and returns the first available cache driver.
 *
 * @return \Xpl\Cache\DriverInterface
 */
PHP_METHOD(Xpl_Cache_Cache, getDetectedDriver) {

	zend_class_entry *_7$$4;
	HashTable *_2;
	HashPosition _1;
	zval *driverClasses = NULL, *classname = NULL, *_0 = NULL, **_3, *_4$$3 = NULL, *_5$$3 = NULL, *_6$$4 = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(driverClasses);
	zephir_create_array(driverClasses, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Xpl\\Cache\\Driver\\ApcuDriver", 1);
	zephir_array_fast_append(driverClasses, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "Xpl\\Cache\\Driver\\ApcDriver", 1);
	zephir_array_fast_append(driverClasses, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "Xpl\\Cache\\Driver\\XCacheDriver", 1);
	zephir_array_fast_append(driverClasses, _0);
	zephir_is_iterable(driverClasses, &_2, &_1, 0, 0, "xpl/cache/cache.zep", 215);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(classname, _3);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZEPHIR_INIT_LNVAR(_5$$3);
		ZEPHIR_CONCAT_VS(_5$$3, classname, "::isAvailable");
		ZEPHIR_CALL_USER_FUNC(_4$$3, _5$$3);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE_IDENTICAL(_4$$3)) {
			zephir_fetch_safe_class(_6$$4, classname);
				_7$$4 = zend_fetch_class(Z_STRVAL_P(_6$$4), Z_STRLEN_P(_6$$4), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(return_value, _7$$4);
			if (zephir_has_constructor(return_value TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", &_8, 0);
				zephir_check_call_status();
			}
			RETURN_MM();
		}
	}
	object_init_ex(return_value, xpl_cache_driver_memorydriver_ce);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM();

}

static zend_object_value zephir_init_properties_Xpl_Cache_Cache(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_2, *_1$$3, *_3$$4;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("config"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("pools"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(this_ptr, SL("pools"), _3$$4 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

