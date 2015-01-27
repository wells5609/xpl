<?php
/**
 * Framework functions.
 */

/** ================================
	DI
================================= */
 
/**
 * Returns an item from the dependency injection container, or the container itself.
 * 
 * @param string $key [Optional] Item key, or null to return the container.
 * @return \xpl\Dependency\DI|mixed
 */
function di($key = null) {
	return isset($key) ? xpl::get($key) : xpl::getDi();
}

/**
 * Registers a dependency.
 * 
 * @param string $key Object key.
 * @param object|\Closure $object Object, or closure that returns the object.
 * @return void
 */
function register($key, $object) {
	xpl::set($key, $object);
}

/**
 * Autoload a namespace from a given directory using PSR-4 spec.
 * 
 * @param string $namespace Class namespace.
 * @param string $dirpath Absolute directory path.
 * @return void
 */
function autoload_psr4($namespace, $dirpath) {
	xpl::get('autoloader')->addPsr4($namespace, $dirpath);
}

/**
 * Autoload a namespace from a given directory using PSR-0 spec.
 * 
 * @param string $namespace Class namespace.
 * @param string $dirpath Absolute directory path.
 * @return void
 */
function autoload_psr0($namespace, $dirpath) {
	xpl::get('autoloader')->addPsr0($namespace, $dirpath);
}

/** ================================
	Function loaders
================================= */

/**
 * Checks if a set of functions for the given namespace have been loaded.
 * 
 * Functions are autoloaded by defining the functions below a dummy 
 * class called "functions" (i.e. class = "<namespace>\functions") in
 * a file called "functions.php" that follows the autoloading scheme.
 * 
 * @param string $namespace Namespace.
 * @return boolean True if functions are loaded, otherwise false.
 */
function functions_loaded($namespace) {
	return class_exists("{$namespace}\\functions", false);
}

/**
 * Loads a set of functions for the given namespace.
 * 
 * @param string $namespace Namespace.
 * @return boolean True if functions loaded, otherwise false.
 */
function load_functions($namespace) {
	return class_exists("{$namespace}\\functions", true);
}


/** ================================
	Bundles
================================= */

/**
 * Registers a bundle provider.
 * 
 * @param string|array $type Bundle type, ID, or an array of ID's.
 * @param \Closure|\xpl\Foundation\BundleProviderInterface $provider
 * @return void
 */
function register_bundle_provider($type, $provider) {
	
	$bundles = xpl::get('bundles');
	
	if (is_array($type)) {
		$bundles->provideMultiple($type, $provider);
	
	} else if (false === strpos($type, '.')) {
		$bundles->provideType($type, $provider);
	
	} else {
		$bundles->provide($type, $provider);
	}
}

/**
 * Returns a bundle object for given key, if it exists.
 * 
 * @param string $key Bundle key like "plugin.users".
 * @return \xpl\Bundle\BundleInterface
 */
function get_bundle($key) {
	return xpl::get('bundles')->getBundle($key);
}

/**
 * Checks if a library is loaded.
 * 
 * @param string $library Library name.
 * @return boolean True if library has been loaded, otherwise false.
 */
function library_loaded($library) {
	return xpl::get('bundles')->isBooted('library.'.$library);
}

/**
 * Loads a library.
 * 
 * @param string $library Library name.
 * @return boolean True if library was successfully loaded, otherwise false.
 */
function load_library($library) {
	return xpl::get('bundles')->boot('library.'.$library);
}

/**
 * Checks whether a plugin is loaded.
 * 
 * @param string $plugin Plugin name.
 * @return boolean True if plugin has been loaded, otherwise false.
 */
function plugin_loaded($plugin) {
	return xpl::get('bundles')->isBooted('plugin.'.$plugin);
}

/**
 * Loads a plugin.
 * 
 * @param string $plugin Plugin name.
 * @return boolean True if plugin was loaded, otherwise false.
 */
function load_plugin($plugin) {	
	return xpl::get('bundles')->boot('plugin.'.$plugin);
}

/**
 * Checks whether an application is loaded.
 * 
 * @param string $app Application ID/name.
 * @return boolean True if app has been loaded, otherwise false.
 */
function app_loaded($app) {
	return xpl::get('bundles')->isBooted('app.'.$app);
}

/**
 * Loads an application.
 * 
 * @param string $app Application ID/name.
 * @return boolean True if app was loaded, otherwise false.
 */
function load_app($app) {
	return xpl::get('bundles')->boot('app.'.$app);
}

/**
 * Returns an application by ID.
 * 
 * @param string $id Application ID.
 * @return \xpl\Bundle\Application\Application
 */
function get_app($app) {
	return xpl::get('bundles')->getBundle('app.'.$app);
}

/**
 * Returns or sets a config item for an application.
 * 
 * @param string $key Config item key.
 * @param mixed $value [Optional] Config item value.
 * @param string $app [Optional] Application ID. Defaults to value of APPID.
 * @return mixed
 */
