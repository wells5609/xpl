
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
#include "kernel/object.h"
#include "kernel/hash.h"
#include "kernel/file.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Xpl_Csv) {

	ZEPHIR_REGISTER_CLASS(Xpl, Csv, xpl, csv, xpl_csv_method_entry, 0);

	zend_declare_property_string(xpl_csv_ce, SL("delimiter"), ",", ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(xpl_csv_ce, SL("enclosure"), "\"", ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(xpl_csv_ce, SL("escape_char"), "\\", ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Xpl_Csv, encode) {

	HashTable *_4;
	HashPosition _3;
	zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *headers_param = NULL, *handle = NULL, *row = NULL, *delimiter = NULL, *enclosure = NULL, *escape = NULL, *contents = NULL, _0, _1, *_2 = NULL, **_5, *_6$$3 = NULL;
	zval *data = NULL, *headers = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data_param, &headers_param);

	data = data_param;
	if (!headers_param) {
		ZEPHIR_INIT_VAR(headers);
		array_init(headers);
	} else {
		zephir_get_arrval(headers, headers_param);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "php://temp", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "w+b", 0);
	ZEPHIR_CALL_FUNCTION(&handle, "fopen", NULL, 90, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_2);
	zephir_read_static_property_ce(&_2, xpl_csv_ce, SL("delimiter") TSRMLS_CC);
	ZEPHIR_CPY_WRT(delimiter, _2);
	ZEPHIR_OBS_NVAR(_2);
	zephir_read_static_property_ce(&_2, xpl_csv_ce, SL("enclosure") TSRMLS_CC);
	ZEPHIR_CPY_WRT(enclosure, _2);
	ZEPHIR_OBS_VAR(escape);
	zephir_read_static_property_ce(&escape, xpl_csv_ce, SL("escape_char") TSRMLS_CC);
	zephir_is_iterable(data, &_4, &_3, 0, 0, "xpl/csv.zep", 26);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(row, _5);
		ZEPHIR_CALL_CE_STATIC(&_6$$3, xpl_type_ce, "toarray", &_7, 0, row);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "fputcsv", &_8, 91, handle, _6$$3, delimiter, enclosure, escape);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(NULL, "rewind", NULL, 92, handle);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&contents, "stream_get_contents", NULL, 93, handle);
	zephir_check_call_status();
	zephir_fclose(handle TSRMLS_CC);
	RETURN_CCTOR(contents);

}

/**
 * Returns an array or object of items from a CSV string.
 *
 * The string is written to a temporary stream so that fgetcsv() can be used.
 * This has the nice (side) effect of avoiding str_getcsv(), which is less
 * forgiving in its treatment of escape characters and delimeters.
 *
 * @param string $csv CSV string.
 * @param boolean $assoc [Optional] Return as associative arrays instead of objects. Default false.
 * @param mixed $headers [Optional] Array of headers, or boolean true if the first CSV row contains headers.
 * Headers will be used as the keys for the values in each row. Defaults to boolean true.
 * @return object|array|null
 */
