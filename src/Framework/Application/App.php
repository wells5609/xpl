<?php

namespace xpl\Framework\Application;

use xpl\Common\Storage\Registry;
use xpl\Routing\Resource;
use xpl\Routing\Router;
use xpl\Web\Response;

class App extends \xpl\Web\Application implements AppInterface {
	
	/**
	 * Called before response is sent when this is the primary app.
	 */
	public function onRespond(Response $response) {
		
	}
	
	/**
	 * Called when views are loaded.
	 */
	public function initViews(\Cms\Cms $cms) {
		
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
	
	/** Alias of getName() */
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
	 * Implementing \xpl\Web\Application
	 */
	public function getResource($name = null) {
		
		$key = 'resource'.(isset($name) ? ".{$name}" : '');
		
		if (isset($this->registry[$key])) {
			return $this->registry[$key];
		}
		
		// resource definition class
		$class = $this->getNamespace().'\\Resource'.(isset($name) ? '\\'.ucfirst($name) : '');
		
		if (class_exists($class, true)) {
			
			$definition = new $class();
			
			$cache = $this->getDI()->offsetGet('cache');
			$factory = $this->getDI()->offsetGet('resource.factory');
			
			// try to get from cache first
			if ($resource = $factory->fromCache($cache, $definition->getName())) {
				return $this->registry[$key] = $resource;
			}
			
			// create from definition
			if ($resource = $factory->fromDefinition($definition)) {
				
				$factory->cache($cache, $resource);
				
				return $this->registry[$key] = $resource;
			}
		}
		
		throw new \RuntimeException("Resource definition class does not exist: '$class'.");
	}
	
}
