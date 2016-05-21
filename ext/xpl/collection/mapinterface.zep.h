
extern zend_class_entry *xpl_collection_mapinterface_ce;

ZEPHIR_INIT_CLASS(Xpl_Collection_MapInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_mapinterface_indexof, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_collection_mapinterface_method_entry) {
	PHP_ABSTRACT_ME(Xpl_Collection_MapInterface, keys, NULL)
	PHP_ABSTRACT_ME(Xpl_Collection_MapInterface, values, NULL)
	PHP_ABSTRACT_ME(Xpl_Collection_MapInterface, indexOf, arginfo_xpl_collection_mapinterface_indexof)
	PHP_FE_END
};
