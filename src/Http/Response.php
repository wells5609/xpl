<?php

namespace xpl\Http;

class Response {
	
	use HeaderTrait;
	
	protected $charset = 'UTF-8';
	protected $status = 200;
	protected $body;
	protected $send_body = true;
	protected $request_mimetype;
	private $sent = false;
	
	/**
	 * Construct response.
	 */
	public function __construct(Request $request) {
		if ($request->is('HEAD')) {
			$this->send_body = false;
		}
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
	 * Sets the body content.
	 * 
	 * @param mixed $body
	 * @return $this
	 */
	public function setBody($body) {
		$this->body = $body;
		return $this;
	}
	
	/**
	 * Returns the body content.
	 * 
	 * @return mixed
	 */
	public function getBody() {
		return $this->body;
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
	 * Sets the Content-Type header.
	 * 
	 * @param string $mimetype Content-type mime to send.
	 * @return $this
	 */
	public function setContentType($mimetype) {
		$this->setHeader('Content-Type', $mimetype, true);
		return $this;
	}
	
	/**
	 * Returns the Content-Type header set, if any.
	 * 
	 * @return string|null
	 */
	public function getContentType() {
		return $this->getHeader('Content-Type');
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
		$this->setHeader('Access-Control-Allow-Origin', $value);
		return $this;
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
	public function send($exit = true) {
		
		if ($this->sent) return;
		
		ob_get_level() and ob_start();
		
		if (! isset($this->status)) {
			$this->status = $this->hasHeader('Location') ? 302 : http_response_code();
		}
		
		Util::sendStatus($this->status);
		
		$this->sendHeaders();
		
		if ($this->send_body) {
			echo $this->body;
		}
		
		ob_get_level() and ob_end_flush();
		
		$this->sent = true;
		
		$exit and exit;
	}
	
}
