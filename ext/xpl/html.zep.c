
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
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Xpl_Html) {

	ZEPHIR_REGISTER_CLASS(Xpl, Html, xpl, html, xpl_html_method_entry, 0);

	/**
	 * Whether to use HTML5
	 * @var boolean
	 */
	zend_declare_property_bool(xpl_html_ce, SL("html5"), 1, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * Self-closing tags.
	 * @var array
	 */
	zend_declare_property_null(xpl_html_ce, SL("selfClosingTags"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * Create an HTML element string.
 *
 * @param string $tag Element tag.
 * @param mixed $attributes [Optional] Element attribute array or string.
 * @param string $content [Optional] Element content to place between opening and closing tags.
 * @return string HTML element string.
 */
PHP_METHOD(Xpl_Html, make) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tag_param = NULL, *attributes = NULL, *content_param = NULL, *_0 = NULL, *_5 = NULL, *_1$$3, *_2$$3, *_3$$3 = NULL, *_4$$5 = NULL, *_6$$6 = NULL, *_7$$6;
	zval *tag = NULL, *content = NULL, *html = NULL, *_8$$7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &tag_param, &attributes, &content_param);

	zephir_get_strval(tag, tag_param);
	if (!attributes) {
		attributes = ZEPHIR_GLOBAL(global_null);
	}
	if (!content_param) {
		ZEPHIR_INIT_VAR(content);
		ZVAL_STRING(content, "", 1);
	} else {
		zephir_get_strval(content, content_param);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "ctype_alnum", NULL, 107, tag);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_STRING(_1$$3, "/[^a-zA-Z0-9]/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "preg_replace", NULL, 108, _1$$3, _2$$3, tag);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
		zephir_get_strval(tag, _3$$3);
	}
	if (unlikely(ZEPHIR_IS_EMPTY(tag))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid HTML tag", "xpl/html.zep", 37);
		return;
	}
	ZEPHIR_INIT_VAR(html);
	ZEPHIR_CONCAT_SV(html, "<", tag);
	if (Z_TYPE_P(attributes) != IS_NULL) {
		ZEPHIR_CALL_SELF(&_4$$5, "attributestring", NULL, 0, attributes);
		zephir_check_call_status();
		zephir_concat_self(&html, _4$$5 TSRMLS_CC);
	}
	ZEPHIR_CALL_SELF(&_5, "isselfclosingtag", NULL, 0, tag);
	zephir_check_call_status();
	if (zephir_is_true(_5)) {
		ZEPHIR_INIT_VAR(_6$$6);
		_7$$6 = zephir_fetch_static_property_ce(xpl_html_ce, SL("html5") TSRMLS_CC);
		if (zephir_is_true(_7$$6)) {
			ZEPHIR_INIT_NVAR(_6$$6);
			ZVAL_STRING(_6$$6, ">", 1);
		} else {
			ZEPHIR_INIT_NVAR(_6$$6);
			ZVAL_STRING(_6$$6, " />\n", 1);
		}
		zephir_concat_self(&html, _6$$6 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_8$$7);
		ZEPHIR_CONCAT_SVSVS(_8$$7, ">", content, "</", tag, ">\n");
		zephir_concat_self(&html, _8$$7 TSRMLS_CC);
	}
	RETURN_CTOR(html);

}

/**
 * Creates an attribute string for an element
 *
 * @param string|array $attributes Attribute string or array
 * @return string Attribute string
 */
PHP_METHOD(Xpl_Html, attributeString) {

	HashTable *_2;
	HashPosition _1;
	zval *str;
	zephir_fcall_cache_entry *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *attributes, *name = NULL, *value = NULL, *_0 = NULL, **_3, *_4$$4 = NULL, _5$$3 = zval_used_for_init, _6$$3 = zval_used_for_init, *_7$$3 = NULL, *_9$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes);



	ZEPHIR_INIT_VAR(str);
	ZVAL_EMPTY_STRING(str);
	ZEPHIR_CALL_SELF(&_0, "parseattributes", NULL, 0, attributes);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "xpl/html.zep", 75);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(name, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		if (Z_TYPE_P(value) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(_4$$4);
			zephir_fast_join_str(_4$$4, SL(" "), value TSRMLS_CC);
			ZEPHIR_CPY_WRT(value, _4$$4);
		}
		ZEPHIR_SINIT_NVAR(_5$$3);
		ZVAL_LONG(&_5$$3, (0 | 48));
		ZEPHIR_SINIT_NVAR(_6$$3);
		ZVAL_STRING(&_6$$3, "UTF-8", 0);
		ZEPHIR_CALL_FUNCTION(&_7$$3, "htmlentities", &_8, 109, value, &_5$$3, &_6$$3, ZEPHIR_GLOBAL(global_false));
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_9$$3);
		ZEPHIR_CONCAT_SVSVS(_9$$3, " ", name, "=\"", _7$$3, "\"");
		zephir_concat_self(&str, _9$$3 TSRMLS_CC);
	}
	RETURN_CTOR(str);

}

