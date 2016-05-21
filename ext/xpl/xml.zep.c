
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Xpl_Xml) {

	ZEPHIR_REGISTER_CLASS(Xpl, Xml, xpl, xml, xpl_xml_method_entry, 0);

	return SUCCESS;

}

/**
 * Returns an XML document as a string.
 *
 * @param array $data Document data.
 * @param string $root_tag Root document element. Default "XML"
 * @param string $version XML version. Default "1.0"
 * @param string $encoding XML encoding. Default "UTF-8"
 * @return string XML document as string
 */
PHP_METHOD(Xpl_Xml, encode) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *root_tag = NULL, *version = NULL, *encoding = NULL;
	zval *data_param = NULL, *root_tag_param = NULL, *version_param = NULL, *encoding_param = NULL, *writer = NULL, *_0;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &data_param, &root_tag_param, &version_param, &encoding_param);

	data = data_param;
	if (!root_tag_param) {
		ZEPHIR_INIT_VAR(root_tag);
		ZVAL_STRING(root_tag, "XML", 1);
	} else {
	if (unlikely(Z_TYPE_P(root_tag_param) != IS_STRING && Z_TYPE_P(root_tag_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'root_tag' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(root_tag_param) == IS_STRING)) {
		zephir_get_strval(root_tag, root_tag_param);
	} else {
		ZEPHIR_INIT_VAR(root_tag);
		ZVAL_EMPTY_STRING(root_tag);
	}
	}
	if (!version_param) {
		ZEPHIR_INIT_VAR(version);
		ZVAL_STRING(version, "1.0", 1);
	} else {
	if (unlikely(Z_TYPE_P(version_param) != IS_STRING && Z_TYPE_P(version_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'version' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(version_param) == IS_STRING)) {
		zephir_get_strval(version, version_param);
	} else {
		ZEPHIR_INIT_VAR(version);
		ZVAL_EMPTY_STRING(version);
	}
	}
	if (!encoding_param) {
		ZEPHIR_INIT_VAR(encoding);
		ZVAL_STRING(encoding, "UTF-8", 1);
	} else {
	if (unlikely(Z_TYPE_P(encoding_param) != IS_STRING && Z_TYPE_P(encoding_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'encoding' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(encoding_param) == IS_STRING)) {
		zephir_get_strval(encoding, encoding_param);
	} else {
		ZEPHIR_INIT_VAR(encoding);
		ZVAL_EMPTY_STRING(encoding);
	}
	}


	ZEPHIR_INIT_VAR(writer);
	object_init_ex(writer, zephir_get_internal_ce(SS("xmlwriter") TSRMLS_CC));
	if (zephir_has_constructor(writer TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, writer, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, writer, "openmemory", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, writer, "startdocument", NULL, 0, version, encoding);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, writer, "startelement", NULL, 0, root_tag);
	zephir_check_call_status();
	ZEPHIR_CALL_SELF(NULL, "writeelement", NULL, 0, writer, data);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, writer, "endelement", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, writer, "enddocument", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZVAL_BOOL(_0, 1);
	ZEPHIR_RETURN_CALL_METHOD(writer, "outputmemory", NULL, 0, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Decodes an XML string into an object or array.
 *
 * @param string $xml A well-formed XML string.
 * @param boolean $assoc [Optional] Decode to an associative array. Default false.
 *
 * @return object|array|null XML data decoded to object(s) or array(s).
 */
PHP_METHOD(Xpl_Xml, decode) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_bool assoc, _0;
	zval *xml_param = NULL, *assoc_param = NULL, *xmlErrors = NULL, *simpleXml = NULL, *_2$$4, _3$$4;
	zval *xml = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &xml_param, &assoc_param);

	if (unlikely(Z_TYPE_P(xml_param) != IS_STRING && Z_TYPE_P(xml_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'xml' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(xml_param) == IS_STRING)) {
		zephir_get_strval(xml, xml_param);
	} else {
		ZEPHIR_INIT_VAR(xml);
		ZVAL_EMPTY_STRING(xml);
	}
	if (!assoc_param) {
		assoc = 0;
	} else {
		assoc = zephir_get_boolval(assoc_param);
	}


	_0 = ZEPHIR_IS_EMPTY(xml);
	if (!(_0)) {
		_0 = !(zephir_start_with_str(xml, SL("<?xml ")));
	}
	if (_0) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_FUNCTION(&xmlErrors, "libxml_use_internal_errors", &_1, 189, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&simpleXml, "simplexml_load_string", NULL, 190, xml);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "libxml_use_internal_errors", &_1, 189, xmlErrors);
	zephir_check_call_status();
	if (zephir_instance_of_ev(simpleXml, zephir_get_internal_ce(SS("simplexmlelement") TSRMLS_CC) TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_2$$4);
		zephir_json_encode(_2$$4, &(_2$$4), simpleXml, 0  TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_3$$4);
		ZVAL_BOOL(&_3$$4, (assoc ? 1 : 0));
		zephir_json_decode(return_value, &(return_value), _2$$4, zephir_get_intval(&_3$$4)  TSRMLS_CC);
		RETURN_MM();
	}
	RETURN_MM_NULL();

}

/**
 * Checks whether the given value is a valid XML string.
 *
 * @param string $arg Value to check if XML.
 *
 * @return boolean TRUE if value is a valid XML string, otherwise false.
 */
PHP_METHOD(Xpl_Xml, validate) {

	zend_bool val = 0, _0, _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *str_param = NULL, *xmlErrors = NULL, *_2 = NULL, *_4 = NULL;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

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


	_0 = ZEPHIR_IS_EMPTY(str);
	if (!(_0)) {
		_0 = !(zephir_start_with_str(str, SL("<?xml ")));
	}
	if (_0) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_FUNCTION(&xmlErrors, "libxml_use_internal_errors", &_1, 189, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "simplexml_load_string", NULL, 190, str);
	zephir_check_call_status();
	_3 = zephir_instance_of_ev(_2, zephir_get_internal_ce(SS("simplexmlelement") TSRMLS_CC) TSRMLS_CC);
	if (_3) {
		ZEPHIR_CALL_FUNCTION(&_4, "libxml_get_last_error", NULL, 191);
		zephir_check_call_status();
		_3 = ZEPHIR_IS_FALSE_IDENTICAL(_4);
	}
	val = _3;
	ZEPHIR_CALL_FUNCTION(NULL, "libxml_use_internal_errors", &_1, 189, xmlErrors);
	zephir_check_call_status();
	RETURN_MM_BOOL(val);

}

/**
 * Writes an element.
 *
 * @param \XMLWriter $writer An XMLWriter instance.
 * @param array $data Data to write to the document.
 * @return void
 */
PHP_METHOD(Xpl_Xml, writeElement) {

	zend_bool _18$$11;
	zval *_8$$7 = NULL;
	HashTable *_1, *_13$$9;
	HashPosition _0, _12$$9;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL, *_9 = NULL, *_11 = NULL, *_15 = NULL, *_16 = NULL, *_17 = NULL, *_20 = NULL, *_22 = NULL, *_23 = NULL;
	zval *data = NULL;
	zval *writer, *data_param = NULL, *key = NULL, *value = NULL, *tag = NULL, *attributes = NULL, **_2, *_3$$3 = NULL, *_5$$4 = NULL, *_6$$5 = NULL, *k$$9 = NULL, *v$$9 = NULL, *_10$$9 = NULL, **_14$$9, *_19$$13 = NULL, _21$$13 = zval_used_for_init;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &writer, &data_param);

	data = data_param;


	zephir_is_iterable(data, &_1, &_0, 0, 0, "xpl/xml.zep", 147);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_CALL_CE_STATIC(&_3$$3, xpl_str_ce, "alnum", &_4, 0, key);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(key, _3$$3);
		if (zephir_is_numeric(key)) {
			ZEPHIR_INIT_LNVAR(_5$$4);
			ZEPHIR_CONCAT_SV(_5$$4, "Item_", key);
			ZEPHIR_CPY_WRT(key, _5$$4);
		}
		if (Z_TYPE_P(value) == IS_OBJECT) {
			ZEPHIR_CALL_CE_STATIC(&_6$$5, xpl_type_ce, "toarray", &_7, 0, value);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(value, _6$$5);
		}
		if (Z_TYPE_P(value) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(tag);
			if (zephir_array_isset_string_fetch(&tag, value, SS("@tag"), 0 TSRMLS_CC)) {
				zephir_get_strval(_8$$7, tag);
				ZEPHIR_CPY_WRT(key, _8$$7);
				zephir_array_unset_string(&value, SS("@tag"), PH_SEPARATE);
			}
			ZEPHIR_CALL_METHOD(NULL, writer, "startelement", &_9, 0, key);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(attributes);
			if (zephir_array_isset_string_fetch(&attributes, value, SS("@attributes"), 0 TSRMLS_CC)) {
				if (Z_TYPE_P(attributes) == IS_ARRAY) {
					ZEPHIR_CALL_FUNCTION(&_10$$9, "array_unique", &_11, 192, attributes);
					zephir_check_call_status();
					zephir_is_iterable(_10$$9, &_13$$9, &_12$$9, 0, 0, "xpl/xml.zep", 127);
					for (
					  ; zephir_hash_get_current_data_ex(_13$$9, (void**) &_14$$9, &_12$$9) == SUCCESS
					  ; zephir_hash_move_forward_ex(_13$$9, &_12$$9)
					) {
						ZEPHIR_GET_HMKEY(k$$9, _13$$9, _12$$9);
						ZEPHIR_GET_HVALUE(v$$9, _14$$9);
						ZEPHIR_CALL_METHOD(NULL, writer, "writeattribute", &_15, 0, k$$9, v$$9);
						zephir_check_call_status();
					}
					zephir_array_unset_string(&value, SS("@attributes"), PH_SEPARATE);
				}
			}
			ZEPHIR_CALL_SELF(NULL, "writeelement", &_16, 0, writer, value);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, writer, "endelement", &_17, 0);
			zephir_check_call_status();
		} else {
			_18$$11 = Z_TYPE_P(value) == IS_NULL;
			if (!(_18$$11)) {
				_18$$11 = zephir_is_scalar(value);
			}
			if (_18$$11) {
				if (Z_TYPE_P(value) == IS_STRING) {
					ZEPHIR_CALL_FUNCTION(&_19$$13, "html_entity_decode", &_20, 135, value);
					zephir_check_call_status();
					ZEPHIR_SINIT_NVAR(_21$$13);
					ZVAL_LONG(&_21$$13, (16 | 128));
					ZEPHIR_CALL_FUNCTION(&value, "htmlentities", &_22, 109, _19$$13, &_21$$13);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(NULL, writer, "writeelement", &_23, 0, key, value);
				zephir_check_call_status();
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

