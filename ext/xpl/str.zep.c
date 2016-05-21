
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
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/concat.h"


/**
 * String utilities.
 */
ZEPHIR_INIT_CLASS(Xpl_Str) {

	ZEPHIR_REGISTER_CLASS(Xpl, Str, xpl, str, xpl_str_method_entry, 0);

	/**
	 * Last error string.
	 *
	 * @var string
	 */
	zend_declare_property_null(xpl_str_ce, SL("lastError"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_class_constant_string(xpl_str_ce, SL("NULL_STRING"), "" TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_class_constant_string(xpl_str_ce, SL("WHITESPACE"), " " TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Xpl_Str, ukey) {

	zval *obj, *params, *extra = NULL;

	zephir_fetch_params(0, 2, 1, &obj, &params, &extra);

	if (!extra) {
		extra = ZEPHIR_GLOBAL(global_null);
	}


	zephir_unique_key(return_value, obj, params TSRMLS_CC);
	return;

}

/**
 * Camelizes an underscored string to camelcase.
 *
 * @param string str
 * @return string
 */
PHP_METHOD(Xpl_Str, camelize) {

	zval *str_param = NULL;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	zephir_camelize(return_value, str);
	RETURN_MM();

}

/**
 * Uncamelizes a camelcase string to underscored.
 *
 * @param string str
 * @return string
 */
PHP_METHOD(Xpl_Str, uncamelize) {

	zval *str_param = NULL;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	zephir_uncamelize(return_value, str);
	RETURN_MM();

}

/**
 * Returns true if $haystack starts with $needle.
 *
 * @param string $haystack String to search within.
 * @param string $needle String to find.
 * @param boolean $case_insensitive Whether to check case-insensitive. Default true.
 * @return boolean
 */
PHP_METHOD(Xpl_Str, startsWith) {

	zend_bool case_insensitive;
	zval *haystack_param = NULL, *needle_param = NULL, *case_insensitive_param = NULL, _0;
	zval *haystack = NULL, *needle = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &haystack_param, &needle_param, &case_insensitive_param);

	zephir_get_strval(haystack, haystack_param);
	zephir_get_strval(needle, needle_param);
	if (!case_insensitive_param) {
		case_insensitive = 1;
	} else {
		case_insensitive = zephir_get_boolval(case_insensitive_param);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_BOOL(&_0, (case_insensitive ? 1 : 0));
	RETURN_MM_BOOL(zephir_start_with(haystack, needle, &_0));

}

/**
 * Returns true if $haystack ends with $needle.
 *
 * @param string $haystack String to search within.
 * @param string $needle String to find.
 * @param boolean $case_insensitive Whether to check case-insensitive. Default true.
 * @return boolean
 */
PHP_METHOD(Xpl_Str, endsWith) {

	zend_bool case_insensitive;
	zval *haystack_param = NULL, *needle_param = NULL, *case_insensitive_param = NULL, _0;
	zval *haystack = NULL, *needle = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &haystack_param, &needle_param, &case_insensitive_param);

	zephir_get_strval(haystack, haystack_param);
	zephir_get_strval(needle, needle_param);
	if (!case_insensitive_param) {
		case_insensitive = 1;
	} else {
		case_insensitive = zephir_get_boolval(case_insensitive_param);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_BOOL(&_0, (case_insensitive ? 1 : 0));
	RETURN_MM_BOOL(zephir_end_with(haystack, needle, &_0));

}

/**
 * Whether the given string contains any of the characters in $charlist
 *
 * @param string str
 * @param string charlist
 * @return boolean True if str contains any of the characters in charlist, otherwise false
 */
PHP_METHOD(Xpl_Str, hasChars) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *charlist_param = NULL, *_0 = NULL;
	zval *str = NULL, *charlist = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &str_param, &charlist_param);

	zephir_get_strval(str, str_param);
	zephir_get_strval(charlist, charlist_param);


	ZEPHIR_CALL_FUNCTION(&_0, "strcspn", NULL, 46, str, charlist);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_LONG_IDENTICAL(_0, zephir_fast_strlen_ev(str)));

}

/**
 * Converts a string to a PEAR-like class name. (e.g. "Http_Request2_Response")
 *
 * @param string
 * @return string
 */
PHP_METHOD(Xpl_Str, pearCase) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL;
	zval *str_param = NULL, *pearStr = NULL, *_0, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_5 = NULL, _6, _7, *_8;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "/[A-Z]/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, " $0", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_3, "preg_replace", &_4, 108, _1, _2, str);
	zephir_check_temp_parameter(_1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_fast_trim(_0, _3, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "/[^a-zA-Z0-9]/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, " ", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&pearStr, "preg_replace", &_4, 108, _1, _2, _0);
	zephir_check_temp_parameter(_1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZEPHIR_CALL_FUNCTION(&_5, "ucwords", NULL, 133, pearStr);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_STRING(&_6, " ", 0);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_STRING(&_7, "_", 0);
	zephir_fast_str_replace(&_1, &_6, &_7, _5 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "/[_]{2,}/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_STRING(_8, "_", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&pearStr, "preg_replace", &_4, 108, _2, _8, _1);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_8);
	zephir_check_call_status();
	RETURN_CCTOR(pearStr);

}

/**
 * Converts a string to "snake_case"
 *
 * @param string
 * @return string
 */
PHP_METHOD(Xpl_Str, snakeCase) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *_0 = NULL;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_CALL_SELF(&_0, "pearcase", NULL, 0, str);
	zephir_check_call_status();
	zephir_fast_strtolower(return_value, _0);
	RETURN_MM();

}

/**
 * Converts a string to "StudlyCaps"
 *
 * @param string
 * @return string
 */
PHP_METHOD(Xpl_Str, studlyCase) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *_0, *_1 = NULL, *_2, *_3 = NULL, *_4 = NULL, _5, _6;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "/[^a-zA-Z0-9]/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, " ", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_3, "preg_replace", NULL, 108, _1, _2, str);
	zephir_check_temp_parameter(_1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_fast_trim(_0, _3, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_4, "ucwords", NULL, 133, _0);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, " ", 0);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_STRING(&_6, "", 0);
	ZEPHIR_INIT_NVAR(_1);
	zephir_fast_str_replace(&_1, &_5, &_6, _4 TSRMLS_CC);
	RETURN_CCTOR(_1);

}

/**
 * Converts a string to "camelCase"
 *
 * @param string
 * @return string
 */
PHP_METHOD(Xpl_Str, camelCase) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *_0 = NULL;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_CALL_SELF(&_0, "studlycase", NULL, 0, str);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("lcfirst", NULL, 134, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sanitizes a string to contain only ASCII characters
 *
 * @param string $str
 * @return string
 */
PHP_METHOD(Xpl_Str, ascii) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, _0 = zval_used_for_init, _1 = zval_used_for_init, *_2 = NULL, *_3, *_4, *_5 = NULL;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 3);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "UTF-8", 0);
	ZEPHIR_CALL_FUNCTION(&_2, "html_entity_decode", NULL, 135, str, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "/[\\x01-\\x08\\x0B-\\x1F]/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_5, "preg_replace", NULL, 108, _3, _4, _2);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 513);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, (8 | 512));
	ZEPHIR_RETURN_CALL_FUNCTION("filter_var", NULL, 136, _5, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Strips non-alphabetic characters from a string.
 *
 * @param string
 * @return string
 */
PHP_METHOD(Xpl_Str, alpha) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *_0 = NULL, *_1 = NULL, *_2, *_3;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CALL_FUNCTION(&_1, "ctype_alpha", NULL, 137, str);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_CPY_WRT(_0, str);
	} else {
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "/[^a-zA-Z]/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_0, "preg_replace", NULL, 108, _2, _3, str);
		zephir_check_temp_parameter(_2);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
	}
	RETURN_CCTOR(_0);

}

/**
 * Strips non-alphanumeric characters from a string.
 *
 * @param string
 * @return string
 */
PHP_METHOD(Xpl_Str, alnum) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *_0 = NULL, *_1 = NULL, *_2, *_3;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CALL_FUNCTION(&_1, "ctype_alnum", NULL, 107, str);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_CPY_WRT(_0, str);
	} else {
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "/[^a-zA-Z0-9]/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_0, "preg_replace", NULL, 108, _2, _3, str);
		zephir_check_temp_parameter(_2);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
	}
	RETURN_CCTOR(_0);

}

