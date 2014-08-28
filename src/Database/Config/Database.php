<?php

namespace xpl\Database\Config;

class Database extends AbstractConfig {
	
	protected $driver;
	protected $host;
	protected $port;
	protected $name;
	protected $user;
	protected $password;
	protected $driver_options;
	
	public function getDsn() {
		return pdo_dsn($this->get('driver'), $this->get('host'), $this->get('name'), $this->get('port'));
	}
	
	public function setDriver($driver) {
		
		if (! in_array($driver, pdo_drivers(), true)) {
			throw new \InvalidArgumentException("Invalid PDO driver '$driver'.");
		}
		
		$this->driver = $driver;
	}
	
}
