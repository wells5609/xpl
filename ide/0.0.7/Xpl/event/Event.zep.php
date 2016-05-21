<?php

namespace Xpl\Event;


class Event
{
    /**
     * Unique identifier for the event.
     *
     * @var string
     */
    protected $id;

    /**
     * Event value.
     *
     * @var mixed
     */
    protected $value;

    /**
     * Whether the default behavior should be prevented.
     *
     * @var boolean
     */
    private $defaultPrevented = false;

    /**
     * Whether propagation should be stopped.
     *
     * @var boolean
     */
    private $propagationStopped = false;


    /**
     * Constructor takes one string parameter, the event ID.
     *
     * @param string $id Event identifier.
     */
    public function __construct($id) {}

    /**
     * Returns the event ID.
     *
     * @return string 
     */
    public function getID() {}

    /**
     * Prevents execution of the event"s default behavior.
     *
     * @return \Xpl\Event\Event 
     */
    final public function preventDefault() {}

    /**
     * Stops propagation of the event.
     *
     * @return \Xpl\Event\Event 
     */
    final public function stopPropagation() {}

    /**
     * Returns true if preventDefault() has been called on the event.
     *
     * @return boolean 
     */
    final public function isDefaultPrevented() {}

    /**
     * Returns true if stopPropagation() has been called on the event.
     *
     * @return boolean 
     */
    final public function isPropagationStopped() {}

    /**
     * Magic get to allow access to non-public properties.
     *
     * @param string $key 
     * @param string $var Propety name.
     * @return mixed value or null.
     */
    public function __get($key) {}

    /**
     * @param string $key 
     */
    public function __isset($key) {}

    /**
     * @param string $key 
     * @param mixed $value 
     */
    public function __set($key, $value) {}

    /**
     * @param mixed $key 
     */
    public function __unset($key) {}

}
