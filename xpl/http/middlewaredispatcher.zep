namespace Xpl\Http;

use Psr\Http\Message\RequestInterface;
use Psr\Http\Message\ResponseInterface;
use InvalidArgumentException;

class MiddlewareDispatcher
{

	/**
	 * @var \Xpl\Http\MiddlewareQueue
	 */
	protected queue;

	/**
	 * @var null|callable
	 */
	protected filter;

	/**
	 * @var null|callable
	 */
	protected finalMiddleware;

	/**
	 * Constructor.
	 *
	 * @param \Xpl\Http\MiddlewareQueue queue The middleware queue.
	 * @param callable filter [Optional] Filters each queue entry before calling.
	 */
	public function __construct(<MiddlewareQueue> queue, var filter = null, var finalMiddleware = null)
    {
		let this->queue = queue;

		if typeof filter != "null" {
			if ! is_callable(filter) {
				throw new InvalidArgumentException("Middleware filter must be callable");
			}
			let this->filter = filter;
		}

		if typeof finalMiddleware != "null" {
			if ! is_callable(finalMiddleware) {
				throw new InvalidArgumentException("Final middleware must be callable");
			}
			let this->finalMiddleware = finalMiddleware;
		} else {
			let this->finalMiddleware = function (<RequestInterface> request, <ResponseInterface> response, callable next) {
				return response;
			};
		}
	}

	/**
	 * Calls the next entry in the queue.
	 *
	 * @param \Psr\Http\Message\RequestInterface request The incoming request.
	 * @param \Psr\Http\Message\ResponseInterface response The outgoing response.
	 *
	 * @return \Psr\Http\Message\ResponseInterface
	 */
	public function __invoke(<RequestInterface> request, <ResponseInterface> response) -> <ResponseInterface>
    {
        var middleware, filter;

		if this->queue->isEmpty() {
            let middleware = this->getFinalMiddleware();
		} else {
			let middleware = this->queue->dequeue();
		}

		let filter = this->filter;

		if typeof filter != "null" {
			let middleware = {filter}(middleware);
		}

		return {middleware}(request, response, this);
	}

	/**
	 * Returns a middleware to run when the queue is empty.
	 *
	 * @return callable
	 */
	public function getFinalMiddleware() -> callable
    {
		if typeof this->finalMiddleware != "null" {
			return this->finalMiddleware;
		}

		return function (<RequestInterface> request, <ResponseInterface> response, callable next) {
			return response;
		};
	}

	/**
	 * Returns a middleware to run when the queue is empty.
	 *
	 * @return callable
	 */
	public function setFinalMiddleware(callable middleware)
    {
		let this->finalMiddleware = middleware;
	}

}
