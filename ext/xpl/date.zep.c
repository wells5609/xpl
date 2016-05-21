
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
#include "ext/date/php_date.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/time.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Xpl_Date) {

	ZEPHIR_REGISTER_CLASS(Xpl, Date, xpl, date, xpl_date_method_entry, 0);

	zend_declare_class_constant_long(xpl_date_ce, SL("MINUTE"), 60 TSRMLS_CC);

	zend_declare_class_constant_long(xpl_date_ce, SL("HOUR"), 3600 TSRMLS_CC);

	zend_declare_class_constant_long(xpl_date_ce, SL("DAY"), 86400 TSRMLS_CC);

	zend_declare_class_constant_long(xpl_date_ce, SL("WEEK"), 604800 TSRMLS_CC);

	zend_declare_class_constant_long(xpl_date_ce, SL("MONTH"), 2592000 TSRMLS_CC);

	zend_declare_class_constant_long(xpl_date_ce, SL("YEAR"), 31536000 TSRMLS_CC);

	zend_declare_class_constant_string(xpl_date_ce, SL("FORMAT_HUMAN"), "d M Y H:i" TSRMLS_CC);

	zend_declare_class_constant_string(xpl_date_ce, SL("FORMAT_SQL"), "Y-m-d H:i:s" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Xpl_Date, isValid) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *dateTime, *time = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dateTime);



	if (zephir_instance_of_ev(dateTime, php_date_get_date_ce() TSRMLS_CC)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_FUNCTION(&time, "strtotime", NULL, 96, dateTime);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_GT_LONG(time, 0));

}

PHP_METHOD(Xpl_Date, time) {

	int ZEPHIR_LAST_CALL_STATUS, _1$$5;
	zval *time = NULL, *_0$$4, *_2$$6 = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &time);

	if (!time) {
		ZEPHIR_CPY_WRT(time, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(time);
	}


	if (Z_TYPE_P(time) == IS_NULL) {
		zephir_time(return_value);
		RETURN_MM();
	}
	if (zephir_instance_of_ev(time, php_date_get_date_ce() TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_0$$4);
		ZVAL_STRING(_0$$4, "U", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_RETURN_CALL_METHOD(time, "format", NULL, 0, _0$$4);
		zephir_check_temp_parameter(_0$$4);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (zephir_is_numeric(time)) {
		_1$$5 = zephir_get_intval(time);
		ZEPHIR_INIT_NVAR(time);
		ZVAL_LONG(time, _1$$5);
	} else {
		ZEPHIR_CALL_FUNCTION(&_2$$6, "strtotime", NULL, 96, time);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(time, _2$$6);
	}
	ZEPHIR_INIT_VAR(_3);
	if (zephir_is_true(time)) {
		ZEPHIR_CPY_WRT(_3, time);
	} else {
		ZVAL_LONG(_3, 0);
	}
	RETURN_CCTOR(_3);

}

PHP_METHOD(Xpl_Date, make) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *time = NULL, *timezone = NULL, *dateObject = NULL, *_0 = NULL, *_4, *_1$$5, *_2$$5, *_3$$5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &time, &timezone);

	if (!time) {
		time = ZEPHIR_GLOBAL(global_null);
	}
	if (!timezone) {
		ZEPHIR_CPY_WRT(timezone, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(timezone);
	}


	ZEPHIR_CALL_SELF(&_0, "timezone", NULL, 0, timezone);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(timezone, _0);
	if (Z_TYPE_P(time) == IS_OBJECT) {
		if (zephir_instance_of_ev(time, php_date_get_date_ce() TSRMLS_CC)) {
			ZEPHIR_RETURN_CALL_METHOD(time, "settimezone", NULL, 0, timezone);
			zephir_check_call_status();
			RETURN_MM();
		} else {
			ZEPHIR_INIT_VAR(_1$$5);
			object_init_ex(_1$$5, spl_ce_InvalidArgumentException);
			ZEPHIR_INIT_VAR(_2$$5);
			zephir_get_class(_2$$5, time, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_3$$5);
			ZEPHIR_CONCAT_SV(_3$$5, "Object argument must be DateTime, given: ", _2$$5);
			ZEPHIR_CALL_METHOD(NULL, _1$$5, "__construct", NULL, 5, _3$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_1$$5, "xpl/date.zep", 62 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(dateObject);
	object_init_ex(dateObject, php_date_get_date_ce());
	ZEPHIR_CALL_SELF(&_0, "time", NULL, 0, time);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SV(_4, "@", _0);
	ZEPHIR_CALL_METHOD(NULL, dateObject, "__construct", NULL, 0, _4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, dateObject, "settimezone", NULL, 0, timezone);
	zephir_check_call_status();
	RETURN_CCTOR(dateObject);

}

PHP_METHOD(Xpl_Date, timezone) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *timezone = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &timezone);

	if (!timezone) {
		ZEPHIR_CPY_WRT(timezone, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(timezone);
	}


	if (Z_TYPE_P(timezone) == IS_NULL) {
		ZEPHIR_CALL_FUNCTION(&timezone, "date_default_timezone_get", NULL, 97);
		zephir_check_call_status();
	} else {
		if (zephir_instance_of_ev(timezone, php_date_get_timezone_ce() TSRMLS_CC)) {
			RETVAL_ZVAL(timezone, 1, 0);
			RETURN_MM();
		}
	}
	object_init_ex(return_value, php_date_get_timezone_ce());
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, timezone);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Xpl_Date, format) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *format = NULL;
	zval *dateTime, *format_param = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &dateTime, &format_param);

	zephir_get_strval(format, format_param);


	ZEPHIR_CALL_SELF(&_0, "make", NULL, 0, dateTime);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_0, "format", NULL, 0, format);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Xpl_Date, formatHuman) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *dateTime, *format = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &dateTime, &format);

	if (!format) {
		ZEPHIR_CPY_WRT(format, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(format);
	}


	if (Z_TYPE_P(format) == IS_NULL) {
		ZEPHIR_INIT_NVAR(format);
		ZVAL_STRING(format, "d M Y H:i", 1);
	}
	ZEPHIR_CALL_SELF(&_0, "make", NULL, 0, dateTime);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_0, "format", NULL, 0, format);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Xpl_Date, formatSql) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *dateTime, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dateTime);



	ZEPHIR_CALL_SELF(&_0, "make", NULL, 0, dateTime);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "Y-m-d H:i:s", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(_0, "format", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