/**
 * Strips invalid unicode from a string.
 *
 * @param string
 * @return string
 */
PHP_METHOD(Xpl_Str, unicode) {

	zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *encoding$$3 = NULL, *substituteCharacter$$4 = NULL, _0$$4 = zval_used_for_init, _1$$4 = zval_used_for_init, *_3$$4 = NULL, *_4, *_5, *_6 = NULL;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	if ((zephir_function_exists_ex(SS("mb_convert_encoding") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_FUNCTION(&encoding$$3, "mb_detect_encoding", NULL, 138, str);
		zephir_check_call_status();
		if (!ZEPHIR_IS_STRING_IDENTICAL(encoding$$3, "ASCII")) {
			ZEPHIR_SINIT_VAR(_0$$4);
			ZVAL_STRING(&_0$$4, "mbstring.substitute_character", 0);
			ZEPHIR_SINIT_VAR(_1$$4);
			ZVAL_STRING(&_1$$4, "none", 0);
			ZEPHIR_CALL_FUNCTION(&substituteCharacter$$4, "ini_set", &_2, 139, &_0$$4, &_1$$4);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_0$$4);
			ZVAL_STRING(&_0$$4, "UTF-8", 0);
			ZEPHIR_SINIT_NVAR(_1$$4);
			ZVAL_STRING(&_1$$4, "UTF-8", 0);
			ZEPHIR_CALL_FUNCTION(&_3$$4, "mb_convert_encoding", NULL, 140, str, &_0$$4, &_1$$4);
			zephir_check_call_status();
			zephir_get_strval(str, _3$$4);
			ZEPHIR_SINIT_NVAR(_0$$4);
			ZVAL_STRING(&_0$$4, "mbstring.substitute_character", 0);
			ZEPHIR_CALL_FUNCTION(NULL, "ini_set", &_2, 139, &_0$$4, substituteCharacter$$4);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "/\\\\u([0-9a-f]{4})/i", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_STRING(_5, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_6, "preg_replace", NULL, 108, _4, _5, str);
	zephir_check_temp_parameter(_4);
	zephir_check_temp_parameter(_5);
	zephir_check_call_status();
	zephir_stripcslashes(return_value, _6 TSRMLS_CC);
	RETURN_MM();

}

/**
 * Sanitizes a string to a "slug" format: lowercase alphanumeric string with given separator.
 *
 * @param string $string Dirty string.
 * @param string $separator [Optional] Character used to replace non-alphanumeric characters. Default "-".
 * @return string Slugified string.
 */
PHP_METHOD(Xpl_Str, slug) {

	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *separator_param = NULL, *slug = NULL, *_0 = NULL, *_1 = NULL, *_2, *_4 = NULL;
	zval *str = NULL, *separator = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &str_param, &separator_param);

	zephir_get_strval(str, str_param);
	if (!separator_param) {
		ZEPHIR_INIT_VAR(separator);
		ZVAL_STRING(separator, "-", 1);
	} else {
		zephir_get_strval(separator, separator_param);
	}


	ZEPHIR_CALL_SELF(&_0, "ascii", NULL, 0, str);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "#[\"\\'\\’\\x01-\\x08\\x0B-\\x1F]#", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&slug, "preg_replace", &_3, 108, _1, _2, _0);
	zephir_check_temp_parameter(_1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "#[^a-z0-9]#i", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_4, "preg_replace", &_3, 108, _1, separator, slug);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "#[/_|+ -]+#u", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&slug, "preg_replace", &_3, 108, _1, separator, _4);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	zephir_fast_trim(_1, slug, separator, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	zephir_fast_strtolower(return_value, _1);
	RETURN_MM();

}

/**
 * Removes single and double quotes from a string.
 *
 * @param string
 * @return string
 */
PHP_METHOD(Xpl_Str, stripQuotes) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *_0, *_1;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "/[\"\\'\\’]/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", NULL, 108, _0, _1, str);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Removes non-printing ASCII control characters from a string.
 *
 * @param string
 * @return string
 */
