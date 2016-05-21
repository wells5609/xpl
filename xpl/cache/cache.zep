namespace Xpl\Cache;

use Xpl\Cache\Driver\MemoryDriver;

class Cache
{

    /**
     * @var string
     */
	const DEFAULT_NAMESPACE = "default";

    /**
     * @var \Xpl\Cache\DriverInterface
     */
	protected driver;

    /**
     * @var \Xpl\Cache\ItemPool[]
     */
	protected pools = [];

    /**
     * @var array[]
     */
	protected config = [];

	/**
	 * @var string
	 */
	protected prefix = "";

	/**
	 * Constructor.
	 *
	 * @param \Xpl\Cache\DriverInterface driver [Optional]
	 */
	public function __construct(<DriverInterface> driver = null)
	{
		if typeof driver == "null" {
			let driver = this->getDetectedDriver();
		}

		this->setDriver(driver);
	}

	/**
	 * Sets the cache item key prefix.
	 *
	 * @param string prefix
	 *
	 * @return \Xpl\Cache\Cache
	 */
	public function setPrefix(string! prefix) -> <Cache>
	{
		let this->prefix = rtrim(prefix, ".") . ".";
		return this;
	}

	/**
	 * Returns the cache item key prefix.
	 *
	 * @return string
	 */
	public function getPrefix() -> string
	{
		return this->prefix;
	}

    /**
     * Returns the cache driver instance.
     *
     * @return \Xpl\Cache\DriverInterface
     */
	public function getDriver() -> <DriverInterface>
    {
        return this->driver;
	}

    /**
     * Sets the cache driver.
     *
     * @param \Xpl\Cache\DriverInterface driver
     *
     * @return \Xpl\Cache\Cache
     */
	public function setDriver(<DriverInterface> driver) -> <Cache>
    {
		let this->driver = driver;
        return this;
	}

    /**
     * Returns the pool configuration settings for a given namespace.
     *
     * @param string namespaceName [Optional]
     *
     * @return array
     */
	public function getConfig(string name) -> array
    {
        array defaults = [];

		if empty name || ! isset this->config[name] {
			return defaults;
		}

		return array_merge(defaults, this->config[name]);
	}

    /**
     * Sets the pool configuration settings for a given namespace.
     *
     * @param string namespaceName
     * @param array config
     *
     * @return \Xpl\Cache\Cache
     */
	public function setConfig(string name, array! config) -> <Cache>
    {
		let this->config[name] = config;
        return this;
	}

    /**
     * Returns the ItemPool for a given namespace.
     *
     * If no pool exists, one will be created.
     *
     * @param string namespaceName [Optional]
     *
     * @return \Xpl\Cache\ItemPool
     */
	public function getPool(string name) -> <ItemPool>
    {
        var pool;

        if !fetch pool, this->pools[name] {
            let pool = this->createPool(name);
            let this->pools[name] = pool;
        }

		return pool;
	}

    /**
     * Sets the ItemPool for a given namespace.
     *
     * @param \Xpl\Cache\ItemPool
     * @param string namespaceName [Optional]
     */
	public function setPool(<ItemPool> pool, string name) -> <Cache>
    {
		let this->pools[name] = pool;
        return this;
	}

    /**
     * Creates an ItemPool for the given namespace.
     *
     * @param string namespaceName
     *
     * @return \Xpl\Cache\ItemPool
     */
	protected function createPool(string! name) -> <ItemPool>
    {
        var config, driver, driverClass, prefix, cachePrefix, defaultTtl;

		let config = this->getConfig(name);

        if fetch driverClass, config["driver"] {
            let driver = create_instance(driverClass);
        } else {
            let driver = this->getDriver();
        }

		let prefix = this->prefix;

		if fetch cachePrefix, config["prefix"] {
			let prefix .= trim(cachePrefix, ".") . ".";
		} else {
            if name !== self::DEFAULT_NAMESPACE {
                let prefix .= name . ".";
            }
		}

        if !fetch defaultTtl, config["default_ttl"] {
            let defaultTtl = 0;
        }

		return new ItemPool(driver, prefix, (int)defaultTtl);
	}

    /**
     * Detects and returns the first available cache driver.
     *
     * @return \Xpl\Cache\DriverInterface
     */
	public static function getDetectedDriver() -> <DriverInterface>
    {
        var driverClasses, classname;

		let driverClasses = [
			"Xpl\\Cache\\Driver\\ApcuDriver",
			"Xpl\\Cache\\Driver\\ApcDriver",
			"Xpl\\Cache\\Driver\\XCacheDriver"
		];

		for classname in driverClasses {
            if call_user_func(classname . "::isAvailable") === true {
				return new {classname}();
			}
		}

		return new MemoryDriver();
	}

}
