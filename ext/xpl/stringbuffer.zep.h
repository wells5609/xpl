
extern zend_class_entry *xpl_stringbuffer_ce;

ZEPHIR_INIT_CLASS(Xpl_StringBuffer);

PHP_METHOD(Xpl_StringBuffer, __construct);
PHP_METHOD(Xpl_StringBuffer, length);
PHP_METHOD(Xpl_StringBuffer, len);
PHP_METHOD(Xpl_StringBuffer, pos);
PHP_METHOD(Xpl_StringBuffer, rpos);
PHP_METHOD(Xpl_StringBuffer, ipos);
PHP_METHOD(Xpl_StringBuffer, ripos);
PHP_METHOD(Xpl_StringBuffer, rchr);
PHP_METHOD(Xpl_StringBuffer, startsWith);
PHP_METHOD(Xpl_StringBuffer, endsWith);
PHP_METHOD(Xpl_StringBuffer, detectEncoding);
PHP_METHOD(Xpl_StringBuffer, filter);
PHP_METHOD(Xpl_StringBuffer, get);
PHP_METHOD(Xpl_StringBuffer, getOriginal);
PHP_METHOD(Xpl_StringBuffer, isChanged);
PHP_METHOD(Xpl_StringBuffer, __toString);
PHP_METHOD(Xpl_StringBuffer, chunk);
PHP_METHOD(Xpl_StringBuffer, at);
PHP_METHOD(Xpl_StringBuffer, first);
PHP_METHOD(Xpl_StringBuffer, last);
PHP_METHOD(Xpl_StringBuffer, toArray);
PHP_METHOD(Xpl_StringBuffer, split);
PHP_METHOD(Xpl_StringBuffer, offsetGet);
PHP_METHOD(Xpl_StringBuffer, offsetExists);
PHP_METHOD(Xpl_StringBuffer, offsetSet);
PHP_METHOD(Xpl_StringBuffer, offsetUnset);
PHP_METHOD(Xpl_StringBuffer, __get);
PHP_METHOD(Xpl_StringBuffer, __call);
PHP_METHOD(Xpl_StringBuffer, set);
PHP_METHOD(Xpl_StringBuffer, setEncoding);
PHP_METHOD(Xpl_StringBuffer, restore);
PHP_METHOD(Xpl_StringBuffer, prepend);
PHP_METHOD(Xpl_StringBuffer, append);
PHP_METHOD(Xpl_StringBuffer, wrap);
PHP_METHOD(Xpl_StringBuffer, trim);
PHP_METHOD(Xpl_StringBuffer, ltrim);
PHP_METHOD(Xpl_StringBuffer, rtrim);
PHP_METHOD(Xpl_StringBuffer, sub);
PHP_METHOD(Xpl_StringBuffer, str);
PHP_METHOD(Xpl_StringBuffer, replace);
PHP_METHOD(Xpl_StringBuffer, ireplace);
PHP_METHOD(Xpl_StringBuffer, pad);
PHP_METHOD(Xpl_StringBuffer, sanitize);
PHP_METHOD(Xpl_StringBuffer, entities);
PHP_METHOD(Xpl_StringBuffer, entityDecode);
PHP_METHOD(Xpl_StringBuffer, specialChars);
PHP_METHOD(Xpl_StringBuffer, specialCharsDecode);
PHP_METHOD(Xpl_StringBuffer, convertEncoding);
PHP_METHOD(Xpl_StringBuffer, convertCase);
PHP_METHOD(Xpl_StringBuffer, upper);
PHP_METHOD(Xpl_StringBuffer, lower);
PHP_METHOD(Xpl_StringBuffer, ucwords);
PHP_METHOD(Xpl_StringBuffer, ucfirst);
PHP_METHOD(Xpl_StringBuffer, lcfirst);
PHP_METHOD(Xpl_StringBuffer, md5);
PHP_METHOD(Xpl_StringBuffer, sha1);
PHP_METHOD(Xpl_StringBuffer, hash);
PHP_METHOD(Xpl_StringBuffer, hashHmac);
PHP_METHOD(Xpl_StringBuffer, isAlnum);
PHP_METHOD(Xpl_StringBuffer, isAlpha);
PHP_METHOD(Xpl_StringBuffer, isUpper);
PHP_METHOD(Xpl_StringBuffer, isLower);
PHP_METHOD(Xpl_StringBuffer, isPrintable);
PHP_METHOD(Xpl_StringBuffer, isControl);
PHP_METHOD(Xpl_StringBuffer, isDigit);
PHP_METHOD(Xpl_StringBuffer, containsChars);
PHP_METHOD(Xpl_StringBuffer, setHtmlEntitiesFlags);
PHP_METHOD(Xpl_StringBuffer, getHtmlEntitiesFlags);
PHP_METHOD(Xpl_StringBuffer, setErrorMode);
PHP_METHOD(Xpl_StringBuffer, error);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, encoding)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_pos, 0, 0, 1)
	ZEND_ARG_INFO(0, needle)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_rpos, 0, 0, 1)
	ZEND_ARG_INFO(0, needle)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_ipos, 0, 0, 1)
	ZEND_ARG_INFO(0, needle)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_ripos, 0, 0, 1)
	ZEND_ARG_INFO(0, needle)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_rchr, 0, 0, 1)
	ZEND_ARG_INFO(0, needle)
	ZEND_ARG_INFO(0, part)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_startswith, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, caseInsensitive)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_endswith, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, caseInsensitive)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_filter, 0, 0, 1)
	ZEND_ARG_INFO(0, filterType)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_chunk, 0, 0, 1)
	ZEND_ARG_INFO(0, position)
	ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_at, 0, 0, 1)
	ZEND_ARG_INFO(0, position)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_first, 0, 0, 0)
	ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_last, 0, 0, 0)
	ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_toarray, 0, 0, 0)
	ZEND_ARG_INFO(0, chunkSize)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_split, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, limit)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, newval)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer___get, 0, 0, 1)
	ZEND_ARG_INFO(0, variable)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer___call, 0, 0, 2)
	ZEND_ARG_INFO(0, func)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_set, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_setencoding, 0, 0, 1)
	ZEND_ARG_INFO(0, encoding)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_prepend, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_append, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_wrap, 0, 0, 2)
	ZEND_ARG_INFO(0, before)
	ZEND_ARG_INFO(0, after)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_trim, 0, 0, 0)
	ZEND_ARG_INFO(0, charlist)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_ltrim, 0, 0, 0)
	ZEND_ARG_INFO(0, charlist)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_rtrim, 0, 0, 0)
	ZEND_ARG_INFO(0, charlist)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_sub, 0, 0, 1)
	ZEND_ARG_INFO(0, start)
	ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_str, 0, 0, 1)
	ZEND_ARG_INFO(0, needle)
	ZEND_ARG_INFO(0, before_needle)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_replace, 0, 0, 2)
	ZEND_ARG_INFO(0, search)
	ZEND_ARG_INFO(0, replace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_ireplace, 0, 0, 2)
	ZEND_ARG_INFO(0, search)
	ZEND_ARG_INFO(0, replace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_pad, 0, 0, 1)
	ZEND_ARG_INFO(0, length)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_sanitize, 0, 0, 0)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_entities, 0, 0, 0)
	ZEND_ARG_INFO(0, flags)
	ZEND_ARG_INFO(0, charset)
	ZEND_ARG_INFO(0, double_encode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_entitydecode, 0, 0, 0)
	ZEND_ARG_INFO(0, flags)
	ZEND_ARG_INFO(0, charset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_specialchars, 0, 0, 0)
	ZEND_ARG_INFO(0, flags)
	ZEND_ARG_INFO(0, charset)
	ZEND_ARG_INFO(0, double_encode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_specialcharsdecode, 0, 0, 0)
	ZEND_ARG_INFO(0, flags)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_convertencoding, 0, 0, 1)
	ZEND_ARG_INFO(0, to_encoding)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_convertcase, 0, 0, 1)
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_md5, 0, 0, 0)
	ZEND_ARG_INFO(0, raw_output)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_sha1, 0, 0, 0)
	ZEND_ARG_INFO(0, raw_output)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_hash, 0, 0, 1)
	ZEND_ARG_INFO(0, algo)
	ZEND_ARG_INFO(0, raw_output)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_hashhmac, 0, 0, 2)
	ZEND_ARG_INFO(0, algo)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, raw_output)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_containschars, 0, 0, 1)
	ZEND_ARG_INFO(0, charList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_sethtmlentitiesflags, 0, 0, 1)
	ZEND_ARG_INFO(0, flags)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_seterrormode, 0, 0, 1)
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_stringbuffer_error, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_stringbuffer_method_entry) {
	PHP_ME(Xpl_StringBuffer, __construct, arginfo_xpl_stringbuffer___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Xpl_StringBuffer, length, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, len, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, pos, arginfo_xpl_stringbuffer_pos, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, rpos, arginfo_xpl_stringbuffer_rpos, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, ipos, arginfo_xpl_stringbuffer_ipos, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, ripos, arginfo_xpl_stringbuffer_ripos, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, rchr, arginfo_xpl_stringbuffer_rchr, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, startsWith, arginfo_xpl_stringbuffer_startswith, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, endsWith, arginfo_xpl_stringbuffer_endswith, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, detectEncoding, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, filter, arginfo_xpl_stringbuffer_filter, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, get, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, getOriginal, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, isChanged, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, chunk, arginfo_xpl_stringbuffer_chunk, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, at, arginfo_xpl_stringbuffer_at, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, first, arginfo_xpl_stringbuffer_first, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, last, arginfo_xpl_stringbuffer_last, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, toArray, arginfo_xpl_stringbuffer_toarray, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, split, arginfo_xpl_stringbuffer_split, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, offsetGet, arginfo_xpl_stringbuffer_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, offsetExists, arginfo_xpl_stringbuffer_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, offsetSet, arginfo_xpl_stringbuffer_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, offsetUnset, arginfo_xpl_stringbuffer_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, __get, arginfo_xpl_stringbuffer___get, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, __call, arginfo_xpl_stringbuffer___call, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, set, arginfo_xpl_stringbuffer_set, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, setEncoding, arginfo_xpl_stringbuffer_setencoding, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, restore, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, prepend, arginfo_xpl_stringbuffer_prepend, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, append, arginfo_xpl_stringbuffer_append, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, wrap, arginfo_xpl_stringbuffer_wrap, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, trim, arginfo_xpl_stringbuffer_trim, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, ltrim, arginfo_xpl_stringbuffer_ltrim, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, rtrim, arginfo_xpl_stringbuffer_rtrim, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, sub, arginfo_xpl_stringbuffer_sub, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, str, arginfo_xpl_stringbuffer_str, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, replace, arginfo_xpl_stringbuffer_replace, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, ireplace, arginfo_xpl_stringbuffer_ireplace, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, pad, arginfo_xpl_stringbuffer_pad, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, sanitize, arginfo_xpl_stringbuffer_sanitize, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, entities, arginfo_xpl_stringbuffer_entities, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, entityDecode, arginfo_xpl_stringbuffer_entitydecode, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, specialChars, arginfo_xpl_stringbuffer_specialchars, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, specialCharsDecode, arginfo_xpl_stringbuffer_specialcharsdecode, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, convertEncoding, arginfo_xpl_stringbuffer_convertencoding, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, convertCase, arginfo_xpl_stringbuffer_convertcase, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, upper, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, lower, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, ucwords, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, ucfirst, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, lcfirst, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, md5, arginfo_xpl_stringbuffer_md5, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, sha1, arginfo_xpl_stringbuffer_sha1, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, hash, arginfo_xpl_stringbuffer_hash, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, hashHmac, arginfo_xpl_stringbuffer_hashhmac, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, isAlnum, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, isAlpha, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, isUpper, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, isLower, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, isPrintable, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, isControl, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, isDigit, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, containsChars, arginfo_xpl_stringbuffer_containschars, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_StringBuffer, setHtmlEntitiesFlags, arginfo_xpl_stringbuffer_sethtmlentitiesflags, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_StringBuffer, getHtmlEntitiesFlags, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_StringBuffer, setErrorMode, arginfo_xpl_stringbuffer_seterrormode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_StringBuffer, error, arginfo_xpl_stringbuffer_error, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
