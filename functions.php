<?php
/**
* XPL core functions
* @package xpl
*/

/* ============ STRINGS ============ */

/**
* Returns true if $haystack starts with $needle.
*/
function str_startswith( $haystack, $needle ) {
	return 0 === strpos( $haystack, $needle );
}

/**
* Returns true if $haystack ends $needle.
*/
function str_endswith( $haystack, $needle ) {
	return $needle === substr( $haystack, -strlen($needle) );
}

/**
* Returns true if $needle is found in $haystack.
*/
function str_in( $haystack, $needle ) {
	return false !== strpos( $haystack, $needle );
}

/**
* Strips unescaped unicode characters (e.g. u00a0). 
* @uses mb_convert_encoding
*/
function str_stripunicode( $str ){
	return stripcslashes( preg_replace( '/\\\\u([0-9a-f]{4})/i', '', mb_convert_encoding($str, 'UTF-8') ) );
}

/**
* Formats string in camelCase.
*/
function str_tocamel( $string, $ignore = '' ){
	$string = trim( str_replace(array('-','_','\\','.'), ' ', $string) );
	$string = ucwords( strtolower($string) );
	if ( !empty($ignore) ){
		// revert strings in $ignore back to original
		foreach((array)$ignore as $i){
			$string = str_replace( ucwords( strtolower($i) ), $i, $string );
		}
	}
	return str_replace(' ', '', $string);
}

/**
* Returns string as slug with specified word separator.
*/
function str_toslug( $string, $sep = '_' ) {
	$string = trim( preg_replace('/[A-Z]/', ' $0', $string) );
	return str_replace( ' ', $sep, strtolower($string) );
}

/**
* Generate a random string from one of several of character pools.
*
* @param int $length Length of the returned random string (default 16)
* @param string $type The type of characters to use to generate string.
* @return string A random string
*/
function str_rand( $length = 16, $pool_type = STR_RAND_ALNUM ){
	$str = '';
	switch ( $pool_type ) {
		case 'alpha':
			$pool = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
			break;
		case 'alnum':
		case 'alphanumeric':
		default:
			$pool = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
			break;
		case 'numeric':
		case 'num':
			$pool = '0123456789';
			break;
		case 'nonzero':
			$pool = '123456789';
			break;
		case 'distinct':
			$pool = '2345679ACDEFHJKLMNPRSTUVWXYZ';
			break;
		case 'hexdec':
		case 'hexadecimal':
			$pool = '0123456789abcdef';
			break;
		case 'punc':
			$pool = '~!@#$%^&*()_-+=[]{};:,<.>/?|';
			break;
		case 'complex':
			$pool = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ~!@#$%^&*()_-+=[]{};:,<.>/?|';
			break;
	}
	for ( $i=0; $i < $length; $i++ ){
		$str .= substr( $pool, mt_rand(0, strlen($pool) - 1), 1 );
	}
	return $str;	
}

/**
* Formats a number by injecting non-numeric characters in a specified
* format into the string in the positions they appear in the format.
*
* @param string The string to format
* @param string The format to apply
* @return string Formatted number
*/
function str_format( $string, $format ){
	// remove any pre-existing formatting characters
	$string = str_replace(array('(',')','+','-',' '), '', $string);
	$result = ''; $fpos = 0; $spos = 0;
	$const = 'STR_FORMAT_' . strtoupper($format) . '_' . strlen($string);
	
	if ( !defined($const) )
		return $string;
	
	$format = constant($const);
		
	while ( (strlen($format) - 1) >= $fpos ){
		if ( ctype_alnum(substr($format, $fpos, 1)) ){
			$result .= substr($string, $spos, 1);
			$spos++;
		} else {
			$result .= substr($format, $fpos, 1);
		}
		$fpos++;
	}
	
	return $result;	
}

