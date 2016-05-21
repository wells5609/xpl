
extern zend_class_entry *xpl_math_ce;

ZEPHIR_INIT_CLASS(Xpl_Math);

PHP_METHOD(Xpl_Math, add);
PHP_METHOD(Xpl_Math, subtract);
PHP_METHOD(Xpl_Math, sub);
PHP_METHOD(Xpl_Math, multiply);
PHP_METHOD(Xpl_Math, mul);
PHP_METHOD(Xpl_Math, divide);
PHP_METHOD(Xpl_Math, div);
PHP_METHOD(Xpl_Math, pow);
PHP_METHOD(Xpl_Math, sqrt);
PHP_METHOD(Xpl_Math, filterNumeric);
PHP_METHOD(Xpl_Math, sum);
PHP_METHOD(Xpl_Math, arraySum);
PHP_METHOD(Xpl_Math, count);
PHP_METHOD(Xpl_Math, mean);
PHP_METHOD(Xpl_Math, median);
PHP_METHOD(Xpl_Math, sumxy);
PHP_METHOD(Xpl_Math, sos);
PHP_METHOD(Xpl_Math, variance);
PHP_METHOD(Xpl_Math, stddev);
PHP_METHOD(Xpl_Math, covariance);
PHP_METHOD(Xpl_Math, correlation);
PHP_METHOD(Xpl_Math, pv);
PHP_METHOD(Xpl_Math, npv);
PHP_METHOD(Xpl_Math, weightedAvg);
PHP_METHOD(Xpl_Math, pct);
PHP_METHOD(Xpl_Math, pctChange);
PHP_METHOD(Xpl_Math, pctChangeArray);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_math_add, 0, 0, 2)
	ZEND_ARG_INFO(0, left)
	ZEND_ARG_INFO(0, right)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_math_subtract, 0, 0, 2)
	ZEND_ARG_INFO(0, left)
	ZEND_ARG_INFO(0, right)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_math_sub, 0, 0, 2)
	ZEND_ARG_INFO(0, left)
	ZEND_ARG_INFO(0, right)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_math_multiply, 0, 0, 2)
	ZEND_ARG_INFO(0, left)
	ZEND_ARG_INFO(0, right)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_math_mul, 0, 0, 2)
	ZEND_ARG_INFO(0, left)
	ZEND_ARG_INFO(0, right)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_math_divide, 0, 0, 2)
	ZEND_ARG_INFO(0, left)
	ZEND_ARG_INFO(0, right)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_math_div, 0, 0, 2)
	ZEND_ARG_INFO(0, left)
	ZEND_ARG_INFO(0, right)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_math_pow, 0, 0, 2)
	ZEND_ARG_INFO(0, left)
	ZEND_ARG_INFO(0, right)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_math_sqrt, 0, 0, 1)
	ZEND_ARG_INFO(0, operand)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_math_filternumeric, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, numbers, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_math_sum, 0, 0, 1)
	ZEND_ARG_INFO(0, left)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_math_arraysum, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_math_count, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_math_mean, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_math_median, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, vals, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_math_sumxy, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, x_values, 0)
	ZEND_ARG_ARRAY_INFO(0, y_values, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_math_sos, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
	ZEND_ARG_INFO(0, values2)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_math_variance, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
	ZEND_ARG_INFO(0, is_sample)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_math_stddev, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
	ZEND_ARG_INFO(0, sample)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_math_covariance, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, x_values, 0)
	ZEND_ARG_ARRAY_INFO(0, y_values, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_math_correlation, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, x_values, 0)
	ZEND_ARG_ARRAY_INFO(0, y_values, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_math_pv, 0, 0, 2)
	ZEND_ARG_INFO(0, cashflow)
	ZEND_ARG_INFO(0, rate)
	ZEND_ARG_INFO(0, period)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_math_npv, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, cashflows, 0)
	ZEND_ARG_INFO(0, rate)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_math_weightedavg, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
	ZEND_ARG_ARRAY_INFO(0, weights, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_math_pct, 0, 0, 2)
	ZEND_ARG_INFO(0, portion)
	ZEND_ARG_INFO(0, total)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_math_pctchange, 0, 0, 2)
	ZEND_ARG_INFO(0, current)
	ZEND_ARG_INFO(0, previous)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_math_pctchangearray, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, vals, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_math_method_entry) {
	PHP_ME(Xpl_Math, add, arginfo_xpl_math_add, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Math, subtract, arginfo_xpl_math_subtract, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Math, sub, arginfo_xpl_math_sub, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Math, multiply, arginfo_xpl_math_multiply, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Math, mul, arginfo_xpl_math_mul, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Math, divide, arginfo_xpl_math_divide, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Math, div, arginfo_xpl_math_div, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Math, pow, arginfo_xpl_math_pow, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Math, sqrt, arginfo_xpl_math_sqrt, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Math, filterNumeric, arginfo_xpl_math_filternumeric, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Math, sum, arginfo_xpl_math_sum, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Math, arraySum, arginfo_xpl_math_arraysum, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Math, count, arginfo_xpl_math_count, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Math, mean, arginfo_xpl_math_mean, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Math, median, arginfo_xpl_math_median, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Math, sumxy, arginfo_xpl_math_sumxy, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Math, sos, arginfo_xpl_math_sos, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Math, variance, arginfo_xpl_math_variance, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Math, stddev, arginfo_xpl_math_stddev, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Math, covariance, arginfo_xpl_math_covariance, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Math, correlation, arginfo_xpl_math_correlation, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Math, pv, arginfo_xpl_math_pv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Math, npv, arginfo_xpl_math_npv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Math, weightedAvg, arginfo_xpl_math_weightedavg, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Math, pct, arginfo_xpl_math_pct, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Math, pctChange, arginfo_xpl_math_pctchange, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Xpl_Math, pctChangeArray, arginfo_xpl_math_pctchangearray, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
