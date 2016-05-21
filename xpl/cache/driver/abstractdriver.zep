namespace Xpl\Cache\Driver;

use Xpl\Cache\Item;
use Xpl\Cache\DriverInterface;

abstract class AbstractDriver implements DriverInterface
{

	/**
	 * Saves the given Item to the cache backend.
	 *
	 * @param \Xpl\Cache\Item
	 *
	 * @return boolean
	 */
	public function put(<Item> cacheItem) -> boolean
    {
        var e;
        try {
            this->save(cacheItem->getKey(), cacheItem->get(), cacheItem->getTtl());
        } catch \Exception, e {
            return false;
        }

        return true;
    }

	/**
	 * Fetches an Item from the cache backend.
	 *
	 * @param \Xpl\Cache\Item cacheItem
	 *
	 * @return \Xpl\Cache\Item
	 */
	public function $fetch(string key) -> <Item>
	{
		if this->exists(key) {
			return this->hit(key, this->get(key));
		}

		return this->miss(key);
	}

	/**
	 * Returns a value from the cache.
	 *
	 * @param string key Item key.
	 *
	 * @return mixed Cached value, if it exists, otherwise null.
	 */
	abstract protected function get(string key) -> var | null;

	/**
	 * Saves a value in the cache.
	 *
	 * @param string key Item key
	 * @param mixed value Item value
	 * @param int ttl Cache lifetime in seconds
	 *
	 * @return void
	 */
	abstract protected function save(string key, var value, int ttl) -> void;

	/**
	 * Returns a new Item on hit.
	 *
	 * @param string key
	 * @param mixed value
	 *
	 * @return \Xpl\Cache\Item
	 */
	protected function hit(string! key, var value) -> <Item>
	{
		return new Item(key, true, value);
	}

	/**
	 * Creates a new Item on miss.
	 *
	 * @param string key
	 *
	 * @return \Xpl\Cache\Item
	 */
	protected function miss(string! key) -> <Item>
	{
		return new Item(key, false, null);
	}

}
