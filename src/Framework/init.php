<?php

if (! isset($di)) {
	
	/** --------------------------------------------------------
	 * Create DI container if none exists.
	 * 
	 * @var xpl\Framework\DI
	 * ------------------------------------------------------ */
	$di = new xpl\Framework\DI;
}

/** --------------------------------------------------------
 * Set DI class facade.
 * 
 * The facade allows static access to one instance 
 * of the DI container.
 * ------------------------------------------------------ */
xpl\Framework\DiFacade::setInstance($di);

/** --------------------------------------------------------
 * Create an alias "xpl" for the facade.
 * 
 * The alias is used in the functions.php file below.
 * ------------------------------------------------------ */
class_alias('xpl\Framework\DiFacade', 'xpl');

/** --------------------------------------------------------
 * Include all xpl functions.
 * ------------------------------------------------------ */
require_once dirname(__DIR__).'/functions.php';
