<?php

namespace Xpl;


class ClassLoader
{
    /**
     * PSR-4 prefixes lengths.
     *
     * @var array
     */
    private $prefixLengthsPsr4 = array();

    /**
     * PSR-4 prefixes and paths.
     *
     * @var array
     */
    private $prefixDirsPsr4 = array();

    /**
     * PSR-4 fallback paths.
     *
     * @var array
     */
    private $fallbackDirsPsr4 = array();

    /**
     * PSR-0 prefixes and paths.
     *
     * @var array
     */
    private $prefixesPsr0 = array();

    /**
     * PSR-0 fallback paths.
     *
     * @var array
     */
    private $fallbackDirsPsr0 = array();

    /**
     * Map of classes to file paths.
     *
     * @var array
     */
    private $classMap = array();

    /**
     * Whether to search in the PHP include path.
     *
     * @var boolean
     */
    private $useIncludePath = false;

    /**
     * Instances of ClassLoaders loaded through loadComposer().
     *
     * @var array
     */
    static private $composerInstances;


    /**
     * Returns a ClassLoader for the given Composer installation.
     *
     * @param string $vendorPath 
     * @param boolean $prepend [Optional] Default = true
     * @return \Xpl\ClassLoader 
     */
    public static function composer($vendorPath, $prepend = true) {}

    /**
     * @return array 
     */
    public function getPrefixes() {}

    /**
     * @return array 
     */
    public function getPrefixesPsr4() {}

    /**
     * @return array 
     */
    public function getFallbackDirs() {}

    /**
     * @return array 
     */
    public function getFallbackDirsPsr4() {}

    /**
     * @return array 
     */
    public function getClassMap() {}

    /**
     * @param array $classMap 
     * @param array $$classMap Class to filename map
     */
    public function addClassMap($classMap) {}

    /**
     * Registers a set of PSR-0 directories for a given prefix, either
     * appending or prepending to the ones previously set for this prefix.
     *
     * @param mixed $prefix 
     * @param mixed $paths 
     * @param bool $prepend 
     * @param string $$prefix The prefix
     * @param array|string $$paths The PSR-0 root directories
     * @param bool $$prepend Whether to prepend the directories
     */
    public function add($prefix, $paths, $prepend = false) {}

    /**
     * Registers a set of PSR-4 directories for a given namespace, either
     * appending or prepending to the ones previously set for this namespace.
     *
     * @throws \InvalidArgumentException
     * @param mixed $prefix 
     * @param mixed $paths 
     * @param bool $prepend 
     * @param string $$prefix The prefix/namespace, with trailing "\\"
     * @param array|string $$paths The PSR-0 base directories
     * @param bool $$prepend Whether to prepend the directories
     */
    public function addPsr4($prefix, $paths, $prepend = false) {}

    /**
     * Registers a set of PSR-0 directories for a given prefix,
     * replacing any others previously set for this prefix.
     *
     * @param mixed $prefix 
     * @param mixed $paths 
     * @param string $$prefix The prefix
     * @param array|string $$paths The PSR-0 base directories
     */
    public function set($prefix, $paths) {}

    /**
     * Registers a set of PSR-4 directories for a given namespace,
     * replacing any others previously set for this namespace.
     *
     * @throws \InvalidArgumentException
     * @param mixed $prefix 
     * @param mixed $paths 
     * @param string $$prefix The prefix/namespace, with trailing "\\"
     * @param array|string $$paths The PSR-4 base directories
     */
    public function setPsr4($prefix, $paths) {}

    /**
     * Turns on searching the include path for class files.
     *
     * @param bool $useIncludePath 
     * @param bool $$useIncludePath 
     */
    public function setUseIncludePath($useIncludePath) {}

    /**
     * Can be used to check if the autoloader uses the include path to check
     * for classes.
     *
     * @return bool 
     */
    public function getUseIncludePath() {}

    /**
     * Registers this instance as an autoloader.
     *
     * @param bool $prepend 
     * @param bool $$prepend Whether to prepend the autoloader or not
     */
    public function register($prepend = false) {}

    /**
     * Unregisters this instance as an autoloader.
     */
    public function unregister() {}

    /**
     * Loads the given class or interface.
     *
     * @param string $className 
     * @param string $$class The name of the class
     * @return bool|null if loaded, null otherwise
     */
    public function loadClass($className) {}

    /**
     * Finds the path to the file where the class is defined.
     *
     * @param string $className 
     * @param string $$class The name of the class
     * @return string|false path if found, false otherwise
     */
    public function findFile($className) {}

    /**
     * @param string $className 
     * @param string $ext 
     * @return string|null 
     */
    protected function findFileWithExtension($className, $ext) {}

}
