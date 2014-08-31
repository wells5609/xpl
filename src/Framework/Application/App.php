<?php

namespace xpl\Framework\Application;

use xpl\Common\Storage\Registry;
use xpl\Routing\Resource;
use xpl\Routing\Router;
use xpl\Web\Response;

class App extends \xpl\Web\Application implements AppInterface {
	
	/**
	 * @var string
	 */
	protected static $primary;
	
	/**
	 * Constructor takes a config instance.
	 * 
	 * @param \xpl\Common\Storage\Config $config
	 * @param \xpl\Common\Storage\Registry $registry [Optional]
	 */
	public function __construct(Config $config, Registry $registry = null) {
		
		if (! is_readable($config->getPath().'config/config.php')) {
			throw new \RuntimeException('Missing config.php for app: "'.$config->get('name').'".');
		}
		
		$this->config = $config;
		$this->registry = $registry ?: new Registry;
		
		$this->config->setParent($this);
		$this->config->setPath('config', 'config/');
		
		$vars = include($this->config->getPath('config').'config.php');
		
		if (! empty($vars['app'])) {
			$this->config->import($vars['app']);
		}
		
		if (! empty($vars['paths'])) {
			foreach($vars['paths'] as $name => $path) {
				$this->config->setPath($name, $path);
			}
		}
		
		if (! isset(static::$primary)) {
			static::$primary = $this->config->get('name');
			$this->config->set('is_primary', true);
		}
		
		$this->onInit();
	}
	
	public function onRespond(Response $response) {
	}
	
	public function initViews(\View\Manager $views) {
		
		$__FILE__ = $this->getPath('config').'views.php';
		
		file_exists($__FILE__) and include $__FILE__;
	}
	
	/**
	 * Sets a config item value.
	 * 
	 * @param string $item Config item key.
	 * @param mixed $value Conifg item value. Pass null to unset the item.
	 */
	public function setConfig($item, $value) {
		if (null === $value) {
			$this->config->remove($item);
		} else {
			$this->config->set($item, $value);
		}
		return $this;
	}
	
	/**
	 * Returns a config item or the entire \App\Config object.
	 * 
	 * @param string $item [Optional] Item key to retrive, or null to get the object.
	 * @return mixed
	 */
	public function getConfig($item = null) {
		return isset($item) ? $this->config->get($item) : $this->config;
	}
	
	/**
	 * Sets a named app directory path.
	 * 
	 * @param string $name Name used to identify the directory.
	 * @param string $path Relative path to directory from application root.
	 * @return $this
	 */
	public function setPath($name, $path) {
		$this->config->setPath($name, $path);
		return $this;
	}
	
	/**
	 * Returns a directory path by name, or the root path if given null.
	 * 
	 * @param string $name Name of directory, or NULL for the root path.
	 * @return string Directory path if found, otherwise null.
	 */
	public function getPath($name = null) {
		return $this->config->getPath($name);
	}
	
	/**
	 * Returns an array of all the app's directory paths.
	 * 
	 * @return array Associative array of directories.
	 */
	public function getPaths() {
		return $this->config->get('paths');
	}
	
	/**
	 * Sets a component in the object registry.
	 * 
	 * @param string $name Component name.
	 * @param object $object Component object.
	 * @return $this
	 */
	public function setComponent($name, $object) {
		$this->registry->set($name, $object);
		return $this;
	}
	
	/**
	 * Retrieves a component from the application's object registry.
	 * 
	 * @param string $name Component name.
	 * @return mixed
	 */
	public function getComponent($name) {
		return $this->registry->get($name);
	}
	
	/**
	 * Alias of getName()
	 * @return string
	 */
	public function getId() {
		return $this->getName();
	}
	
	/**
	 * Checks whether the app is the primary app.
	 * 
	 * @return boolean
	 */
	public function isPrimary() {
		return (bool) $this->config->get('is_primary');
	}
	
	/**
	 * Called at end of `__construct()`
	 */
	protected function onInit() {
		$this->loadComponents();
	}
	
	/**
	 * Sets up initial application components in object registry.
	 */
	protected function loadComponents() {
	}
	
	/**
	 * Adds autoloading of the app's namespace from the directory/(ies) given.
	 * 
	 * The application's namespace MUST be set prior to calling, otherwise
	 * a RuntimeException is thrown.
	 * 
	 * @param string $dir Directory path.
	 * @param boolean $psr4 [Optional] Whether to load using PSR-4. Default false.
	 * 
	 * @throws \RuntimeException if app namespace is not set.
	 */
	protected function autoloadRegister($dir, $psr4 = false) {
		
		if (! $namespace = $this->getNamespace()) {
			throw new \RuntimeException("Must set app namespace to register autoloader.");
		}
		
		$func = 'add'.($psr4 ? 'Psr4' : '');
		
		composer()->$func($namespace.'\\', $dir);
	}
	
}
