namespace Xpl;

use Xpl\Collection\Config;

interface ConfigurableInterface
{

    /**
     * Sets the object configuration.
     *
     * @param \Xpl\Collection\Config config
     */
    public function setConfig(<Config> config);

    /**
     * Returns the object configuration.
     *
     * @return \Xpl\Collection\Config
     */
    public function getConfig() -> <Config> | null;

}