/** 
* Returns 1st occurance of text between two strings. 
* The "between" strings are not included in output.
*/
function str_between($source, $str_start, $str_end){
	$str1 = explode($str_start,$source);
	$str2 = explode($str_end,$str1[1]);
	return trim($str2[0]);
}

/**
* Returns pretty-printed JSON string.
*/
function json_prettyprint( $json ){
	$tab = " ";
	$new_json = "";
	$indent_level = 0;
	$in_string = false;
	$len = strlen($json);
	for ( $c = 0; $c < $len; $c++ ){
		$char = $json[$c];
		switch ($char){
			case '{':
			case '[':
				if ( !$in_string ){
					$new_json .= $char . "\n" . str_repeat($tab, $indent_level+1);
					$indent_level++;
				} else {
					$new_json .= $char;
				}
				break;
			case '}':
			case ']':
				if ( !$in_string ) {
					$indent_level--;
					$new_json .= "\n" . str_repeat($tab, $indent_level) . $char;
				} else {
					$new_json .= $char;
				}
				break;
			case ',':
				if ( !$in_string ){
					$new_json .= ",\n" . str_repeat($tab, $indent_level);
				} else {
					$new_json .= $char;
				}
				break;
			case ':':
				if ( !$in_string ){
					$new_json .= ": ";
				} else {
					$new_json .= $char;
				}
				break;
			case '"':
				if ($c > 0 && $json[$c-1] != '\\'){
					$in_string = !$in_string;
				}
			default:
				$new_json .= $char;
				break;                                        
		}
	}
	return $new_json;	
}


/* ============ CONSTANTS ============ */

/**
* Defines a constant if undefined.
* Returns the constant value in either case.
* Shortcut for: if (!defined($X)) define($X); return constant($X);
*
* @param string $constant The constant's name
* @param mixed $default Value to set if constant not defined
* @return mixed Value of constant
*/ 
function define_default( $constant, $default ){
	
	if ( !defined($constant) ){
		define($constant, $default);
	}
}


/* ============ PATHS, URLS ============ */

/**
* Base64 encode data safe for URLs.
*/
function base64_encode_urlsafe( $data ){
	
	$b64 = base64_encode($data);
    
	return str_replace(
        array('+', '/', '\r', '\n', '='),
        array('-', '_'),
        $b64
    );	
}

/**
* Decode a URL-safe base64-encoded string.
*/
function base64_decode_urlsafe( $b64 ){
    
	$b64 = str_replace(
        array('-', '_'),
        array('+', '/'),
        $b64
    );
    
	return base64_decode($b64);
}

/**
* Makes double slashes and backslashes (win32) into forward slashes
*/
function normalizepath($path){
	
	return rtrim( str_replace(
		array('http:/', 'https:/'),
		array('http://', 'https://'),
		str_replace(array('//', '\\'), '/', $path)
	), '/' );
}

/**
* Returns file extension if exists, otherwise false.
*/
function pathinfo_extension($path){
	
	$ext = pathinfo(rtrim($path, '/\\'), PATHINFO_EXTENSION);
	return $ext ? $ext : false;	
}

/**
* Using pathinfo() and PATHINFO_FILENAME will return the directory name if 
* path is not a file. We do not want this behavior.
*/
function pathinfo_filename($path){
	
	if ( ! pathinfo_extension($path) ){
		return false;
	}
	
	return pathinfo(rtrim($path, '/\\'), PATHINFO_FILENAME);	
}

/**
* Returns URL to given file or directory path.
*/
function url( $path = '', $protocol = 'http' ){
	
	if ( empty($path) ){
		$path = $_SERVER['REQUEST_URI'];
	}

	$path = normalizepath( $path );
	$url = normalizepath( $_SERVER['HTTP_HOST'] );
	
	if ( $pos = strpos($path, $url) ){
		$url = trim( substr($path, $pos), '/' );
	} else {
		$url .= '/' . trim( $path, '/' );	
	}
	
	if ( false === $protocol ){
		return $url;
	} elseif ( is_ssl() ) {
		$protocol .= 's';
	}
	
	$url = rtrim($protocol, ':/') . '://' . trim($url, '/');
	
	if ( false === pathinfo_extension($url) ){
		$url .= '/';
	}
	
	return $url;
}

