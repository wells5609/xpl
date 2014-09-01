<?php

namespace xpl\Foundation;

class BundleManager
{	
	/**
	 * Bundles of joy.
	 * @var array
	 */
	protected $bundles = array();
	
	/**
	 * Callbacks or BundleProviderInterfaces that provide bundles.
	 * @var array
	 */
	protected $providers = array();
	
	/**
	 * Sets an object or callback that provides a bundle upon request.
	 * 
	 * @param string $bundle_name
	 * @param \xpl\Bundle\BundleProviderInterface|callable $provider
	 * @return void
	 */
	public function provide($bundle_name, $provider) {
		
		if (! $provider instanceof BundleProviderInterface && ! is_callable($provider)) {
			throw new \InvalidArgumentException("Provider must be instance of BundleProviderInterface or callable.");
		}
		
		$this->providers[strtolower($bundle_name)] = $provider;
	}
	
	/**
	 * Sets an object or callback that provides bundles of a specific type.
	 * 
	 * @param string $bundle_type Type of bundle.
	 * @param \xpl\Bundle\BundleProviderInterface|callable $provider
	 * @return void
	 */
	public function provideType($bundle_type, $provider) {
		
		if (! $provider instanceof BundleProviderInterface && ! is_callable($provider)) {
			throw new \InvalidArgumentException("Provider must be instance of BundleProviderInterface or callable.");
		}
		
		$this->providers[strtolower($bundle_type)] = $provider;
	}
	
	/**
	 * Sets an object or callback that provides multiple bundles.
	 * 
	 * @param array $bundles Indexed array of bundle names.
	 * @param \xpl\Bundle\BundleProviderInterface|callable $provider
	 * @return void
	 */
	public function provideMultiple(array $bundles, $provider) {
		
		if (! $provider instanceof BundleProviderInterface && ! is_callable($provider)) {
			throw new \InvalidArgumentException("Provider must be instance of BundleProviderInterface or callable.");
		}
		
		foreach($bundles as $bundle) {
			$this->providers[strtolower($bundle)] = $provider;
		}
	}
	
	/**
	 * Sets a bundle.
	 * 
	 * Overwrite this function to do stuff to bundles as they're set (e.g. inject DI).
	 * 
	 * @param \xpl\Foundation\BundleInterface $bundle
	 * @return void
	 */
	public function setBundle(BundleInterface $bundle) {
		
		$this->bundles[strtolower($bundle->getIdentifier())] = $bundle;
	}
	
	/**
	 * Returns a bundle by name, booting from provider if necessary.
	 * 
	 * @param string $name Bundle name.
	 * @return \xpl\Bundle\BundleInterface Bundle or null on failure.
	 */
	public function getBundle($name) {
		
		$name = strtolower($name);
		
		if (isset($this->bundles[$name])) {
			return $this->bundles[$name];
		}
		
		if ($this->provideBundle($name)) {
			return $this->bundles[$name];
		}
		
		return null;
	}
	
	/**
	 * Checks whether a bundle exists.
	 * 
	 * A bundle exists when it:
	 * (a) has been created (and possibly booted), or
	 * (b) has a provider registered (exclusively or for its type)
	 * 
	 * @param string $name Bundle name.
	 * @return boolean True if bundle exists, otherwise false.
	 */
	public function exists($name) {
			
		$name = strtolower($name);
		
		if (isset($this->bundles[$name]) || isset($this->providers[$name])) {
			return true;
		}
		
		if (! empty($this->providers)) {
			
			list($bundle_type, $bundle_name) = explode('.', $name, 2);
			
			return isset($this->providers[$bundle_type]);
		}
		
		return false;
	}
	
	/**
	 * Checks whether a given bundle exists and has been booted.
	 * 
	 * @param string $name Bundle name.
	 * @return boolean True if exists and booted, otherwise false.
	 */
	public function isBooted($name) {
		
		$name = strtolower($name);
		
		if (isset($this->bundles[$name])) {
			return $this->bundles[$name]->isBooted();
		}
		
		return false;
	}
	
	/**
	 * Boots a bundle.
	 * 
	 * @param string $name Bundle name.
	 * @return boolean True if booted, otherwise false.
	 */
	public function boot($name) {
		
		if ($bundle = $this->getBundle($name)) {
			return $this->bootBundle($bundle);
		}
		
		return false;
	}
	
	/**
	 * Sets a bundle object from its provider.
	 * 
	 * @param string $name Bundle name.
	 * @return boolean True if bundle was provided, otherwise false.
	 * @throws \UnexpectedValueException if an implementation of BundleInterface is not provided.
	 */
	protected function provideBundle($name) {
		
		if (false !== strpos($name, '.')) {
			list($bundle_type, $bundle_name) = explode('.', $name, 2);
		} else {
			$bundle_type = null;
			$bundle_name = $name;
		}
		
		if (isset($this->providers[$name])) {
			// Bundle-specific provider
			$provider = $this->providers[$name];
		} else if (isset($this->providers[$bundle_type])) {
			// Bundle type provider
			$provider = $this->providers[$bundle_type];
		} else {
			return false;
		}
		
		if ($provider instanceof BundleProviderInterface) {
			$bundle = $provider->provideBundle($bundle_type, $bundle_name);
		} else {
			$bundle = call_user_func($provider, $bundle_type, $bundle_name);
		}
		
		if (! $bundle instanceof BundleInterface) {
			throw new \UnexpectedValueException("A valid bundle was not provided for '$name'.");
		}
		
		$this->setBundle($bundle);
		
		return true;
	}
	
	/**
	 * Boots a bundle, including its dependencies.
	 * 
	 * @param \xpl\Bundle\BundleInterface $bundle
	 * @return boolean
	 */
	protected function bootBundle(BundleInterface $bundle) {
		
		// Boot bundle dependencies
		$this->bootDependencies($bundle);
		
		// Shutdown and remove any bundles that this bundle overrides.
		if ($overrides = $bundle->getOverrides()) {
			
			foreach($overrides as $name) {
			
				$name = strtolower($name);
				
				if (isset($this->bundles[$name])) {
						
					$this->bundles[$name]->shutdown();
					
					unset($this->bundles[$name]);
				}
			}
		}
		
		$bundle->boot();
		
		return true;
	}
	
	/**
	 * Loads a bundle's dependencies.
	 * 
	 * @param \xpl\Foundation\BundleInterface $bundle
	 * 
	 * @throws \xpl\Foundation\Exception\BundleDependency if missing dependency bundles.
	 */
	protected function bootDependencies(BundleInterface $bundle) {
		
		if (! $depends = $bundle->getDependencies()) {
			return;
		}
		
		$missing = array();
		
		foreach($depends as $dependency) {
			try {
				
				$dependOn = $this->getBundle($dependency);
				
				if (! $dependOn || ! $this->bootBundle($dependOn)) {
					$missing[] = $dependency;
				}
				
			} catch (Exception\BundleDependency $e) {
				
				// catch dependency exceptions while recursing
				$missing = array_merge($missing, $e->getMissing());
			}
		}
		
		if (! empty($missing)) {
			
			$message = sprintf(
				'Could not boot bundle "%s" - failed to load dependencies: "%s"', 
				$bundle->getName(), 
				implode(', ', $missing)
			);
			
			$exception = new Exception\BundleDependency($message, 793);
			$exception->setMissing($missing);
			
			throw $exception;
		}
	}
	
}