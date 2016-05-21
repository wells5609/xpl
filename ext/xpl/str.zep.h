
extern zend_class_entry *xpl_str_ce;

ZEPHIR_INIT_CLASS(Xpl_Str);

PHP_METHOD(Xpl_Str, ukey);
PHP_METHOD(Xpl_Str, camelize);
PHP_METHOD(Xpl_Str, uncamelize);
PHP_METHOD(Xpl_Str, startsWith);
PHP_METHOD(Xpl_Str, endsWith);
PHP_METHOD(Xpl_Str, hasChars);
PHP_METHOD(Xpl_Str, pearCase);
PHP_METHOD(Xpl_Str, snakeCase);
PHP_METHOD(Xpl_Str, studlyCase);
PHP_METHOD(Xpl_Str, camelCase);
PHP_METHOD(Xpl_Str, ascii);
PHP_METHOD(Xpl_Str, alpha);
PHP_METHOD(Xpl_Str, alnum);
PHP_METHOD(Xpl_Str, unicode);
PHP_METHOD(Xpl_Str, slug);
PHP_METHOD(Xpl_Str, stripQuotes);
PHP_METHOD(Xpl_Str, stripControl);
PHP_METHOD(Xpl_Str, filterSqlLike);
PHP_METHOD(Xpl_Str, filterUrl);
PHP_METHOD(Xpl_Str, isJson);
PHP_METHOD(Xpl_Str, isXml);
PHP_METHOD(Xpl_Str, isSerialized);
PHP_METHOD(Xpl_Str, format);
PHP_METHOD(Xpl_Str, between);
PHP_METHOD(Xpl_Str, sentences);
PHP_METHOD(Xpl_Str, handleError);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_str_ukey, 0, 0, 2)
	ZEND_ARG_INFO(0, obj)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, extra)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_str_camelize, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_str_uncamelize, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_str_startswith, 0, 0, 2)
	ZEND_ARG_INFO(0, haystack)
	ZEND_ARG_INFO(0, needle)
	ZEND_ARG_INFO(0, case_insensitive)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_str_endswith, 0, 0, 2)
	ZEND_ARG_INFO(0, haystack)
	ZEND_ARG_INFO(0, needle)
	ZEND_ARG_INFO(0, case_insensitive)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_str_haschars, 0, 0, 2)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, charlist)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_str_pearcase, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_str_snakecase, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_str_studlycase, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_str_camelcase, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_str_ascii, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_str_alpha, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_str_alnum, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_str_unicode, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_str_slug, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, separator)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_str_stripquotes, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_str_stripcontrol, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_str_filtersqllike, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_str_filterurl, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, flags)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_str_isjson, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_str_isxml, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_str_isserialized, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_str_format, 0, 0, 2)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, template)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_str_between, 0, 0, 3)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, substr_start)
	ZEND_ARG_INFO(0, substr_end)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_str_sentences, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, num)
	ZEND_ARG_INFO(0, strip_abbr)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_str_handleerror, 0, 0, 2)
	ZEND_ARG_INFO(0, errorNum)
	ZEND_ARG_INFO(0, errorMsg)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_str_method_entry) {
	PHP_ME(Xpl_Str, ukey, arginfo_xpl_str_ukey, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Str, camelize, arginfo_xpl_str_camelize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Str, uncamelize, arginfo_xpl_str_uncamelize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Str, startsWith, arginfo_xpl_str_startswith, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Str, endsWith, arginfo_xpl_str_endswith, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Str, hasChars, arginfo_xpl_str_haschars, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Str, pearCase, arginfo_xpl_str_pearcase, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Str, snakeCase, arginfo_xpl_str_snakecase, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Str, studlyCase, arginfo_xpl_str_studlycase, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Str, camelCase, arginfo_xpl_str_camelcase, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Str, ascii, arginfo_xpl_str_ascii, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Str, alpha, arginfo_xpl_str_alpha, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Str, alnum, arginfo_xpl_str_alnum, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Str, unicode, arginfo_xpl_str_unicode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Str, slug, arginfo_xpl_str_slug, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Str, stripQuotes, arginfo_xpl_str_stripquotes, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Str, stripControl, arginfo_xpl_str_stripcontrol, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Str, filterSqlLike, arginfo_xpl_str_filtersqllike, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Str, filterUrl, arginfo_xpl_str_filterurl, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Str, isJson, arginfo_xpl_str_isjson, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Str, isXml, arginfo_xpl_str_isxml, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Str, isSerialized, arginfo_xpl_str_isserialized, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Str, format, arginfo_xpl_str_format, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Str, between, arginfo_xpl_str_between, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Str, sentences, arginfo_xpl_str_sentences, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Str, handleError, arginfo_xpl_str_handleerror, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