function app_config($key, $value = null, $appID = null) {
	
	if (! isset($appID)) {
		$appID = xpl::get('env')->get('app');
	}
	
	if (! $app = xpl::get('bundles')->getBundle('app.'.$appID)) {
		throw new RuntimeException("Invalid application: '$appID'.");
	}
		
	$prev_value = $app->getConfig($key);
	
	if (isset($value)) {
		$app->setConfig($key, $value);
	}
	
	return $prev_value;
}


/** ================================
	Environment/System
================================= */

/**
 * Returns an environment variable value.
 * 
 * @param string $key Variable name.
 * @param mixed $default [Optional] Default value to return if not set.
 * @return mixed Environment variable value, or default value if not set.
 */
function env($key, $default = null) {
	return xpl::get('env')->get($key) ?: $default;
}

/**
 * Sets an environment variable.
 * 
 * @param string $key Variable name.
 * @param mixed $value Item value.
 * @return void
 */
function env_set($key, $value) {
	xpl::get('env')->set($key, $value);
}

/**
 * Returns the domain name string, optionally including subdomain and/or TLD.
 * 
 * @param int $flags Bitwise flags
 * @return string
 */
function domain_name($flags = null) {
	return xpl\System\Server::getDomainName($flags);
}

/**
 * Returns a named path.
 * 
 * @param string $name Path name.
 * @return string Path if found, otherwise null.
 */
function get_path($name) {
	return xpl::get('env')->getPath($name);
}


/** ================================
	Services
================================= */

/**
 * Returns a registered service instance.
 * 
 * @param string $name Service name.
 * @return \xpl\Data\Service\ServiceInterface
 */
function service($name) {
	return xpl::get('services')->get($name);
}

/**
 * Returns whether a service is running or registered.
 * 
 * @param string $name Service name.
 * @return boolean True if the service exists, otherwise false.
 */
function service_exists($name) {
	return xpl::get('services')->exists($name);
}

/**
 * Registers a service class.
 * 
 * @param string $name Service name.
 * @param string $class Service classname, an implementation of ServiceInterface.
 * @return void
 */
function register_service($name, $class) {
	xpl::get('services')->register($name, $class);
}

/**
 * Unregisters a service.
 * 
 * @param string $name Service name.
 * @param string $class [Optional] Service class. If given, the service is 
 * only unregistered if its class matches the one given.
 * @return void
 */
function unregister_service($name, $class = null) {
	xpl::get('services')->unregister($name, $class = null);
}


/** ============================
	Database
============================= */

/**
 * Returns a database configuration.
 * 
 * @param string $dbname Database name.
 * @return \xpl\Database\Config\Database
 */
function db_get_config($dbname) {
	return xpl::get('dbal')->getConfig($dbname);
}

/**
 * Configures a database from an associative array.
 * 
 * @param array $config Associative array of config options.
 * @return boolean True if db was successfully configured, otherwise false.
 */
function db_configure(array $config) {
	return xpl::get('dbal')->configure($config);
}

/**
 * Returns a connection for the given database.
 * 
 * @param string $name Database name
 * @return \xpl\Database\PdoAdapter
 */
function db_connect($name) {
	return xpl::get('dbal')->connect($name);
}

/**
 * Returns number of queries executed during the current request.
 * 
 * @return integer
 */
function db_get_query_count() {
	return xpl::get('dbal')->getTotalQueries();
}

/**
 * Returns the connection pool instance.
 * 
 * @return \xpl\Database\ConnectionPool
 */
function dbal() {
	return xpl::get('dbal');
}


/** ============================
	Events
============================= */

/**
 * Binds a callback to an event.
 * 
 * @param string|\xpl\Event\Event $event Event ID or object.
 * @param callable $callback Callback to run on event trigger.
 * @param int $priority [Optional] Listener priority. Default 10.
 */
function on($event, $callback, $priority = 10) {
	xpl::get('events')->on($event, $callback, $priority);
}

/**
 * Binds a callback to an event, where all other bindings are ignored.
 * 
 * Events with a "one" callback will only have their "one" listener
 * called - any others will be ignored.
 * 
 * @param string|\xpl\Event\Event $event Event ID or object.
 * @param callable $callback Callback to run on event trigger.
 * @param int $priority [Optional] Listener priority. Default 10.
 */
function once($event, $callback, $priority = 10) {
	xpl::get('events')->one($event, $callback, $priority);
}

/**
 * Triggers an event.
 * 
 * @param string|\xpl\Event\Event $event Event ID or object.
 * @param ... Arguments to pass to callback(s).
 * @return array Event results.
 */
function trigger($event /*[, $arg1 [, ...]]*/) {
	$args = func_get_args();
	array_shift($args);
	return xpl::get('events')->triggerArray($event, $args);
}

