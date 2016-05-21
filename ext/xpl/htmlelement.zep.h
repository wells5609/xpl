
extern zend_class_entry *xpl_htmlelement_ce;

ZEPHIR_INIT_CLASS(Xpl_HtmlElement);

PHP_METHOD(Xpl_HtmlElement, __construct);
PHP_METHOD(Xpl_HtmlElement, setTag);
PHP_METHOD(Xpl_HtmlElement, getTag);
PHP_METHOD(Xpl_HtmlElement, setAttribute);
PHP_METHOD(Xpl_HtmlElement, setAttributes);
PHP_METHOD(Xpl_HtmlElement, addAttribute);
PHP_METHOD(Xpl_HtmlElement, addAttributes);
PHP_METHOD(Xpl_HtmlElement, getAttribute);
PHP_METHOD(Xpl_HtmlElement, getAttributes);
PHP_METHOD(Xpl_HtmlElement, hasAttribute);
PHP_METHOD(Xpl_HtmlElement, removeAttribute);
PHP_METHOD(Xpl_HtmlElement, setContent);
PHP_METHOD(Xpl_HtmlElement, getContent);
PHP_METHOD(Xpl_HtmlElement, prependContent);
PHP_METHOD(Xpl_HtmlElement, appendContent);
PHP_METHOD(Xpl_HtmlElement, __toString);
PHP_METHOD(Xpl_HtmlElement, setPrependString);
PHP_METHOD(Xpl_HtmlElement, getPrependString);
PHP_METHOD(Xpl_HtmlElement, setAppendString);
PHP_METHOD(Xpl_HtmlElement, getAppendString);
PHP_METHOD(Xpl_HtmlElement, prepend);
PHP_METHOD(Xpl_HtmlElement, append);
PHP_METHOD(Xpl_HtmlElement, prependElement);
PHP_METHOD(Xpl_HtmlElement, appendElement);
PHP_METHOD(Xpl_HtmlElement, serialize);
PHP_METHOD(Xpl_HtmlElement, unserialize);
PHP_METHOD(Xpl_HtmlElement, getDefaultAttributes);
PHP_METHOD(Xpl_HtmlElement, prepare);
static zend_object_value zephir_init_properties_Xpl_HtmlElement(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_htmlelement_settag, 0, 0, 1)
	ZEND_ARG_INFO(0, tag)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_htmlelement_setattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, overwrite)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_htmlelement_setattributes, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_htmlelement_addattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_htmlelement_addattributes, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_htmlelement_getattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_htmlelement_hasattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_htmlelement_removeattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_htmlelement_setcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_htmlelement_prependcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_htmlelement_appendcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_htmlelement_setprependstring, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_htmlelement_setappendstring, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_htmlelement_prepend, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_htmlelement_append, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_htmlelement_prependelement, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_htmlelement_appendelement, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_htmlelement_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, serial)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_htmlelement_method_entry) {
	PHP_ME(Xpl_HtmlElement, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Xpl_HtmlElement, setTag, arginfo_xpl_htmlelement_settag, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_HtmlElement, getTag, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_HtmlElement, setAttribute, arginfo_xpl_htmlelement_setattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_HtmlElement, setAttributes, arginfo_xpl_htmlelement_setattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_HtmlElement, addAttribute, arginfo_xpl_htmlelement_addattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_HtmlElement, addAttributes, arginfo_xpl_htmlelement_addattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_HtmlElement, getAttribute, arginfo_xpl_htmlelement_getattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_HtmlElement, getAttributes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_HtmlElement, hasAttribute, arginfo_xpl_htmlelement_hasattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_HtmlElement, removeAttribute, arginfo_xpl_htmlelement_removeattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_HtmlElement, setContent, arginfo_xpl_htmlelement_setcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_HtmlElement, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_HtmlElement, prependContent, arginfo_xpl_htmlelement_prependcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_HtmlElement, appendContent, arginfo_xpl_htmlelement_appendcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_HtmlElement, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_HtmlElement, setPrependString, arginfo_xpl_htmlelement_setprependstring, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_HtmlElement, getPrependString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_HtmlElement, setAppendString, arginfo_xpl_htmlelement_setappendstring, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_HtmlElement, getAppendString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_HtmlElement, prepend, arginfo_xpl_htmlelement_prepend, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_HtmlElement, append, arginfo_xpl_htmlelement_append, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_HtmlElement, prependElement, arginfo_xpl_htmlelement_prependelement, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_HtmlElement, appendElement, arginfo_xpl_htmlelement_appendelement, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_HtmlElement, serialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_HtmlElement, unserialize, arginfo_xpl_htmlelement_unserialize, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_HtmlElement, getDefaultAttributes, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Xpl_HtmlElement, prepare, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
