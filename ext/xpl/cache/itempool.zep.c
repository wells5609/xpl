
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "ext/spl/spl_array.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/time.h"


/**
 * CacheItemPoolInterface generates CacheItemInterface objects.
 *
 * The primary purpose of Cache\CacheItemPoolInterface is to accept a key from
 * the Calling Library and return the associated Cache\CacheItemInterface object.
 * It is also the primary point of interaction with the entire cache collection.
 * All configuration and initialization of the Pool is left up to an
 * Implementing Library.
 */
ZEPHIR_INIT_CLASS(Xpl_Cache_ItemPool) {

	ZEPHIR_REGISTER_CLASS(Xpl\\Cache, ItemPool, xpl, cache_itempool, xpl_cache_itempool_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(xpl_cache_itempool_ce, SL("prefix"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var \Xpl\Cache\DriverInterface
	 */
	zend_declare_property_null(xpl_cache_itempool_ce, SL("driver"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(xpl_cache_itempool_ce, SL("items"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(xpl_cache_itempool_ce, SL("deferred"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var boolean
	 */
	zend_declare_property_bool(xpl_cache_itempool_ce, SL("commitOnClear"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var boolean
	 */
	zend_declare_property_bool(xpl_cache_itempool_ce, SL("commitOnSave"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	xpl_cache_itempool_ce->create_object = zephir_init_properties_Xpl_Cache_ItemPool;

	zend_class_implements(xpl_cache_itempool_ce TSRMLS_CC, 1, zephir_get_internal_ce(SS("psr\\cache\\cacheitempoolinterface") TSRMLS_CC));
	return SUCCESS;

}

/**
 * Constructor.
 */
PHP_METHOD(Xpl_Cache_ItemPool, __construct) {

	int defaultTtl;
	zval *prefix = NULL;
	zval *driver, *prefix_param = NULL, *defaultTtl_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &driver, &prefix_param, &defaultTtl_param);

	if (!prefix_param) {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_STRING(prefix, "", 1);
	} else {
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
	}
	if (!defaultTtl_param) {
		defaultTtl = 0;
	} else {
	if (unlikely(Z_TYPE_P(defaultTtl_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'defaultTtl' must be a int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	defaultTtl = Z_LVAL_P(defaultTtl_param);
	}


	zephir_update_property_this(this_ptr, SL("driver"), driver TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("prefix"), prefix TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the cache driver.
 *
 * @return \Xpl\Cache\DriverInterface
 * 	 The current cache driver instance.
 */
PHP_METHOD(Xpl_Cache_ItemPool, getDriver) {

	

	RETURN_MEMBER(this_ptr, "driver");

}

/**
 * Returns a Cache Item representing the specified key.
 *
 * This method must always return a CacheItemInterface object, even in case of
 * a cache miss. It MUST NOT return null.
 *
 * @param string key
 *   The key for which to return the corresponding Cache Item.
 *
 * @throws \Xpl\Cache\InvalidArgumentException
 *   If the key string is not a legal value a \Psr\Cache\InvalidArgumentException
 *   MUST be thrown.
 *
 * @return \Psr\Cache\CacheItemInterface
 *   The corresponding Cache Item.
 */
PHP_METHOD(Xpl_Cache_ItemPool, getItem) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *item = NULL, *_0 = NULL, *_3, *_5, *_6, *_7, *_8 = NULL, *_1$$3, *_4$$4 = NULL;
	zval *key = NULL, *_2$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isvalidkey", NULL, 0, key);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, xpl_cache_invalidargumentexception_ce);
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_CONCAT_SVS(_2$$3, "Invalid item key: '", key, "'.");
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 42, _2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "xpl/cache/itempool.zep", 91 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(item);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&item, _3, key, 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_4$$4, this_ptr, "isitemexpired", NULL, 0, item);
		zephir_check_call_status();
		if (!(zephir_is_true(_4$$4))) {
			RETURN_CCTOR(item);
		}
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("driver"), PH_NOISY_CC);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_CONCAT_VV(_7, _6, key);
	ZEPHIR_CALL_METHOD(&item, _5, "fetch", NULL, 0, _7);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_8, item, "ishit", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_8)) {
		zephir_update_property_array(this_ptr, SL("items"), key, item TSRMLS_CC);
	}
	RETURN_CCTOR(item);

}

/**
 * Returns a traversable set of cache items.
 *
 * @param array keys
 * An indexed array of keys of items to retrieve.
 *
 * @throws \Psr\Cache\InvalidArgumentException
 *   If any of the keys in keys are not a legal value a \Psr\Cache\InvalidArgumentException
 *   MUST be thrown.
 *
 * @return array|\Traversable
 *   A traversable collection of Cache Items keyed by the cache keys of
 *   each item. A Cache item will be returned for each key, even if that
 *   key is not found. However, if no keys are specified then an empty
 *   traversable MUST be returned instead.
 */
PHP_METHOD(Xpl_Cache_ItemPool, getItems) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keys_param = NULL, *items = NULL, *_1;
	zval *keys = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &keys_param);

	if (!keys_param) {
		ZEPHIR_INIT_VAR(keys);
		array_init(keys);
	} else {
	keys = keys_param;
	}


	if (zephir_fast_count_int(keys TSRMLS_CC) == 0) {
		object_init_ex(return_value, spl_ce_ArrayObject);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 43);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, this_ptr);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "getItem", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_CALL_FUNCTION(&items, "array_map", NULL, 44, _0, keys);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("array_combine", NULL, 45, keys, items);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Confirms if the cache contains specified cache item.
 *
 * Note: This method MAY avoid retrieving the cached value for performance reasons.
 * This could result in a race condition with CacheItemInterface::get(). To avoid
 * such situation use CacheItemInterface::isHit() instead.
 *
 * @param string key
 *    The key for which to check existence.
 *
 * @throws \Psr\Cache\InvalidArgumentException
 *   If the key string is not a legal value a \Psr\Cache\InvalidArgumentException
 *   MUST be thrown.
 *
 * @return bool
 *  True if item exists in the cache, false otherwise.
 */
PHP_METHOD(Xpl_Cache_ItemPool, hasItem) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_0 = NULL, *_3, *_4, *_5, *_1$$3;
	zval *key = NULL, *_2$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isvalidkey", NULL, 0, key);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, xpl_cache_invalidargumentexception_ce);
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_CONCAT_SVS(_2$$3, "Invalid item key: '", key, "'.");
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 42, _2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "xpl/cache/itempool.zep", 158 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("driver"), PH_NOISY_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_VV(_5, _4, key);
	ZEPHIR_RETURN_CALL_METHOD(_3, "exists", NULL, 0, _5);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Deletes all items in the pool.
 *
 * @return bool
 *   True if the pool was successfully cleared. False if there was an error.
 */
PHP_METHOD(Xpl_Cache_ItemPool, clear) {

	HashTable *_4$$3;
	HashPosition _3$$3;
	zval *prefix = NULL, *driver = NULL, *key = NULL, *e = NULL, *_0, *_1$$3, *_2$$3 = NULL, **_5$$3, *_8$$3, *_6$$4 = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("prefix"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(prefix, _0);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("driver"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(driver, _0);

	/* try_start_1: */

		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2$$3);
		zephir_is_iterable(_1$$3, &_4$$3, &_3$$3, 0, 0, "xpl/cache/itempool.zep", 183);
		for (
		  ; zephir_hash_get_current_data_ex(_4$$3, (void**) &_5$$3, &_3$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_4$$3, &_3$$3)
		) {
			ZEPHIR_GET_HMKEY(key, _4$$3, _3$$3);
			ZEPHIR_GET_HVALUE(_2$$3, _5$$3);
			ZEPHIR_INIT_LNVAR(_6$$4);
			ZEPHIR_CONCAT_VV(_6$$4, prefix, key);
			ZEPHIR_CALL_METHOD(NULL, driver, "delete", &_7, 0, _6$$4);
			zephir_check_call_status_or_jump(try_end_1);
		}
		ZEPHIR_INIT_VAR(_8$$3);
		array_init(_8$$3);
		zephir_update_property_this(this_ptr, SL("items"), _8$$3 TSRMLS_CC);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_CPY_WRT(e, EG(exception));
		if (zephir_instance_of_ev(e, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			RETURN_MM_BOOL(0);
		}
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("commitOnClear"), PH_NOISY_CC);
	if (ZEPHIR_IS_TRUE_IDENTICAL(_0)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "commit", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(1);

}

/**
 * Removes the item from the pool.
 *
 * @param string key
 *   The key for which to delete
 *
 * @throws \Psr\Cache\InvalidArgumentException
 *   If the key string is not a legal value a \Psr\Cache\InvalidArgumentException
 *   MUST be thrown.
 *
 * @return bool
 *   True if the item was successfully removed. False if there was an error.
 */
PHP_METHOD(Xpl_Cache_ItemPool, deleteItem) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *e = NULL, *_0 = NULL, *_1$$3, *_3$$4, *_4$$4, *_5$$4, *_6$$4;
	zval *key = NULL, *_2$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isvalidkey", NULL, 0, key);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, xpl_cache_invalidargumentexception_ce);
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_CONCAT_SVS(_2$$3, "Invalid item key: '", key, "'.");
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 42, _2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "xpl/cache/itempool.zep", 214 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}

	/* try_start_1: */

		_3$$4 = zephir_fetch_nproperty_this(this_ptr, SL("driver"), PH_NOISY_CC);
		_4$$4 = zephir_fetch_nproperty_this(this_ptr, SL("prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_5$$4);
		ZEPHIR_CONCAT_VV(_5$$4, _4$$4, key);
		ZEPHIR_CALL_METHOD(NULL, _3$$4, "delete", NULL, 0, _5$$4);
		zephir_check_call_status_or_jump(try_end_1);
		_6$$4 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
		zephir_array_unset(&_6$$4, key, PH_SEPARATE);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_CPY_WRT(e, EG(exception));
		if (zephir_instance_of_ev(e, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			RETURN_MM_BOOL(0);
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Removes multiple items from the pool.
 *
 * @param array keys
 *   An array of keys that should be removed from the pool.

 * @throws \Psr\Cache\InvalidArgumentException
 *   If any of the keys in keys are not a legal value a \Psr\Cache\InvalidArgumentException
 *   MUST be thrown.
 *
 * @return bool
 *   True if the items were successfully removed. False if there was an error.
 */
PHP_METHOD(Xpl_Cache_ItemPool, deleteItems) {

	HashTable *_2;
	HashPosition _1;
	zend_bool success;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL, *_10 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keys_param = NULL, *driver = NULL, *prefix = NULL, *key = NULL, *e = NULL, *_0, **_3, *_4$$3 = NULL, *_6$$4 = NULL, *_7$$4 = NULL, *_9$$5 = NULL, *_11$$5;
	zval *keys = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keys_param);

	keys = keys_param;


	success = 1;
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("driver"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(driver, _0);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("prefix"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(prefix, _0);
	zephir_is_iterable(keys, &_2, &_1, 0, 0, "xpl/cache/itempool.zep", 268);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(key, _3);
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "isvalidkey", &_5, 0, key);
		zephir_check_call_status();
		if (!(zephir_is_true(_4$$3))) {
			ZEPHIR_INIT_NVAR(_6$$4);
			object_init_ex(_6$$4, xpl_cache_invalidargumentexception_ce);
			ZEPHIR_INIT_LNVAR(_7$$4);
			ZEPHIR_CONCAT_SVS(_7$$4, "Invalid item key: '", key, "'.");
			ZEPHIR_CALL_METHOD(NULL, _6$$4, "__construct", &_8, 42, _7$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_6$$4, "xpl/cache/itempool.zep", 254 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}

		/* try_start_1: */

			ZEPHIR_INIT_LNVAR(_9$$5);
			ZEPHIR_CONCAT_VV(_9$$5, prefix, key);
			ZEPHIR_CALL_METHOD(NULL, driver, "delete", &_10, 0, _9$$5);
			zephir_check_call_status_or_jump(try_end_1);
			_11$$5 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
			zephir_array_unset(&_11$$5, key, PH_SEPARATE);

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_CPY_WRT(e, EG(exception));
			if (zephir_instance_of_ev(e, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				success = 0;
			}
		}
	}
	RETURN_MM_BOOL(success);

}

/**
 * Persists a cache item immediately.
 *
 * @param \Psr\Cache\CacheItemInterface item
 *   The cache item to save.
 *
 * @return bool
 *   True if the item was successfully persisted. False if there was an error.
 */
PHP_METHOD(Xpl_Cache_ItemPool, save) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *item, *e = NULL, *_0$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &item);




	/* try_start_1: */

		_0$$3 = zephir_fetch_nproperty_this(this_ptr, SL("driver"), PH_NOISY_CC);
		ZEPHIR_RETURN_CALL_METHOD(_0$$3, "put", NULL, 0, item);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_MM();

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_CPY_WRT(e, EG(exception));
		if (zephir_instance_of_ev(e, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			RETURN_MM_BOOL(0);
		}
	}

}

/**
 * Sets a cache item to be persisted later.
 *
 * @param \Psr\Cache\CacheItemInterface item
 *   The cache item to save.
 *
 * @return bool
 *   False if the item could not be queued or if a commit was attempted and failed. True otherwise.
 */
PHP_METHOD(Xpl_Cache_ItemPool, saveDeferred) {

	zval *item, *e = NULL;

	zephir_fetch_params(0, 1, 0, &item);




	/* try_start_1: */

		zephir_update_property_array_append(this_ptr, SL("deferred"), item TSRMLS_CC);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_CPY_WRT(e, EG(exception));
		if (zephir_instance_of_ev(e, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			RETURN_BOOL(0);
		}
	}
	RETURN_BOOL(1);

}

/**
 * Persists any deferred cache items.
 *
 * @return bool
 *   True if all not-yet-saved items were successfully saved or there were none. False otherwise.
 */
PHP_METHOD(Xpl_Cache_ItemPool, commit) {

	HashTable *_2$$4;
	HashPosition _1$$4;
	zval *deferred = NULL, *item = NULL, *e = NULL, *_0, *_6, **_3$$4, *_4$$5 = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, count = 0, saved;

	ZEPHIR_MM_GROW();

	saved = 0;
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("deferred"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(deferred, _0);
	count = zephir_fast_count_int(deferred TSRMLS_CC);
	if (count == 0) {
		RETURN_MM_BOOL(1);
	}

	/* try_start_1: */

		zephir_is_iterable(deferred, &_2$$4, &_1$$4, 0, 0, "xpl/cache/itempool.zep", 335);
		for (
		  ; zephir_hash_get_current_data_ex(_2$$4, (void**) &_3$$4, &_1$$4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2$$4, &_1$$4)
		) {
			ZEPHIR_GET_HVALUE(item, _3$$4);
			ZEPHIR_CALL_METHOD(&_4$$5, this_ptr, "save", &_5, 0, item);
			zephir_check_call_status_or_jump(try_end_1);
			if (zephir_is_true(_4$$5)) {
				saved += 1;
			}
		}

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_CPY_WRT(e, EG(exception));
		if (zephir_instance_of_ev(e, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_VAR(_6);
	array_init(_6);
	zephir_update_property_this(this_ptr, SL("deferred"), _6 TSRMLS_CC);
	RETURN_MM_BOOL(saved == count);

}

/**
 * Resets the cache items in memory.
 *
 * @return void
 */
PHP_METHOD(Xpl_Cache_ItemPool, reset) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("items"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks if an item key is valid.
 *
 * @param string key
 *
 * @return boolean
 */
PHP_METHOD(Xpl_Cache_ItemPool, isValidKey) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *len = NULL, _0, *_1 = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	ZEPHIR_INIT_VAR(len);
	ZVAL_LONG(len, zephir_fast_strlen_ev(key));
	if (ZEPHIR_IS_LONG_IDENTICAL(len, 0)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "{}()/\\@:", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "strcspn", NULL, 46, key, &_0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(len, _1));

}

/**
 * Checks whether the given item is expired.
 *
 * @param \Xpl\Cache\Item
 *
 * @return boolean
 */
PHP_METHOD(Xpl_Cache_ItemPool, isItemExpired) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *cacheItem, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cacheItem);



	ZEPHIR_INIT_VAR(_0);
	zephir_time(_0);
	ZEPHIR_CALL_METHOD(&_1, cacheItem, "getexpiration", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_GE(_0, _1));

}

static zend_object_value zephir_init_properties_Xpl_Cache_ItemPool(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_2, *_1$$3, *_3$$4;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("deferred"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("deferred"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("items"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(this_ptr, SL("items"), _3$$4 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

