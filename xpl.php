<?php
/*
Plugin name: XPL
Description: x PHP Library
Author: wells
Version: 0.4.2
Provides: xpl
*/
define('XPL_VERSION', '0.4.2');

define('STR_RAND_ALPHA', 'alpha');
define('STR_RAND_ALNUM', 'alnum');
define('STR_RAND_NUM', 'num');
define('STR_RAND_NONZERO', 'nonzero');
define('STR_RAND_DISTINCT', 'distinct');
define('STR_RAND_HEXDEC', 'hexdec');
define('STR_RAND_PUNC', 'punc');
define('STR_RAND_COMPLEX', 'complex');
define('STR_FORMAT_PHONE_7', '000-0000');
define('STR_FORMAT_PHONE_10', '(000) 000-0000');
define('STR_FORMAT_PHONE_11', '+0 (000) 000-0000');
define('STR_FORMAT_PHONE_12', '+00 00 0000 0000');
define('STR_FORMAT_HASH_16', '00000000-0000-0000');
define('STR_FORMAT_HASH_24', '00000000-0000-0000-00000000');
define('STR_FORMAT_HASH_32', '00000000-0000-00000000-0000-00000000');
define('STR_FORMAT_HASH_40', '00000000-0000-0000-00000000-0000-0000-00000000');
define('STR_FORMAT_HASH_48', '00000000-0000-00000000-0000-0000-00000000-0000-00000000');

require 'functions.php';
require 'classes/XplAutoloader.php';
require 'classes/XplDirectory.php';
require 'classes/XplArrayObject.php';

// for PHP < 5.4
define_default('SCANDIR_SORT_DESCENDING', 1);	
define_default('SCANDIR_SORT_ASCENDING', 0);

// init
if ( function_exists('add_action') ){ // in WordPress
	add_action('plugins_loaded', 'xplPluginInit', 9);
} else {
	xplPluginInit();
}

function xplPluginInit(){
	
	if ( function_exists('apache_request_headers') ){
		define('REQUEST_HEADERS_FUNC', 'apache_request_headers');
	} elseif ( extension_loaded('http') ){
		define('REQUEST_HEADERS_FUNC', 'http_get_request_headers');
	}
	
	if ( defined('XPL_INCLUDE_PATH') ){
		
		autoload( false, XPL_INCLUDE_PATH, true );
		
		function xpl_get_include_path( $path = '' ){
			return XPL_INCLUDE_PATH . '/' . $path;
		}
	}
}

/**
* Xpl class
* @package xpl
*/
class Xpl {
	
	protected $functions = array(
		'core' => array('str_startswith', 'str_endswith', 'str_in', 'str_stripunicode', 'str_tocamel', 'str_toslug', 'str_rand', 'str_format', 'str_between', 'json_prettyprint', 'define_default', 'normalizepath', 'pathinfo_extension', 'pathinfo_filename', 'url', 'dirurl', 'dir_object', 'get_files', 'include_files', 'include_files_recursive', 'maybe_include', 'autoload', 'xml_write_document', 'xml_write_element', 'get_request_headers', 'get_request_header'),
		'user' => array()
	);
	
	protected $constants = array(
		'core' => array('REQUEST_HEADERS_FUNC', 'STR_RAND_ALPHA', 'STR_RAND_ALNUM', 'STR_RAND_NUM', 'STR_RAND_NONZERO', 'STR_RAND_DISTINCT', 'STR_RAND_HEXDEC', 'STR_RAND_PUNC', 'STR_RAND_COMPLEX', 'STR_FORMAT_PHONE_7', 'STR_FORMAT_PHONE_10', 'STR_FORMAT_PHONE_11', 'STR_FORMAT_PHONE_12', 'STR_FORMAT_HASH_16', 'STR_FORMAT_HASH_24', 'STR_FORMAT_HASH_32', 'STR_FORMAT_HASH_40', 'STR_FORMAT_HASH_48'),
		'user' => array()
	);
	
	protected $classes = array(
		'core' => array('XplAutoloader', 'XplDirectory', 'XplArrayObject'),
		'user' => array()
	);
	
	static protected $_instance;
	
	static final function instance(){
		if ( !isset(self::$_instance) )
			self::$_instance = new self();
		return self::$_instance;
	}

	public function register( $type, $thing ){
		
		if ( !isset($this->$type) ){
			if (isset($this->{$type . 's'})) $type .= 's';
			else return false;
		}
		
		if ( !in_array($thing, $this->{$type}['user']) ){
			array_push($this->{$type}['user'], $thing);
		}
		
		return $this;
	}
	
	public function get( $type, $group = true ){
		
		if ( !isset($this->$type) ){
			if (isset($this->{$type . 's'})) $type .= 's';
			else return false;
		}
		
		if ( empty($group) ){
			return array_merge($this->{$type}['user'], $this->{$type}['core']);
		}
		
		if ( is_string($group) && isset($this->{$type}[$group]) ){
			return $this->{$type}[$group];	
		}
		
		return $this->$type;
	}
}

/** ======== XPL info functions ======== */

// Get XPL functions
function xpl_get_defined_functions(){
	return Xpl::instance()->get('functions');
}

// Get XPL constants
function xpl_get_defined_constants(){
	return Xpl::instance()->get('constants');
}

// Get XPL classes
function xpl_get_defined_classes(){
	return Xpl::instance()->get('classes');
}

/** ======== XPL register functions ======== */

// register a function
function xpl_register_user_func( $function ){
	Xpl::instance()->register('functions', $function);	
}

// register a constant
function xpl_register_user_constant( $const ){	
	Xpl::instance()->register('constants', $const);	
}

// register a class
function xpl_register_user_class( $class ){
	Xpl::instance()->register('classes', $class);	
}