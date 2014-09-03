<?php

namespace xpl\Database;

class ConnectionPool {
	
	protected $configurations = array();
	protected $connections = array();
	protected $iniFile;
	private $fileScanned = false;
	
	public function __construct($path = null) {
		isset($path) and $this->setIniPath($path);
	}
	
	/**
	 * Set directory/file path to db.ini
	 * 
	 * @param string $path File or directory path to db.ini
	 */
	public function setIniPath($path) {
		
		if (! $realpath = realpath($path)) {
			throw new \RuntimeException("Invalid filepath: '$path'.");
		}
		
		if (is_dir($realpath)) {
			$realpath .= DIRECTORY_SEPARATOR.'db.ini';
		}
		
		if (file_exists($realpath)) {
			$this->iniFile = $realpath;
		}
	}
	
	/**
	 * Returns a PDO connection for a configured database, creating if necessary.
	 * 
	 * @param string $dbname
	 * @return \xpl\Component\Database\PdoAdapter
	 */
	public function connect($dbname) {
		
		if (isset($this->connections[$dbname])) {
			return $this->connections[$dbname];
		}
		
		if (! $config = $this->getConfig($dbname)) {
			throw new \RuntimeException("Unknown database: '$dbname'.");
		}
		
		$this->connections[$dbname] = $dbc = new PdoAdapter($config);
		
		$dbc->connect();
		
		return $dbc;
	}
	
	/**
	 * Returns an array of settings from db.ini for a given database.
	 * 
	 * @param string $dbname Database name.
	 * @return array Associative array of database settings
	 */
	public function getConfig($dbname) {
		
		if (! $this->fileScanned && isset($this->iniFile)) {
		
			$settings = parse_ini_file($this->iniFile, true);
			
			$this->fileScanned = 1;
			
			foreach($settings as $database => $vars) {
				$vars['name'] = $database;
				$this->configure($vars);
			}
		}	
		
		return isset($this->configurations[$dbname]) ? $this->configurations[$dbname] : null;
	}
	
	/**
	 * Checks whether a given database has been configured.
	 * 
	 * @param string $dbname Database name.
	 * @return boolean
	 */
	public function isConfigured($dbname) {
		return isset($this->configurations[$dbname]);
	}
	
	/**
	 * Configure a database connection from an associative array.
	 * 
	 * @param array $config Associative array of DB settings.
	 */
	public function configure(array $config) {
		
		$defaults = array(
			'driver' => 'mysql',
			'host' => '127.0.0.1',
			'name' => null,
			'user' => null,
			'password' => null,
			'driver_options' => array()
		);
		
		$vars = array_replace($defaults, $config);
		
		if (isset($this->configurations[$vars['name']])) {
			throw new \RuntimeException("Already configured database '{$vars['name']}'.");
		}
		
		if (false !== stripos($vars['host'], '{$sqlite_path}') && function_exists('sqlite_file')) {
			$vars['host'] = sqlite_file(str_ireplace('{$sqlite_path}', '', $vars['host']));
		}
		
		$this->configurations[$vars['name']] = new Config\Database($vars);
		
		return true;
	}
	
	/**
	 * Returns the total number of DB queries executed by all connections 
	 * during the current request.
	 * 
	 * @return int|null
	 */
	public function getTotalQueries() {
		
		$n = 0;
			
		if (! empty($this->connections)) {
			foreach($this->connections as $connection) {
				$n += $connection->getNumQueries();
			}
		}
		
		return (int) $n;
	}
	
	public function get($db) {
		return $this->connect($db);
	}
	
}
