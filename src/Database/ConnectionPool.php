<?php

namespace xpl\Database;

use RuntimeException;

class ConnectionPool {
	
	protected $ini_file;
	protected $configs;
	protected $connections;
	private $file_scanned = false;
	
	public function __construct($path = null) {
		
		$this->configs = array();
		$this->connections = array();
		
		if (isset($path)) {
			$this->setIniPath($path);
		}
	}
	
	/**
	 * Set directory or file path to db.ini
	 * 
	 * @param string $path File or directory path to (folder containing) db.ini.
	 */
	public function setIniPath($path) {
		
		if (! $ini_file = realpath($path)) {
			throw new RuntimeException("Invalid filepath: '$path'.");
		}
		
		if (is_dir($ini_file)) {
			$ini_file .= DIRECTORY_SEPARATOR.'db.ini';
		}
		
		if (! file_exists($ini_file)) {
			throw new RuntimeException("db.ini file does not exist in: '$path'.");
		}
		
		$this->ini_file = $ini_file;
	}
	
	/**
	 * Configure a database connection from an associative array.
	 * 
	 * @param array $config Associative array of DB settings.
	 */
	public function configure(array $config) {
		
		$vars = array_replace(array(
			'driver' => 'mysql',
			'host' => '127.0.0.1',
			'name' => null,
			'user' => null,
			'password' => null,
			'driver_options' => array()
		), $config);
		
		if (isset($this->configs[$vars['name']])) {
			throw new RuntimeException("Already configured database '{$vars['name']}'.");
		}
		
		$this->configs[$vars['name']] = new Config\Database($vars);
		
		return true;
	}
	
	/**
	 * Returns a PDO connection for a configured database, creating if necessary.
	 * 
	 * @param string $dbname
	 * @return \xpl\Database\PdoAdapter
	 */
	public function connect($dbname) {
		
		if (! isset($this->connections[$dbname])) {
			
			if (! $config = $this->getConfig($dbname)) {
				throw new RuntimeException("Unknown database: '$dbname'.");
			}
			
			$this->connections[$dbname] = new PdoAdapter($config);
			
			$this->connections[$dbname]->connect();
		}
		
		return $this->connections[$dbname];
	}
	
	/**
	 * Checks whether a given database has been configured.
	 * 
	 * @param string $dbname Database name.
	 * @return boolean
	 */
	public function isConfigured($dbname) {
		return isset($this->configs[$dbname]);
	}
	
	/**
	 * Returns an array of settings from db.ini for a given database.
	 * 
	 * @param string $dbname Database name.
	 * @return array Associative array of database settings
	 */
	public function getConfig($dbname) {
		
		if (! $this->file_scanned && isset($this->ini_file)) {
			
			$config = parse_ini_file($this->ini_file, true);
		
			foreach($config as $database => $vars) {
				$vars['name'] = $database;
				$this->configure($vars);
			}
			
			$this->file_scanned = true;
		}	
		
		return isset($this->configs[$dbname]) ? $this->configs[$dbname] : null;
	}
	
	/**
	 * Returns the total number of DB queries executed by all connections 
	 * during the current request.
	 * 
	 * @return int|null
	 */
	public function getTotalQueries() {
		
		$num = 0;
			
		if (! empty($this->connections)) {
			foreach($this->connections as $conn) {
				$num += $conn->getNumQueries();
			}
		}
		
		return (int)$num;
	}
	
	/**
	 * Alias of connect()
	 */
	public function get($db) {
		return $this->connect($db);
	}
	
}