/**
* Returns directory URL to $path, a file or dir path. 
* @uses dirname()
*/
function dirurl( $path, $protocol = 'http' ){
	
	$url = url($path, $protocol);
	if ( false !== pathinfo_extension($path) ){
		$url = dirname($url) . '/';
	}
	return $url;
}

/**
* Returns Xpl_Directory object
*/
function dir_object( $directory ){
	
	return new XplDirectory( $directory );	
}

/**
* Returns array of file paths in $directory matching $pattern
*/	
function get_files( $directory, $pattern = "*.php" ){
	
	return dir_object( $directory )->files( $pattern );
}

/**
* Includes files in $dir (string or array) matching $pattern. Optionally recursive.
*/
function include_files( $dir, $pattern = "*.php", $recursive = false ){
	
	if ( is_array($dir) ){
		foreach($dir as $path){
			include_files($path, $pattern, $recursive);
		}
		return;
	} elseif ( !is_dir($dir) ){
		return false;
	}
	
	return dir_object($dir)->includeFiles( $pattern, $recursive );
}

function include_files_recursive( $dir, $pattern = "*.php" ){
	return include_files( $dir, $pattern, true );	
}

/**
* Includes a file at given path if it exists.
*/
function maybe_include( $path ){
	
	if ( file_exists( $path ) ){
		include_once $path;
		return true;
	}
	
	return false;
}

/**
* Register a class or paths to autoload.
*/
function autoload( $class, $path, $prepend = false, $autoloader = null ){
	
	if ( null === $autoloader ){
		$Autoloader = XplAutoloader::instance();
	} elseif ( $autoloader instanceof XplAutoloader ){
		$Autoloader =& $autoloader;
	} elseif ( is_string($autoloader) ){
		$Autoloader = XplAutoloader::instance( $autoloader );	
	} else {
		throw new Exception('Parameter $autoloader must be string or instance of XplAutoloader.');
	}
	
	if ( $class && is_string($path) && pathinfo_extension($path) ){
		$Autoloader->addClass($class, $path);
	}
	else {
		if ( !is_array($path) ) $path = array($path);
		$Autoloader->addPaths($class, $path, $prepend);
	}
}


/* ============ XML ============ */

/**
* Creates a new XML document. Returns string.
*/
function xml_write_document( array $data, $root_tag = 'document' ){
	$xml = new XMLWriter();
	$xml->openMemory();
	$xml->startDocument('1.0', 'UTF-8');
	$xml->startElement( $root_tag );
	xml_write_element( $xml, $data );
	$xml->endElement();
	$xml->endDocument();
	return $xml->outputMemory(true);
}

/**
* Creates an XML element string using XMLWriter object.
*/
function xml_write_element( XMLWriter $xml, array $data ){
	
	foreach($data as $key => $value){
		
		if ( preg_match('/(\d+)/',$key) ){
			 $key = 'key_'.$key;
		}
		
		$key = strip_tags( str_replace( array(' ','-','/','\\'), '_', $key ) );
		
		if ( is_object( $value ) ){
			$value = get_object_vars( $value );
		}
				
		if ( is_array( $value ) ){
			
			if ( isset( $value['tag'] ) && is_string( $value['tag'] ) ){
				$key = str_replace( ' ', '', $value['tag'] );
				unset( $value['tag'] );
			}
			
			$xml->startElement( $key );
			
			if ( isset( $value['attributes'] ) ){
				foreach( array_unique( $value['attributes'] ) as $k => $v ){
					$xml->writeAttribute( $k, $v );
				}
				unset( $value['attributes'] );
			}
			
			xml_write_element( $xml, $value );
			
			$xml->endElement();
			
		} else {
			$xml->writeElement( $key, $value );
		}
	}
}


