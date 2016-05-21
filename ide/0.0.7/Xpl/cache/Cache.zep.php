<?php

namespace Xpl\Cache;


class Cache
{
    /**
     * @var string
     */
    const DEFAULT_NAMESPACE = "default";

    /**
     * @var \Xpl\Cache\DriverInterface
     */
    protected $driver;

    /**
     * @var \Xpl\Cache\ItemPool[]
     */
    protected $pools = array();

    /**
     * @var array[]
     */
    protected $config = array();

    /**
     * @var string
     */
    protected $prefix = "";


    /**
     * Constructor.
     *
     * @param \Xpl\Cache\DriverInterface $driver [Optional]
     */
    public function __construct(DriverInterface $driver = null) {}

    /**
     * Sets the cache item key prefix.
     *
     * @param string $prefix 
     * @return \Xpl\Cache\Cache 
     */
    public function setPrefix($prefix) {}

    /**
     * Returns the cache item key prefix.
     *
     * @return string 
     */
    public function getPrefix() {}

    /**
     * Returns the cache driver instance.
     *
     * @return \Xpl\Cache\DriverInterface 
     */
    public function getDriver() {}

    /**
     * Sets the cache driver.
     *
     * @param \Xpl\Cache\DriverInterface $driver 
     * @return \Xpl\Cache\Cache 
     */
    public function setDriver(DriverInterface $driver) {}

    /**
     * Returns the pool configuration settings for a given namespace.
     *
     * @param string $name 
     * @param string $namespaceName [Optional]
     * @return array 
     */
    public function getConfig($name) {}

    /**
     * Sets the pool configuration settings for a given namespace.
     *
     * @param string $name 
     * @param array $config 
     * @param string $namespaceName 
     * @return \Xpl\Cache\Cache 
     */
    public function setConfig($name, $config) {}

    /**
     * Returns the ItemPool for a given namespace.
     * If no pool exists, one will be created.
     *
     * @param string $name 
     * @param string $namespaceName [Optional]
     * @return \Xpl\Cache\ItemPool 
     */
    public function getPool($name) {}

    /**
     * Sets the ItemPool for a given namespace.
     *
     * @param mixed $pool 
     * @param string $name 
     * @param \Xpl\Cache\ItemPool  
     * @param string $namespaceName [Optional]
     * @return Cache 
     */
    public function setPool(ItemPool $pool, $name) {}

    /**
     * Creates an ItemPool for the given namespace.
     *
     * @param string $name 
     * @param string $namespaceName 
     * @return \Xpl\Cache\ItemPool 
     */
    protected function createPool($name) {}

    /**
     * Detects and returns the first available cache driver.
     *
     * @return \Xpl\Cache\DriverInterface 
     */
    public static function getDetectedDriver() {}

}
