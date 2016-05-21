<?php

namespace Xpl\Event;


class Listener
{
    /**
     * Event's unique identifier.
     *
     * @var string
     */
    protected $event_id;

    /**
     * Callback.
     *
     * @var callable
     */
    protected $callback;

    /**
     * Priority.
     *
     * @var integer
     */
    protected $priority;


    /**
     * Construct listener using event ID, callback, and priority.
     *
     * @param string $event_id 
     * @param callable $callback Callback to run when listener called.
     * @param integer $priority Listener execution priority.
     * @param string $eventID Unique identifier for the event.
     */
    public function __construct($event_id, $callback, $priority) {}

    /**
     * Invokes the listener's callback function.
     *
     * @param array $args Array of arguments to pass to callback.
     * @return mixed of callback.
     */
    public function __invoke($args) {}

    /**
     * @param mixed $key 
     */
    public function __get($key) {}

}
