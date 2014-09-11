<?php

namespace xpl\Routing\Route;

use xpl\Routing\Route;
use xpl\Routing\Resource;

class Compiler 
{
	
	/**
	 * @var \xpl\Routing\Resource
	 */
	protected $resource;
	
	/**
	 * Constructor.
	 * 
	 * @param \xpl\Routing\Resource $resource
	 */
	public function __construct(Resource $resource) {
		$this->resource = $resource;
	}
	
	/**
	 * Compiles a route URI path.
	 * 
	 * Parses the path for tokens and replaces with regex. The matched tokens
	 * are added to the route as the "$tokens" property. The route then knows
	 * what to accept as parameters if and when it is matched.
	 * 
	 * @param \xpl\Routing\Route $route
	 */
	public function compile(Route $route) {
		
		$uri = $route->getUri();
		$tokens = $search = $replace = array();
		
		if (preg_match_all('#\{(\w+)\}(\?)?#', $uri, $vars)) {
			
			$resource_tokens = $this->resource->getTokens();
			
			foreach($vars[1] as $i => $token) {
				
				if (! $regex = $resource_tokens->get($token)) {
					throw new \InvalidArgumentException("Unknown route token: '$token'.");
				}
				
				$regex = "({$regex})";
				
				if (! empty($vars[2][$i])) {
					$regex .= '?';
				}
				
				$search[] = $vars[0][$i];
				$replace[] = $regex;
				
				$tokens[$token] = $token;
			}
			
			$uri = str_replace($search, $replace, $uri);
		}
		
		$route->setCompiledUri($uri);
		$route->setTokens($tokens);
	}
	
}