PHP_METHOD(Xpl_Str, stripControl) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *_0, *_1;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "/[\\x01-\\x08\\x0B-\\x1F]/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", NULL, 108, _0, _1, str);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Escapes text for SQL LIKE special characters % and _.
 *
 * @param string $text The text to be escaped.
 * @return string text, safe for inclusion in LIKE query.
 */
PHP_METHOD(Xpl_Str, filterSqlLike) {

	zval *_0, *_2;
	zval *str_param = NULL, *_1 = NULL;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "%", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "_", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "\\\\%", 1);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "\\\\_", 1);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_INIT_NVAR(_1);
	zephir_fast_str_replace(&_1, _0, _2, str TSRMLS_CC);
	RETURN_CCTOR(_1);

}

/**
 * Sanitizes a URL, decoding using rawurldecode() and filter_var().
 *
 * @param string url URL, possibly containing encoded characters
 * @param int flags [Optional] Optional filter_var() flags
 * @return string Sanitized URL with "%##" characters translated
 */
PHP_METHOD(Xpl_Str, filterUrl) {

	int flags, ZEPHIR_LAST_CALL_STATUS;
	zval *url_param = NULL, *flags_param = NULL, *_0 = NULL, _1, _2;
	zval *url = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &url_param, &flags_param);

	zephir_get_strval(url, url_param);
	if (!flags_param) {
		flags = 0;
	} else {
		flags = zephir_get_intval(flags_param);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "rawurldecode", NULL, 141, url);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 518);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, flags);
	ZEPHIR_RETURN_CALL_FUNCTION("filter_var", NULL, 136, _0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns whether the given variable is a valid JSON string.
 *
 * @param string
 * @return boolean
 */
PHP_METHOD(Xpl_Str, isJson) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *str_param = NULL;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_RETURN_CALL_CE_STATIC(xpl_json_ce, "validate", &_0, 142, str);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Checks whether the given value is a valid XML string.
 *
 * @param string $arg Value to check if XML.
 * @return boolean TRUE if value is a valid XML string, otherwise false.
 */
PHP_METHOD(Xpl_Str, isXml) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *str_param = NULL;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_RETURN_CALL_CE_STATIC(xpl_xml_ce, "validate", &_0, 143, str);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Checks whether the given value is a valid serialized string.
 *
 * @param string $data Value to check if serialized
 * @return boolean TRUE If value is a valid serialized string, otherwise false.
 */
PHP_METHOD(Xpl_Str, isSerialized) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, _0, *_1;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	if (ZEPHIR_IS_STRING_IDENTICAL(str, "")) {
		RETURN_MM_BOOL(0);
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(str, "N;")) {
		RETURN_MM_BOOL(1);
	}
	zephir_update_static_property_ce(xpl_str_ce, SL("lastError"), &ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "Xpl\\Str::handleError", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 144, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "unserialize", NULL, 4, str);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", NULL, 145);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_1);
	zephir_read_static_property_ce(&_1, xpl_str_ce, SL("lastError") TSRMLS_CC);
	if (Z_TYPE_P(_1) == IS_NULL) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Formats a string by injecting non-numeric characters into
 * the string in the positions they appear in the template.
 *
 * @param string $string The string to format
 * @param string $template String format to apply
 * @return string Formatted string.
 */
PHP_METHOD(Xpl_Str, format) {

	int ZEPHIR_LAST_CALL_STATUS, fpos, spos;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *str_param = NULL, *template_param = NULL, *chr = NULL, *len = NULL, _0$$3 = zval_used_for_init, _1$$3 = zval_used_for_init, *_2$$3 = NULL, _4$$5 = zval_used_for_init, _5$$5 = zval_used_for_init, *_6$$5 = NULL;
	zval *str = NULL, *template = NULL, *result;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &str_param, &template_param);

	zephir_get_strval(str, str_param);
	zephir_get_strval(template, template_param);


	ZEPHIR_INIT_VAR(result);
	ZVAL_EMPTY_STRING(result);
	fpos = 0;
	spos = 0;
	ZEPHIR_INIT_VAR(len);
	ZVAL_LONG(len, (zephir_fast_strlen_ev(template) - 1));
	while (1) {
		if (!(ZEPHIR_GE_LONG(len, fpos))) {
			break;
		}
		ZEPHIR_SINIT_NVAR(_0$$3);
		ZVAL_LONG(&_0$$3, fpos);
		ZEPHIR_SINIT_NVAR(_1$$3);
		ZVAL_LONG(&_1$$3, 1);
		ZEPHIR_INIT_NVAR(chr);
		zephir_substr(chr, template, zephir_get_intval(&_0$$3), 1 , 0);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "ctype_alnum", &_3, 107, chr);
		zephir_check_call_status();
		if (!(zephir_is_true(_2$$3))) {
			zephir_concat_self(&result, chr TSRMLS_CC);
		} else {
			ZEPHIR_SINIT_NVAR(_4$$5);
			ZVAL_LONG(&_4$$5, spos);
			ZEPHIR_SINIT_NVAR(_5$$5);
			ZVAL_LONG(&_5$$5, 1);
			ZEPHIR_INIT_NVAR(_6$$5);
			zephir_substr(_6$$5, str, zephir_get_intval(&_4$$5), 1 , 0);
			zephir_concat_self(&result, _6$$5 TSRMLS_CC);
			spos++;
		}
		fpos++;
	}
	RETURN_CTOR(result);

}

