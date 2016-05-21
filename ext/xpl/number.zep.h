
extern zend_class_entry *xpl_number_ce;

ZEPHIR_INIT_CLASS(Xpl_Number);

PHP_METHOD(Xpl_Number, __construct);
PHP_METHOD(Xpl_Number, getPrecision);
PHP_METHOD(Xpl_Number, setPrecision);
PHP_METHOD(Xpl_Number, asFloat);
PHP_METHOD(Xpl_Number, asDouble);
PHP_METHOD(Xpl_Number, asInt);
PHP_METHOD(Xpl_Number, asInteger);
PHP_METHOD(Xpl_Number, asString);
PHP_METHOD(Xpl_Number, __toString);
PHP_METHOD(Xpl_Number, safe);
PHP_METHOD(Xpl_Number, display);
PHP_METHOD(Xpl_Number, format);
PHP_METHOD(Xpl_Number, cmp);
PHP_METHOD(Xpl_Number, equals);
PHP_METHOD(Xpl_Number, add);
PHP_METHOD(Xpl_Number, sub);
PHP_METHOD(Xpl_Number, mul);
PHP_METHOD(Xpl_Number, div);
PHP_METHOD(Xpl_Number, pow);
PHP_METHOD(Xpl_Number, sqrt);
PHP_METHOD(Xpl_Number, create);
PHP_METHOD(Xpl_Number, cast);
PHP_METHOD(Xpl_Number, isMixedNumber);
PHP_METHOD(Xpl_Number, newInstance);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_number___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, number)
	ZEND_ARG_INFO(0, precision)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_number_setprecision, 0, 0, 1)
	ZEND_ARG_INFO(0, digits)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_number_format, 0, 0, 1)
	ZEND_ARG_INFO(0, decimals)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_number_cmp, 0, 0, 1)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_number_equals, 0, 0, 1)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_number_add, 0, 0, 1)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_number_sub, 0, 0, 1)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_number_mul, 0, 0, 1)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_number_div, 0, 0, 1)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_number_pow, 0, 0, 1)
	ZEND_ARG_INFO(0, exponent)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_number_create, 0, 0, 1)
	ZEND_ARG_INFO(0, number)
	ZEND_ARG_INFO(0, precision)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_number_cast, 0, 0, 1)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_number_ismixednumber, 0, 0, 1)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_number_newinstance, 0, 0, 1)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_number_method_entry) {
	PHP_ME(Xpl_Number, __construct, arginfo_xpl_number___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Xpl_Number, getPrecision, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Number, setPrecision, arginfo_xpl_number_setprecision, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Number, asFloat, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Number, asDouble, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Number, asInt, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Number, asInteger, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Number, asString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Number, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Number, safe, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Number, display, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Number, format, arginfo_xpl_number_format, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Number, cmp, arginfo_xpl_number_cmp, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Number, equals, arginfo_xpl_number_equals, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Number, add, arginfo_xpl_number_add, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Number, sub, arginfo_xpl_number_sub, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Number, mul, arginfo_xpl_number_mul, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Number, div, arginfo_xpl_number_div, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Number, pow, arginfo_xpl_number_pow, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Number, sqrt, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Xpl_Number, create, arginfo_xpl_number_create, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Number, cast, arginfo_xpl_number_cast, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Number, isMixedNumber, arginfo_xpl_number_ismixednumber, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Number, newInstance, arginfo_xpl_number_newinstance, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
