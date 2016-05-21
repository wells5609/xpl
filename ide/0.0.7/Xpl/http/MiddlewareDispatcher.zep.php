<?php

namespace Xpl\Http;


class MiddlewareDispatcher
{
    /**
     * @var \Xpl\Http\MiddlewareQueue
     */
    protected $queue;

    /**
     * @var null|callable
     */
    protected $filter;


    /**
     * Constructor.
     *
     * @param \Xpl\Http\MiddlewareQueue $queue The middleware queue.
     * @param callable $filter [Optional] Filters each queue entry before calling.
     */
    public function __construct(MiddlewareQueue $queue, $filter = null) {}

    /**
     * Calls the next entry in the queue.
     *
     * @param \Psr\Http\Message\RequestInterface $request The incoming request.
     * @param \Psr\Http\Message\ResponseInterface $response The outgoing response.
     * @return \Psr\Http\Message\ResponseInterface 
     */
    public function __invoke(\Psr\Http\Message\RequestInterface $request, \Psr\Http\Message\ResponseInterface $response) {}

    /**
     * Returns the next middleware callable.
     *
     * @return callable 
     */
    protected function getNextMiddleware() {}

    /**
     * Returns a middleware to run when the queue is empty.
     *
     * @return callable 
     */
    protected function getFinalMiddleware() {}

}