/**
 * Triggers an event using an array of arguments.
 * 
 * @param string|\xpl\Event\Event $event Event ID or object.
 * @param array $args Arguments to pass to callback(s).
 * @return array Event results.
 */
function trigger_array($event, array $args = array()) {
	return xpl::get('events')->triggerArray($event, $args);
}

/**
 * Triggers a filter event.
 * 
 * Filter events pass their value through as a public
 * property on Event (e.g. $event->value).
 * 
 * The function returns the value as last modified by the 
 * event listeners, or the initial value if none exist.
 * 
 * @param string|xpl\Event\Event $event Event ID or object.
 * @param mixed $value Initial value to filter.
 * @param ... Arguments to pass to callback(s).
 * @return mixed Filtered value.
 */
function filter($event, $value) {
	$args = func_get_args();
	array_shift($args);
	return xpl::get('events')->filterArray($event, $args);
}

/**
 * Triggers a filter event.
 * 
 * @param string|xpl\Event\Event $event Event ID or object.
 * @param array $args Initial value and callback arguments.
 * @return mixed Filtered value.
 */
function filter_array($event, array $args) {
	return xpl::get('events')->filterArray($event, $args);
}


/** ============================
	URLs
============================= */

/**
 * @return \xpl\Utility\Url
 */
function url() {
	return xpl::get('url');
}

/**
 * Returns URL to the specified application.
 *
 * @param string $appID Application ID. Default is APPID.
 * @param string $path [Optional] URI path.
 * @param string $query [Optional] Query string.
 * @return string URL
 */
function app_url($appID = APPID, $path = null, $query = null) {
	return xpl::get('url')->toApp($appID, $path, $query);
}

/**
 * Returns URL to the current site.
 *
 * @param string $path [Optional] URL path.
 * @param string $query [Optional] Query string appended to URL.
 * @return string URL
 */
function site_url($path = null, $query = null) {
	return xpl::get('url')->to($path, $query);
}

/**
 * Returns the current request URL.
 * 
 * @return string Current request URL.
 */
function current_url() {
	return xpl::get('url')->getCurrent();
}

/**
 * Returns a URL from a file path.
 *
 * @param string $path Absolute path to file on local filesystem.
 * @return string URL to given file.
 */
function file_url($path) {
	return xpl::get('url')->toFile($path);
}

/**
 * Returns a URL to a Google-hosted jQuery library.
 *
 * @param string $version jQuery version. Default "1.11.1".
 * @return string
 */
function jquery_url($version = '1.11.1') {
	return xpl::get('url')->toJquery($version);
}


/** ============================
	Request
============================= */

/**
 * Returns the current request URI path.
 * 
 * @return string Current request path.
 */
function request_uri() {
	return xpl::get('request')->getUri();
}

/**
 * Returns the current request query string.
 * 
 * @return string Current request query.
 */
function request_query() {
	return xpl::get('request')->getQuery();
}

/**
 * Returns the value of a parameter from the current request.
 * 
 * @param string $name Parameter name.
 * @return string|null Parameter value, if set, otherwise null.
 */
function request_param($name) {
	return xpl::get('request')->getParam($name);
}

/**
 * Returns whether a given request parameter exists.
 * 
 * @param string $name Parameter name.
 * @return boolean True if the parameter exists, otherwise false.
 */
function request_param_exists($name) {
	return xpl::get('request')->hasParam($name);
}


/** ============================
	Response
============================= */

function redirect($url, $status = 0) {
	xpl::get('response')->redirect($url, $status);
}

function response_status($code = null) {
	
	if (! isset($code)) {
		return xpl::get('response')->getStatus();
	}
	
	xpl::get('response')->setStatus($code);
}

function response_content_type($content_type = null) {
		
	if (! isset($content_type)) {
		return xpl::get('response')->getContentType();
	}
	
	xpl::get('response')->setContentType($content_type);
}

function response_type($type = null) {
	
	if (! isset($type)) {
		return xpl::get('response')->getType();
	}
	
	if (is_string($type)) {
		
		if ('api' === $type) {
			$class = 'xpl\\Api\\Response\\Type';
		} else {
			$class = 'xpl\\Web\\Response\\'.ucfirst($type);
		}
		
		if (! class_exists($class)) {
			throw new Exception("Error Processing Request");
		}
		
		$type = new $class();
	}
	
	xpl::get('response')->setType($type);
}


/** ============================
	Utility
============================= */
load_functions('xpl\Utility');

/** ============================
	Common
============================= */
load_functions('xpl\Common');

/** ============================
	Cache
============================= */
load_functions('xpl\Cache');

/** ============================
	Session
============================= */
load_functions('xpl\Session');

/** ============================
	Http
============================= */
load_functions('xpl\Http');

/** ============================
	Framework
============================= */
load_functions('xpl\Framework');
