
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "xpl.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *xpl_arrayable_ce;
zend_class_entry *xpl_collection_ce;
zend_class_entry *xpl_collection_listinterface_ce;
zend_class_entry *xpl_cache_driverinterface_ce;
zend_class_entry *xpl_collection_mapinterface_ce;
zend_class_entry *xpl_collection_setinterface_ce;
zend_class_entry *xpl_serializer_serializer_ce;
zend_class_entry *xpl_collection_queueinterface_ce;
zend_class_entry *xpl_collection_stackinterface_ce;
zend_class_entry *xpl_configurableinterface_ce;
zend_class_entry *xpl_cache_cacheawareinterface_ce;
zend_class_entry *xpl_comparator_ce;
zend_class_entry *xpl_http_middlewareinterface_ce;
zend_class_entry *xpl_readonlyinterface_ce;
zend_class_entry *xpl_sortable_ce;
zend_class_entry *xpl_cache_driver_abstractdriver_ce;
zend_class_entry *xpl_collection_abstractbasecollection_ce;
zend_class_entry *xpl_number_ce;
zend_class_entry *xpl_cache_exception_ce;
zend_class_entry *xpl_collection_queue_ce;
zend_class_entry *xpl_0__closure_ce;
zend_class_entry *xpl_1__closure_ce;
zend_class_entry *xpl_apcu_ce;
zend_class_entry *xpl_base64url_ce;
zend_class_entry *xpl_cache_cache_ce;
zend_class_entry *xpl_cache_driver_apcdriver_ce;
zend_class_entry *xpl_cache_driver_apcudriver_ce;
zend_class_entry *xpl_cache_driver_memorydriver_ce;
zend_class_entry *xpl_cache_driver_xcachedriver_ce;
zend_class_entry *xpl_cache_invalidargumentexception_ce;
zend_class_entry *xpl_cache_item_ce;
zend_class_entry *xpl_cache_itempool_ce;
zend_class_entry *xpl_classloader_ce;
zend_class_entry *xpl_classutil_ce;
zend_class_entry *xpl_collection_arrayobject_ce;
zend_class_entry *xpl_collection_config_ce;
zend_class_entry *xpl_collection_map_ce;
zend_class_entry *xpl_collection_objectset_ce;
zend_class_entry *xpl_collection_scalarset_ce;
zend_class_entry *xpl_collection_sequence_ce;
zend_class_entry *xpl_collection_set_ce;
zend_class_entry *xpl_collection_stack_ce;
zend_class_entry *xpl_configurable_ce;
zend_class_entry *xpl_csv_ce;
zend_class_entry *xpl_date_ce;
zend_class_entry *xpl_enum_ce;
zend_class_entry *xpl_event_event_ce;
zend_class_entry *xpl_event_listener_ce;
zend_class_entry *xpl_event_manager_ce;
zend_class_entry *xpl_filesystem_container_ce;
zend_class_entry *xpl_html_ce;
zend_class_entry *xpl_htmlelement_ce;
zend_class_entry *xpl_http_middlewaredispatcher_ce;
zend_class_entry *xpl_http_middlewarequeue_ce;
zend_class_entry *xpl_json_ce;
zend_class_entry *xpl_math_ce;
zend_class_entry *xpl_money_ce;
zend_class_entry *xpl_namespacealias_ce;
zend_class_entry *xpl_object_ce;
zend_class_entry *xpl_outputbuffer_ce;
zend_class_entry *xpl_rate_ce;
zend_class_entry *xpl_serializer_igbinary_ce;
zend_class_entry *xpl_serializer_json_ce;
zend_class_entry *xpl_serializer_php_ce;
zend_class_entry *xpl_str_ce;
zend_class_entry *xpl_stream_ce;
zend_class_entry *xpl_stringbuffer_ce;
zend_class_entry *xpl_system_ce;
zend_class_entry *xpl_type_ce;
zend_class_entry *xpl_xml_ce;

