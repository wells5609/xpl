
extern zend_class_entry *xpl_collection_queueinterface_ce;

ZEPHIR_INIT_CLASS(Xpl_Collection_QueueInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_xpl_collection_queueinterface_enqueue, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(xpl_collection_queueinterface_method_entry) {
	PHP_ABSTRACT_ME(Xpl_Collection_QueueInterface, enqueue, arginfo_xpl_collection_queueinterface_enqueue)
	PHP_ABSTRACT_ME(Xpl_Collection_QueueInterface, dequeue, NULL)
	PHP_FE_END
};
