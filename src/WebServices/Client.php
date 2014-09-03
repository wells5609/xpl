<?php

namespace xpl\WebServices;

class Client {
	
	protected $adapter;
	
	public function __construct(Client\RequestAdapterInterface $adapter) {
		$this->adapter = $adapter;
	}
	
	public function __invoke(RequestInterface $request) {
		
		return $request->createResponse(call_user_func($this->adapter, $request->getUrl(), $request->getOptions()));
	}
	
	public function supportsMultiple() {
		return $this->adapter instanceof Client\MultiRequestAdapterInterface;
	}
	
	public function multi(array $requests) {
		
		if (! $this->adapter instanceof Client\MultiRequestAdapterInterface) {
			throw new \RuntimeException("Adapter does not support multiple requests.");
		}
		
		return $this->adapter->multi($requests);
	}
	
	/**
	 * Returns the "best" request adapter class available.
	 * 
	 * @return string Class name, or null if none are available.
	 */
	public static function detectAdapterClass() {
		
		$adapters = array(
			'GuzzleHttp\\Client' => 'GuzzleAdapter',
			'Buzz\\Browser' => 'BuzzAdapter',
			'Requests' => 'RequestsAdapter',
		);
		
		foreach($adapters as $class => $client_class) {
			if (class_exists($class, true)) {
				return __NAMESPACE__.'\\Client\\'.$qclass;
			}
		}
		
		if (ini_get('allow_url_fopen')) {
			return __NAMESPACE__.'\\Client\\FopenAdapter';
		}
		
		return null;
	}
	
}
