namespace Xpl\Cache;

interface CacheAwareInterface
{

    /**
     * Sets the Cache.
     *
     * @param \Xpl\Cache\Cache cache
     */
	public function setCache(<Cache> cache);

    /**
     * Returns the Cache.
     *
     * @return \Xpl\Cache\Cache
     */
	public function getCache() -> <Cache>;

}
