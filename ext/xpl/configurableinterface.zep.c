
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Xpl_ConfigurableInterface) {

	ZEPHIR_REGISTER_INTERFACE(Xpl, ConfigurableInterface, xpl, configurableinterface, xpl_configurableinterface_method_entry);

	return SUCCESS;

}

/**
 * Sets the object configuration.
 *
 * @param \Xpl\Collection\Config config
 */
ZEPHIR_DOC_METHOD(Xpl_ConfigurableInterface, setConfig);

/**
 * Returns the object configuration.
 *
 * @return \Xpl\Collection\Config
 */
ZEPHIR_DOC_METHOD(Xpl_ConfigurableInterface, getConfig);

