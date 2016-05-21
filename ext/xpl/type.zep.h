
extern zend_class_entry *xpl_type_ce;

ZEPHIR_INIT_CLASS(Xpl_Type);

PHP_METHOD(Xpl_Type, iterate);
PHP_METHOD(Xpl_Type, toArray);
PHP_METHOD(Xpl_Type, toObject);
PHP_METHOD(Xpl_Type, toArrays);
PHP_METHOD(Xpl_Type, toObjects);
PHP_METHOD(Xpl_Type, natcast);
PHP_METHOD(Xpl_Type, toBool);
PHP_METHOD(Xpl_Type, toScalar);
PHP_METHOD(Xpl_Type, toNumber);
PHP_METHOD(Xpl_Type, isMixedNumber);
PHP_METHOD(Xpl_Type, castNumericString);
PHP_METHOD(Xpl_Type, isScalarObject);
PHP_METHOD(Xpl_Type, objectToScalar);
PHP_METHOD(Xpl_Type, canStringCast);
PHP_METHOD(Xpl_Type, getDecimalPoint);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_type_iterate, 0, 0, 1)
	ZEND_ARG_INFO(0, argument)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_type_toarray, 0, 0, 1)
	ZEND_ARG_INFO(0, arg)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_type_toobject, 0, 0, 1)
	ZEND_ARG_INFO(0, arg)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_type_toarrays, 0, 0, 1)
	ZEND_ARG_INFO(0, arg)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_type_toobjects, 0, 0, 1)
	ZEND_ARG_INFO(0, arg)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_type_natcast, 0, 0, 1)
	ZEND_ARG_INFO(0, variable)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_type_tobool, 0, 0, 1)
	ZEND_ARG_INFO(0, arg)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_type_toscalar, 0, 0, 1)
	ZEND_ARG_INFO(0, arg)
	ZEND_ARG_INFO(0, flags)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_type_tonumber, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_type_ismixednumber, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_type_castnumericstring, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, allowNonNumeric)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_type_isscalarobject, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_type_objecttoscalar, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_type_canstringcast, 0, 0, 1)
	ZEND_ARG_INFO(0, variable)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_type_method_entry) {
	PHP_ME(Xpl_Type, iterate, arginfo_xpl_type_iterate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Type, toArray, arginfo_xpl_type_toarray, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Type, toObject, arginfo_xpl_type_toobject, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Type, toArrays, arginfo_xpl_type_toarrays, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Type, toObjects, arginfo_xpl_type_toobjects, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Type, natcast, arginfo_xpl_type_natcast, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Type, toBool, arginfo_xpl_type_tobool, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Type, toScalar, arginfo_xpl_type_toscalar, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Type, toNumber, arginfo_xpl_type_tonumber, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Type, isMixedNumber, arginfo_xpl_type_ismixednumber, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Type, castNumericString, arginfo_xpl_type_castnumericstring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Type, isScalarObject, arginfo_xpl_type_isscalarobject, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Type, objectToScalar, arginfo_xpl_type_objecttoscalar, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Type, canStringCast, arginfo_xpl_type_canstringcast, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Type, getDecimalPoint, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