PHP_METHOD(Xpl_Csv, decode) {

	zval *data;
	zephir_fcall_cache_entry *_8 = NULL, *_11 = NULL, *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool assoc, hasHeaders;
	zval *csv, *assoc_param = NULL, *headers = NULL, *handle = NULL, *numHeaders = NULL, *line = NULL, *_13 = NULL, _0$$3, _1$$3, *_2$$6, *_3$$6, *_4$$6, *_5$$9, *_6$$9, *_7$$9, *_9$$12 = NULL, *_10$$12 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &csv, &assoc_param, &headers);

	if (!assoc_param) {
		assoc = 0;
	} else {
		assoc = zephir_get_boolval(assoc_param);
	}
	if (!headers) {
		ZEPHIR_CPY_WRT(headers, ZEPHIR_GLOBAL(global_true));
	} else {
		ZEPHIR_SEPARATE_PARAM(headers);
	}


	hasHeaders = 0;
	ZEPHIR_INIT_VAR(data);
	array_init(data);
	if (Z_TYPE_P(csv) == IS_STRING) {
		if (ZEPHIR_IS_EMPTY(csv)) {
			RETURN_MM_NULL();
		}
		ZEPHIR_SINIT_VAR(_0$$3);
		ZVAL_STRING(&_0$$3, "php://temp/maxmemory=2097152", 0);
		ZEPHIR_SINIT_VAR(_1$$3);
		ZVAL_STRING(&_1$$3, "w+b", 0);
		ZEPHIR_CALL_FUNCTION(&handle, "fopen", NULL, 90, &_0$$3, &_1$$3);
		zephir_check_call_status();
		zephir_fwrite(NULL, handle, csv TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "rewind", NULL, 92, handle);
		zephir_check_call_status();
	} else {
		if (Z_TYPE_P(csv) != IS_RESOURCE) {
			ZEPHIR_INIT_VAR(_2$$6);
			object_init_ex(_2$$6, spl_ce_InvalidArgumentException);
			ZEPHIR_INIT_VAR(_3$$6);
			zephir_gettype(_3$$6, csv TSRMLS_CC);
			ZEPHIR_INIT_VAR(_4$$6);
			ZEPHIR_CONCAT_SV(_4$$6, "Expecting CSV string or resource, given: ", _3$$6);
			ZEPHIR_CALL_METHOD(NULL, _2$$6, "__construct", NULL, 5, _4$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(_2$$6, "xpl/csv.zep", 68 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(handle, csv);
	}
	if (Z_TYPE_P(headers) == IS_ARRAY) {
		hasHeaders = zephir_fast_count_int(headers TSRMLS_CC) > 0;
	} else {
		if (Z_TYPE_P(headers) != IS_BOOL) {
			ZEPHIR_INIT_VAR(_5$$9);
			object_init_ex(_5$$9, spl_ce_InvalidArgumentException);
			ZEPHIR_INIT_VAR(_6$$9);
			zephir_gettype(_6$$9, headers TSRMLS_CC);
			ZEPHIR_INIT_VAR(_7$$9);
			ZEPHIR_CONCAT_SV(_7$$9, "Expecting headers to be array or bool, given: ", _6$$9);
			ZEPHIR_CALL_METHOD(NULL, _5$$9, "__construct", NULL, 5, _7$$9);
			zephir_check_call_status();
			zephir_throw_exception_debug(_5$$9, "xpl/csv.zep", 78 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		hasHeaders = zephir_is_true(headers);
		ZEPHIR_CALL_FUNCTION(&headers, "fgetcsv", &_8, 94, handle);
		zephir_check_call_status();
	}
	if (hasHeaders == 1) {
		ZEPHIR_INIT_VAR(numHeaders);
		ZVAL_LONG(numHeaders, zephir_fast_count_int(headers TSRMLS_CC));
	}
	while (1) {
		if (!(!(zephir_feof(handle TSRMLS_CC)))) {
			break;
		}
		ZEPHIR_CALL_FUNCTION(&line, "fgetcsv", &_8, 94, handle);
		zephir_check_call_status();
		if (hasHeaders == 1) {
			ZEPHIR_INIT_NVAR(_9$$12);
			ZVAL_STRING(_9$$12, "", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_FUNCTION(&_10$$12, "array_pad", &_11, 95, line, numHeaders, _9$$12);
			zephir_check_temp_parameter(_9$$12);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&line, "array_combine", &_12, 45, headers, _10$$12);
			zephir_check_call_status();
		}
		if (assoc == 1) {
			zephir_array_append(&data, line, PH_SEPARATE, "xpl/csv.zep", 98);
		} else {
			zephir_convert_to_object(line);
			zephir_array_append(&data, line, PH_SEPARATE, "xpl/csv.zep", 100);
		}
	}
	zephir_fclose(handle TSRMLS_CC);
	ZEPHIR_INIT_VAR(_13);
	if (assoc) {
		ZEPHIR_CPY_WRT(_13, data);
	} else {
		zephir_convert_to_object(data);
		ZEPHIR_CPY_WRT(_13, data);
	}
	RETURN_CCTOR(_13);

}

