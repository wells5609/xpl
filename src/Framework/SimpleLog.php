<?php

namespace xpl\Framework;

class SimpleLog {
	
	protected static $log_file;
	protected static $messages = array();
	
	/**
	 * Sets the log file.
	 * 
	 * @param string $file
	 */
	public static function setFile($file) {
		
		if (file_exists($file) && ! is_writable($file)) {
			throw new \InvalidArgumentException("Given unwritable log file: '$file'.");
		}
		
		static::$log_file = $file;
		
		register_shutdown_function(__CLASS__.'::write');
	}
	
	/**
	 * Logs a message.
	 * 
	 * @param string $message
	 * @param string $func [Optional]
	 */
	public static function log($message, $func = null) {
			
		$msg = udate('Y-m-d g:i:s.u a').' "'.$message.'"';

		$trace = debug_backtrace(DEBUG_BACKTRACE_IGNORE_ARGS, 3);
		$caller = array_pop($trace);
		
		$msg .= "\tFile: ".$caller['file'].' on line '.$caller['line'];
		
		if ($func) {
			$msg .= "\tFunction: {$func}";
		}

		static::$messages[] = $msg;
	}
	
	/**
	 * Writes the log messages on shutdown.
	 */
	public static function write() {
		
		if (! empty(static::$messages)) {
		
			$string = '';
		
			foreach(static::$messages as $msg) {
				$string .= PHP_EOL.$msg;
			}
		
			file_put_contents(static::$log_file, $string, FILE_APPEND|LOCK_EX);
		}
	}
}
