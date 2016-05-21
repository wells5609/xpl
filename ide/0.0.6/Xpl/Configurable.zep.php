<?php

namespace Xpl;


abstract class Configurable implements \Xpl\ConfigurableInterface
{
    /**
     * @var \Xpl\Collection\Config
     */
    protected $configuration;


    /**
     * Sets the object configuration.
     *
     * @param \Xpl\Collection\Config $config 
     */
    public function setConfig(\Xpl\Collection\Config $config) {}

    /**
     * Returns the object configuration.
     *
     * @return \Xpl\Collection\Config 
     */
    public function getConfig() {}

    /**
     * Injects a Config for the object when none is set.
     *
     * @return \Xpl\Collection\Config|null 
     */
    protected function injectConfig() {}

}
