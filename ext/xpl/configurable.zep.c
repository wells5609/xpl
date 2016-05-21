
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/require.h"


ZEPHIR_INIT_CLASS(Xpl_Configurable) {

	ZEPHIR_REGISTER_CLASS(Xpl, Configurable, xpl, configurable, xpl_configurable_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var \Xpl\Collection\Config
	 */
	zend_declare_property_null(xpl_configurable_ce, SL("configuration"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(xpl_configurable_ce TSRMLS_CC, 1, xpl_configurableinterface_ce);
	return SUCCESS;

}

/**
 * Sets the object configuration.
 *
 * @param \Xpl\Collection\Config config
 */
PHP_METHOD(Xpl_Configurable, setConfig) {

	zval *config;

	zephir_fetch_params(0, 1, 0, &config);



	zephir_update_property_this(this_ptr, SL("configuration"), config TSRMLS_CC);

}

/**
 * Returns the object configuration.
 *
 * @return \Xpl\Collection\Config
 */
PHP_METHOD(Xpl_Configurable, getConfig) {

	zval *config = NULL, *e = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(config);
	zephir_read_property_this(&config, this_ptr, SL("configuration"), PH_NOISY_CC);
	if (Z_TYPE_P(config) != IS_OBJECT) {

		/* try_start_1: */

			ZEPHIR_CALL_METHOD(&config, this_ptr, "injectconfig", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_update_property_this(this_ptr, SL("configuration"), config TSRMLS_CC);

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_CPY_WRT(e, EG(exception));
			if (zephir_instance_of_ev(e, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				RETURN_MM_NULL();
			}
		}
	}
	RETURN_CCTOR(config);

}

/**
 * Injects a Config for the object when none is set.
 *
 * @return \Xpl\Collection\Config|null
 */
PHP_METHOD(Xpl_Configurable, injectConfig) {

	zval *reflection = NULL, *dirPath = NULL, *filePath = NULL, *config = NULL, *_0 = NULL, *_1 = NULL, *_2$$5, *_3$$5, *_4$$5, *_5$$6, *_6$$6, *_7$$6;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(reflection);
	object_init_ex(reflection, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, reflection, "__construct", NULL, 63, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, reflection, "getfilename", NULL, 88);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&dirPath, "dirname", NULL, 89, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(filePath);
	ZEPHIR_CONCAT_VS(filePath, dirPath, "/config/config.php");
	if (!((zephir_file_exists(filePath TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Could not locate object Config.", "xpl/configurable.zep", 62);
		return;
	}
	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_1);
	if (zephir_require_zval_ret(&_1, filePath TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CPY_WRT(config, _1);
	if (Z_TYPE_P(config) == IS_OBJECT) {
		if (!(zephir_instance_of_ev(config, xpl_collection_config_ce TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(_2$$5);
			object_init_ex(_2$$5, spl_ce_InvalidArgumentException);
			ZEPHIR_INIT_VAR(_3$$5);
			zephir_get_class(_3$$5, config, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_4$$5);
			ZEPHIR_CONCAT_SV(_4$$5, "Config must be instance of Xpl\\Config, given: ", _3$$5);
			ZEPHIR_CALL_METHOD(NULL, _2$$5, "__construct", NULL, 5, _4$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_2$$5, "xpl/configurable.zep", 69 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_VAR(_5$$6);
		object_init_ex(_5$$6, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(_6$$6);
		zephir_gettype(_6$$6, config TSRMLS_CC);
		ZEPHIR_INIT_VAR(_7$$6);
		ZEPHIR_CONCAT_SV(_7$$6, "Config must be instance of Xpl\\Config, given: ", _6$$6);
		ZEPHIR_CALL_METHOD(NULL, _5$$6, "__construct", NULL, 5, _7$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5$$6, "xpl/configurable.zep", 72 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(config);

}

