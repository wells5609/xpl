
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
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Xpl_NamespaceAlias) {

	ZEPHIR_REGISTER_CLASS(Xpl, NamespaceAlias, xpl, namespacealias, xpl_namespacealias_method_entry, 0);

	/**
	 * Original namespace.
	 *
	 * @var string
	 */
	zend_declare_property_null(xpl_namespacealias_ce, SL("original"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Namespace alias.
	 *
	 * @var string
	 */
	zend_declare_property_null(xpl_namespacealias_ce, SL("alias"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Length of the alias namespace.
	 *
	 * @var int
	 */
	zend_declare_property_null(xpl_namespacealias_ce, SL("aliasLength"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Classes in the aliased namespace that have been resolved.
	 *
	 * @var array
	 */
	zend_declare_property_null(xpl_namespacealias_ce, SL("resolved"), ZEND_ACC_PRIVATE TSRMLS_CC);

	xpl_namespacealias_ce->create_object = zephir_init_properties_Xpl_NamespaceAlias;
	return SUCCESS;

}

/**
 * Constructor. Sets the original and alias namespace.
 *
 * @param string original Actual namespace name.
 * @param string alias Alias namespace to use in code.
 */
PHP_METHOD(Xpl_NamespaceAlias, __construct) {

	zval *original_param = NULL, *alias_param = NULL, *_0, _1, *_2, *_3, _4, *_5, *_6, *_7;
	zval *original = NULL, *alias = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &original_param, &alias_param);

	if (unlikely(Z_TYPE_P(original_param) != IS_STRING && Z_TYPE_P(original_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'original' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(original_param) == IS_STRING)) {
		zephir_get_strval(original, original_param);
	} else {
		ZEPHIR_INIT_VAR(original);
		ZVAL_EMPTY_STRING(original);
	}
	if (unlikely(Z_TYPE_P(alias_param) != IS_STRING && Z_TYPE_P(alias_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'alias' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(alias_param) == IS_STRING)) {
		zephir_get_strval(alias, alias_param);
	} else {
		ZEPHIR_INIT_VAR(alias);
		ZVAL_EMPTY_STRING(alias);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "\\", 0);
	zephir_fast_trim(_0, original, &_1, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VS(_2, _0, "\\");
	zephir_update_property_this(this_ptr, SL("original"), _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, "\\", 0);
	zephir_fast_trim(_3, alias, &_4, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_VS(_5, _3, "\\");
	zephir_update_property_this(this_ptr, SL("alias"), _5 TSRMLS_CC);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("alias"), PH_NOISY_CC);
	ZEPHIR_INIT_ZVAL_NREF(_7);
	ZVAL_LONG(_7, zephir_fast_strlen_ev(_6));
	zephir_update_property_this(this_ptr, SL("aliasLength"), _7 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Autoloader implementation to resolve classes in the aliased namespace.
 *
 * @param string classname
 */
PHP_METHOD(Xpl_NamespaceAlias, load) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *classname_param = NULL, *realClass = NULL, *_0, *_1$$3, *_2$$3, *_3$$3;
	zval *classname = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &classname_param);

	zephir_get_strval(classname, classname_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("alias"), PH_NOISY_CC);
	if (zephir_start_with(classname, _0, NULL)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("original"), PH_NOISY_CC);
		_2$$3 = zephir_fetch_nproperty_this(this_ptr, SL("aliasLength"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_3$$3);
		zephir_substr(_3$$3, classname, zephir_get_intval(_2$$3), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_INIT_VAR(realClass);
		ZEPHIR_CONCAT_VV(realClass, _1$$3, _3$$3);
		if (zephir_class_exists(realClass, 1 TSRMLS_CC)) {
			zephir_update_property_array(this_ptr, SL("resolved"), classname, realClass TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(NULL, "class_alias", NULL, 118, realClass, classname);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns an array of classes that have been resolved.
 *
 * @return array
 */
PHP_METHOD(Xpl_NamespaceAlias, getResolved) {

	

	RETURN_MEMBER(this_ptr, "resolved");

}

/**
 * Registers the autoloader.
 *
 * @return \Xpl\NamespaceAlias
 */
PHP_METHOD(Xpl_NamespaceAlias, register) {

	zval *_1;
	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, this_ptr);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "load", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", NULL, 53, _0, ZEPHIR_GLOBAL(global_true), ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Unregisters the autoloader.
 *
 * @return \Xpl\NamespaceAlias
 */
PHP_METHOD(Xpl_NamespaceAlias, unregister) {

	zval *_1;
	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, this_ptr);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "load", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_unregister", NULL, 54, _0);
	zephir_check_call_status();
	RETURN_THIS();

}

static zend_object_value zephir_init_properties_Xpl_NamespaceAlias(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("resolved"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("resolved"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

