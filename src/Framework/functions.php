<?php
/**
 * @package xpl/framework
 * 
 * Framework functions
 */
namespace xpl\Framework {
	class functions {
		// dummy class
	}
}

namespace {

/**
 * Whether XDebug is loaded and enabled.
 */
define('XDEBUG_ENABLED', extension_loaded('xdebug') && xdebug_is_enabled());

/**
 * Returns time elapsed since start of request.
 * 
 * @param int $decimals [Optional] Decimal precision. Default 4.
 * @param boolean $milliseconds [Optional] Return in milliseconds. Default false.
 * @return string Time elapsed, possibly in milliseconds.
 */
function xpl_time_index($decimals = 4, $milliseconds = false) {
	
	if (XDEBUG_ENABLED) {
		$time = xdebug_time_index();
	
	} else if (isset($_SERVER['REQUEST_TIME_FLOAT'])) {
		$time = microtime(true) - $_SERVER['REQUEST_TIME_FLOAT'];
	
	} else {
		return 'n/a';
	}
	
	return number_format(($milliseconds ? $time*1000 : $time), $decimals);
}

/**
 * Returns memory used by the script (or optionally the peak usage).
 * 
 * @param int $decimals [Optional] Decimal precision. Default 4.
 * @param boolean $peak [Optional] Return peak usage. Default false.
 * @return string MiB of memory consumed by the script.
 */
function xpl_memory_usage($decimals = 4, $peak = false) {
		
	if (XDEBUG_ENABLED) {
		$usage = $peak ? xdebug_peak_memory_usage() : xdebug_memory_usage();
	} else {
		$usage = $peak ? memory_get_peak_usage() : memory_get_usage();
	}
	
	return number_format($usage/1024/1024, $decimals);
}

/**
 * Returns the time elapsed and memory consumed by the script during the current request.
 * 
 * @param boolean $fixed_position [Optional] Display the output in fixed bottom left of browser. Default true.
 * @return string HTML string of request stats output.
 */
function xpl_request_stats($fixed_position = true) {
	
	$s = $fixed_position
		? '<span style="font-family:Arial;font-size:12px;color:#fff;background:#000;position:fixed;bottom:0;left:0;padding:2px 5px 0">'
		: '<span class="text-sm">';
	
	$s .= '<b>'.xpl_time_index(4, true).'<small> ms</small> '.xpl_memory_usage(3).'<small>MB</small>';
	
	if (function_exists('db_get_query_count')) {
		$s .= ' '.db_get_query_count().' <small>DB queries</small>';
	}
	
	$s .= '</b></span>';
	
	return $s;
}

/**
 * Used as a basic stopwatch for profiling. The default `$action`
 * starts the timer. Setting `$action` to 'stop' returns the 
 * difference between now and the last start time.
 *
 *	@param string $action (optional) 'start' or 'stop'.
 *	@param integer $start_time (optional)
 *	@return float
 */
function xpl_timer($action = 'start', $start_time = null) {
	
	static $time;
	
	$now = microtime(true);
	
	if ('start' === $action) {
		$time = $now;
	
	} else if ('stop' === $action) {
		
		if (empty($start_time)) {
			$start_time = $time;
		}
		
		unset($time);
		
		return $now - $start_time;
	}
	
	return $now;
}

/**
 * Logs a message with the framework SimpleLog.
 * 
 * @param string $message
 * @param string $function [Optional]
 */
function xpl_log($message, $function = null) {
	xpl\Framework\SimpleLog::log($message, $function);
}

/**
 * Initializes the framework logger.
 * 
 * @param string $log_file
 */
function xpl_log_file($file = null) {
	
	if (! isset($file)) {
		return xpl\Framework\SimpleLog::getFile();
	}
	
	xpl\Framework\SimpleLog::setFile($file);
}

/**
 * Initializes the framework's static facades.
 * 
 * @param \xpl\Framework\DI $di
 */
function xpl_facades_init(xpl\Framework\DI $di) {
	
	xpl\Framework\StaticFacade::setDI($di);
	
	require_once 'facades/facades.php';
}

} // namespace