/**
 * Parses a string of attributes to an array
 *
 * @param string|array str Attribute string/array
 * @return array
 */
PHP_METHOD(Xpl_Html, parseAttributes) {

	HashTable *_2;
	HashPosition _1;
	zval *attributes;
	zval *str = NULL, *arr = NULL, *attr = NULL, *parts = NULL, *name = NULL, *vals = NULL, *_0, **_3, *_4$$6 = NULL, _5$$6 = zval_used_for_init, _6$$6 = zval_used_for_init, *_7$$9 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str);

	ZEPHIR_SEPARATE_PARAM(str);


	ZEPHIR_INIT_VAR(attributes);
	array_init(attributes);
	if (Z_TYPE_P(str) != IS_STRING) {
		RETVAL_ZVAL(str, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_fast_trim(_0, str, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_CPY_WRT(str, _0);
	if (!(zephir_memnstr_str(str, SL("\" "), "xpl/html.zep", 96))) {
		ZEPHIR_INIT_VAR(arr);
		zephir_create_array(arr, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(arr, str);
	} else {
		ZEPHIR_INIT_NVAR(arr);
		zephir_fast_explode_str(arr, SL("\" "), str, LONG_MAX TSRMLS_CC);
	}
	zephir_is_iterable(arr, &_2, &_1, 0, 0, "xpl/html.zep", 130);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(attr, _3);
		ZEPHIR_INIT_NVAR(_4$$6);
		ZEPHIR_SINIT_NVAR(_5$$6);
		ZVAL_STRING(&_5$$6, "\"", 0);
		ZEPHIR_SINIT_NVAR(_6$$6);
		ZVAL_STRING(&_6$$6, "", 0);
		zephir_fast_str_replace(&_4$$6, &_5$$6, &_6$$6, attr TSRMLS_CC);
		ZEPHIR_CPY_WRT(attr, _4$$6);
		if (!(zephir_memnstr_str(attr, SL("="), "xpl/html.zep", 110))) {
			zephir_array_update_zval(&attributes, attr, &attr, PH_COPY | PH_SEPARATE);
		} else {
			ZEPHIR_INIT_NVAR(parts);
			zephir_fast_explode_str(parts, SL("="), attr, 2  TSRMLS_CC);
			ZEPHIR_OBS_NVAR(name);
			zephir_array_fetch_long(&name, parts, 0, PH_NOISY, "xpl/html.zep", 118 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(vals);
			zephir_array_fetch_long(&vals, parts, 1, PH_NOISY, "xpl/html.zep", 119 TSRMLS_CC);
			if (zephir_memnstr_str(vals, SL(" "), "xpl/html.zep", 122)) {
				ZEPHIR_INIT_NVAR(_7$$9);
				zephir_fast_explode_str(_7$$9, SL(" "), vals, LONG_MAX TSRMLS_CC);
				ZEPHIR_CPY_WRT(vals, _7$$9);
			}
			zephir_array_update_zval(&attributes, name, &vals, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CTOR(attributes);

}

/**
 * Applies htmlentities() to an attribute string using ENT_NOQUOTES to protect against XSS
 *
 * @param string $str Attribute value string
 * @return string Escaped attribute value
 */
PHP_METHOD(Xpl_Html, escapeAttribute) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, _0, _1;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, (0 | 48));
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "UTF-8", 0);
	ZEPHIR_RETURN_CALL_FUNCTION("htmlentities", NULL, 109, str, &_0, &_1, ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Whether the given tag is self-closing.
 *
 * @param string $tag Element tag.
 * @return boolean
 */
PHP_METHOD(Xpl_Html, isSelfClosingTag) {

	zval *_1$$3;
	zval *tag_param = NULL, *_0, *_2;
	zval *tag = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &tag_param);

	zephir_get_strval(tag, tag_param);


	ZEPHIR_OBS_VAR(_0);
	zephir_read_static_property_ce(&_0, xpl_html_ce, SL("selfClosingTags") TSRMLS_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(_1$$3);
		zephir_create_array(_1$$3, 10, 0 TSRMLS_CC);
		add_assoc_long_ex(_1$$3, SS("hr"), 1);
		add_assoc_long_ex(_1$$3, SS("br"), 1);
		add_assoc_long_ex(_1$$3, SS("input"), 1);
		add_assoc_long_ex(_1$$3, SS("meta"), 1);
		add_assoc_long_ex(_1$$3, SS("base"), 1);
		add_assoc_long_ex(_1$$3, SS("basefont"), 1);
		add_assoc_long_ex(_1$$3, SS("col"), 1);
		add_assoc_long_ex(_1$$3, SS("frame"), 1);
		add_assoc_long_ex(_1$$3, SS("link"), 1);
		add_assoc_long_ex(_1$$3, SS("param"), 1);
		zephir_update_static_property_ce(xpl_html_ce, SL("selfClosingTags"), &_1$$3 TSRMLS_CC);
	}
	_2 = zephir_fetch_static_property_ce(xpl_html_ce, SL("selfClosingTags") TSRMLS_CC);
	RETURN_MM_BOOL(zephir_array_isset(_2, tag));

}

