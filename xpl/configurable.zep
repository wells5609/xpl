namespace Xpl;

use Xpl\Collection\Config;
use ReflectionClass;
use RuntimeException;
use InvalidArgumentException;

abstract class Configurable implements ConfigurableInterface
{

    /**
     * @var \Xpl\Collection\Config
     */
    protected configuration;

    /**
     * Sets the object configuration.
     *
     * @param \Xpl\Collection\Config config
     */
    public function setConfig(<Config> config)
    {
        let this->configuration = config;
    }

    /**
     * Returns the object configuration.
     *
     * @return \Xpl\Collection\Config
     */
    public function getConfig() -> <Config> | null
    {
        var config, e;
        let config = this->configuration;

        if typeof config != "object" {
            try {
                let config = this->injectConfig();
                let this->configuration = config;
            } catch \Exception, e {
                return null;
            }
        }

        return config;
    }

    /**
     * Injects a Config for the object when none is set.
     *
     * @return \Xpl\Collection\Config|null
     */
    protected function injectConfig() -> <Config> | null
    {
        var reflection, dirPath, filePath, config;

        let reflection = new ReflectionClass(this);
        let dirPath = dirname(reflection->getFileName());
        let filePath = dirPath . "/config/config.php";

        if ! file_exists(filePath) {
            throw new RuntimeException("Could not locate object Config.");
        }

        let config = require filePath;

        if typeof config == "object" {
            if ! (config instanceof Config) {
                throw new InvalidArgumentException("Config must be instance of Xpl\\Config, given: " . get_class(config));
            }
        } else {
            throw new InvalidArgumentException("Config must be instance of Xpl\\Config, given: " . gettype(config));
        }

        return config;
    }

}
