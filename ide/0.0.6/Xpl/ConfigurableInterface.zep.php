<?php

namespace Xpl;


interface ConfigurableInterface
{

    /**
     * Sets the object configuration.
     *
     * @param \Xpl\Collection\Config $config 
     */
    public function setConfig(\Xpl\Collection\Config $config);

    /**
     * Returns the object configuration.
     *
     * @return \Xpl\Collection\Config 
     */
    public function getConfig();

}
