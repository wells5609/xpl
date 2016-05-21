<?php

namespace Xpl;


class NamespaceAlias
{
    /**
     * Original namespace.
     *
     * @var string
     */
    private $original;

    /**
     * Namespace alias.
     *
     * @var string
     */
    private $alias;

    /**
     * Length of the alias namespace.
     *
     * @var int
     */
    private $aliasLength;

    /**
     * Classes in the aliased namespace that have been resolved.
     *
     * @var array
     */
    private $resolved = array();


    /**
     * Constructor. Sets the original and alias namespace.
     *
     * @param string $original Actual namespace name.
     * @param string $alias Alias namespace to use in code.
     */
    public function __construct($original, $alias) {}

    /**
     * Autoloader implementation to resolve classes in the aliased namespace.
     *
     * @param string $classname 
     */
    public function load($classname) {}

    /**
     * Returns an array of classes that have been resolved.
     *
     * @return array 
     */
    public function getResolved() {}

    /**
     * Registers the autoloader.
     *
     * @return \Xpl\NamespaceAlias 
     */
    public function register() {}

    /**
     * Unregisters the autoloader.
     *
     * @return \Xpl\NamespaceAlias 
     */
    public function unregister() {}

}
