<?php

namespace xpl\Http;

class Response {
	
	use HeaderTrait;
	
	protected $charset = 'UTF-8';
	protected $status = 200;
	protected $body;
	protected $formatter;
	protected $send_body = true;
	private $sent = false;
	
	/**
	 * Construct response.
	 */
	public function __construct(Request $request, Response\Formatter $formatter) {
		
		if ($request->is('HEAD')) {
			$this->send_body = false;
		}
		
		$this->formatter = $formatter;
		
		$this->body = new Response\Body();
	}
	
	public function getFormatter() {
		return $this->formatter;
	}
	
	/**
	 * Sets the body content.
	 * 
	 * @param mixed $body
	 * @return $this
	 */
	public function setBody($body) {
		
		if ($body instanceof Response\BodyInterface) {
			$this->body = $body;
		} else {
			$this->body->set($body);
		}
		
		return $this;
	}
	
	/**
	 * Returns the body content or object.
	 * 
	 * @param boolean $as_object [Optional] Return the object. Default false.
	 * @return mixed|\xpl\Component\Http\Response\BodyInterface
	 */
	public function getBody($as_object = false) {
		return $as_object ? $this->body : $this->body->get();
	}
	
	/**
	 * Marks the response as sent and hence prevents it being sent (again).
	 * 
	 * The response does not actually have to have been sent.
	 * 
	 * @return $this
	 */
	final public function setSent() {
		$this->sent = true;
		return $this;
	}
	
	/**
	 * Checks whether the response has been sent.
	 * 
	 * @return boolean
	 */
	final public function isSent() {
		return $this->sent;
	}
	
	/**
	 * Sets output charset.
	 * 
	 * @param string $charset Charset to send w/ content-type.
	 * @return $this
	 */
	public function setCharset($charset) {
		$this->charset = $charset;
		return $this;
	}

	/**
	 * Returns output charset
	 * 
	 * @return string Charset
	 */
	public function getCharset() {
		return $this->charset;
	}

	/**
	 * Sets the HTTP response status code.
	 * 
	 * @param int $code HTTP status code.
	 * @return $this
	 */
	public function setStatus($code) {
		$this->status = (int)$code;
		return $this;
	}
	
	/**
	 * Returns the response status code.
	 * 
	 * @return int HTTP status code.
	 */
	public function getStatus() {
		return $this->status;
	}
	
	/**
	 * Sets the "Access-Control-Allow-Origin" header to the given value.
	 * 
	 * Used to allow CORS requests. Set to "*" to allow all hosts.
	 * 
	 * @param string $value
	 * @return $this
	 */
	public function setAccessControlAllowOrigin($value) {
		return $this->setHeader('Access-Control-Allow-Origin', $value);
	}
	
	/**
	 * Sets the various cache headers. Auto unsets 'Last-Modified'
	 * if $expires_offset is falsy.
	 * 
	 * @param int|bool $expires_offset	Time in seconds from now to cache. 
	 * 									Pass 0 or false for no cache.
	 * @return $this
	 */
	public function setCacheHeaders($expires_offset = 86400) {

		$headers = Util::buildCacheHeaders($expires_offset);
		
		// empty("0") is false negative
		if (empty($expires_offset) || '0' === $expires_offset) {
			unset($this->headers['Last-Modified']);
		}

		$this->setHeaders($headers);

		return $this;
	}
	
	/**
	 * Redirects the user's browser to a new location.
	 * 
	 * @param string $url URL to redirect user to.
	 * @param int $status [Optional] Valid redirect status code to send. Default 0 (sends 302).
	 * @param boolean $send Whether to send the redirect response immediately. Default true.
	 * @return $this
	 */
	public function redirect($url, $status = 0, $send = true) {
			
		$this->setHeader('Location', $url, true);
		
		$this->send_body = false;
		
		if (0 !== $status && 300 < $status && 400 > $status) {
			$this->setStatus($status);
		}
		
		if ($send) {
			$this->send();
		}
		
		return $this;
	}
	
	/**
	 * Sends the response headers and body, then exits.
	 * 
	 * @return void
	 */
	public function send() {
		
		if ($this->sent) return;
		
		ob_get_level() and ob_start();
		
		if (! isset($this->status)) {
			$this->status = $this->hasHeader('Location') ? 302 : http_response_code();
		}
		
		Util::sendStatus($this->status);
		
		$this->sendHeaders();
		
		if ($this->send_body) {
			$this->sendBody();
		}
		
		ob_get_level() and ob_end_flush();
		
		$this->sent = true;
		
		exit;
	}
	
	protected function sendBody() {
		
		if ($this->body instanceof Response\BodyStream) {
			$body = call_user_func($this->body, $this);
		
		} else {
			
			// The content type may change depending on the data, so
			// send the content-type header after building the output.
			$body = $this->getFormatter()->format($this);
			
			Util::sendContentType($this->getFormatter()->getMimetype(), $this->getCharset());
		}
		
		echo $body;
	}

}
