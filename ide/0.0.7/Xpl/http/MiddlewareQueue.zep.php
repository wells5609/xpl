<?php

namespace Xpl\Http;


class MiddlewareQueue extends \Xpl\Collection\Queue
{

    /**
     * @param mixed $middleware 
     */
    public function enqueue($middleware) {}

    /**
     * @param mixed $index 
     * @param mixed $value 
     */
    public function offsetSet($index, $value) {}

    /**
     * @param mixed $middleware 
     */
    public function push($middleware) {}

    /**
     * @param mixed $middleware 
     */
    public function attach($middleware) {}

    /**
     * @param mixed $middleware 
     */
    public function unshift($middleware) {}

    /**
     * @param mixed $middleware 
     */
    public static function assertValidMiddleware($middleware) {}

}
