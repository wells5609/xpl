<?php

namespace xpl\Framework\Application;

use xpl\Routing\RoutableInterface;
use xpl\Routing\Resource;
use xpl\Routing\RouteInterface as Route;
use xpl\Foundation\RequestInterface as Request;
use xpl\Foundation\ControllerInterface as Controller;
use xpl\Web\Response;

class App extends \xpl\Bundle\Application implements RoutableInterface 
{
	
	protected function onInit() {
		$this->loadIncludes();
	}
	
	/**
	 * Called when one of the application's route is matched by the router.
	 * 
	 * @param \xpl\Routing\RouteInterface $route
	 * @param \xpl\Foundation\RequestInterface $request
	 * @param \xpl\Foundation\ControllerInterface $controller
	 */
	public function onRoute(Route $route, Request $request, Controller $controller) {}
	
	/**
	 * Called before response is sent when this is the primary app.
	 * 
	 * @param \xpl\Web\Response $response
	 */
	public function onRespond(Response $response) {}
	
	/**
	 * Checks whether the app is the primary app.
	 * 
	 * @return boolean
	 */
	public function isPrimary() {
		return (bool)$this->config->get('is_primary');
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
	 * Alias of getName() 
	 */
	public function getId() {
		return $this->getName();
	}
	
	/**
	 * Implementing \xpl\Web\Application
	 * 
	 * @param string $name [Optional]
	 * @return \xpl\Routing\Resource
	 */
	public function getResource($name = null) {
		
		$key = 'resource'.(isset($name) ? '.'.$name : '');
		
		if (isset($this->registry[$key])) {
			return $this->registry[$key];
		}
		
		// resource definition class
		$class = $this->getResourceDefinitionClass($name);
		
		if (class_exists($class)) {
			
			$definition = new $class();
			$cache = di('cache');
			$factory = di('resource.factory');
			$cache_is_active = env('cache_routes', true);
			
			// try to get from cache first
			if ($cache_is_active && $resource = $factory->fromCache($cache, $definition->getName())) {
				return $this->registry[$key] = $resource;
			}
			
			// create from definition
			if ($resource = $factory->fromDefinition($definition)) {
				
				if ($cache_is_active) {
					$factory->cache($cache, $resource);
				}
				
				return $this->registry[$key] = $resource;
			}
		}
		
		throw new \RuntimeException("No resource available (Could not find definition class: '$class').");
	}
	
	protected function getResourceDefinitionClass($name = null) {
		return $this->getNamespace().'\\Resource'.(isset($name) ? '\\'.ucfirst($name) : '');
	}
	
	protected function loadIncludes() {
		
		if ($includes = $this->getConfig('include')) {
			
			$path = $this->getpath();
			
			foreach((array)$includes as $include) {
				
				if (file_exists($path.$include)) {
					include $path.$include;
				}
			}
		}
	}
	
}