/**
 * Returns 1st occurance of text between two strings.
 *
 * The "between" strings are not included in output.
 *
 * @param string $string The string in which to search.
 * @param string $substr_start The starting string.
 * @param string $substr_end The ending string.
 * @return string Text between $start and $end.
 */
PHP_METHOD(Xpl_Str, between) {

	zval *str_param = NULL, *substr_start_param = NULL, *substr_end_param = NULL, *str1 = NULL, *substr1 = NULL, *str2 = NULL, *_0;
	zval *str = NULL, *substr_start = NULL, *substr_end = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &str_param, &substr_start_param, &substr_end_param);

	if (unlikely(Z_TYPE_P(str_param) != IS_STRING && Z_TYPE_P(str_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'str' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(str_param) == IS_STRING)) {
		zephir_get_strval(str, str_param);
	} else {
		ZEPHIR_INIT_VAR(str);
		ZVAL_EMPTY_STRING(str);
	}
	if (unlikely(Z_TYPE_P(substr_start_param) != IS_STRING && Z_TYPE_P(substr_start_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'substr_start' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(substr_start_param) == IS_STRING)) {
		zephir_get_strval(substr_start, substr_start_param);
	} else {
		ZEPHIR_INIT_VAR(substr_start);
		ZVAL_EMPTY_STRING(substr_start);
	}
	if (unlikely(Z_TYPE_P(substr_end_param) != IS_STRING && Z_TYPE_P(substr_end_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'substr_end' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(substr_end_param) == IS_STRING)) {
		zephir_get_strval(substr_end, substr_end_param);
	} else {
		ZEPHIR_INIT_VAR(substr_end);
		ZVAL_EMPTY_STRING(substr_end);
	}


	ZEPHIR_INIT_VAR(str1);
	zephir_fast_explode(str1, substr_start, str, LONG_MAX TSRMLS_CC);
	ZEPHIR_OBS_VAR(substr1);
	if (!(zephir_array_isset_long_fetch(&substr1, str1, 1, 0 TSRMLS_CC))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(str2);
	zephir_fast_explode(str2, substr_end, substr1, LONG_MAX TSRMLS_CC);
	zephir_array_fetch_long(&_0, str2, 0, PH_NOISY | PH_READONLY, "xpl/str.zep", 374 TSRMLS_CC);
	zephir_fast_trim(return_value, _0, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	RETURN_MM();

}

/**
 * Get a given number of sentences from a string.
 *
 * @param string $text The full string of sentences.
 * @param int $num Number of sentences to return. Default 1.
 * @param boolean|array $strip_abbr Whether to strip abbreviations (they break the function).
 * Pass an array to account for those abbreviations as well.
 * @return string Given number of sentences.
 */
PHP_METHOD(Xpl_Str, sentences) {

	HashTable *_2$$4;
	HashPosition _1$$4;
	int num, ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *num_param = NULL, *strip_abbr = NULL, *replacements = NULL, *strip = NULL, *replace_keys = NULL, *replace_vals = NULL, *matches = NULL, *_0 = NULL, *_9, _10, *_12, *_13, **_3$$4, *_4$$5 = NULL, _5$$5 = zval_used_for_init, _6$$5 = zval_used_for_init, *_7$$5 = NULL, *_8$$3;
	zval *str = NULL, *_11;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &str_param, &num_param, &strip_abbr);

	zephir_get_strval(str, str_param);
	if (!num_param) {
		num = 1;
	} else {
		num = zephir_get_intval(num_param);
	}
	if (!strip_abbr) {
		strip_abbr = ZEPHIR_GLOBAL(global_false);
	}


	ZEPHIR_INIT_VAR(replace_keys);
	array_init(replace_keys);
	ZEPHIR_INIT_VAR(replace_vals);
	array_init(replace_vals);
	ZEPHIR_INIT_VAR(matches);
	array_init(matches);
	ZEPHIR_CALL_FUNCTION(&_0, "strip_tags", NULL, 146, str);
	zephir_check_call_status();
	zephir_get_strval(str, _0);
	if (zephir_is_true(strip_abbr)) {
		ZEPHIR_INIT_VAR(replacements);
		zephir_create_array(replacements, 7, 0 TSRMLS_CC);
		add_assoc_stringl_ex(replacements, SS("Dr."), SL("<Dr>"), 1);
		add_assoc_stringl_ex(replacements, SS("Mrs."), SL("<Mrs>"), 1);
		add_assoc_stringl_ex(replacements, SS("Mr."), SL("<Mr>"), 1);
		add_assoc_stringl_ex(replacements, SS("Ms."), SL("<Ms>"), 1);
		add_assoc_stringl_ex(replacements, SS("Co."), SL("<Co>"), 1);
		add_assoc_stringl_ex(replacements, SS("Ltd."), SL("<Ltd>"), 1);
		add_assoc_stringl_ex(replacements, SS("Inc."), SL("<Inc>"), 1);
		if (Z_TYPE_P(strip_abbr) == IS_ARRAY) {
			zephir_is_iterable(strip_abbr, &_2$$4, &_1$$4, 0, 0, "xpl/str.zep", 412);
			for (
			  ; zephir_hash_get_current_data_ex(_2$$4, (void**) &_3$$4, &_1$$4) == SUCCESS
			  ; zephir_hash_move_forward_ex(_2$$4, &_1$$4)
			) {
				ZEPHIR_GET_HVALUE(strip, _3$$4);
				ZEPHIR_INIT_NVAR(_4$$5);
				ZEPHIR_SINIT_NVAR(_5$$5);
				ZVAL_STRING(&_5$$5, ".", 0);
				ZEPHIR_SINIT_NVAR(_6$$5);
				ZVAL_STRING(&_6$$5, "", 0);
				zephir_fast_str_replace(&_4$$5, &_5$$5, &_6$$5, strip TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_7$$5);
				ZEPHIR_CONCAT_SVS(_7$$5, "<", _4$$5, ">");
				zephir_array_update_zval(&replacements, strip, &_7$$5, PH_COPY | PH_SEPARATE);
			}
		}
		ZEPHIR_INIT_NVAR(replace_keys);
		zephir_array_keys(replace_keys, replacements TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&replace_vals, "array_values", NULL, 68, replacements);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_8$$3);
		zephir_fast_str_replace(&_8$$3, replace_keys, replace_vals, str TSRMLS_CC);
		zephir_get_strval(str, _8$$3);
	}
	ZEPHIR_INIT_VAR(_9);
	ZEPHIR_SINIT_VAR(_10);
	ZVAL_LONG(&_10, num);
	ZEPHIR_INIT_VAR(_11);
	ZEPHIR_CONCAT_SVS(_11, "/^([^.!?]*[\\.!?]+){0,", &_10, "}/");
	zephir_preg_match(_9, _11, str, matches, 0, 0 , 0  TSRMLS_CC);
	if (!(zephir_is_true(_9))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(_12);
	if (zephir_is_true(strip_abbr)) {
		zephir_array_fetch_long(&_13, matches, 0, PH_NOISY | PH_READONLY, "xpl/str.zep", 427 TSRMLS_CC);
		zephir_fast_str_replace(&_12, replace_vals, replace_keys, _13 TSRMLS_CC);
	} else {
		zephir_array_fetch_long(&_12, matches, 0, PH_NOISY, "xpl/str.zep", 427 TSRMLS_CC);
	}
	RETURN_CCTOR(_12);

}

/**
 * Class error handler
 *
 * @param int errorNum
 * @param string errorMsg
 */
PHP_METHOD(Xpl_Str, handleError) {

	zval *errorMsg = NULL, *_1;
	zval *errorNum_param = NULL, *errorMsg_param = NULL, _0;
	int errorNum;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &errorNum_param, &errorMsg_param);

	errorNum = zephir_get_intval(errorNum_param);
	zephir_get_strval(errorMsg, errorMsg_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, errorNum);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VSV(_1, &_0, ": ", errorMsg);
	zephir_update_static_property_ce(xpl_str_ce, SL("lastError"), &_1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

