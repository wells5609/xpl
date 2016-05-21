
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Xpl_StringBuffer) {

	ZEPHIR_REGISTER_CLASS(Xpl, StringBuffer, xpl, stringbuffer, xpl_stringbuffer_method_entry, 0);

	/**
	 * The current string value
	 *
	 * @var string
	 */
	zend_declare_property_null(xpl_stringbuffer_ce, SL("value"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * The original string value
	 *
	 * @var string
	 */
	zend_declare_property_null(xpl_stringbuffer_ce, SL("original"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * The string's encoding
	 *
	 * @var string
	 */
	zend_declare_property_null(xpl_stringbuffer_ce, SL("encoding"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * HTML entities flags
	 *
	 * @var int
	 */
	zend_declare_property_long(xpl_stringbuffer_ce, SL("htmlEntFlags"), 2, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * Error mode. One of "ERROR_*" class constants
	 *
	 * @var int
	 */
	zend_declare_property_long(xpl_stringbuffer_ce, SL("errorMode"), 0, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_class_constant_long(xpl_stringbuffer_ce, SL("CASE_LOWER"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(xpl_stringbuffer_ce, SL("CASE_UPPER"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(xpl_stringbuffer_ce, SL("CASE_TITLE"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(xpl_stringbuffer_ce, SL("PAD_LEFT"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(xpl_stringbuffer_ce, SL("PAD_RIGHT"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(xpl_stringbuffer_ce, SL("PAD_BOTH"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(xpl_stringbuffer_ce, SL("ERROR_THROW"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(xpl_stringbuffer_ce, SL("ERROR_TRIGGER"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(xpl_stringbuffer_ce, SL("ERROR_IGNORE"), 2 TSRMLS_CC);

	zend_class_implements(xpl_stringbuffer_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

/**
 * Constructor
 *
 * @param string string
 */
PHP_METHOD(Xpl_StringBuffer, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *encoding = NULL, _0, *_1 = NULL;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &str_param, &encoding);

	zephir_get_strval(str, str_param);
	if (!encoding) {
		ZEPHIR_CPY_WRT(encoding, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(encoding);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "mbstring", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 16, &_0);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Missing mbstring extension", "xpl/stringbuffer.zep", 64);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, str);
	zephir_check_call_status();
	if (Z_TYPE_P(encoding) == IS_NULL) {
		ZEPHIR_CALL_FUNCTION(&encoding, "mb_detect_encoding", NULL, 138, str);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setencoding", NULL, 0, encoding);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the string length
 *
 * @return int
 */
PHP_METHOD(Xpl_StringBuffer, length) {

	zval *_0, *_1;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("encoding"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("mb_strlen", NULL, 156, _0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Alias of StringBuffer::length()
 */
PHP_METHOD(Xpl_StringBuffer, len) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "length", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Finds the position of the first occurance of the given substring
 *
 * @return int
 */
PHP_METHOD(Xpl_StringBuffer, pos) {

	int offset, ZEPHIR_LAST_CALL_STATUS;
	zval *needle_param = NULL, *offset_param = NULL, *_0, *_1, _2;
	zval *needle = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &needle_param, &offset_param);

	if (unlikely(Z_TYPE_P(needle_param) != IS_STRING && Z_TYPE_P(needle_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'needle' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(needle_param) == IS_STRING)) {
		zephir_get_strval(needle, needle_param);
	} else {
		ZEPHIR_INIT_VAR(needle);
		ZVAL_EMPTY_STRING(needle);
	}
	if (!offset_param) {
		offset = 0;
	} else {
		offset = zephir_get_intval(offset_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("encoding"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, offset);
	ZEPHIR_RETURN_CALL_FUNCTION("mb_strpos", NULL, 157, _0, needle, &_2, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Finds the position of the last occurance of the given substring
 *
 * @return int
 */
PHP_METHOD(Xpl_StringBuffer, rpos) {

	int offset, ZEPHIR_LAST_CALL_STATUS;
	zval *needle_param = NULL, *offset_param = NULL, *_0, *_1, _2;
	zval *needle = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &needle_param, &offset_param);

	if (unlikely(Z_TYPE_P(needle_param) != IS_STRING && Z_TYPE_P(needle_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'needle' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(needle_param) == IS_STRING)) {
		zephir_get_strval(needle, needle_param);
	} else {
		ZEPHIR_INIT_VAR(needle);
		ZVAL_EMPTY_STRING(needle);
	}
	if (!offset_param) {
		offset = 0;
	} else {
		offset = zephir_get_intval(offset_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("encoding"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, offset);
	ZEPHIR_RETURN_CALL_FUNCTION("mb_strrpos", NULL, 158, _0, needle, &_2, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Finds the position of the first occurance of the given substring case insensitively
 *
 * @return int
 */
PHP_METHOD(Xpl_StringBuffer, ipos) {

	int offset, ZEPHIR_LAST_CALL_STATUS;
	zval *needle_param = NULL, *offset_param = NULL, *_0, *_1, _2;
	zval *needle = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &needle_param, &offset_param);

	if (unlikely(Z_TYPE_P(needle_param) != IS_STRING && Z_TYPE_P(needle_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'needle' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(needle_param) == IS_STRING)) {
		zephir_get_strval(needle, needle_param);
	} else {
		ZEPHIR_INIT_VAR(needle);
		ZVAL_EMPTY_STRING(needle);
	}
	if (!offset_param) {
		offset = 0;
	} else {
		offset = zephir_get_intval(offset_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("encoding"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, offset);
	ZEPHIR_RETURN_CALL_FUNCTION("mb_stripos", NULL, 159, _0, needle, &_2, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Finds the position of the last occurance of the given substring case insensitively
 *
 * @return int
 */
PHP_METHOD(Xpl_StringBuffer, ripos) {

	int offset, ZEPHIR_LAST_CALL_STATUS;
	zval *needle_param = NULL, *offset_param = NULL, *_0, *_1, _2;
	zval *needle = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &needle_param, &offset_param);

	if (unlikely(Z_TYPE_P(needle_param) != IS_STRING && Z_TYPE_P(needle_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'needle' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(needle_param) == IS_STRING)) {
		zephir_get_strval(needle, needle_param);
	} else {
		ZEPHIR_INIT_VAR(needle);
		ZVAL_EMPTY_STRING(needle);
	}
	if (!offset_param) {
		offset = 0;
	} else {
		offset = zephir_get_intval(offset_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("encoding"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, offset);
	ZEPHIR_RETURN_CALL_FUNCTION("mb_strripos", NULL, 160, _0, needle, &_2, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Finds the last occurance of the given substring
 *
 * @param string needle
 * @param boolean part If set to TRUE, it returns the string from the beginning to the last occurrence of needle.
 * If set to FALSE, it returns the string from the last occurrence of needle to the end.
 * @return int
 */
PHP_METHOD(Xpl_StringBuffer, rchr) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool part;
	zval *needle_param = NULL, *part_param = NULL, *_0, *_1, _2;
	zval *needle = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &needle_param, &part_param);

	if (unlikely(Z_TYPE_P(needle_param) != IS_STRING && Z_TYPE_P(needle_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'needle' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(needle_param) == IS_STRING)) {
		zephir_get_strval(needle, needle_param);
	} else {
		ZEPHIR_INIT_VAR(needle);
		ZVAL_EMPTY_STRING(needle);
	}
	if (!part_param) {
		part = 0;
	} else {
		part = zephir_get_boolval(part_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("encoding"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_BOOL(&_2, (part ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("mb_strrchr", NULL, 161, _0, needle, &_2, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Whether the string starts with the given substring
 *
 * @return bool
 */
PHP_METHOD(Xpl_StringBuffer, startsWith) {

	zend_bool caseInsensitive;
	zval *str_param = NULL, *caseInsensitive_param = NULL, *_0, _1;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &str_param, &caseInsensitive_param);

	zephir_get_strval(str, str_param);
	if (!caseInsensitive_param) {
		caseInsensitive = 0;
	} else {
		caseInsensitive = zephir_get_boolval(caseInsensitive_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_BOOL(&_1, (caseInsensitive ? 1 : 0));
	RETURN_MM_BOOL(zephir_start_with(_0, str, &_1));

}

/**
 * Whether the string ends with the given substring
 *
 * @return bool
 */
PHP_METHOD(Xpl_StringBuffer, endsWith) {

	zend_bool caseInsensitive;
	zval *str_param = NULL, *caseInsensitive_param = NULL, *_0, _1;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &str_param, &caseInsensitive_param);

	zephir_get_strval(str, str_param);
	if (!caseInsensitive_param) {
		caseInsensitive = 0;
	} else {
		caseInsensitive = zephir_get_boolval(caseInsensitive_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_BOOL(&_1, (caseInsensitive ? 1 : 0));
	RETURN_MM_BOOL(zephir_end_with(_0, str, &_1));

}

/**
 * Returns the detected string encoding
 *
 * @return string
 */
PHP_METHOD(Xpl_StringBuffer, detectEncoding) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("mb_detect_encoding", NULL, 138, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Applies filter_var() to the string using the given filter type
 *
 * @return mixed
 */
PHP_METHOD(Xpl_StringBuffer, filter) {

	zval *filterType_param = NULL, *options_param = NULL, *_0, _1, _2;
	int filterType, options, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &filterType_param, &options_param);

	if (unlikely(Z_TYPE_P(filterType_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filterType' must be a int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	filterType = Z_LVAL_P(filterType_param);
	if (!options_param) {
		options = 0;
	} else {
	if (unlikely(Z_TYPE_P(options_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'options' must be a int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	options = Z_LVAL_P(options_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, filterType);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, options);
	ZEPHIR_RETURN_CALL_FUNCTION("filter_var", NULL, 136, _0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the current string value
 *
 * @return string
 */
PHP_METHOD(Xpl_StringBuffer, get) {

	

	RETURN_MEMBER(this_ptr, "value");

}

/**
 * Returns the original string value
 *
 * @return string
 */
PHP_METHOD(Xpl_StringBuffer, getOriginal) {

	

	RETURN_MEMBER(this_ptr, "original");

}

/**
 * Whether the value has been changed from the original value
 *
 * @return bool
 */
PHP_METHOD(Xpl_StringBuffer, isChanged) {

	zval *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("original"), PH_NOISY_CC);
	RETURN_BOOL(!ZEPHIR_IS_IDENTICAL(_0, _1));

}

/**
 * Returns the current string value
 *
 * @return string
 */
PHP_METHOD(Xpl_StringBuffer, __toString) {

	zval *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("value"), PH_NOISY_CC);
	zephir_get_strval(_1, _0);
	RETURN_CTOR(_1);

}

/**
 * Grabs a chunk of the string length characters in length starting at position
 *
 * @param int pos Position to start
 * @param int length [Optional] Character length of the chunk. Default 1.
 */
PHP_METHOD(Xpl_StringBuffer, chunk) {

	zval *position_param = NULL, *length_param = NULL, *_0, *_1, _2, _3;
	int position, length, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &position_param, &length_param);

	position = zephir_get_intval(position_param);
	if (!length_param) {
		length = 1;
	} else {
		length = zephir_get_intval(length_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("encoding"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, position);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, length);
	ZEPHIR_RETURN_CALL_FUNCTION("mb_substr", NULL, 162, _0, &_2, &_3, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the character at position (starting from 0)
 *
 * @param int pos
 * @return string
 */
PHP_METHOD(Xpl_StringBuffer, at) {

	zval *position_param = NULL, *_0, *_1, _2, _3;
	int position, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &position_param);

	position = zephir_get_intval(position_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("encoding"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, position);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 1);
	ZEPHIR_RETURN_CALL_FUNCTION("mb_substr", NULL, 162, _0, &_2, &_3, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the first length number of characters
 *
 * @param int length Number of characters to return. Default 1
 * @return string
 */
PHP_METHOD(Xpl_StringBuffer, first) {

	zval *length_param = NULL, *_0, *_1, _2, _3;
	int length, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &length_param);

	if (!length_param) {
		length = 1;
	} else {
		length = zephir_get_intval(length_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("encoding"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, length);
	ZEPHIR_RETURN_CALL_FUNCTION("mb_substr", NULL, 162, _0, &_2, &_3, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the last length number of characters
 *
 * @param int length Number of characters to return. Default 1
 * @return string
 */
PHP_METHOD(Xpl_StringBuffer, last) {

	zval *length_param = NULL, *_0, _1, *_2 = NULL, *_3;
	int length, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &length_param);

	if (!length_param) {
		length = 1;
	} else {
	if (unlikely(Z_TYPE_P(length_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'length' must be a int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	length = Z_LVAL_P(length_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, length);
	ZEPHIR_CALL_FUNCTION(&_2, "abs", NULL, 163, &_1);
	zephir_check_call_status();
	zephir_negate(_2 TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("encoding"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("mb_substr", NULL, 162, _0, _2, ZEPHIR_GLOBAL(global_null), _3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Splits the string into an array with each chunk being length in length.
 *
 * Unlike str_split(), this implementation will split by characters when dealing with a multi-byte string.
 *
 * @param int length Length of the array chunks. Default 1
 *
 * @return array
 */
PHP_METHOD(Xpl_StringBuffer, toArray) {

	zval *chars;
	zephir_fcall_cache_entry *_4 = NULL;
	zval *chunkSize_param = NULL, *fullString = NULL, *encoding = NULL, *character = NULL, *_0, *_1 = NULL, _2$$3 = zval_used_for_init, _3$$3 = zval_used_for_init;
	int chunkSize, ZEPHIR_LAST_CALL_STATUS, length = 0, i;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &chunkSize_param);

	if (!chunkSize_param) {
		chunkSize = 1;
	} else {
	if (unlikely(Z_TYPE_P(chunkSize_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'chunkSize' must be a int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	chunkSize = Z_LVAL_P(chunkSize_param);
	}


	ZEPHIR_INIT_VAR(chars);
	array_init(chars);
	i = 0;
	ZEPHIR_OBS_VAR(fullString);
	zephir_read_property_this(&fullString, this_ptr, SL("value"), PH_NOISY_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("encoding"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(encoding, _0);
	ZEPHIR_CALL_FUNCTION(&_1, "mb_strlen", NULL, 156, fullString, encoding);
	zephir_check_call_status();
	length = zephir_get_intval(_1);
	while (1) {
		if (!(i < length)) {
			break;
		}
		ZEPHIR_SINIT_NVAR(_2$$3);
		ZVAL_LONG(&_2$$3, i);
		ZEPHIR_SINIT_NVAR(_3$$3);
		ZVAL_LONG(&_3$$3, chunkSize);
		ZEPHIR_CALL_FUNCTION(&character, "mb_substr", &_4, 162, fullString, &_2$$3, &_3$$3, encoding);
		zephir_check_call_status();
		zephir_array_append(&chars, character, PH_SEPARATE, "xpl/stringbuffer.zep", 292);
		i += chunkSize;
	}
	RETURN_CTOR(chars);

}

/**
 * Split a multibyte string using regular expression pattern and returns the result as an array.
 *
 * @param string pattern Regex pattern
 * @param int limit [Optional] If specified, string will be split in limit elements as maximum.
 *
 * @return array
 */
PHP_METHOD(Xpl_StringBuffer, split) {

	int limit, ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *limit_param = NULL, *_0, _1;
	zval *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &limit_param);

	if (unlikely(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(pattern);
		ZVAL_EMPTY_STRING(pattern);
	}
	if (!limit_param) {
		limit = -1;
	} else {
		limit = zephir_get_intval(limit_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, limit);
	ZEPHIR_RETURN_CALL_FUNCTION("mb_split", NULL, 164, pattern, _0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the character at position p (alias of at())
 *
 * @param int offset
 * @return string
 */
PHP_METHOD(Xpl_StringBuffer, offsetGet) {

	zval *offset_param = NULL, *_0;
	int offset, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset_param);

	offset = zephir_get_intval(offset_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, offset);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "at", NULL, 0, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Whether there is a character at the given offset
 *
 * @param int offset
 * @return bool
 */
PHP_METHOD(Xpl_StringBuffer, offsetExists) {

	zval *offset_param = NULL, *_0 = NULL;
	int offset, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset_param);

	offset = zephir_get_intval(offset_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "length", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_GE_LONG(_0, offset));

}

/**
 * Throws an exception. Strings are immutable
 *
 * @throws \RuntimeException()
 */
PHP_METHOD(Xpl_StringBuffer, offsetSet) {

	zval *offset_param = NULL, *newval;
	int offset;

	zephir_fetch_params(0, 2, 0, &offset_param, &newval);

	offset = zephir_get_intval(offset_param);


	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_RuntimeException, "Cannot set character using ArrayAccess", "xpl/stringbuffer.zep", 340);
	return;

}

/**
 * Throws an exception. Strings are immutable
 *
 * @throws \RuntimeException()
 */
PHP_METHOD(Xpl_StringBuffer, offsetUnset) {

	zval *offset_param = NULL;
	int offset;

	zephir_fetch_params(0, 1, 0, &offset_param);

	offset = zephir_get_intval(offset_param);


	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_RuntimeException, "Cannot unset character using ArrayAccess", "xpl/stringbuffer.zep", 350);
	return;

}

/**
 * Magic property access for "length", "charset", "encoding", "first", and "last"
 */
PHP_METHOD(Xpl_StringBuffer, __get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *variable_param = NULL, *_0 = NULL, *_1, *_2$$4;
	zval *variable = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &variable_param);

	if (unlikely(Z_TYPE_P(variable_param) != IS_STRING && Z_TYPE_P(variable_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'variable' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(variable_param) == IS_STRING)) {
		zephir_get_strval(variable, variable_param);
	} else {
		ZEPHIR_INIT_VAR(variable);
		ZVAL_EMPTY_STRING(variable);
	}


	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtolower(_1, variable);
	do {
		if (ZEPHIR_IS_STRING(_1, "length")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "length", NULL, 0);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(_1, "charset")) {
			_2$$4 = zephir_fetch_nproperty_this(this_ptr, SL("encoding"), PH_NOISY_CC);
			ZEPHIR_RETURN_CALL_FUNCTION("mb_preferred_mime_name", NULL, 165, _2$$4);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(_1, "encoding")) {
			RETURN_MM_MEMBER(this_ptr, "encoding");
		}
		if (ZEPHIR_IS_STRING(_1, "first")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "first", NULL, 0);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(_1, "last")) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "last", NULL, 0);
			zephir_check_call_status();
			RETURN_MM();
		}
	} while(0);

	RETURN_MM_NULL();

}

/**
 * Allows print(), echo(), and return() methods
 */
PHP_METHOD(Xpl_StringBuffer, __call) {

	zval *args = NULL;
	zval *func_param = NULL, *args_param = NULL, *_0 = NULL, *_1, *_2$$3;
	zval *func = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &func_param, &args_param);

	if (unlikely(Z_TYPE_P(func_param) != IS_STRING && Z_TYPE_P(func_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'func' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(func_param) == IS_STRING)) {
		zephir_get_strval(func, func_param);
	} else {
		ZEPHIR_INIT_VAR(func);
		ZVAL_EMPTY_STRING(func);
	}
	args = args_param;


	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtolower(_1, func);
	do {
		if (ZEPHIR_IS_STRING(_1, "print") || ZEPHIR_IS_STRING(_1, "echo")) {
			_2$$3 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
			zend_print_zval(_2$$3, 0);
			break;
		}
		if (ZEPHIR_IS_STRING(_1, "return")) {
			RETURN_MM_MEMBER(this_ptr, "value");
		}
	} while(0);

	RETURN_MM_NULL();

}

/**
 * Sets a new string value
 *
 * @param string string
 * @return \Xpl\StringBuffer
 */
PHP_METHOD(Xpl_StringBuffer, set) {

	zval *str_param = NULL, *_0, *_1$$3;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	zephir_update_property_this(this_ptr, SL("value"), str TSRMLS_CC);
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("original"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("original"), _1$$3 TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Sets the string encoding
 *
 * @param string
 * @return \Xpl\StringBuffer
 */
PHP_METHOD(Xpl_StringBuffer, setEncoding) {

	zval *encoding_param = NULL;
	zval *encoding = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &encoding_param);

	zephir_get_strval(encoding, encoding_param);


	zephir_update_property_this(this_ptr, SL("encoding"), encoding TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Restores the string to its original value
 * @return \Xpl\StringBuffer
 */
PHP_METHOD(Xpl_StringBuffer, restore) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("original"), PH_NOISY_CC);
	zephir_update_property_this(this_ptr, SL("value"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Prepends a string to the string
 *
 * @param string string
 * @return \Xpl\StringBuffer
 */
PHP_METHOD(Xpl_StringBuffer, prepend) {

	zval *str_param = NULL, *_0, *_1;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VV(_1, str, _0);
	zephir_update_property_this(this_ptr, SL("value"), _1 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Appends a string to the string
 *
 * @param string string
 * @return \Xpl\StringBuffer
 */
PHP_METHOD(Xpl_StringBuffer, append) {

	zval *str_param = NULL;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	zephir_update_property_this(this_ptr, SL("value"), str TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Wraps the string between the two given
 *
 * @param string before String to prepend
 * @param string after String to append
 * @return \Xpl\StringBuffer
 */
PHP_METHOD(Xpl_StringBuffer, wrap) {

	zval *before_param = NULL, *after_param = NULL, *_0, *_1;
	zval *before = NULL, *after = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &before_param, &after_param);

	zephir_get_strval(before, before_param);
	zephir_get_strval(after, after_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VVV(_1, before, _0, after);
	zephir_update_property_this(this_ptr, SL("value"), _1 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Strips whitespace (or characters) from the beginning and end of the string
 *
 * @param string charlist [Optional]
 * @return \Xpl\StringBuffer
 */
PHP_METHOD(Xpl_StringBuffer, trim) {

	zval *charlist = NULL, *_0 = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &charlist);

	if (!charlist) {
		charlist = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	if (Z_TYPE_P(charlist) == IS_STRING) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_0);
		zephir_fast_trim(_0, _1, charlist, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	} else {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_0);
		zephir_fast_trim(_0, _2, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	}
	zephir_update_property_this(this_ptr, SL("value"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Strips whitespace (or characters) from the beginning of the string
 *
 * @param string charlist [Optional]
 * @return \Xpl\StringBuffer
 */
PHP_METHOD(Xpl_StringBuffer, ltrim) {

	zval *charlist = NULL, *_0 = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &charlist);

	if (!charlist) {
		charlist = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	if (Z_TYPE_P(charlist) == IS_STRING) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_0);
		zephir_fast_trim(_0, _1, charlist, ZEPHIR_TRIM_LEFT TSRMLS_CC);
	} else {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_0);
		zephir_fast_trim(_0, _2, NULL , ZEPHIR_TRIM_LEFT TSRMLS_CC);
	}
	zephir_update_property_this(this_ptr, SL("value"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Strips whitespace (or characters) from the end of the string
 *
 * @param string charlist [Optional]
 * @return \Xpl\StringBuffer
 */
PHP_METHOD(Xpl_StringBuffer, rtrim) {

	zval *charlist = NULL, *_0 = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &charlist);

	if (!charlist) {
		charlist = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	if (Z_TYPE_P(charlist) == IS_STRING) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_0);
		zephir_fast_trim(_0, _1, charlist, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	} else {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_0);
		zephir_fast_trim(_0, _2, NULL , ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	}
	zephir_update_property_this(this_ptr, SL("value"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Get part of the string
 *
 * @param int start Start position
 * @param int length [Optional] Length of the substring
 * @return \Xpl\StringBuffer
 */
PHP_METHOD(Xpl_StringBuffer, sub) {

	zval *start_param = NULL, *length = NULL, *_0, *_1, _2, *_3 = NULL;
	int start, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &start_param, &length);

	start = zephir_get_intval(start_param);
	if (!length) {
		length = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("encoding"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, start);
	ZEPHIR_CALL_FUNCTION(&_3, "mb_substr", NULL, 162, _0, &_2, length, _1);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("value"), _3 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * @return \Xpl\StringBuffer
 */
PHP_METHOD(Xpl_StringBuffer, str) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool before_needle;
	zval *needle_param = NULL, *before_needle_param = NULL, *_0, *_1, _2, *_3 = NULL;
	zval *needle = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &needle_param, &before_needle_param);

	zephir_get_strval(needle, needle_param);
	if (!before_needle_param) {
		before_needle = 0;
	} else {
		before_needle = zephir_get_boolval(before_needle_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("encoding"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_BOOL(&_2, (before_needle ? 1 : 0));
	ZEPHIR_CALL_FUNCTION(&_3, "mb_strstr", NULL, 166, _0, needle, &_2, _1);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("value"), _3 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * @return \Xpl\StringBuffer
 */
PHP_METHOD(Xpl_StringBuffer, replace) {

	zval *search, *replace, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &search, &replace);



	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	zephir_fast_str_replace(&_0, search, replace, _1 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("value"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * @return \Xpl\StringBuffer
 */
PHP_METHOD(Xpl_StringBuffer, ireplace) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *search, *replace, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &search, &replace);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "str_ireplace", NULL, 167, search, replace, _0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("value"), _1 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * @return \Xpl\StringBuffer
 */
PHP_METHOD(Xpl_StringBuffer, pad) {

	zval *str = NULL;
	zval *length_param = NULL, *str_param = NULL, *type_param = NULL, *_0, _1, _2, *_3 = NULL;
	int length, type, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &length_param, &str_param, &type_param);

	length = zephir_get_intval(length_param);
	if (!str_param) {
		ZEPHIR_INIT_VAR(str);
		ZVAL_STRING(str, " ", 1);
	} else {
		zephir_get_strval(str, str_param);
	}
	if (!type_param) {
		type = 1;
	} else {
		type = zephir_get_intval(type_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, length);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, type);
	ZEPHIR_CALL_FUNCTION(&_3, "str_pad", NULL, 168, _0, &_1, str, &_2);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("value"), _3 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * @return \Xpl\StringBuffer
 */
PHP_METHOD(Xpl_StringBuffer, sanitize) {

	zval *type_param = NULL, *options_param = NULL, *_0 = NULL, *_1, *_2;
	int type, options, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &type_param, &options_param);

	if (!type_param) {
		type = 0;
	} else {
		type = zephir_get_intval(type_param);
	}
	if (!options_param) {
		options = 0;
	} else {
		options = zephir_get_intval(options_param);
	}


	if (type == 0) {
		type = 513;
	}
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, type);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, options);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "filter", NULL, 0, _1, _2);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("value"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * @return \Xpl\StringBuffer
 */
PHP_METHOD(Xpl_StringBuffer, entities) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool double_encode;
	zval *charset = NULL;
	zval *flags = NULL, *charset_param = NULL, *double_encode_param = NULL, *_0, _1, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &flags, &charset_param, &double_encode_param);

	if (!flags) {
		ZEPHIR_CPY_WRT(flags, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(flags);
	}
	if (!charset_param) {
		ZEPHIR_INIT_VAR(charset);
		ZVAL_STRING(charset, "UTF-8", 1);
	} else {
		zephir_get_strval(charset, charset_param);
	}
	if (!double_encode_param) {
		double_encode = 0;
	} else {
		double_encode = zephir_get_boolval(double_encode_param);
	}


	if (Z_TYPE_P(flags) == IS_NULL) {
		ZEPHIR_OBS_NVAR(flags);
		zephir_read_static_property_ce(&flags, xpl_stringbuffer_ce, SL("htmlEntFlags") TSRMLS_CC);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_BOOL(&_1, (double_encode ? 1 : 0));
	ZEPHIR_CALL_FUNCTION(&_2, "htmlentities", NULL, 109, _0, flags, charset, &_1);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("value"), _2 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * @return \Xpl\StringBuffer
 */
PHP_METHOD(Xpl_StringBuffer, entityDecode) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *charset = NULL;
	zval *flags = NULL, *charset_param = NULL, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &flags, &charset_param);

	if (!flags) {
		ZEPHIR_CPY_WRT(flags, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(flags);
	}
	if (!charset_param) {
		ZEPHIR_INIT_VAR(charset);
		ZVAL_STRING(charset, "UTF-8", 1);
	} else {
		zephir_get_strval(charset, charset_param);
	}


	if (Z_TYPE_P(flags) == IS_NULL) {
		ZEPHIR_OBS_NVAR(flags);
		zephir_read_static_property_ce(&flags, xpl_stringbuffer_ce, SL("htmlEntFlags") TSRMLS_CC);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "html_entity_decode", NULL, 135, _0, flags, charset);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("value"), _1 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * @return \Xpl\StringBuffer
 */
PHP_METHOD(Xpl_StringBuffer, specialChars) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool double_encode;
	zval *charset = NULL;
	zval *flags = NULL, *charset_param = NULL, *double_encode_param = NULL, *_0, _1, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &flags, &charset_param, &double_encode_param);

	if (!flags) {
		ZEPHIR_CPY_WRT(flags, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(flags);
	}
	if (!charset_param) {
		ZEPHIR_INIT_VAR(charset);
		ZVAL_STRING(charset, "UTF-8", 1);
	} else {
		zephir_get_strval(charset, charset_param);
	}
	if (!double_encode_param) {
		double_encode = 0;
	} else {
		double_encode = zephir_get_boolval(double_encode_param);
	}


	if (Z_TYPE_P(flags) == IS_NULL) {
		ZEPHIR_OBS_NVAR(flags);
		zephir_read_static_property_ce(&flags, xpl_stringbuffer_ce, SL("htmlEntFlags") TSRMLS_CC);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_BOOL(&_1, (double_encode ? 1 : 0));
	ZEPHIR_CALL_FUNCTION(&_2, "htmlspecialchars", NULL, 169, _0, flags, charset, &_1);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("value"), _2 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * @return \Xpl\StringBuffer
 */
PHP_METHOD(Xpl_StringBuffer, specialCharsDecode) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *flags = NULL, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &flags);

	if (!flags) {
		ZEPHIR_CPY_WRT(flags, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(flags);
	}


	if (Z_TYPE_P(flags) == IS_NULL) {
		ZEPHIR_OBS_NVAR(flags);
		zephir_read_static_property_ce(&flags, xpl_stringbuffer_ce, SL("htmlEntFlags") TSRMLS_CC);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "htmlspecialchars_decode", NULL, 170, _0, flags);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("value"), _1 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Converts the string to another encoding
 *
 * @param string to_encoding The type of encoding that the string is being converted to
 * @return \Xpl\StringBuffer
 */
PHP_METHOD(Xpl_StringBuffer, convertEncoding) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *to_encoding_param = NULL, *_0, *_1, *_2 = NULL, *_3, *_4 = NULL;
	zval *to_encoding = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &to_encoding_param);

	zephir_get_strval(to_encoding, to_encoding_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("encoding"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_2, "mb_convert_encoding", NULL, 140, _0, to_encoding, _1);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("value"), _2 TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_4, "mb_detect_encoding", NULL, 138, _3);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("encoding"), _4 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Converts the string to the given case
 *
 * @param int mode One of CASE_LOWER, CASE_UPPER, or CASE_TITLE
 * @return \Xpl\StringBuffer
 */
PHP_METHOD(Xpl_StringBuffer, convertCase) {

	zval *mode_param = NULL, *_0, *_1, _2, *_3 = NULL;
	int mode, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &mode_param);

	mode = zephir_get_intval(mode_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("encoding"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, mode);
	ZEPHIR_CALL_FUNCTION(&_3, "mb_convert_case", NULL, 171, _0, &_2, _1);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("value"), _3 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Uppercases the string
 *
 * @return \Xpl\StringBuffer
 */
PHP_METHOD(Xpl_StringBuffer, upper) {

	zval *_0, *_1, *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("encoding"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_2, "mb_strtoupper", NULL, 172, _0, _1);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("value"), _2 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Lowercases the string
 *
 * @return \Xpl\StringBuffer
 */
PHP_METHOD(Xpl_StringBuffer, lower) {

	zval *_0, *_1, *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("encoding"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_2, "mb_strtolower", NULL, 173, _0, _1);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("value"), _2 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Applies ucwords() to the string
 *
 * @return \Xpl\StringBuffer
 */
PHP_METHOD(Xpl_StringBuffer, ucwords) {

	zval *_0, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "ucwords", NULL, 133, _0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("value"), _1 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Converts the first character to uppercase
 *
 * @return \Xpl\StringBuffer
 */
PHP_METHOD(Xpl_StringBuffer, ucfirst) {

	zval *encoding = NULL, *_0, *_1 = NULL, *_2 = NULL, _3, *_4 = NULL, *_5;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("encoding"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(encoding, _0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "first", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "mb_strtoupper", NULL, 172, _1, encoding);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 1);
	ZEPHIR_CALL_FUNCTION(&_4, "mb_substr", NULL, 162, _0, &_3, ZEPHIR_GLOBAL(global_null), encoding);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_VV(_5, _2, _4);
	zephir_update_property_this(this_ptr, SL("value"), _5 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Converts the first character to lowercase
 *
 * @return \Xpl\StringBuffer
 */
PHP_METHOD(Xpl_StringBuffer, lcfirst) {

	zval *encoding = NULL, *_0, *_1 = NULL, *_2 = NULL, _3, *_4 = NULL, *_5;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("encoding"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(encoding, _0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "first", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "mb_strtolower", NULL, 173, _1, encoding);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 1);
	ZEPHIR_CALL_FUNCTION(&_4, "mb_substr", NULL, 162, _0, &_3, ZEPHIR_GLOBAL(global_null), encoding);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_VV(_5, _2, _4);
	zephir_update_property_this(this_ptr, SL("value"), _5 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Applies md5() hash to the string
 *
 * @param bool raw_output [Optional]
 * @return \Xpl\StringBuffer
 */
PHP_METHOD(Xpl_StringBuffer, md5) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *raw_output_param = NULL, *_0, _1, *_2 = NULL;
	zend_bool raw_output;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &raw_output_param);

	if (!raw_output_param) {
		raw_output = 0;
	} else {
		raw_output = zephir_get_boolval(raw_output_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_BOOL(&_1, (raw_output ? 1 : 0));
	ZEPHIR_CALL_FUNCTION(&_2, "md5", NULL, 174, _0, &_1);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("value"), _2 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Applies sha1() hash to the string
 *
 * @param bool raw_output [Optional]
 * @return \Xpl\StringBuffer
 */
PHP_METHOD(Xpl_StringBuffer, sha1) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *raw_output_param = NULL, *_0, _1, *_2 = NULL;
	zend_bool raw_output;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &raw_output_param);

	if (!raw_output_param) {
		raw_output = 0;
	} else {
		raw_output = zephir_get_boolval(raw_output_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_BOOL(&_1, (raw_output ? 1 : 0));
	ZEPHIR_CALL_FUNCTION(&_2, "sha1", NULL, 119, _0, &_1);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("value"), _2 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Applies a given hash algorithm to the string
 *
 * @param string algo Hash algorithm
 * @param bool raw_output [Optional]
 * @return \Xpl\StringBuffer
 */
PHP_METHOD(Xpl_StringBuffer, hash) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool raw_output;
	zval *algo_param = NULL, *raw_output_param = NULL, *_0, _1, *_2 = NULL;
	zval *algo = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &algo_param, &raw_output_param);

	if (unlikely(Z_TYPE_P(algo_param) != IS_STRING && Z_TYPE_P(algo_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'algo' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(algo_param) == IS_STRING)) {
		zephir_get_strval(algo, algo_param);
	} else {
		ZEPHIR_INIT_VAR(algo);
		ZVAL_EMPTY_STRING(algo);
	}
	if (!raw_output_param) {
		raw_output = 0;
	} else {
		raw_output = zephir_get_boolval(raw_output_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_BOOL(&_1, (raw_output ? 1 : 0));
	ZEPHIR_CALL_FUNCTION(&_2, "hash", NULL, 175, algo, _0, &_1);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("value"), _2 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Applies a given HMAC hash to the string
 *
 * @param string algo Hash algorithm
 * @param string key HMAC key
 * @param bool raw_output [Optional]
 * @return \Xpl\StringBuffer
 */
PHP_METHOD(Xpl_StringBuffer, hashHmac) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool raw_output;
	zval *algo_param = NULL, *key_param = NULL, *raw_output_param = NULL, *_0, _1, *_2 = NULL;
	zval *algo = NULL, *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &algo_param, &key_param, &raw_output_param);

	if (unlikely(Z_TYPE_P(algo_param) != IS_STRING && Z_TYPE_P(algo_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'algo' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(algo_param) == IS_STRING)) {
		zephir_get_strval(algo, algo_param);
	} else {
		ZEPHIR_INIT_VAR(algo);
		ZVAL_EMPTY_STRING(algo);
	}
	zephir_get_strval(key, key_param);
	if (!raw_output_param) {
		raw_output = 0;
	} else {
		raw_output = zephir_get_boolval(raw_output_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_BOOL(&_1, (raw_output ? 1 : 0));
	ZEPHIR_CALL_FUNCTION(&_2, "hash_hmac", NULL, 176, algo, _0, key, &_1);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("value"), _2 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * @return bool
 */
PHP_METHOD(Xpl_StringBuffer, isAlnum) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("ctype_alnum", NULL, 107, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @return bool
 */
PHP_METHOD(Xpl_StringBuffer, isAlpha) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("ctype_alpha", NULL, 137, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @return bool
 */
PHP_METHOD(Xpl_StringBuffer, isUpper) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("ctype_upper", NULL, 177, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @return bool
 */
PHP_METHOD(Xpl_StringBuffer, isLower) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("ctype_lower", NULL, 178, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @return bool
 */
PHP_METHOD(Xpl_StringBuffer, isPrintable) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("ctype_print", NULL, 179, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @return bool
 */
PHP_METHOD(Xpl_StringBuffer, isControl) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("ctype_cntrl", NULL, 180, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @return bool
 */
PHP_METHOD(Xpl_StringBuffer, isDigit) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("ctype_digit", NULL, 181, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Whether the given string contains any of the characters in $charlist
 *
 * @param string charList
 *
 * @return boolean True if the string contains any of the characters in charList, otherwise false
 */
PHP_METHOD(Xpl_StringBuffer, containsChars) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *charList_param = NULL, *_0, *_1 = NULL, *_2 = NULL;
	zval *charList = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &charList_param);

	if (unlikely(Z_TYPE_P(charList_param) != IS_STRING && Z_TYPE_P(charList_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'charList' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(charList_param) == IS_STRING)) {
		zephir_get_strval(charList, charList_param);
	} else {
		ZEPHIR_INIT_VAR(charList);
		ZVAL_EMPTY_STRING(charList);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("value"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "strcspn", NULL, 46, _0, charList);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "length", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_IDENTICAL(_1, _2));

}

/**
 * Sets the HTML entities flags
 *
 * @param int flags
 */
PHP_METHOD(Xpl_StringBuffer, setHtmlEntitiesFlags) {

	zval *flags_param = NULL, *_0;
	int flags;

	zephir_fetch_params(0, 1, 0, &flags_param);

	flags = zephir_get_intval(flags_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, flags);
	zephir_update_static_property_ce(xpl_stringbuffer_ce, SL("htmlEntFlags"), &_0 TSRMLS_CC);

}

/**
 * Returns the HTML entities flags
 *
 * @return int
 */
PHP_METHOD(Xpl_StringBuffer, getHtmlEntitiesFlags) {

	zval *_0;


	_0 = zephir_fetch_static_property_ce(xpl_stringbuffer_ce, SL("htmlEntFlags") TSRMLS_CC);
	RETURN_CTORW(_0);

}

/**
 * Sets the error mode
 *
 * @param int mode One of "ERROR_*" class constants
 *
 * @throws \InvalidArgumentException if given an invalid error mode
 */
PHP_METHOD(Xpl_StringBuffer, setErrorMode) {

	zval *_6$$3;
	zval *_0;
	zval *mode_param = NULL, *_1 = NULL, _2, *_3 = NULL, *_7, *_4$$3, _5$$3;
	int mode, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &mode_param);

	mode = zephir_get_intval(mode_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 2);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 0);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, mode);
	ZEPHIR_CALL_FUNCTION(&_3, "in_array", NULL, 2, &_2, _0, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	if (!(zephir_is_true(_3))) {
		ZEPHIR_INIT_VAR(_4$$3);
		object_init_ex(_4$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_SINIT_VAR(_5$$3);
		ZVAL_LONG(&_5$$3, mode);
		ZEPHIR_INIT_VAR(_6$$3);
		ZEPHIR_CONCAT_SVS(_6$$3, "Invalid error mode: ", &_5$$3, ".");
		ZEPHIR_CALL_METHOD(NULL, _4$$3, "__construct", NULL, 5, _6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4$$3, "xpl/stringbuffer.zep", 859 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_ZVAL_NREF(_7);
	ZVAL_LONG(_7, mode);
	zephir_update_static_property_ce(xpl_stringbuffer_ce, SL("errorMode"), &_7 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Triggers an error, throws an exception, or does nothing, based on the current error mode
 *
 * @param string message Error message
 * @return null
 */
PHP_METHOD(Xpl_StringBuffer, error) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *_0, _1$$4, *_2$$5;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &message_param);

	if (!message_param) {
		ZEPHIR_INIT_VAR(message);
		ZVAL_STRING(message, "An error occurred", 1);
	} else {
		zephir_get_strval(message, message_param);
	}


	_0 = zephir_fetch_static_property_ce(xpl_stringbuffer_ce, SL("errorMode") TSRMLS_CC);
	do {
		if (ZEPHIR_IS_LONG(_0, 2)) {
			break;
		}
		if (ZEPHIR_IS_LONG(_0, 1)) {
			ZEPHIR_SINIT_VAR(_1$$4);
			ZVAL_LONG(&_1$$4, 512);
			ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 115, message, &_1$$4);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_INIT_VAR(_2$$5);
		object_init_ex(_2$$5, spl_ce_RuntimeException);
		ZEPHIR_CALL_METHOD(NULL, _2$$5, "__construct", NULL, 111, message);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$5, "xpl/stringbuffer.zep", 881 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	RETURN_MM_NULL();

}

