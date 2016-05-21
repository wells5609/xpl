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
     * Returns the cache driver instance.
     *
     * @return \Xpl\Cache\DriverInterface 
     */
    public function getDriver() {}

    /**
     * Returns the pool configuration settings for a given namespace.
     *
     * @param string $namespaceName [Optional]
     * @return array 
     */
    public function getConfig($namespaceName = "") {}

    /**
     * Returns the ItemPool for a given namespace.
     * If no pool exists, one will be created.
     *
     * @param string $namespaceName [Optional]
     * @return \Xpl\Cache\ItemPool 
     */
    public function getPool($namespaceName = "") {}

    /**
     * Sets the cache driver.
     *
     * @param \Xpl\Cache\DriverInterface $driver 
     * @return \Xpl\Cache\Cache 
     */
    public function setDriver(DriverInterface $driver) {}

    /**
     * Sets the pool configuration settings for a given namespace.
     *
     * @param string $namespaceName 
     * @param array $config 
     * @return \Xpl\Cache\Cache 
     */
    public function setConfig($namespaceName, $config) {}

    /**
     * Sets the ItemPool for a given namespace.
     *
     * @param mixed $pool 
     * @param string $namespaceName [Optional]
     * @param \Xpl\Cache\ItemPool  
     * @return Cache 
     */
    public function setPool(ItemPool $pool, $namespaceName = "") {}

    /**
     * Creates an ItemPool for the given namespace.
     *
     * @param string $namespaceName 
     * @return \Xpl\Cache\ItemPool 
     */
    protected function createPool($namespaceName) {}

    /**
     * Detects and returns the first available cache driver.
     *
     * @return \Xpl\Cache\DriverInterface 
     */
    public static function getDetectedDriver() {}

}
