namespace Xpl\Http;

use Psr\Http\Message\RequestInterface;
use Psr\Http\Message\ResponseInterface;

interface MiddlewareInterface
{

	/**
     * Invoke the middleware logic.
     *
     * @param \Psr\Http\Message\RequestInterface request
     * @param \Psr\Http\Message\ResponseInterface response
     * @param callable|\Xpl\Http\MiddlewareInterface|null nextMiddleware
	 *
     * @return \Psr\Http\Message\ResponseInterface
     */
    public function __invoke(
        <RequestInterface> request,
        <ResponseInterface> response,
        var nextMiddleware = null
    ) -> <ResponseInterface>;

}
