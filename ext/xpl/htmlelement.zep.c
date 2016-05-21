
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Xpl_HtmlElement) {

	ZEPHIR_REGISTER_CLASS(Xpl, HtmlElement, xpl, htmlelement, xpl_htmlelement_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(xpl_htmlelement_ce, SL("_tag"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(xpl_htmlelement_ce, SL("_prependString"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(xpl_htmlelement_ce, SL("_appendString"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(xpl_htmlelement_ce, SL("_attributes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_null(xpl_htmlelement_ce, SL("_content"), ZEND_ACC_PROTECTED TSRMLS_CC);

	xpl_htmlelement_ce->create_object = zephir_init_properties_Xpl_HtmlElement;

	zend_class_implements(xpl_htmlelement_ce TSRMLS_CC, 1, zend_ce_serializable);
	return SUCCESS;

}

/**
 * Constructor.
 */
PHP_METHOD(Xpl_HtmlElement, __construct) {

	zval *_0, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "div", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "settag", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getdefaultattributes", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setattributes", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the element's HTML tag.
 *
 * @param string tag
 * @return \Xpl\HtmlElement
 */
PHP_METHOD(Xpl_HtmlElement, setTag) {

	zval *tag_param = NULL, *_0;
	zval *tag = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &tag_param);

	zephir_get_strval(tag, tag_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, tag);
	zephir_update_property_this(this_ptr, SL("_tag"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the element's HTML tag.
 *
 * @return string
 */
PHP_METHOD(Xpl_HtmlElement, getTag) {

	

	RETURN_MEMBER(this_ptr, "_tag");

}

/**
 * Sets a single attribute.
 *
 * @param string name
 * @param mixed value
 * @param boolean overwrite [Optional] Default = true
 * @return \Xpl\HtmlElement
 */
PHP_METHOD(Xpl_HtmlElement, setAttribute) {

	zend_bool overwrite, _0;
	zval *name_param = NULL, *value, *overwrite_param = NULL, *attrs = NULL, *arrVal = NULL, *_1$$6, *_2$$6;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name_param, &value, &overwrite_param);

	zephir_get_strval(name, name_param);
	if (!overwrite_param) {
		overwrite = 1;
	} else {
		overwrite = zephir_get_boolval(overwrite_param);
	}


	ZEPHIR_OBS_VAR(attrs);
	zephir_read_property_this(&attrs, this_ptr, SL("_attributes"), PH_NOISY_CC);
	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(arrVal, value);
	} else {
		ZEPHIR_INIT_NVAR(arrVal);
		zephir_create_array(arrVal, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(arrVal, value);
	}
	_0 = !(zephir_array_isset(attrs, name));
	if (!(_0)) {
		_0 = overwrite;
	}
	if (_0) {
		zephir_array_update_zval(&attrs, name, &arrVal, PH_COPY | PH_SEPARATE);
	} else {
		ZEPHIR_INIT_VAR(_1$$6);
		zephir_array_fetch(&_2$$6, attrs, name, PH_NOISY | PH_READONLY, "xpl/htmlelement.zep", 84 TSRMLS_CC);
		zephir_fast_array_merge(_1$$6, &(_2$$6), &(arrVal) TSRMLS_CC);
		zephir_array_update_zval(&attrs, name, &_1$$6, PH_COPY | PH_SEPARATE);
	}
	zephir_update_property_this(this_ptr, SL("_attributes"), attrs TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets the element's attributes.
 *
 * @param array attributes
 * @return \Xpl\HtmlElement
 */
PHP_METHOD(Xpl_HtmlElement, setAttributes) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, *name = NULL, *value = NULL, **_2;
	zval *attributes = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	zephir_get_arrval(attributes, attributes_param);


	zephir_is_iterable(attributes, &_1, &_0, 0, 0, "xpl/htmlelement.zep", 106);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(name, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setattribute", &_3, 0, name, value);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Adds an attribute to the element.
 *
 * @param string name
 * @param mixed value
 * @return \Xpl\HtmlElement
 */
PHP_METHOD(Xpl_HtmlElement, addAttribute) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	zephir_get_strval(name, name_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_BOOL(_0, 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "setattribute", NULL, 0, name, value, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds multiple attributes to the element.
 *
 * @param array
 * @return \Xpl\HtmlElement
 */
PHP_METHOD(Xpl_HtmlElement, addAttributes) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, *name = NULL, *value = NULL, **_2;
	zval *attributes = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	zephir_get_arrval(attributes, attributes_param);


	zephir_is_iterable(attributes, &_1, &_0, 0, 0, "xpl/htmlelement.zep", 135);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(name, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addattribute", &_3, 0, name, value);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Returns an attribute by name.
 *
 * @param string name
 * @return array|null
 */
PHP_METHOD(Xpl_HtmlElement, getAttribute) {

	zval *name_param = NULL, *_0, *_1, *_2;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_attributes"), PH_NOISY_CC);
	if (zephir_array_isset(_1, name)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_attributes"), PH_NOISY_CC);
		zephir_array_fetch(&_0, _2, name, PH_NOISY, "xpl/htmlelement.zep", 146 TSRMLS_CC);
	} else {
		ZVAL_NULL(_0);
	}
	RETURN_CCTOR(_0);

}

/**
 * Returns the element's attributes.
 *
 * @return array
 */
PHP_METHOD(Xpl_HtmlElement, getAttributes) {

	

	RETURN_MEMBER(this_ptr, "_attributes");

}

/**
 * Checks whether the element has a given attribute.
 *
 * @param string name
 * @param mixed value [Optional]
 * @return \Xpl\HtmlElement
 */
PHP_METHOD(Xpl_HtmlElement, hasAttribute) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value = NULL, *_0, *_1, *_2;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &value);

	zephir_get_strval(name, name_param);
	if (!value) {
		value = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_attributes"), PH_NOISY_CC);
	if (!(zephir_array_isset(_0, name))) {
		RETURN_MM_BOOL(0);
	}
	if (Z_TYPE_P(value) == IS_NULL) {
		RETURN_MM_BOOL(1);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_attributes"), PH_NOISY_CC);
	zephir_array_fetch(&_2, _1, name, PH_NOISY | PH_READONLY, "xpl/htmlelement.zep", 176 TSRMLS_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("in_array", NULL, 2, value, _2, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Removes an attribute from the element.
 *
 * @param string name
 * @param mixed value [Optional]
 * @return \Xpl\HtmlElement
 */
PHP_METHOD(Xpl_HtmlElement, removeAttribute) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value = NULL, *attributeValues = NULL, *_0, *_1$$4, *valueKey$$5 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &value);

	zephir_get_strval(name, name_param);
	if (!value) {
		value = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(attributeValues);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_attributes"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&attributeValues, _0, name, 0 TSRMLS_CC)) {
		if (Z_TYPE_P(value) == IS_NULL) {
			_1$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_attributes"), PH_NOISY_CC);
			zephir_array_unset(&_1$$4, name, PH_SEPARATE);
		} else {
			ZEPHIR_CALL_FUNCTION(&valueKey$$5, "array_search", NULL, 67, value, attributeValues, ZEPHIR_GLOBAL(global_true));
			zephir_check_call_status();
			if (!ZEPHIR_IS_FALSE_IDENTICAL(valueKey$$5)) {
				zephir_array_unset(&attributeValues, valueKey$$5, PH_SEPARATE);
				zephir_update_property_array(this_ptr, SL("_attributes"), name, attributeValues TSRMLS_CC);
			}
		}
	}
	RETURN_THIS();

}

/**
 * Sets the content.
 *
 * @param string content
 * @return \Xpl\HtmlElement
 */
PHP_METHOD(Xpl_HtmlElement, setContent) {

	zval *content_param = NULL;
	zval *content = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	zephir_get_strval(content, content_param);


	zephir_update_property_this(this_ptr, SL("_content"), content TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the content.
 *
 * @return string
 */
PHP_METHOD(Xpl_HtmlElement, getContent) {

	zval *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_content"), PH_NOISY_CC);
	zephir_get_strval(_1, _0);
	RETURN_CTOR(_1);

}

/**
 * Prepends content.
 *
 * @param string content
 * @return \Xpl\HtmlElement
 */
PHP_METHOD(Xpl_HtmlElement, prependContent) {

	zval *content_param = NULL, *_0, *_1;
	zval *content = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	zephir_get_strval(content, content_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_content"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VV(_1, content, _0);
	zephir_update_property_this(this_ptr, SL("_content"), _1 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Appends content.
 *
 * @param string content
 * @return \Xpl\HtmlElement
 */
PHP_METHOD(Xpl_HtmlElement, appendContent) {

	zval *content_param = NULL;
	zval *content = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	zephir_get_strval(content, content_param);


	zephir_update_property_this(this_ptr, SL("_content"), content TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the element as a string.
 *
 * @return string
 */
PHP_METHOD(Xpl_HtmlElement, __toString) {

	zval *_0 = NULL, *_1 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL;
	zval *html;
	zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(html);
	ZVAL_EMPTY_STRING(html);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "prepare", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getprependstring", NULL, 0);
	zephir_check_call_status();
	zephir_concat_self(&html, _0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "gettag", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getattributes", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getcontent", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_1, xpl_html_ce, "make", &_2, 110, _3, _4, _5);
	zephir_check_call_status();
	zephir_concat_self(&html, _1 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "getappendstring", NULL, 0);
	zephir_check_call_status();
	zephir_concat_self(&html, _6 TSRMLS_CC);
	RETURN_CTOR(html);

}

PHP_METHOD(Xpl_HtmlElement, setPrependString) {

	zval *content_param = NULL;
	zval *content = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	zephir_get_strval(content, content_param);


	zephir_update_property_this(this_ptr, SL("_prependString"), content TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Xpl_HtmlElement, getPrependString) {

	zval *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_prependString"), PH_NOISY_CC);
	zephir_get_strval(_1, _0);
	RETURN_CTOR(_1);

}

PHP_METHOD(Xpl_HtmlElement, setAppendString) {

	zval *content_param = NULL;
	zval *content = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	zephir_get_strval(content, content_param);


	zephir_update_property_this(this_ptr, SL("_appendString"), content TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Xpl_HtmlElement, getAppendString) {

	zval *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_appendString"), PH_NOISY_CC);
	zephir_get_strval(_1, _0);
	RETURN_CTOR(_1);

}

PHP_METHOD(Xpl_HtmlElement, prepend) {

	zval *content_param = NULL, *_0, *_1;
	zval *content = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	zephir_get_strval(content, content_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prependString"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VV(_1, content, _0);
	zephir_update_property_this(this_ptr, SL("_prependString"), _1 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Xpl_HtmlElement, append) {

	zval *content_param = NULL;
	zval *content = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	zephir_get_strval(content, content_param);


	zephir_update_property_this(this_ptr, SL("_appendString"), content TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Xpl_HtmlElement, prependElement) {

	zval *content_param = NULL;
	zval *content = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	zephir_get_strval(content, content_param);


	zephir_update_property_this(this_ptr, SL("_prependString"), content TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Xpl_HtmlElement, appendElement) {

	zval *content_param = NULL, *_0, *_1;
	zval *content = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	zephir_get_strval(content, content_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_appendString"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VV(_1, content, _0);
	zephir_update_property_this(this_ptr, SL("_appendString"), _1 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Xpl_HtmlElement, serialize) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "get_object_vars", NULL, 62, this_ptr);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 3, _0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Xpl_HtmlElement, unserialize) {

	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *serial_param = NULL, *key = NULL, *value = NULL, *_0 = NULL, **_3;
	zval *serial = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serial_param);

	if (unlikely(Z_TYPE_P(serial_param) != IS_STRING && Z_TYPE_P(serial_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'serial' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(serial_param) == IS_STRING)) {
		zephir_get_strval(serial, serial_param);
	} else {
		ZEPHIR_INIT_VAR(serial);
		ZVAL_EMPTY_STRING(serial);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "unserialize", NULL, 4, serial);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "xpl/htmlelement.zep", 329);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		zephir_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the default attributes for the element.
 *
 * Subclasses can overwrite this method to implement element-specific defaults.
 *
 * @return array
 */
PHP_METHOD(Xpl_HtmlElement, getDefaultAttributes) {

	

	array_init(return_value);
	return;

}

/**
 * Called at start of __toString() before any HTML is generated.
 *
 * In subclasses, this method can be used to print sub-elements
 * in the current element's content.
 */
PHP_METHOD(Xpl_HtmlElement, prepare) {

	


}

static zend_object_value zephir_init_properties_Xpl_HtmlElement(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_attributes"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("_attributes"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

