
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


ZEPHIR_INIT_CLASS(Xpl_Money_Format) {

	ZEPHIR_REGISTER_CLASS(Xpl\\Money, Format, xpl, money_format, xpl_money_format_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(xpl_money_format_ce, SL("decimalPoint"), ".", ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_string(xpl_money_format_ce, SL("thousandsSep"), ",", ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(xpl_money_format_ce, SL("intlCurrSymbol"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(xpl_money_format_ce, SL("currencySymbol"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(xpl_money_format_ce, SL("monDecimalPoint"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(xpl_money_format_ce, SL("monThousandsSep"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_string(xpl_money_format_ce, SL("positiveSign"), "", ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_string(xpl_money_format_ce, SL("negativeSign"), "-", ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * @var int
	 */
	zend_declare_property_null(xpl_money_format_ce, SL("intlFracDigits"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * @var int
	 */
	zend_declare_property_null(xpl_money_format_ce, SL("fracDigits"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(xpl_money_format_ce, SL("grouping"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(xpl_money_format_ce, SL("monGrouping"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Xpl_Money_Format, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *localeConv = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &localeConv);

	if (!localeConv) {
		ZEPHIR_CPY_WRT(localeConv, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(localeConv);
	}


	if (Z_TYPE_P(localeConv) != IS_ARRAY) {
		ZEPHIR_CALL_FUNCTION(&localeConv, "localeconv", NULL, 74);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