/* ============ HTTP HEADERS ============ */

if ( ! function_exists('get_request_headers') ){

/** 
* Returns HTTP request headers as array.
*/
	function get_request_headers(){
		
		if ( defined('REQUEST_HEADERS_FUNC') ){
			$func = REQUEST_HEADERS_FUNC;
			$headers = $func();
		}
		else { // Manual labor
			$headers = array();
			$misfits = array('CONTENT_TYPE', 'CONTENT_LENGTH', 'CONTENT_MD5', 'PHP_AUTH_USER', 'PHP_AUTH_PW', 'PHP_AUTH_DIGEST', 'AUTH_TYPE');
			foreach ( $_SERVER as $key => $value ) {
				if ( 0 === strpos($key, 'HTTP_') ){
					$headers[$key] = $value;
				} elseif ( in_array($key, $misfits) ){
					$headers[$key] = $value;
				}
			}
		}
		
		// Normalize header keys
		$the_headers = array();
		foreach ( $headers as $key => $value ) {
			$key = str_replace( 'http-', '', str_replace( '_', '-', strtolower($key) ) );
			$the_headers[ $key ] = $value;
		}
		
		return $the_headers;
	}

}

if ( ! function_exists('get_request_header') ){
	
/**
* Returns a single HTTP request header if set.
*/
	function get_request_header( $name ){
		
		$headers = get_request_headers();
		$name = str_replace( '_', '-', strtolower($name) );
		return isset( $headers[ $name ] ) ? $headers[ $name ] : null;
	}

}


/* ============ Helpers/Fallbacks ============ */

if ( !function_exists('fnmatch') ){

/** fnmatch
*
* fnmatch() is not available on non-POSIX compliant systems (except Windows PHP>5.3).
* @link http://www.php.net/manual/en/function.fnmatch.php
*
* @param string $pattern Shell wildcard pattern to match.
* @param string $string String in which to search for match.
* @param int $flags FNM_* constant flags
* @return boolean Whether match found in string.
*/
	define('FNM_PATHNAME', 1);
	define('FNM_NOESCAPE', 2);
	define('FNM_PERIOD', 4);
	define('FNM_CASEFOLD', 16);
	
	function fnmatch( $pattern, $string, $flags = 0 ){
		
		$modifiers = null;
	 	$transforms = array(
			'\*'	=> '.*',
			'\?'	=> '.',
			'\[\!'	=> '[^',
			'\['	=> '[',
			'\]'	=> ']',
			'\.'	=> '\.',
			'\\'	=> '\\\\'
		);
	   
		// Forward slash in string must be in pattern:
		if ($flags & FNM_PATHNAME)
			$transforms['\*'] = '[^/]*';
		
	    // Back slash should not be escaped:
		if ($flags & FNM_NOESCAPE)
			unset($transforms['\\']);
		
	    // Perform case insensitive match:
		if ($flags & FNM_CASEFOLD)
			$modifiers .= 'i';
		
	    // Period at start must be the same as pattern:
		if ($flags & FNM_PERIOD)
			if (strpos($string, '.') === 0 && strpos($pattern, '.') !== 0) return false;
	   
		$pattern = '#^' . strtr(preg_quote($pattern, '#'), $transforms) . '$#' . $modifiers;
	   
		return (boolean) preg_match($pattern, $string); 
	}
}

// Stolen from WordPress
if ( !function_exists('is_ssl') ){

	function is_ssl() {
		if ( isset($_SERVER['HTTPS']) ) {
			if ( 'on' == strtolower($_SERVER['HTTPS']) )
				return true;
			if ( '1' == $_SERVER['HTTPS'] )
				return true;
		} elseif ( isset($_SERVER['SERVER_PORT']) && ( '443' == $_SERVER['SERVER_PORT'] ) ) {
			return true;
		}
		return false;
	}	
}