ZEND_DECLARE_MODULE_GLOBALS(xpl)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(xpl)
{
#if PHP_VERSION_ID < 50500
	char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		size_t len = strlen(old_lc_all);
		char *tmp  = calloc(len+1, 1);
		if (UNEXPECTED(!tmp)) {
			return FAILURE;
		}

		memcpy(tmp, old_lc_all, len);
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif
	REGISTER_INI_ENTRIES();
	ZEPHIR_INIT(Xpl_Arrayable);
	ZEPHIR_INIT(Xpl_Collection);
	ZEPHIR_INIT(Xpl_Collection_ListInterface);
	ZEPHIR_INIT(Xpl_Cache_DriverInterface);
	ZEPHIR_INIT(Xpl_Collection_MapInterface);
	ZEPHIR_INIT(Xpl_Collection_SetInterface);
	ZEPHIR_INIT(Xpl_Serializer_Serializer);
	ZEPHIR_INIT(Xpl_Collection_QueueInterface);
	ZEPHIR_INIT(Xpl_Collection_StackInterface);
	ZEPHIR_INIT(Xpl_ConfigurableInterface);
	ZEPHIR_INIT(Xpl_Cache_CacheAwareInterface);
	ZEPHIR_INIT(Xpl_Comparator);
	ZEPHIR_INIT(Xpl_Http_MiddlewareInterface);
	ZEPHIR_INIT(Xpl_ReadOnlyInterface);
	ZEPHIR_INIT(Xpl_Sortable);
	ZEPHIR_INIT(Xpl_Cache_Driver_AbstractDriver);
	ZEPHIR_INIT(Xpl_Collection_AbstractBaseCollection);
	ZEPHIR_INIT(Xpl_Number);
	ZEPHIR_INIT(Xpl_Cache_Exception);
	ZEPHIR_INIT(Xpl_Collection_Queue);
	ZEPHIR_INIT(Xpl_Apcu);
	ZEPHIR_INIT(Xpl_Base64Url);
	ZEPHIR_INIT(Xpl_Cache_Cache);
	ZEPHIR_INIT(Xpl_Cache_Driver_ApcDriver);
	ZEPHIR_INIT(Xpl_Cache_Driver_ApcuDriver);
	ZEPHIR_INIT(Xpl_Cache_Driver_MemoryDriver);
	ZEPHIR_INIT(Xpl_Cache_Driver_XCacheDriver);
	ZEPHIR_INIT(Xpl_Cache_InvalidArgumentException);
	ZEPHIR_INIT(Xpl_Cache_Item);
	ZEPHIR_INIT(Xpl_Cache_ItemPool);
	ZEPHIR_INIT(Xpl_ClassLoader);
	ZEPHIR_INIT(Xpl_ClassUtil);
	ZEPHIR_INIT(Xpl_Collection_ArrayObject);
	ZEPHIR_INIT(Xpl_Collection_Config);
	ZEPHIR_INIT(Xpl_Collection_Map);
	ZEPHIR_INIT(Xpl_Collection_ObjectSet);
	ZEPHIR_INIT(Xpl_Collection_ScalarSet);
	ZEPHIR_INIT(Xpl_Collection_Sequence);
	ZEPHIR_INIT(Xpl_Collection_Set);
	ZEPHIR_INIT(Xpl_Collection_Stack);
	ZEPHIR_INIT(Xpl_Configurable);
	ZEPHIR_INIT(Xpl_Csv);
	ZEPHIR_INIT(Xpl_Date);
	ZEPHIR_INIT(Xpl_Enum);
	ZEPHIR_INIT(Xpl_Event_Event);
	ZEPHIR_INIT(Xpl_Event_Listener);
	ZEPHIR_INIT(Xpl_Event_Manager);
	ZEPHIR_INIT(Xpl_Filesystem_Container);
	ZEPHIR_INIT(Xpl_Html);
	ZEPHIR_INIT(Xpl_HtmlElement);
	ZEPHIR_INIT(Xpl_Http_MiddlewareDispatcher);
	ZEPHIR_INIT(Xpl_Http_MiddlewareQueue);
	ZEPHIR_INIT(Xpl_Json);
	ZEPHIR_INIT(Xpl_Math);
	ZEPHIR_INIT(Xpl_Money);
	ZEPHIR_INIT(Xpl_NamespaceAlias);
	ZEPHIR_INIT(Xpl_Object);
	ZEPHIR_INIT(Xpl_OutputBuffer);
	ZEPHIR_INIT(Xpl_Rate);
	ZEPHIR_INIT(Xpl_Serializer_Igbinary);
	ZEPHIR_INIT(Xpl_Serializer_Json);
	ZEPHIR_INIT(Xpl_Serializer_Php);
	ZEPHIR_INIT(Xpl_Str);
	ZEPHIR_INIT(Xpl_Stream);
	ZEPHIR_INIT(Xpl_StringBuffer);
	ZEPHIR_INIT(Xpl_System);
	ZEPHIR_INIT(Xpl_Type);
	ZEPHIR_INIT(Xpl_Xml);
	ZEPHIR_INIT(xpl_0__closure);
	ZEPHIR_INIT(xpl_1__closure);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(xpl)
{

	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_xpl_globals *xpl_globals TSRMLS_DC)
{
	xpl_globals->initialized = 0;

	/* Memory options */
	xpl_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	xpl_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	xpl_globals->cache_enabled = 1;

	/* Recursive Lock */
	xpl_globals->recursive_lock = 0;

	/* Static cache */
	memset(xpl_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);


}

static PHP_RINIT_FUNCTION(xpl)
{

	zend_xpl_globals *xpl_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(xpl_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);

	zephir_initialize_memory(xpl_globals_ptr TSRMLS_CC);

	zephir_init_static_properties_Xpl_ClassLoader(TSRMLS_C);
	zephir_init_static_properties_Xpl_ClassUtil(TSRMLS_C);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(xpl)
{

	

	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(xpl)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_XPL_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_XPL_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_XPL_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_XPL_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_XPL_ZEPVERSION);
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(xpl)
{
	php_zephir_init_globals(xpl_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(xpl)
{

}


zend_function_entry php_xpl_functions[] = {
ZEND_FE_END

};

zend_module_entry xpl_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_XPL_EXTNAME,
	php_xpl_functions,
	PHP_MINIT(xpl),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(xpl),
#else
	NULL,
#endif
	PHP_RINIT(xpl),
	PHP_RSHUTDOWN(xpl),
	PHP_MINFO(xpl),
	PHP_XPL_VERSION,
	ZEND_MODULE_GLOBALS(xpl),
	PHP_GINIT(xpl),
	PHP_GSHUTDOWN(xpl),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_XPL
ZEND_GET_MODULE(xpl)
#endif
