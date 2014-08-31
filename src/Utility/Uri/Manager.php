<?php

namespace xpl\Utility\Uri;

class Manager {
	
	protected static $templates = array();
	
	public static function register(Template $uri_template) {
		static::$templates[$uri_template->name()] = $uri_template;
	}
	
	public static function unregister($uri_template_name) {
		unset(static::$templates[$uri_template_name]);
	}
	
	public static function build($name, array $args) {
		
		if (isset(static::$templates[$name])) {
			return static::$templates[$name]->build($args);
		}
		
		$tmpl = new Template($name);
		
		return $tmpl->build($args);
	}
	
}
