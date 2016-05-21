<?php

namespace Xpl\Http;


interface MiddlewareInterface
{

    /**
     * Invoke the middleware logic.
     *
     * @param \Psr\Http\Message\RequestInterface $request 
     * @param \Psr\Http\Message\ResponseInterface $response 
     * @param callable|\Xpl\Http\MiddlewareInterface|null $nextMiddleware 
     * @return \Psr\Http\Message\ResponseInterface 
     */
    public function __invoke(\Psr\Http\Message\RequestInterface $request, \Psr\Http\Message\ResponseInterface $response, $nextMiddleware = null);

}
